//umanskyvivian@gmail.com
#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <iostream>
#include "Enums.hpp"
#include <vector>

class Player;
class Board;

class DevelopmentCard
{
public:
    virtual void useCard(Player &player, std::vector<Player> &players, Board &board) = 0;
    virtual DevelopmentCardType getType() const = 0;
    virtual ~DevelopmentCard() = default;
};

#endif // DEVELOPMENTCARD_HPP
