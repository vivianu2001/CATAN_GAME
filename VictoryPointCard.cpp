#include "VictoryPointCard.hpp"
#include "Player.hpp"
#include "Board.hpp"

void VictoryPointCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    player.addVictoryPoint(1);
}
