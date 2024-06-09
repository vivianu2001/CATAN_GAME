#ifndef VICTORYPOINTCARD_HPP
#define VICTORYPOINTCARD_HPP

#include "DevelopmentCard.hpp"

class VictoryPointCard : public DevelopmentCard
{
    bool used;

public:
    VictoryPointCard();
    void useCard(Player &player, std::vector<Player> &players, Board &board) override;
    DevelopmentCardType getType() const override;
};

#endif // VICTORYPOINTCARD_HPP
