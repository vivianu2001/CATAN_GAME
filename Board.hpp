#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Tile
{
public:
    std::string resource;
    int number;

    Tile(std::string res = "None", int num = 0) : resource(res), number(num) {}
};

class Board
{
public:
    std::vector<std::vector<Tile>> grid;

    Board();
    void displayBoard() const;
};

#endif // BOARD_HPP
