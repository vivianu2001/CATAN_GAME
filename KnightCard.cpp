#include "KnightCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

KnightCard::KnightCard()
{
    std::cout << "Knight card created" << std::endl;
}

void KnightCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    player.playKnightCard(players);
}
