#include "VictoryPointCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
VictoryPointCard::VictoryPointCard()
{
    std::cout << "Victory Point card created" << std::endl;
}

void VictoryPointCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    player.addVictoryPoint(2);
}
