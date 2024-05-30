#include "Player.hpp"
#include <iostream>

Player::Player(const std::string &name) : name(name), victoryPoints(0)
{
}

void Player::placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
{
    // Implement logic to place a settlement
    victoryPoints++;
}

void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
{
    // Implement logic to place a road
}

void Player::rollDice()
{
    int diceRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
    std::cout << name << " rolled a " << diceRoll << std::endl;
    // Distribute resources based on the dice roll and the player's settlements
}

void Player::trade(Player &otherPlayer, const std::string &give, const std::string &take, int giveAmount, int takeAmount)
{
    Resource::Type giveResource = stringToResource(give);
    Resource::Type takeResource = stringToResource(take);

    // Implement trading logic
}

void Player::buyDevelopmentCard()
{
    // Implement logic to buy a development card
}

void Player::endTurn()
{
    // Implement logic to end the player's turn
}

void Player::printPoints() const
{
    std::cout << name << " has " << victoryPoints << " points." << std::endl;
}

Resource::Type Player::stringToResource(const std::string &resourceStr) const
{
    if (resourceStr == "wood") return Resource::WOOD;
    if (resourceStr == "brick") return Resource::BRICK;
    if (resourceStr == "wool") return Resource::WOOL;
    if (resourceStr == "grain") return Resource::GRAIN;
    if (resourceStr == "ore") return Resource::ORE;
    return Resource::NONE;
}

bool Player::hasResources(const std::map<Resource::Type, int> &requiredResources) const
{
    for (const auto &req : requiredResources)
    {
        if (resources.at(req.first) < req.second)
        {
            return false;
        }
    }
    return true;
}

void Player::addResource(Resource::Type type, int quantity)
{
    resources[type] += quantity;
}

void Player::removeResource(Resource::Type type, int quantity)
{
    if (resources[type] >= quantity)
    {
        resources[type] -= quantity;
    }
}

// Add missing methods
void Player::addSettlement()
{
    // Implement logic to add a settlement
    victoryPoints++;
}

void Player::addRoad()
{
    // Implement logic to add a road
}

void Player::addVictoryPoints(int points)
{
    victoryPoints += points;
}
