//umanskyvivian@gmail.com
#include "SettlementBank.hpp"
#include "Enums.hpp"
#include "Player.hpp"
bool SettlementBank::canAfford(const Player &player) const
{
    return player.getResourceCount(ResourceType::Wood) >= 1 &&
           player.getResourceCount(ResourceType::Brick) >= 1 &&
           player.getResourceCount(ResourceType::Wool) >= 1 &&
           player.getResourceCount(ResourceType::Oat) >= 1;
}

void SettlementBank::purchase(Player &player)
{

    player.addResource(ResourceType::Wood, -1);
    player.addResource(ResourceType::Brick, -1);
    player.addResource(ResourceType::Wool, -1);
    player.addResource(ResourceType::Oat, -1);
    player.addVictoryPoint(1);
}
