#ifndef TRADEMANAGER_HPP
#define TRADEMANAGER_HPP

#include "Player.hpp"

class TradeManager
{
public:
    static bool tradeResources(Player &player1, ResourceType res1, int amount1, Player &player2, ResourceType res2, int amount2);
    static bool tradeDevelopmentCards(Player &player1, Player &player2, DevelopmentCardType card1, DevelopmentCardType card2);

private:
    static bool verifyTradeResources(const Player &player1, const Player &player2, ResourceType res1, int amount1, ResourceType res2, int amount2);

    static bool verifyTradeDevelopmentCards(const Player &playerA, const Player &playerB, DevelopmentCardType cardA, DevelopmentCardType cardB);
};

#endif // TRADEMANAGER_HPP
