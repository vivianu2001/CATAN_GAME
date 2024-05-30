// board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <memory>
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"

class Board
{
public:
    Board();

    void initializeBoard();
    std::vector<Tile> getTiles() const;
    std::vector<Vertex> getVertices() const;
    std::vector<Edge> getEdges() const;

private:
    std::vector<Tile> tiles;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
};

#endif // BOARD_HPP
