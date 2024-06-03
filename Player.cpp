#include "Player.hpp"
#include <iostream>

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

    std::cout << "Victory Points: " << victoryPoints << std::endl;
}

// Add a development card to the player's inventory
void Player::addDevelopmentCard(DevelopmentCardType card)
{
    developmentCards[card]++;
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
bool Player::buildSettlement(int vertexId)
{
    resources[ResourceType::Wood]--;
    resources[ResourceType::Brick]--;
    resources[ResourceType::Wool]--;
    resources[ResourceType::Oat]--;
    addSettlement(vertexId);
    return true;
}

// Check if the player has sufficient resources to build a settlement
bool Player::canBuildSettlement() const
{
    return getResourceCount(ResourceType::Wood) > 0 &&
           getResourceCount(ResourceType::Brick) > 0 &&
           getResourceCount(ResourceType::Wool) > 0 &&
           getResourceCount(ResourceType::Oat) > 0;
}

bool Player::canBuildRoad() const
{
    return getResourceCount(ResourceType::Wood) > 0 &&
           getResourceCount(ResourceType::Brick) > 0;
}

bool Player::canBuildCity() const
{
    return getResourceCount(ResourceType::Iron) >= 3 &&
           getResourceCount(ResourceType::Oat) >= 2;
}

bool Player::buildRoad(int edgeId)
{
    // Deduct resource costs
    resources[ResourceType::Wood]--;
    resources[ResourceType::Brick]--;
    addRoad(edgeId);
    return true;
}

bool Player::buildCity(int vertexId)
{
    // Deduct resource costs
    resources[ResourceType::Iron] -= 3;
    resources[ResourceType::Oat] -= 2;

    // Remove settlement if it exists
    auto it = std::find(settlements.begin(), settlements.end(), vertexId);
    if (it != settlements.end())
    {
        settlements.erase(it);
        addVictoryPoint(-1); // Remove the settlement point
    }

    addCity(vertexId);
    return true;
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
    addVictoryPoint(1);
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

// Add a city to the player's inventory
void Player::addCity(int vertexId)
{
    cities.push_back(vertexId);
    addVictoryPoint(1);
}

// Retrieve the player's total city count
int Player::getCityCount() const
{
    return cities.size();
}

// Retrieve the player's cities
const std::vector<int> &Player::getCities() const
{
    return cities;
}
int Player::getDevelopmentCardCount(DevelopmentCardType card) const
{
    auto it = developmentCards.find(card);
    return it != developmentCards.end() ? it->second : 0;
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
        DevelopmentCardType card = static_cast<DevelopmentCardType>(std::rand() % 5);
        addDevelopmentCard(card);
        std::cout << "Player " << name << " bought a development card: " << developmentCardTypeToString(card) << std::endl;
    }
    else
    {
        std::cout << "Not enough resources to buy a development card" << std::endl;
    }
}
void Player::discardResources()
{
    int totalResources = getTotalResourceCount();
    int discardCount = totalResources / 2;

    std::vector<std::pair<ResourceType, int>> resourceList(resources.begin(), resources.end());
    std::random_shuffle(resourceList.begin(), resourceList.end());

    for (auto &resource : resourceList)
    {
        int discard = std::min(discardCount, resource.second);
        resources[resource.first] -= discard;
        discardCount -= discard;
        if (discardCount <= 0)
            break;
    }
}

int Player::getTotalResourceCount() const
{
    int total = 0;
    for (const auto &resource : resources)
    {
        total += resource.second;
    }
    return total;
}