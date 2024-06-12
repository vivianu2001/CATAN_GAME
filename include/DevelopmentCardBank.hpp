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
    void removeDevelopmentCard(DevelopmentCardType card, Player &player);
    DevelopmentCardType useDevelopmentCard(int cardIndex, Player &player, std::vector<Player> &players, Board &board);
    void printDevelopmentCards() const;
    std::size_t getCount() const;

    DevelopmentCardType buyDevelopmentCard(Player &player);
       ~DevelopmentCardBank();

private:
    std::vector<DevelopmentCard *> developmentCards;
    static int VictoryCards;
    static int KnightCards;
};

#endif // DEVELOPMENTCARDBANK_HPP
