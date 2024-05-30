#pragma once
#include <string>
#include <unordered_map>

enum class ResourceType
{
    Wood,
    Brick,
    Wool,
    Grain,
    Ore
};
enum class DevelopmentCardType
{
    Knight,
    RoadBuilding,
    YearOfPlenty,
    Monopoly,
    VictoryPoint
};

class Player
{
public:
    Player(const std::string &name) : name(name) {}

    // Resource management
    void addResource(ResourceType type, int amount)
    {
        resources[type] += amount;
    }

    int getResourceCount(ResourceType type) const
    {
        auto it = resources.find(type);
        return it != resources.end() ? it->second : 0;
    }

    // Development cards
    void addDevelopmentCard(DevelopmentCardType card)
    {
        developmentCards[card]++;
    }

    int getDevelopmentCardCount(DevelopmentCardType card) const
    {
        auto it = developmentCards.find(card);
        return it != developmentCards.end() ? it->second : 0;
    }

    // Victory points
    void addVictoryPoint(int points)
    {
        victoryPoints += points;
    }

    int getVictoryPoints() const
    {
        return victoryPoints;
    }

    // Example method to handle building a road or settlement
    bool buildSettlement()
    {
        if (canBuildSettlement())
        {
            // Deduct resources, add settlement, etc.
            return true;
        }
        return false;
    }

    // Example check for build conditions
    bool canBuildSettlement() const
    {
        // Check if the player has enough resources to build a settlement
        return getResourceCount(ResourceType::Wood) > 0 &&
               getResourceCount(ResourceType::Brick) > 0 &&
               getResourceCount(ResourceType::Wool) > 0 &&
               getResourceCount(ResourceType::Grain) > 0;
    }

private:
    std::string name;
    std::unordered_map<ResourceType, int> resources;
    std::unordered_map<DevelopmentCardType, int> developmentCards;
    int victoryPoints = 0;
};
