#include "DevelopmentCardBank.hpp"
#include "PromotionCard.hpp"
#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"
#include "Player.hpp"
#include "DevelopmentCard.hpp"

bool DevelopmentCardBank::canAfford(const Player &player) const
{
    return player.getResourceCount(ResourceType::Iron) >= 1 &&
           player.getResourceCount(ResourceType::Wool) >= 1 &&
           player.getResourceCount(ResourceType::Oat) >= 1;
}

void DevelopmentCardBank::purchase(Player &player)
{
    if (canAfford(player))
    {
        player.addResource(ResourceType::Iron, -1);
        player.addResource(ResourceType::Wool, -1);
        player.addResource(ResourceType::Oat, -1);
    }
}

void DevelopmentCardBank::addDevelopmentCard(DevelopmentCardType card)
{
    switch (card)
    {
    case DevelopmentCardType::Knight:
        developmentCards.push_back(new KnightCard());
        break;
    case DevelopmentCardType::Monopoly:
        developmentCards.push_back(new PromotionCard(PromotionCardType::MONOPOLY));
        break;
    case DevelopmentCardType::RoadBuilding:
        developmentCards.push_back(new PromotionCard(PromotionCardType::BUILDING_ROADS));
        break;
    case DevelopmentCardType::YearOfPlenty:
        developmentCards.push_back(new PromotionCard(PromotionCardType::YEAR_OF_PLENTY));
        break;
    case DevelopmentCardType::VictoryPoint:
        developmentCards.push_back(new VictoryPointCard());
        break;
    }
}

bool DevelopmentCardBank::hasDevelopmentCard(DevelopmentCardType card) const
{
    for (const auto &devCard : developmentCards)
    {
        if (dynamic_cast<KnightCard *>(devCard) && card == DevelopmentCardType::Knight)
        {
            return true;
        }
        if (auto promotionCard = dynamic_cast<PromotionCard *>(devCard))
        {
            if (card == toDevelopmentCardType(promotionCard->getType()))
            {
                return true;
            }
        }
        if (dynamic_cast<VictoryPointCard *>(devCard) && card == DevelopmentCardType::VictoryPoint)
        {
            return true;
        }
    }
    return false;
}

void DevelopmentCardBank::removeDevelopmentCard(DevelopmentCardType card)
{
    for (auto it = developmentCards.begin(); it != developmentCards.end(); ++it)
    {
        if (dynamic_cast<KnightCard *>(*it) && card == DevelopmentCardType::Knight)
        {
            delete *it;
            developmentCards.erase(it);
            return;
        }
        if (auto promotionCard = dynamic_cast<PromotionCard *>(*it))
        {
            if (card == toDevelopmentCardType(promotionCard->getType()))
            {
                delete *it;
                developmentCards.erase(it);
                return;
            }
        }
        if (dynamic_cast<VictoryPointCard *>(*it) && card == DevelopmentCardType::VictoryPoint)
        {
            delete *it;
            developmentCards.erase(it);
            return;
        }
    }
}

void DevelopmentCardBank::useDevelopmentCard(int cardIndex, Player &player, std::vector<Player> &players, Board &board)
{
    if (cardIndex < developmentCards.size())
    {
        developmentCards[cardIndex]->useCard(player, players, board);
        delete developmentCards[cardIndex];
        developmentCards.erase(developmentCards.begin() + cardIndex);
    }
    else
    {
        std::cout << "Invalid card index" << std::endl;
    }
}

void DevelopmentCardBank::printDevelopmentCards() const
{
    for (const auto &card : developmentCards)
    {
        if (dynamic_cast<PromotionCard *>(card))
        {
            PromotionCard *promotionCard = static_cast<PromotionCard *>(card);
            switch (promotionCard->getType())
            {
            case PromotionCardType::MONOPOLY:
                std::cout << "Monopoly" << std::endl;
                break;
            case PromotionCardType::BUILDING_ROADS:
                std::cout << "Building Roads" << std::endl;
                break;
            case PromotionCardType::YEAR_OF_PLENTY:
                std::cout << "Year of Plenty" << std::endl;
                break;
            }
        }
        else if (dynamic_cast<KnightCard *>(card))
        {
            std::cout << "Knight" << std::endl;
        }
        else if (dynamic_cast<VictoryPointCard *>(card))
        {
            std::cout << "Victory Point" << std::endl;
        }
    }
}
