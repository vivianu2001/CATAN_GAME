
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "TradeManager.hpp"

TEST_CASE("Trade resources between players")
{
    Player player1("Player1");
    Player player2("Player2");

    player1.addResource(ResourceType::Wood, 5);
    player2.addResource(ResourceType::Brick, 5);

    CHECK(player1.getResourceCount(ResourceType::Wood) == 5);
    CHECK(player2.getResourceCount(ResourceType::Brick) == 5);

    bool tradeSuccess = TradeManager::tradeResources(player1, ResourceType::Wood, 2, player2, ResourceType::Brick, 3);
    CHECK(tradeSuccess);
    CHECK(player1.getResourceCount(ResourceType::Wood) == 3);
    CHECK(player1.getResourceCount(ResourceType::Brick) == 3);
    CHECK(player2.getResourceCount(ResourceType::Wood) == 2);
    CHECK(player2.getResourceCount(ResourceType::Brick) == 2);
}

TEST_CASE("Trade development cards between players")
{
    Player player1("Player1");
    Player player2("Player2");

    player1.addDevelopmentCard(DevelopmentCardType::Knight);
    player2.addDevelopmentCard(DevelopmentCardType::Monopoly);

    CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    CHECK(player2.hasDevelopmentCard(DevelopmentCardType::Monopoly));

    bool tradeSuccess = TradeManager::tradeDevelopmentCards(player1, player2, DevelopmentCardType::Knight, DevelopmentCardType::Monopoly);
    CHECK(tradeSuccess);
    CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Monopoly));
    CHECK(!player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    CHECK(player2.hasDevelopmentCard(DevelopmentCardType::Knight));
    CHECK(!player2.hasDevelopmentCard(DevelopmentCardType::Monopoly));
}

TEST_CASE("Fail trade resources due to insufficient amount")
{
    Player player1("Player1");
    Player player2("Player2");

    player1.addResource(ResourceType::Wood, 2);
    player2.addResource(ResourceType::Brick, 3);

    CHECK(player1.getResourceCount(ResourceType::Wood) == 2);
    CHECK(player2.getResourceCount(ResourceType::Brick) == 3);

    bool tradeSuccess = TradeManager::tradeResources(player1, ResourceType::Wood, 3, player2, ResourceType::Brick, 2);
    CHECK(!tradeSuccess);
    CHECK(player1.getResourceCount(ResourceType::Wood) == 2);
    CHECK(player2.getResourceCount(ResourceType::Brick) == 3);
}

TEST_CASE("Fail trade development cards due to absence of card")
{
    Player player1("Player1");
    Player player2("Player2");

    player1.addDevelopmentCard(DevelopmentCardType::Knight);

    CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    CHECK(!player2.hasDevelopmentCard(DevelopmentCardType::Monopoly));

    bool tradeSuccess = TradeManager::tradeDevelopmentCards(player1, player2, DevelopmentCardType::Knight, DevelopmentCardType::Monopoly);
    CHECK(!tradeSuccess);
    CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    CHECK(!player2.hasDevelopmentCard(DevelopmentCardType::Knight));
}

TEST_CASE("Building roads, settlements, and cities")
{
    Player player1("Player1");

    player1.addResource(ResourceType::Wood, 1);
    player1.addResource(ResourceType::Brick, 1);
    player1.addResource(ResourceType::Wool, 1);
    player1.addResource(ResourceType::Oat, 1);
    player1.addResource(ResourceType::Iron, 3);
    player1.addResource(ResourceType::Oat, 2);

    CHECK(player1.buildRoad(1));
    CHECK(player1.buildSettlement(2));
    CHECK(player1.buildCity(2));

    CHECK(player1.getRoadCount() == 1);
    CHECK(player1.getSettlementCount() == 0); // The settlement was upgraded to a city
    CHECK(player1.getCityCount() == 1);
}

TEST_CASE("Buying and using development cards")
{
    Player player1("Player1");

    player1.addResource(ResourceType::Iron, 1);
    player1.addResource(ResourceType::Wool, 1);
    player1.addResource(ResourceType::Oat, 1);

    player1.buyDevelopmentCard();
    CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight) ||
          player1.hasDevelopmentCard(DevelopmentCardType::Monopoly) ||
          player1.hasDevelopmentCard(DevelopmentCardType::RoadBuilding) ||
          player1.hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) ||
          player1.hasDevelopmentCard(DevelopmentCardType::VictoryPoint));

    // if (player1.hasDevelopmentCard(DevelopmentCardType::Knight))
    // {
    //     player1.useDevelopmentCard(0, players, board);
    //     CHECK(!player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    // }
}

TEST_CASE("Resource distribution based on dice roll")
{
    Board board;
    board.initializeBoard();

    Player player1("Player1");
    Player player2("Player2");

    std::vector<Player> players = {Player("Player1"), Player("Player2")};

    board.initializePlayerSettlementsAndRoads(player1, 3, 6, 28, 36);
    board.initializePlayerSettlementsAndRoads(player2, 13, 14, 41, 55);

    CHECK(player1.getResourceCount(ResourceType::Wood) == 1);
    CHECK(player2.getResourceCount(ResourceType::Wood) == 0);

    board.distributeResources(9, players);

    CHECK(player1.getResourceCount(ResourceType::Wood) == 2);
    CHECK(player2.getResourceCount(ResourceType::Wood) == 0);
}
