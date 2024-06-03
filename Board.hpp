#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Player.hpp"
#include "BoardConfig.hpp"
#include "Enums.hpp"

class Board
{
public:
    Board();                                   // Constructor for the board.
    const std::vector<Tile> &getTiles() const; // Returns a reference to the vector of tiles.
    const std::vector<Vertex> &getVertices() const;
    const std::vector<Edge> &getEdges() const;
    void initializeBoard();
    // Build settlement
    bool buildSettlement(int playerId, int vertexId);
    std::vector<ResourceType> initializeSettlements(int player, int vertex_id);

    // Build road
    bool buildRoad(int playerId, int edgeId);
    // Initializes the board with tiles and their respective edges and vertices.
    void distributeResources(int diceRoll, std::vector<Player> &players);

private:
    std::vector<Tile> tiles; // Vector containing all the tiles of the board.
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    void initializeVertices();
    void initializeEdges();
    void initializeTiles();
    void linkVerticesAndEdges();
    void linkTiles();
};
#endif // BOARD_HPP