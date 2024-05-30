#pragma once
#include <vector>
#include "Tile.hpp"

class Board
{
public:
    Board();                                   // Constructor for the board.
    const std::vector<Tile> &getTiles() const; // Returns a reference to the vector of tiles.
    void initializeBoard();                    // Initializes the board with tiles and their respective edges and vertices.

private:
    std::vector<Tile> tiles; // Vector containing all the tiles of the board.
};
