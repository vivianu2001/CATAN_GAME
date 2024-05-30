#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include "Resource.hpp"
#include "Board.hpp"

class Player
{
public:
    Player(const std::string &name);

    void placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    void rollDice();
    void trade(Player &otherPlayer, const std::string &give, const std::string &take, int giveAmount, int takeAmount);
    void buyDevelopmentCard();
    void endTurn();
    void printPoints() const;

    int getVictoryPoints() const { return victoryPoints; }
    std::string getName() const { return name; }  // Add this method

    // Add missing methods
    void addSettlement();
    void addRoad();
    void addVictoryPoints(int points);

private:
    std::string name;
    int victoryPoints;
    std::map<Resource::Type, int> resources;

    // Helper methods
    Resource::Type stringToResource(const std::string &resourceStr) const;
    bool hasResources(const std::map<Resource::Type, int> &requiredResources) const;
    void addResource(Resource::Type type, int quantity);
    void removeResource(Resource::Type type, int quantity);
};

#endif // PLAYER_HPP
