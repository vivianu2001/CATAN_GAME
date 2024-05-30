#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "resource_type.hpp"
#include "residence.hpp"
#include "Board.hpp"

class Player
{
public:
    Player(const std::string &name);

    std::string getName() const;
    void addResource(ResourceType resource, int amount);
    void removeResource(ResourceType resource, int amount);
    int getResourceAmount(ResourceType resource) const;

    void placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);

    const std::vector<int> &getSettlements() const;
    const std::vector<int> &getRoads() const;

private:
    std::string name;
    std::map<ResourceType, int> resources;
    std::vector<int> settlements;
    std::vector<int> roads;
};

#endif // PLAYER_HPP
