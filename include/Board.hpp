#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "BoardConfig.hpp"
#include "Enums.hpp"
class Player;

class Board
{
public:
    Board();
    void initializeBoard();
    const std::vector<Tile> &getTiles() const;
    const std::vector<Vertex> &getVertices() const;
    const std::vector<Edge> &getEdges() const;
    bool buildSettlement(int playerId, int vertexId, bool start);
    std::vector<ResourceType> initializeSettlements(int player, int vertex_id);
    bool isTwoRoadSegmentsAway(int vertexId, int playerId) const;
    bool buildRoad(int playerId, int edgeId);
    void distributeResources(int diceRoll, std::vector<Player> &players);
    bool buildCity(int playerId, int vertexId);
    void initializePlayerSettlementsAndRoads(Player &player, int settlement1, int road1, int settlement2, int road2);

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