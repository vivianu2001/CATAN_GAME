#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "Enums.hpp"

// Player Tests
TEST_CASE("Player initialization")
{
    Player player("TestPlayer");
    CHECK(player.getVictoryPoints() == 0);
    CHECK(player.getName() == "TestPlayer");
    CHECK(player.getPlayerId() >= 0); // Assuming player IDs are non-negative
}

TEST_CASE("Player resource management")
{
    Player player("TestPlayer");

    SUBCASE("Adding and getting resources")
    {
        player.addResource(ResourceType::Wood, 3);
        CHECK(player.getResourceCount(ResourceType::Wood) == 3);

        player.addResource(ResourceType::Brick, 2);
        CHECK(player.getResourceCount(ResourceType::Brick) == 2);
    }

    SUBCASE("Can build structures based on resources")
    {
        player.addResource(ResourceType::Wood, 1);
        player.addResource(ResourceType::Brick, 1);
        player.addResource(ResourceType::Wool, 1);
        player.addResource(ResourceType::Oat, 1);

        CHECK(player.canBuildSettlement() == true);
        player.addResource(ResourceType::Iron, 3);
        player.addResource(ResourceType::Oat, 2);
        CHECK(player.canBuildCity() == true);
    }
}

TEST_CASE("Player development card management")
{
    Player player("TestPlayer");

    SUBCASE("Adding and checking development cards")
    {
        player.addDevelopmentCard(DevelopmentCardType::Knight);
        CHECK(player.hasDevelopmentCard(DevelopmentCardType::Knight) == true);

        player.addDevelopmentCard(DevelopmentCardType::Monopoly);
        CHECK(player.hasDevelopmentCard(DevelopmentCardType::Monopoly) == true);
    }

    SUBCASE("Removing development cards")
    {
        player.addDevelopmentCard(DevelopmentCardType::Knight);
        player.removeDevelopmentCard(DevelopmentCardType::Knight);
        CHECK(player.hasDevelopmentCard(DevelopmentCardType::Knight) == false);
    }
}
