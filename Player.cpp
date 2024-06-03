#include "Player.hpp"
int Player::playerCount = 0;

// Constructor that initializes the player with a name
Player::Player(const std::string &name) : name(name), victoryPoints(0)
{
    playerId = playerCount++;
}
int Player::getPlayerId() const
{
    return playerId;
}
int Player::getResourceCount(ResourceType type) const
{
    auto it = resources.find(type);
    return it != resources.end() ? it->second : 0;
}

// Add resources to the player's inventory
void Player::addResource(ResourceType type, int amount)
{
    resources[type] += amount;
}
void Player::printResources() const
{
    std::cout << "Player " << name << " resources:" << std::endl;
    for (const auto &resource : resources)
    {
        std::cout << "Resource: " << static_cast<int>(resource.first)
                  << ", Amount: " << resource.second << std::endl;
    }
}
void Player::addRoad(int edgeId)
{
    roads.push_back(edgeId);
}
void Player::printStatus() const
{
    std::cout << "Player " << name << " status:" << std::endl;

    std::cout << "Resources:" << std::endl;
    for (const auto &resource : resources)
    {
        std::cout << "Resource: " << static_cast<int>(resource.first)
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

    std::cout << "Victory Points: " << victoryPoints << std::endl;
}

// Add a development card to the player's inventory
void Player::addDevelopmentCard(DevelopmentCardType card)
{
    developmentCards[card]++;
}

// Retrieve the count of a specific type of development card
int Player::getDevelopmentCardCount(DevelopmentCardType card) const
{
    auto it = developmentCards.find(card);
    return it != developmentCards.end() ? it->second : 0;
}

// Increment the player's victory points
void Player::addVictoryPoint(int points)
{
    victoryPoints += points;
}

// Retrieve the player's total victory points
int Player::getVictoryPoints() const
{
    return victoryPoints;
}

// Example gameplay logic for building a settlement
bool Player::buildSettlement()
{
    if (canBuildSettlement())
    {
        // Assume resource costs are deducted here
        return true;
    }
    return false;
}

// Check if the player has sufficient resources to build a settlement
bool Player::canBuildSettlement() const
{
    // Simplified check; real game might have specific resource requirements
    return getResourceCount(ResourceType::Wood) > 0 &&
           getResourceCount(ResourceType::Brick) > 0 &&
           getResourceCount(ResourceType::Wool) > 0 &&
           getResourceCount(ResourceType::Grain) > 0;
}
const std::string &Player::getName() const
{
    return name;
}
int Player::getRoadCount() const
{
    return roads.size();
}

// Retrieve the player's roads
const std::vector<int> &Player::getRoads() const
{
    return roads;
}

// Add a settlement to the player's inventory
void Player::addSettlement(int vertexId)
{
    settlements.push_back(vertexId);
}

// Retrieve the player's total settlement count
int Player::getSettlementCount() const
{
    return settlements.size();
}

// Retrieve the player's settlements
const std::vector<int> &Player::getSettlements() const
{
    return settlements;
}
