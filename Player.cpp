#include "Player.hpp"
#include <iostream>
#include "Board.hpp"
#include "PromotionCard.hpp"
#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"

int Player::playerCount = 0;
Player *Player::largestArmyPlayer = nullptr;

Player::Player(const std::string &name) : knightCount(0), hasLargestArmy(false), name(name), victoryPoints(0)
{
    playerId = playerCount++;
}

int Player::getPlayerId() const
{
    return playerId;
}

const std::string &Player::getName() const
{
    return name;
}

int Player::getResourceCount(ResourceType type) const
{
    auto it = resources.find(type);
    return it != resources.end() ? it->second : 0;
}

void Player::addResource(ResourceType type, int amount)
{
    resources[type] += amount;
}

void Player::addRoad(int edgeId)
{
    roads.push_back(edgeId);
}

const std::vector<int> &Player::getRoads() const
{
    return roads;
}

int Player::getRoadCount() const
{
    return roads.size();
}

void Player::addSettlement(int vertexId)
{
    settlements.push_back(vertexId);
    addVictoryPoint(1);
}

const std::vector<int> &Player::getSettlements() const
{
    return settlements;
}

int Player::getSettlementCount() const
{
    return settlements.size();
}

void Player::addCity(int vertexId)
{
    cities.push_back(vertexId);
    addVictoryPoint(1);
}

const std::vector<int> &Player::getCities() const
{
    return cities;
}

int Player::getCityCount() const
{
    return cities.size();
}

int Player::getVictoryPoints() const
{
    return victoryPoints;
}

void Player::addVictoryPoint(int points)
{
    victoryPoints += points;
}

void Player::printStatus() const
{
    std::cout << "Player " << name << " status:" << std::endl;
    std::cout << "Resources:" << std::endl;
    for (const auto &resource : resources)
    {
        std::cout << "Resource: " << resourceTypeToString(resource.first)
                  << ", Amount: " << resource.second << std::endl;
    }
    std::cout << "Roads:" << std::endl;
    for (const auto &road : roads)
    {
        std::cout << "Edge ID: " << road << std::endl;
    }
    std::cout << "Settlements:" << std::endl;
    for (const auto &settlement : settlements)
    {
        std::cout << "Vertex ID: " << settlement << std::endl;
    }
    std::cout << "Cities:" << std::endl;
    for (const auto &city : cities)
    {
        std::cout << "Vertex ID: " << city << std::endl;
    }
    std::cout << "Development Cards:" << std::endl;
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
    std::cout << "Victory Points: " << victoryPoints << std::endl;
}

void Player::buyDevelopmentCard()
{
    if (getResourceCount(ResourceType::Iron) > 0 &&
        getResourceCount(ResourceType::Wool) > 0 &&
        getResourceCount(ResourceType::Oat) > 0)
    {
        resources[ResourceType::Iron]--;
        resources[ResourceType::Wool]--;
        resources[ResourceType::Oat]--;

        // Randomly assign a development card
        int cardType = std::rand() % 5;
        DevelopmentCard *card;
        switch (cardType)
        {
        case 0:
            card = new PromotionCard(PromotionCardType::MONOPOLY);
            break;
        case 1:
            card = new PromotionCard(PromotionCardType::BUILDING_ROADS);
            break;
        case 2:
            card = new PromotionCard(PromotionCardType::YEAR_OF_PLENTY);
            break;
        case 3:
            card = new KnightCard();
            break;
        case 4:
            card = new VictoryPointCard();
            break;
        default:
            card = nullptr; // Should not happen
            break;
        }
        if (card)
        {
            developmentCards.push_back(card);
            std::cout << "Player " << name << " bought a development card." << std::endl;
        }
    }
    else
    {
        std::cout << "Not enough resources to buy a development card" << std::endl;
    }
}

void Player::useDevelopmentCard(int cardIndex, std::vector<Player> &players, Board &board)
{
    if (cardIndex < developmentCards.size())
    {
        developmentCards[cardIndex]->useCard(*this, players, board);
        delete developmentCards[cardIndex];
        developmentCards.erase(developmentCards.begin() + cardIndex);
    }
    else
    {
        std::cout << "Invalid card index" << std::endl;
    }
}

void Player::playKnightCard(std::vector<Player> &players)
{
    knightCount++;
    checkAndUpdateLargestArmy(players);
}

void Player::checkAndUpdateLargestArmy(std::vector<Player> &players)
{
    if (knightCount >= 3)
    {
        if (largestArmyPlayer == nullptr || knightCount > largestArmyPlayer->knightCount)
        {
            if (largestArmyPlayer != nullptr)
            {
                largestArmyPlayer->hasLargestArmy = false;
                largestArmyPlayer->addVictoryPoint(-2);
            }
            largestArmyPlayer = this;
            hasLargestArmy = true;
            addVictoryPoint(2);
        }
    }
}

bool Player::buildSettlement(int vertexId)
{
    if (canBuildSettlement())
    {
        resources[ResourceType::Wood]--;
        resources[ResourceType::Brick]--;
        resources[ResourceType::Wool]--;
        resources[ResourceType::Oat]--;
        addSettlement(vertexId);
        return true;
    }
    return false;
}

bool Player::canBuildSettlement() const
{
    return getResourceCount(ResourceType::Wood) > 0 &&
           getResourceCount(ResourceType::Brick) > 0 &&
           getResourceCount(ResourceType::Wool) > 0 &&
           getResourceCount(ResourceType::Oat) > 0;
}

bool Player::buildRoad(int edgeId)
{
    if (canBuildRoad())
    {
        resources[ResourceType::Wood]--;
        resources[ResourceType::Brick]--;
        addRoad(edgeId);
        return true;
    }
    return false;
}

bool Player::canBuildRoad() const
{
    return getResourceCount(ResourceType::Wood) > 0 &&
           getResourceCount(ResourceType::Brick) > 0;
}

bool Player::buildCity(int vertexId)
{
    if (canBuildCity())
    {
        resources[ResourceType::Iron] -= 3;
        resources[ResourceType::Oat] -= 2;
        auto it = std::find(settlements.begin(), settlements.end(), vertexId);
        if (it != settlements.end())
        {
            settlements.erase(it);
            addVictoryPoint(-1);
        }
        addCity(vertexId);
        return true;
    }
    return false;
}

bool Player::canBuildCity() const
{
    return getResourceCount(ResourceType::Iron) >= 3 &&
           getResourceCount(ResourceType::Oat) >= 2;
}
bool Player::hasDevelopmentCard(DevelopmentCardType card) const
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

void Player::addDevelopmentCard(DevelopmentCardType card)
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

void Player::removeDevelopmentCard(DevelopmentCardType card)
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