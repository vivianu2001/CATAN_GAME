//umanskyvivian@gmail.com
#ifndef CITYBANK_HPP
#define CITYBANK_HPP

#include "Bank.hpp"

class CityBank : public Bank
{
public:
    bool canAfford(const Player &player) const override;
    void purchase(Player &player) override;
};

#endif // CITYBANK_HPP
