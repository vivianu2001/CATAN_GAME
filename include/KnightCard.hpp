//umanskyvivian@gmail.com
#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include "DevelopmentCard.hpp"

class KnightCard : public DevelopmentCard
{
    bool used;

public:
    KnightCard(); // Declare the constructor
    void useCard(Player &player, std::vector<Player> &players, Board &board) override;
    DevelopmentCardType getType() const override;
};

#endif // KNIGHTCARD_HPP
