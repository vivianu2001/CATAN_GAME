#include "Player.hpp"
#include <iostream>
#include "Board.hpp"
#include "PromotionCard.hpp"
#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"
#include "DevelopmentCardBank.hpp"
#include <algorithm>

int Player::playerCount = 0;

Player::Player(const std::string &name) : knightCount(0), name(name), victoryPoints(0)
{
    playerId = ++playerCount;
    for (ResourceType type : {ResourceType::Wood, ResourceType::Brick, ResourceType::Wool, ResourceType::Iron, ResourceType::Oat})
    {
        resources[type] = 0;
    }
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
const std::vector<int> &Player::getSettlements() const
{
    return settlements;
}

const std::vector<int> &Player::getRoads() const
{
    return roads;
}

int Player::getRoadCount() const
{
    return roads.size();
}
int Player::getKnightCount() const
{
    return knightCount;
}
int Player::addKnightCount(int n)
{
    knightCount = knightCount + n;
    return knightCount;
}
void Player::addResource(ResourceType type, int amount)
{
    resources[type] += amount;
}

void Player::addRoad(int edgeId)
{
    roads.push_back(edgeId);
}
void Player::addSettlement(int vertexId)
{
    settlements.push_back(vertexId);
    // addVictoryPoint(1);
}

int Player::getSettlementCount() const
{
    return settlements.size();
}

void Player::addCity(int vertexId)
{
    cities.push_back(vertexId);
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

int Player::getDevCardsCount() const
{
    return developmentCardBank.getCount();
}

void Player::addVictoryPoint(int points)
{
    victoryPoints += points;
}

bool Player::buildSettlement(int vertexId)
{
    if (settlementBank.canAfford(*this))
    {
        settlementBank.purchase(*this);
        addSettlement(vertexId);
        return true;
    }
    return false;
}

bool Player::buildRoad(int edgeId)
{
    if (roadBank.canAfford(*this))
    {
        roadBank.purchase(*this);
        addRoad(edgeId);
        return true;
    }
    return false;
}

bool Player::buildCity(int vertexId)
{

    if (cityBank.canAfford(*this))
    {
        cityBank.purchase(*this);
        auto it = std::find(settlements.begin(), settlements.end(), vertexId);
        if (it != settlements.end())
        {
            settlements.erase(it);
        }
        addCity(vertexId);
        return true;
    }
    return false;
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
    std::cout << "Victory Points:" << this->getVictoryPoints() << std::endl;
    std::cout << "Cards:" << std::endl;
    developmentCardBank.printDevelopmentCards();
}
bool Player::buyDevelopmentCard(std::vector<Player> &players, Board &board)
{
    if (developmentCardBank.canAfford(*this))
    {
        developmentCardBank.purchase(*this);

        DevelopmentCardType card = developmentCardBank.buyDevelopmentCard(*this);
        developmentCardBank.addDevelopmentCard(card);
        if (card == DevelopmentCardType::Knight || card == DevelopmentCardType::VictoryPoint)
        {
            useDevelopmentCard(developmentCardBank.getCount() - 1, players, board);
        }

        std::cout << "Player " << name << " bought a development card." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Not enough resources to buy a development card" << std::endl;
        return false;
    }
}

DevelopmentCardType Player::useDevelopmentCard(int cardIndex, std::vector<Player> &players, Board &board)
{
    // if (cardIndex < developmentCards.size())
    // {
    //     DevelopmentCardType cardType = developmentCards[cardIndex]->getType();
    //     developmentCards[cardIndex]->useCard(*this, players, board);

    //     // Only delete and erase the card if it's not a Knight or Victory Point card
    //     if (cardType != DevelopmentCardType::Knight && cardType != DevelopmentCardType::VictoryPoint)
    //     {
    //         delete developmentCards[cardIndex];
    //         developmentCards.erase(developmentCards.begin() + cardIndex);
    //     }
    //     return cardType;

    // else
    // {
    //     std::cout << "Invalid card index" << std::endl;
    //     // Handle invalid card index appropriately, possibly return a default value or handle the error
    //     return DevelopmentCardType::Knight; // Default return value or handle appropriately
    // }
    return developmentCardBank.useDevelopmentCard(cardIndex, *this, players, board);
}
void Player::playKnightCard(std::vector<Player> &players)
{
    knightCount++;
}

bool Player::hasDevelopmentCard(DevelopmentCardType card) const
{
    return developmentCardBank.hasDevelopmentCard(card);
}

void Player::addDevelopmentCard(DevelopmentCardType card)
{
    developmentCardBank.addDevelopmentCard(card);
}

void Player::removeDevelopmentCard(DevelopmentCardType card)
{
    developmentCardBank.removeDevelopmentCard(card, *this);
}
void Player::resetPlayerCount()
{
    playerCount = 0;
}
Player::~Player()
{
    for (auto card : developmentCards)
    {
        delete card;
    }
}