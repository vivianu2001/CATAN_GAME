#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include "Enums.hpp"
#include "Bank.hpp"
#include "RoadBank.hpp"
#include "SettlementBank.hpp"
#include "CityBank.hpp"
#include "DevelopmentCardBank.hpp"
#include "DevelopmentCard.hpp"

class Board;

class Player
{
public:
    Player(const std::string &name);
    void removeDevelopmentCard(DevelopmentCardType card);
    static void resetPlayerCount();
    int getPlayerId() const;
    const std::string &getName() const;
    int getResourceCount(ResourceType type) const;
    int getRoadCount() const;
    int getKnightCount() const;
    int addKnightCount(int n);
    const std::vector<int> &getRoads() const;
    const std::vector<int> &getSettlements() const;
    int getSettlementCount() const;
    const std::vector<int> &getCities() const;
    int getCityCount() const;
    int getVictoryPoints() const;

    void addResource(ResourceType type, int amount);
    void addRoad(int edgeId);
    void addSettlement(int vertexId);
    void addCity(int vertexId);
    void addVictoryPoint(int points);

    bool buildSettlement(int vertexId);
    bool buildRoad(int edgeId);
    bool buildCity(int vertexId);
    bool buyDevelopmentCard();

    void useDevelopmentCard(int cardIndex, std::vector<Player> &players, Board &board);

    void playKnightCard(std::vector<Player> &players);
    void checkAndUpdateLargestArmy(std::vector<Player> &players);

    bool hasDevelopmentCard(DevelopmentCardType card) const;

    void addDevelopmentCard(DevelopmentCardType card);

    void printStatus() const;

private:
    static int playerCount;

    int knightCount;
    int playerId;
    std::string name;
    int victoryPoints;
    std::map<ResourceType, int> resources;
    std::vector<int> roads;
    std::vector<int> settlements;
    std::vector<int> cities;
    std::vector<DevelopmentCard *> developmentCards; // Vector of pointers to DevelopmentCard
    RoadBank roadBank;
    SettlementBank settlementBank;
    CityBank cityBank;
    DevelopmentCardBank developmentCardBank;
};

#endif // PLAYER_HPP
