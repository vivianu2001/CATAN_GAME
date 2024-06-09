#include "KnightCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

KnightCard::KnightCard()
{
    used = false;
    std::cout << "Knight card created" << std::endl;
}

void KnightCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    if (!used)
    {
        player.addKnightCount(1);
        if (player.getKnightCount() == 3)
        {

            player.addVictoryPoint(2);
        }
        used = true;
    }
    else
    {
        std::cout << "Card already used" << std::endl;
    }
}

DevelopmentCardType KnightCard::getType() const
{
    return DevelopmentCardType::Knight;
}
