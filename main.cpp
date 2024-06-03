#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include <set>

void initializePlayerSettlementsAndRoads(Board &board, Player &player, int settlement1, int road1, int settlement2, int road2);

int main(int argc, char **argv)
{
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
    std::cout << "\nPlayers have joined the game:\n";
    for (const auto &player : players)
    {
        std::cout << "Player: " << player.getName() << std::endl;
    }
    std::cout << "-----------------------------------\n";

    // Initialize each player's settlements and roads
    initializePlayerSettlementsAndRoads(board, players[0], 3, 4, 7, 8);
    initializePlayerSettlementsAndRoads(board, players[1], 12, 13, 17, 18);
    initializePlayerSettlementsAndRoads(board, players[2], 21, 22, 27, 28);

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
