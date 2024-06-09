#include "DevelopmentCardBank.hpp"
#include "PromotionCard.hpp"
#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"
#include "Player.hpp"
#include "DevelopmentCard.hpp"

int DevelopmentCardBank ::KnightCards = 0;
int DevelopmentCardBank ::VictoryCards = 0;

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
            if (card == toDevelopmentCardType(promotionCard->getTypeP()))
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

void DevelopmentCardBank::removeDevelopmentCard(DevelopmentCardType card, Player &player)
{
    for (auto it = developmentCards.begin(); it != developmentCards.end(); ++it)
    {
        if (dynamic_cast<KnightCard *>(*it) && card == DevelopmentCardType::Knight)
        {
            if (player.getKnightCount() == 3)
            {
                player.addVictoryPoint(-2);
                player.addKnightCount(-1);
            }
            delete *it;
            developmentCards.erase(it);
            return;
        }
        if (dynamic_cast<VictoryPointCard *>(*it) && card == DevelopmentCardType::VictoryPoint)
        {

            player.addVictoryPoint(-1);

            delete *it;
            developmentCards.erase(it);
            return;
        }
        if (auto promotionCard = dynamic_cast<PromotionCard *>(*it))
        {
            if (card == toDevelopmentCardType(promotionCard->getTypeP()))
            {
                delete *it;
                developmentCards.erase(it);
                return;
            }
        }
    }
}

void DevelopmentCardBank::useDevelopmentCard(int cardIndex, Player &player, std::vector<Player> &players, Board &board)
{
    if (cardIndex < developmentCards.size())
    {
        DevelopmentCardType cardType = developmentCards[cardIndex]->getType();
        developmentCards[cardIndex]->useCard(player, players, board);

        // Only delete and erase the card if it's not a Knight or Victory Point card
        if (cardType != DevelopmentCardType::Knight && cardType != DevelopmentCardType::VictoryPoint)
        {
            delete developmentCards[cardIndex];
            developmentCards.erase(developmentCards.begin() + cardIndex);
        }
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
            switch (promotionCard->getTypeP())
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
    }
}
DevelopmentCardType DevelopmentCardBank::buyDevelopmentCard(Player &player)
{

    int cardType = std::rand() % 5;
    DevelopmentCardType card;
    if (VictoryCards == 4 && KnightCards < 3)
    {
        cardType = 3;
    }
    if (VictoryCards < 4 && KnightCards == 3)
    {
        cardType = 4;
    }
    if (VictoryCards == 4 && KnightCards == 3)
    {
        cardType = 0;
    }

    switch (cardType)
    {
    case 0:
        card = DevelopmentCardType::Monopoly;

        break;
    case 1:
        card = DevelopmentCardType::RoadBuilding;

        break;
    case 2:
        card = DevelopmentCardType::YearOfPlenty;

        break;
    case 3:
        card = DevelopmentCardType::Knight;
        KnightCards++;
        break;
    case 4:
        card = DevelopmentCardType::VictoryPoint;
        VictoryCards++;
        player.addVictoryPoint(2);
        break;
    }
    return card;
}
