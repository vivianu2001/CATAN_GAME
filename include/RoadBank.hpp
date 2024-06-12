//umanskyvivian@gmail.com
#ifndef ROADBANK_HPP
#define ROADBANK_HPP

#include "Bank.hpp"

class Player;

class RoadBank : public Bank
{
public:
    bool canAfford(const Player &player) const override;
    void purchase(Player &player) override;
};

#endif // ROADBANK_HPP
