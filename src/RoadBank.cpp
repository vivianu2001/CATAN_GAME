//umanskyvivian@gmail.com
#include "RoadBank.hpp"
#include "Enums.hpp"
#include "Player.hpp"
bool RoadBank::canAfford(const Player &player) const
{
    return player.getResourceCount(ResourceType::Wood) >= 1 &&
           player.getResourceCount(ResourceType::Brick) >= 1;
}

void RoadBank::purchase(Player &player)
{

    player.addResource(ResourceType::Wood, -1);
    player.addResource(ResourceType::Brick, -1);
}
