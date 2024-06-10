#include "CityBank.hpp"
#include "Enums.hpp"
#include "Player.hpp"

bool CityBank::canAfford(const Player &player) const
{
    return player.getResourceCount(ResourceType::Iron) >= 3 &&
           player.getResourceCount(ResourceType::Oat) >= 2;
}

void CityBank::purchase(Player &player)
{

    player.addResource(ResourceType::Iron, -3);
    player.addResource(ResourceType::Oat, -2);
    player.addVictoryPoint(1);
}
