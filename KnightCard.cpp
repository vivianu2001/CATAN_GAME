#include "KnightCard.hpp"
#include "Player.hpp"
#include "Board.hpp"

void KnightCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    player.playKnightCard(players);
}