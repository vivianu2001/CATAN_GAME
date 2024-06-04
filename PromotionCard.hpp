#ifndef PROMOTIONCARD_HPP
#define PROMOTIONCARD_HPP

#include "DevelopmentCard.hpp"
#include "Enums.hpp"

class PromotionCard : public DevelopmentCard
{
public:
    PromotionCard(PromotionCardType type);
    void useCard(Player &player, std::vector<Player> &players, Board &board) override;
    PromotionCardType getType() const;

private:
    PromotionCardType type;
};

#endif // PROMOTIONCARD_HPP
