#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include <set>
#include "Enums.hpp"
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time

void initializePlayerSettlementsAndRoads(Board &board, Player &player, int settlement1, int road1, int settlement2, int road2);
int rollDice();
void takeTurn(Board &board, Player &player, std::vector<Player> &players);
bool checkVictory(const Player &player);

int main(int argc, char **argv)
{
    std::srand(std::time(0)); // Seed random number generator
    std::vector<Player> players;
    std::string name;

    // Prompt for player names interactively
    std::cout << "Welcome to Catan! Please enter the names of three players." << std::endl;

    for (int i = 1; i <= 3; ++i)
    {
        std::cout << "Enter name for Player " << i << ": ";
        std::getline(std::cin, name);
        players.emplace_back(name);
    }

    // Initialize the game board
    Board board;
    board.initializeBoard();

    // Display a welcome message for each player
    std::cout << "\nPlayers have joined the game!\n";
    std::cout << "-----------------------------------\n";

    // Initialize each player's settlements and roads
    initializePlayerSettlementsAndRoads(board, players[0], 3, 6, 28, 36);   // red
    initializePlayerSettlementsAndRoads(board, players[1], 13, 14, 41, 55); // yellow
    initializePlayerSettlementsAndRoads(board, players[2], 40, 52, 43, 57); // blue

    // Start the game loop
    bool gameOver = false;
    while (!gameOver)
    {
        for (auto &player : players)
        {
            takeTurn(board, player, players);
            if (checkVictory(player))
            {
                std::cout << player.getName() << " has won the game with " << player.getVictoryPoints() << " victory points!" << std::endl;
                gameOver = true;
                break;
            }
        }
    }

    return 0;
}

void initializePlayerSettlementsAndRoads(Board &board, Player &player, int settlement1, int road1, int settlement2, int road2)
{
    auto collectResources = [&player](std::vector<ResourceType> resources)
    {
        std::set<ResourceType> uniqueResources;
        for (const auto &resource : resources)
        {
            if (uniqueResources.find(resource) == uniqueResources.end() && player.getResourceCount(resource) == 0)
            {
                player.addResource(resource, 1);
                uniqueResources.insert(resource);
            }
        }
    };

    // Initialize first settlement
    std::vector<ResourceType> resources1 = board.initializeSettlements(player.getPlayerId(), settlement1);
    collectResources(resources1);
    player.addSettlement(settlement1);
    if (board.buildRoad(player.getPlayerId(), road1))
    {
        player.addRoad(road1);
    }

    // Initialize second settlement
    std::vector<ResourceType> resources2 = board.initializeSettlements(player.getPlayerId(), settlement2);
    collectResources(resources2);
    player.addSettlement(settlement2);
    if (board.buildRoad(player.getPlayerId(), road2))
    {
        player.addRoad(road2);
    }

    // Add initial victory points
    player.addVictoryPoint(2);

    // Print player status
    player.printStatus();
    std::cout << "-----------------------------------\n";
}

int rollDice()
{
    int die1 = std::rand() % 6 + 1;
    int die2 = std::rand() % 6 + 1;
    return die1 + die2;
}

void takeTurn(Board &board, Player &player, std::vector<Player> &players)
{
    std::cout << "\n"
              << player.getName() << "'s turn. Press Enter to roll dice.";
    std::cin.ignore();

    int diceRoll = rollDice();
    std::cout << player.getName() << " rolled a " << diceRoll << "." << std::endl;

    // Distribute resources based on dice roll
    board.distributeResources(diceRoll, players);

    // If the roll total is 7, handle discarding resources
    if (diceRoll == 7)
    {
        std::cout << "Rolled a 7! Players with more than 7 resource cards must discard half." << std::endl;
        for (auto &otherPlayer : players)
        {
            if (otherPlayer.getTotalResourceCount() > 7)
            {
                otherPlayer.discardResources();
            }
        }
    }

    // Player actions
    std::string action;
    while (true)
    {
        std::cout << "\nChoose an action: trade, build_road, build_settlement, build_city, buy_development_card, use_development_card, end_turn: ";
        std::getline(std::cin, action);

        if (action == "trade")
        {
            // Implement trade logic
            std::cout << "Trading is not yet implemented." << std::endl;
        }
        else if (action == "build_road")
        {
            int edgeId;
            std::cout << "Enter edge ID to build road: ";
            std::cin >> edgeId;
            std::cin.ignore();
            if (player.canBuildRoad())
            {
                if (board.buildRoad(player.getPlayerId(), edgeId))
                {
                    player.addRoad(edgeId);
                }
                else
                {
                    std::cout << "Failed to place road on the board. Please choose a valid edge ID." << std::endl;
                }
            }
            else
            {
                std::cout << "Not enough resources to build a road." << std::endl;
            }
        }
        else if (action == "build_settlement")
        {
            int vertexId;
            std::cout << "Enter vertex ID to build settlement: ";
            std::cin >> vertexId;
            std::cin.ignore();
            if (player.canBuildSettlement())
            {
                if (board.buildSettlement(player.getPlayerId(), vertexId))
                {
                    player.addSettlement(vertexId);
                }
                else
                {
                    std::cout << "Failed to place settlement on the board. Please choose a valid vertex ID." << std::endl;
                }
            }
            else
            {
                std::cout << "Not enough resources to build a settlement." << std::endl;
            }
        }
        else if (action == "build_city")
        {
            int vertexId;
            std::cout << "Enter vertex ID to build city: ";
            std::cin >> vertexId;
            std::cin.ignore();
            if (player.canBuildCity())
            {
                if (board.buildCity(player.getPlayerId(), vertexId))
                {
                    player.addCity(vertexId);
                }
                else
                {
                    std::cout << "Failed to upgrade settlement to city. Please choose a valid vertex ID." << std::endl;
                }
            }
            else
            {
                std::cout << "Not enough resources to build a city." << std::endl;
            }
        }
        else if (action == "buy_development_card")
        {
            player.buyDevelopmentCard();
        }
        else if (action == "use_development_card")
        {
            // Implement development card usage logic
            std::cout << "Using development cards is not yet implemented." << std::endl;
            return; // End the turn after using a development card
        }
        else if (action == "end_turn")
        {
            break;
        }
        else
        {
            std::cout << "Invalid action. Please try again.";
        }
    }

    // Print player status
    std::cout << "\nStatus of Player " << player.getName() << " after turn:\n";
    player.printStatus();
    std::cout << "-----------------------------------\n";
}

bool checkVictory(const Player &player)
{
    return player.getVictoryPoints() >= 10;
}
