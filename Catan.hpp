#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "Player.hpp"
#include "Board.hpp"

class Catan
{
public:
    Catan(Player &p1, Player &p2, Player &p3);

    void chooseStartingPlayer();
    Board getBoard() const;

private:
    std::vector<Player> players;
    Board board;
    Player *startingPlayer;
};

#endif // CATAN_HPP
