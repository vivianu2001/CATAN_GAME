#include <iostream>
#include <vector>
#include <set>
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time
#include "Player.hpp"
#include "Board.hpp"
#include "Enums.hpp"

void initializePlayerSettlementsAndRoads(Board &board, Player &player, int settlement1, int road1, int settlement2, int road2);
int rollDice();
void trade(Player &player1, Player &player2);

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
    std::cout << "\nPlayers have joined the game!";
    std::cout << "-----------------------------------\n";

    // Initialize each player's settlements and roads
    initializePlayerSettlementsAndRoads(board, players[0], 3, 6, 28, 36);   // red
    initializePlayerSettlementsAndRoads(board, players[1], 13, 14, 41, 55); // yellow
    initializePlayerSettlementsAndRoads(board, players[2], 40, 52, 43, 57); // blue

    while (true)
    {
        for (auto &player : players)
        {
            std::cout << "\n"
                      << player.getName() << "'s turn. Press Enter to roll dice.";
            std::cin.ignore();

            int diceRoll = rollDice();
            std::cout << player.getName() << " rolled a " << diceRoll << "." << std::endl;

            // Distribute resources based on dice roll
            board.distributeResources(diceRoll, players);

            std::string action;
            while (true)
            {
                std::cout << "\nChoose an action: trade, build_road, build_settlement, build_city, buy_development_card, use_development_card, end_turn: ";
                std::getline(std::cin, action);

                if (action == "trade")
                {
                    std::string tradeWith;
                    std::cout << "Enter the name of the player you want to trade with: ";
                    std::getline(std::cin, tradeWith);

                    if (tradeWith == player.getName())
                    {
                        std::cout << "You cannot trade with yourself." << std::endl;
                        continue;
                    }

                    bool playerFound = false;
                    for (auto &otherPlayer : players)
                    {
                        if (otherPlayer.getName() == tradeWith)
                        {
                            trade(player, otherPlayer);
                            playerFound = true;
                            break;
                        }
                    }

                    if (!playerFound)
                    {
                        std::cout << "Player not found. Please try again." << std::endl;
                    }
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
                        if (board.buildSettlement(player.getPlayerId(), vertexId, false))
                        {
                            player.addSettlement(vertexId);
                        }
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
                    }
                }
                else if (action == "buy_development_card")
                {
                    player.buyDevelopmentCard();
                }
                else if (action == "use_development_card")
                {
                    player.useDevelopmentCard(players, board);
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

            // Check for game over condition
            if (player.getVictoryPoints() >= 10)
            {
                std::cout << "Player " << player.getName() << " has won the game with " << player.getVictoryPoints() << " victory points!" << std::endl;
                return 0;
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

void trade(Player &player1, Player &player2)
{
    std::string resource1, resource2;
    int amount1, amount2;

    std::cout << player1.getName() << ", enter the resource you want to trade (Wood, Brick, Wool, Iron, Oat): ";
    std::getline(std::cin, resource1);
    std::cout << "Enter the amount: ";
    std::cin >> amount1;
    std::cin.ignore();

    std::cout << player2.getName() << ", enter the resource you want to trade (Wood, Brick, Wool, Iron, Oat): ";
    std::getline(std::cin, resource2);
    std::cout << "Enter the amount: ";
    std::cin >> amount2;
    std::cin.ignore();

    ResourceType res1 = stringToResourceType(resource1);
    ResourceType res2 = stringToResourceType(resource2);

    if (player1.getResourceCount(res1) >= amount1 && player2.getResourceCount(res2) >= amount2)
    {
        player1.addResource(res1, -amount1);
        player2.addResource(res2, -amount2);

        player1.addResource(res2, amount2);
        player2.addResource(res1, amount1);

        std::cout << "Trade successful!" << std::endl;
    }
    else
    {
        std::cout << "Trade failed. Not enough resources." << std::endl;
    }
}
