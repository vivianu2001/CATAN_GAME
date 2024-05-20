#include <iostream>
#include "Hex.hpp"
#include "Board.hpp"

int main()
{
    // Create the board with hexagon tiles
    std::vector<std::vector<Hex>> board = {
        {{"Wood", 11}, {"Brick", 12}, {"Wool", 5}},
        {{"Oats", 6}, {"Iron", 9}, {"Wool", 4}},
        {{"Oats", 3}, {"Desert", 7}, {"Wood", 8}},
        {{"Brick", 2}, {"Iron", 10}, {"Wool", 9}}};

    // Print the board
    printBoard(board);

    return 0;
}
