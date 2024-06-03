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
    bool buildSettlement();
    bool canBuildSettlement() const;
    // Getter for the player's name
    const std::string &getName() const;
    int getPlayerId() const;
    void printResources() const; // Add this lin

private:
    static int playerCount;                                        // Static variable to keep track of the number of player objects
    int playerId;                                                  // Player ID
    std::string name;                                              // Player's name
    std::unordered_map<ResourceType, int> resources;               // Map of resources and their counts
    std::unordered_map<DevelopmentCardType, int> developmentCards; // Map of development cards and their counts
    int victoryPoints = 0;                                         // Total number of victory points
};
