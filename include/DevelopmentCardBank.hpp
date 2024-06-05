#ifndef DEVELOPMENTCARDBANK_HPP
#define DEVELOPMENTCARDBANK_HPP

#include "DevelopmentCard.hpp"
#include "Enums.hpp"
#include <vector>
#include <iostream>
#include "Bank.hpp"
class Player;

class DevelopmentCardBank : Bank
{
public:
    bool canAfford(const Player &player) const;
    void purchase(Player &player);

    void addDevelopmentCard(DevelopmentCardType card);
    bool hasDevelopmentCard(DevelopmentCardType card) const;
    void removeDevelopmentCard(DevelopmentCardType card);
    void useDevelopmentCard(int cardIndex, Player &player, std::vector<Player> &players, Board &board);
    void printDevelopmentCards() const;

private:
    std::vector<DevelopmentCard *> developmentCards;
};

#endif // DEVELOPMENTCARDBANK_HPP
