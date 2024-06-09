#include "VictoryPointCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
VictoryPointCard::VictoryPointCard()
{
    used = false;
    std::cout << "Victory Point card created" << std::endl;
}

void VictoryPointCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    if (!used)
    {
        player.addVictoryPoint(1);
        used = true;
    }
    else
    {
        std::cout << "Card already used" << std::endl;
    }
}
DevelopmentCardType VictoryPointCard::getType() const
{
    return DevelopmentCardType::VictoryPoint;
}
