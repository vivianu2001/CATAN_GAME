#ifndef CATAN_HPP
#define CATAN_HPP

#include "Board.hpp"
#include "Player.hpp"
#include <vector>

class Catan
{
public:
    Catan(Player &p1, Player &p2, Player &p3);

    void ChooseStartingPlayer();
    Board getBoard() const;
    void printWinner() const;
    void initializePlayers();

private:
    Board board;
    std::vector<Player> players;
    Player *startingPlayer;
};

#endif // CATAN_HPP
