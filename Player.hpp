#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include "ResourceType.hpp"
#include "DevelopmentCard.hpp"
#include "Board.hpp"  // Include the Board class to allow for placement methods

class Player {
public:
    std::string name;
    std::map<ResourceType, int> resources;
    int victoryPoints;
    std::vector<DevelopmentCard> devCards;

    Player(std::string playerName);

    void addResource(ResourceType type, int quantity);
    void placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    void rollDice();
    void trade(Player &other, const std::string &give, const std::string &receive, int giveQty, int receiveQty);
    void buyDevelopmentCard();
    void endTurn();
    void printPoints();
};

#endif // PLAYER_HPP
