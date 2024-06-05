#ifndef SETTLEMENTBANK_HPP
#define SETTLEMENTBANK_HPP

#include "Bank.hpp"
class player;

class SettlementBank : public Bank
{
public:
    bool canAfford(const Player &player) const override;
    void purchase(Player &player) override;
};

#endif // SETTLEMENTBANK_HPP
