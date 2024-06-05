#include "TradeManager.hpp"
#include <iostream>

bool TradeManager::verifyTradeResources(const Player &player1, const Player &player2, ResourceType res1, int amount1, ResourceType res2, int amount2)
{
    return player1.getResourceCount(res1) >= amount1 && player2.getResourceCount(res2) >= amount2;
}

bool TradeManager::verifyTradeDevelopmentCards(const Player &playerA, const Player &playerB, DevelopmentCardType cardA, DevelopmentCardType cardB)
{
    return playerA.hasDevelopmentCard(cardA) && playerB.hasDevelopmentCard(cardB);
}

bool TradeManager::tradeResources(Player &player1, ResourceType res1, int amount1, Player &player2, ResourceType res2, int amount2)
{
    if (verifyTradeResources(player1, player2, res1, amount1, res2, amount2))
    {
        player1.addResource(res1, -amount1);
        player2.addResource(res2, -amount2);
        player1.addResource(res2, amount2);
        player2.addResource(res1, amount1);
        std::cout << "Trade successful!" << std::endl;
        return true;
    }
    std::cout << "Trade failed. Not enough resources." << std::endl;
    return false;
}

bool TradeManager::tradeDevelopmentCards(Player &player1, Player &player2, DevelopmentCardType card1, DevelopmentCardType card2)
{
    if (verifyTradeDevelopmentCards(player1, player2, card1, card2))
    {
        player1.removeDevelopmentCard(card1);
        player2.removeDevelopmentCard(card2);
        player1.addDevelopmentCard(card2);
        player2.addDevelopmentCard(card1);
        std::cout << "Trade executed successfully!" << std::endl;
        return true;
    }
    std::cout << "Trade verification failed. Ensure both players have the specified cards." << std::endl;
    return false;
}
