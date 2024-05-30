#include "Player.hpp"
#include <iostream>

Player::Player(const std::string &name) : name(name) {}

std::string Player::getName() const
{
    return name;
}

void Player::addResource(ResourceType resource, int amount)
{
    resources[resource] += amount;
}

void Player::removeResource(ResourceType resource, int amount)
{
    resources[resource] -= amount;
}

int Player::getResourceAmount(ResourceType resource) const
{
    auto it = resources.find(resource);
    return it != resources.end() ? it->second : 0;
}

void Player::placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
{
    // Implement logic to place a settlement on the board
    std::cout << name << " placed a settlement at " << places[0] << " and " << places[1] << " with numbers " << placesNum[0] << " and " << placesNum[1] << std::endl;
    // For simplicity, we add a dummy index to the settlements vector
    settlements.push_back(placesNum[0]);
}

void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
{
    // Implement logic to place a road on the board
    std::cout << name << " placed a road at " << places[0] << " and " << places[1] << " with numbers " << placesNum[0] << " and " << placesNum[1] << std::endl;
    // For simplicity, we add a dummy index to the roads vector
    roads.push_back(placesNum[1]);
}

const std::vector<int> &Player::getSettlements() const
{
    return settlements;
}

const std::vector<int> &Player::getRoads() const
{
    return roads;
}
