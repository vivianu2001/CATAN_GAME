#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
int runTests();

int main(int argc, char **argv)
{

    std::cout << "\nRunning tests..." << std::endl;
    int testResult = runTests(); // Run tests and capture the result

    return testResult; // Return the result of the tests as the program's exit code
    // std::vector<Player> players;
    // std::string name;

    // // Prompt for player names interactively
    // std::cout << "Welcome to Catan! Please enter the names of three players." << std::endl;

    // for (int i = 1; i <= 3; ++i)
    // {
    //     std::cout << "Enter name for Player " << i << ": ";
    //     std::getline(std::cin, name);
    //     players.emplace_back(name);
    // }

    // // Initialize the game board
    // Board board;
    // board.initializeBoard();

    // // Display a welcome message for each player
    // for (const auto &player : players)
    // {
    //     std::cout << "Player: " << player.getName() << " has joined the game." << std::endl;
    // }

    // std::vector<ResourceType> resources = board.initializeSettlements(players[0].getPlayerId(), 3);
    // for (const auto &resource : resources)
    // {
    //     players[0].addResource(resource, 1);
    // }
    // players[0].addSettlement(3);

    // board.buildRoad(players[0].getPlayerId(), 4);
    // players[0].addRoad(4);
    // players[0].printStatus();
    // return 0;

    // // Setup initial game state for each player
    // for (auto &player : players)
    // {
    //     for (int i = 0; i < 2; ++i)
    //     { // Each player places 2 settlements and 2 roads
    //         // Assume board.getVertices() and board.getEdges() provide access to these components
    //         Vertex &settlementVertex = board.getVertices().at(settlementPositions[i]);
    //         Edge &roadEdge = board.getEdges().at(roadPositions[i]);

    //         if (!settlementVertex.isOccupied())
    //         {
    //             settlementVertex.build(Vertex::BuildingType::Settlement, player.getId());
    //             player.addVictoryPoint(1); // Each settlement is worth 1 victory point

    //             // Allocate resources based on adjacent tiles
    //             for (Tile &tile : board.getAdjacentTiles(settlementVertex))
    //             {
    //                 player.addResource(tile.getResourceType(), 1); // Each adjacent tile gives 1 resource
    //             }
    //         }

    //         if (!roadEdge.hasRoad())
    //         {
    //             roadEdge.buildRoad(player.getId());
    //         }
    //     }
    // }

    // // Announce starting players and their resources
    // for (const auto &player : players)
    // {
    //     std::cout << player.getName() << " starts with " << player.getResourceCount(ResourceType::Wood) << " wood, "
    //               << player.getResourceCount(ResourceType::Brick) << " brick, and other resources." << std::endl;
    // }

    // Start game loop or more setup here
    // For now, just exit
    // return 0;
}
