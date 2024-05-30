#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

int main()
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
    for (const auto &player : players)
    {
        std::cout << "Player: " << player.getName() << " has joined the game." << std::endl;
    }
    // std::vector<int> settlementPositions = {0, 3, 7, 11, 15}; // Example vertex IDs for initial settlements
    // std::vector<int> roadPositions = {1, 4, 8, 12, 16};       // Example edge IDs for initial roads

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

    // Announce starting players and their resources
    for (const auto &player : players)
    {
        std::cout << player.getName() << " starts with " << player.getResourceCount(ResourceType::Wood) << " wood, "
                  << player.getResourceCount(ResourceType::Brick) << " brick, and other resources." << std::endl;
    }

    // Start game loop or more setup here
    // For now, just exit
    return 0;
}
