#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <iostream>

class Player;
class Board;

class DevelopmentCard
{
public:
    virtual void useCard(Player &player, std::vector<Player> &players, Board &board) = 0;
    virtual ~DevelopmentCard() = default;
};

#endif // DEVELOPMENTCARD_HPP
