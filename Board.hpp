#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Player.hpp"


class Board
{
public:
    Board();                                   // Constructor for the board.
    const std::vector<Tile> &getTiles() const; // Returns a reference to the vector of tiles.
    void initializeBoard();
    // Build settlement
    bool buildSettlement(int playerId, int vertexId);

    // Build road
    bool buildRoad(int playerId, int edgeId);
    // Initializes the board with tiles and their respective edges and vertices.

private:
    std::vector<Tile> tiles; // Vector containing all the tiles of the board.
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
};
#endif // BOARD_HPP