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

            // Print player status
            std::cout << "\nStatus of Player " << player.getName() << " after rolling dice:\n";
            player.printStatus();
            std::cout << "-----------------------------------\n";
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