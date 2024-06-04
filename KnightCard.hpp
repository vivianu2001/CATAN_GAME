#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include "DevelopmentCard.hpp"

class KnightCard : public DevelopmentCard
{
public:
    void useCard(Player &player, std::vector<Player> &players, Board &board) override;
};

#endif // KNIGHTCARD_HPP
