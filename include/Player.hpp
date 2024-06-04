#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <map>
#include <string>
#include "DevelopmentCard.hpp"
#include "Enums.hpp"

class Board;

class Player
{
public:
    Player(const std::string &name);

    int getPlayerId() const;
    const std::string &getName() const;

    int getResourceCount(ResourceType type) const;
    void addResource(ResourceType type, int amount);

    void addRoad(int edgeId);
    const std::vector<int> &getRoads() const;
    int getRoadCount() const;

    void addSettlement(int vertexId);
    const std::vector<int> &getSettlements() const;
    int getSettlementCount() const;

    void addCity(int vertexId);
    const std::vector<int> &getCities() const;
    int getCityCount() const;

    int getVictoryPoints() const;
    void addVictoryPoint(int points);

    void buyDevelopmentCard();
    void useDevelopmentCard(int cardIndex, std::vector<Player> &players, Board &board);

    void printStatus() const;

    bool buildSettlement(int vertexId);
    bool canBuildSettlement() const;

    bool buildRoad(int edgeId);
    bool canBuildRoad() const;

    bool buildCity(int vertexId);
    bool canBuildCity() const;
    bool hasDevelopmentCard(DevelopmentCardType card) const;
    void addDevelopmentCard(DevelopmentCardType card);
    void removeDevelopmentCard(DevelopmentCardType card);
    void playKnightCard(std::vector<Player> &players);

    void checkAndUpdateLargestArmy(std::vector<Player> &players);

private:
    static int playerCount;
    static Player *largestArmyPlayer;
    int knightCount;
    bool hasLargestArmy;
    int playerId;
    std::string name;
    int victoryPoints;
    std::map<ResourceType, int> resources;
    std::vector<int> roads;
    std::vector<int> settlements;
    std::vector<int> cities;
    std::vector<DevelopmentCard *> developmentCards; // Vector of pointers to DevelopmentCard
};

#endif // PLAYER_HPP
