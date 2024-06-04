#ifndef VICTORYPOINTCARD_HPP
#define VICTORYPOINTCARD_HPP

#include "DevelopmentCard.hpp"

class VictoryPointCard : public DevelopmentCard
{
public:
    VictoryPointCard();
    void useCard(Player &player, std::vector<Player> &players, Board &board) override;
};

#endif // VICTORYPOINTCARD_HPP
