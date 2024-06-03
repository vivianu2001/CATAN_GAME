#pragma once
#include <string>
#include <unordered_map>
#include "Enums.hpp"
#include <iostream>
class Player
{
public:
    // Constructor that takes a player's name
    explicit Player(const std::string &name);

    // Methods to manage resources
    void addResource(ResourceType type, int amount);
    int getResourceCount(ResourceType type) const;

    // Methods to manage development cards
    void addDevelopmentCard(DevelopmentCardType card);
    int getDevelopmentCardCount(DevelopmentCardType card) const;

    // Methods to manage victory points
    void addVictoryPoint(int points);
    int getVictoryPoints() const;

    // Gameplay functionality
    bool buildSettlement(int vertexId);
    bool canBuildSettlement() const;
    bool canBuildRoad() const;
    bool canBuildCity() const;
    bool buildRoad(int edgeId);
    bool buildCity(int vertexId);
    // Getter for the player's name
    const std::string &getName() const;
    int getPlayerId() const;
    void printResources() const; // Add this lin
    void addRoad(int edgeId);
    int getRoadCount() const;
    const std::vector<int> &getRoads() const;

    void addSettlement(int vertexId);
    int getSettlementCount() const;
    const std::vector<int> &getSettlements() const;
    void addCity(int vertexId);
    int getCityCount() const;
    const std::vector<int> &getCities() const;
    void buyDevelopmentCard();
    void printStatus() const;
    void discardResources();           // New method to handle discarding resources
    int getTotalResourceCount() const; // New method to get the total count of resources

private:
    static int playerCount;                                        // Static variable to keep track of the number of player objects
    int playerId;                                                  // Player ID
    std::string name;                                              // Player's name
    std::unordered_map<ResourceType, int> resources;               // Map of resources and their counts
    std::unordered_map<DevelopmentCardType, int> developmentCards; // Map of development cards and their counts
    int victoryPoints = 0;
    std::vector<int> roads;
    std::vector<int> settlements; // Total number of victory points
    std::vector<int> cities;
};
