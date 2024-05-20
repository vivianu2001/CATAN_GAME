#include "Player.h"
#include <iostream>
#include <stdexcept>

Player::Player(std::string playerName) : name(playerName), victoryPoints(0) {
    resources[ResourceType::Wood] = 0;
    resources[ResourceType::Brick] = 0;
    resources[ResourceType::Wool] = 0;
    resources[ResourceType::Oats] = 0;
    resources[ResourceType::Iron] = 0;
}

void Player::addResource(ResourceType type, int quantity) {
    resources[type] += quantity;
}

void Player::placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board) {
    // Implement logic for placing a settlement
}

void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board) {
    // Implement logic for placing a road
}

void Player::rollDice() {
    int roll = (rand() % 6 + 1) + (rand() % 6 + 1);
    std::cout << "Dice rolled: " << roll << std::endl;
    // Distribute resources based on roll
}

void Player::trade(Player &other, const std::string &give, const std::string &receive, int giveQty, int receiveQty) {
    // Implement trading logic
}

void Player::buyDevelopmentCard() {
    // Implement logic for buying a development card
}

void Player::endTurn() {
    // Implement logic for ending a turn
}

void Player::printPoints() {
    std::cout << name << " has " << victoryPoints << " points." << std::endl;
}
