#include "Board.hpp"
#include <iostream>

const std::vector<std::string> hexTop = {
    "  ___  ",
    " /   \\ ",
    "/     \\"};

const std::vector<std::string> hexBottom = {
    "\\     /",
    " \\___/ "};

void printHexRow(const std::vector<Tile> &tiles)
{
    // Print the top half of the hexes
    for (const auto &line : hexTop)
    {
        for (const auto &tile : tiles)
        {
            std::cout << line;
        }
        std::cout << std::endl;
    }

    // Print the middle line with resource type and number
    for (const auto &tile : tiles)
    {
        std::cout << "| " << tile.resource << " " << tile.number << " |";
    }
    std::cout << std::endl;

    // Print the bottom half of the hexes
    for (const auto &line : hexBottom)
    {
        for (const auto &tile : tiles)
        {
            std::cout << line;
        }
        std::cout << std::endl;
    }
}

Board::Board()
{
    // Initialize the grid with some predefined resource types and numbers
    grid = {
        {Tile("Wood", 11), Tile("Brick", 12), Tile("Wool", 5)},
        {Tile("Oats", 6), Tile("Iron", 9), Tile("Wool", 4)},
        {Tile("Oats", 3), Tile("Desert", 7), Tile("Wood", 8)},
        {Tile("Brick", 2), Tile("Iron", 10), Tile("Wool", 9)}};
}

void Board::displayBoard() const
{
    for (const auto &row : grid)
    {
        printHexRow(row);
        std::cout << std::endl;
    }
}
