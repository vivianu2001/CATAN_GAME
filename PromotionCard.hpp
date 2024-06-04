#ifndef PROMOTIONCARD_HPP
#define PROMOTIONCARD_HPP

#include "DevelopmentCard.hpp"

class PromotionCard : public DevelopmentCard
{
public:
    enum Type
    {
        MONOPOLY,
        BUILDING_ROADS,
        YEAR_OF_PLENTY
    };
    PromotionCard(Type type) : type(type) {}
    void useCard(Player &player, std::vector<Player> &players, Board &board) override;

private:
    Type type;
};

#endif // PROMOTIONCARD_HPP
