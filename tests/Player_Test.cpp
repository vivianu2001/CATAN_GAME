
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "TradeManager.hpp"

// TEST_CASE("Checking adding and removing sources by buying ")
// {
//     std::vector<Player> players = {Player("Player1"), Player("Player2")};
//     Board board;
//     // board.initializePlayerSettlementsAndRoads(players[0], 13, 14, 41, 55);
//     // board.initializePlayerSettlementsAndRoads(players[1], 15, 18, 48, 64);
//     CHECK(players[0].buildRoad(2) == false);
//     CHECK(players[0].buildSettlement(2) == false);
//     CHECK(players[0].buildCity(2) == false);
//     CHECK(players[0].buyDevelopmentCard() == false);

//     players[0].addResource(ResourceType::Wood, 1);
//     players[0].addResource(ResourceType::Brick, 1);
//     CHECK(players[0].buildRoad(2) == true);
//     CHECK(players[0].getResourceCount(ResourceType::Wood) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Brick) == 0);

//     players[0].addResource(ResourceType::Wood, 1);
//     players[0].addResource(ResourceType::Brick, 1);
//     players[0].addResource(ResourceType::Oat, 1);
//     players[0].addResource(ResourceType::Wool, 1);
//     CHECK(players[0].buildSettlement(2) == true);

//     CHECK(players[0].getResourceCount(ResourceType::Wood) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Brick) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);

//     players[0].addResource(ResourceType::Wood, 1);
//     players[0].addResource(ResourceType::Brick, 1);
//     players[0].addResource(ResourceType::Oat, 1);
//     players[0].addResource(ResourceType::Wool, 1);
//     players[0].addResource(ResourceType::Iron, 1);
//     CHECK(players[0].buyDevelopmentCard() == true);

//     CHECK(players[0].getResourceCount(ResourceType::Wood) == 1);
//     CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);
//     CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Iron) == 0);

//     players[0].addResource(ResourceType::Oat, 1);
//     players[0].addResource(ResourceType::Oat, 1);
//     players[0].addResource(ResourceType::Iron, 1);
//     players[0].addResource(ResourceType::Iron, 1);
//     players[0].addResource(ResourceType::Iron, 1);
//     CHECK(players[0].buildCity(2) == true);

//     CHECK(players[0].getResourceCount(ResourceType::Wood) == 1);
//     CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);
//     CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);
//     CHECK(players[0].getResourceCount(ResourceType::Iron) == 0);
//     Player::resetPlayerCount();
//}

TEST_CASE("Check player development cards")
{
    std::vector<Player> players = {Player("Player1"), Player("Player2")};

    players[0].addDevelopmentCard(DevelopmentCardType::Monopoly);
    CHECK(players[0].hasDevelopmentCard(DevelopmentCardType::Monopoly) == true);
    Board board;
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].useDevelopmentCard(1, players, board);
    CHECK(players[0].getVictoryPoints() == 0);
    players[0].useDevelopmentCard(1, players, board);
    CHECK(players[0].getVictoryPoints() == 0);
    players[0].useDevelopmentCard(1, players, board);
    CHECK(players[0].getVictoryPoints() == 2);
    players[0].useDevelopmentCard(0, players, board);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 1);

    // CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    // CHECK(player[1].hasDevelopmentCard(DevelopmentCardType::Monopoly));

    // bool tradeSuccess = TradeManager::tradeDevelopmentCards(player1, player[1], DevelopmentCardType::Knight, DevelopmentCardType::Monopoly);
    // CHECK(tradeSuccess);
    // CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Monopoly));
    // CHECK(!player1.hasDevelopmentCard(DevelopmentCardType::Knight));
    // CHECK(player[1].hasDevelopmentCard(DevelopmentCardType::Knight));
    // CHECK(!player[1].hasDevelopmentCard(DevelopmentCardType::Monopoly));
}

// TEST_CASE("Fail trade resources due to insufficient amount")
// {

// bool tradeSuccess = TradeManager::tradeResources(players[0], ResourceType::Wood, 2, players[1], ResourceType::Brick, 3);
// CHECK(tradeSuccess);
// CHECK(players[0].getResourceCount(ResourceType::Wood) == 3);
// CHECK(players[0].getResourceCount(ResourceType::Brick) == 3);
// CHECK(players[1].getResourceCount(ResourceType::Wood) == 2);
// CHECK(players[1].getResourceCount(ResourceType::Brick) == 2);
//     bool tradeSuccess = TradeManager::tradeDevelopmentCards(player1, player[1], DevelopmentCardType::Knight, DevelopmentCardType::Monopoly);
//     CHECK(tradeSuccess);
//     CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Monopoly));
//     CHECK(!player1.hasDevelopmentCard(DevelopmentCardType::Knight));
//     CHECK(player[1].hasDevelopmentCard(DevelopmentCardType::Knight));
//     CHECK(!player[1].hasDevelopmentCard(DevelopmentCardType::Monopoly));
// Player player1("Player1");
// Player player[1]("player[1]");
//     Player player1("Player1");
//     Player player[1]("player[1]");

//     player1.addResource(ResourceType::Wood, 2);
//     player[1].addResource(ResourceType::Brick, 3);

//     CHECK(player1.getResourceCount(ResourceType::Wood) == 2);
//     CHECK(player[1].getResourceCount(ResourceType::Brick) == 3);

//     bool tradeSuccess = TradeManager::tradeResources(player1, ResourceType::Wood, 3, player[1], ResourceType::Brick, 2);
//     CHECK(!tradeSuccess);
//     CHECK(player1.getResourceCount(ResourceType::Wood) == 2);
//     CHECK(player[1].getResourceCount(ResourceType::Brick) == 3);
// }

// TEST_CASE("Fail trade development cards due to absence of card")
// {
//     Player player1("Player1");
//     Player player[1]("player[1]");

//     player1.addDevelopmentCard(DevelopmentCardType::Knight);

//     CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight));
//     CHECK(!player[1].hasDevelopmentCard(DevelopmentCardType::Monopoly));

//     bool tradeSuccess = TradeManager::tradeDevelopmentCards(player1, player[1], DevelopmentCardType::Knight, DevelopmentCardType::Monopoly);
//     CHECK(!tradeSuccess);
//     CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight));
//     CHECK(!player[1].hasDevelopmentCard(DevelopmentCardType::Knight));
// }

// TEST_CASE("Building roads, settlements, and cities")
// {
//     Player player1("Player1");

//     player1.addResource(ResourceType::Wood, 1);
//     player1.addResource(ResourceType::Brick, 1);
//     player1.addResource(ResourceType::Wool, 1);
//     player1.addResource(ResourceType::Oat, 1);
//     player1.addResource(ResourceType::Iron, 3);
//     player1.addResource(ResourceType::Oat, 2);

//     CHECK(player1.buildRoad(1));
//     CHECK(player1.buildSettlement(2));
//     CHECK(player1.buildCity(2));

//     CHECK(player1.getRoadCount() == 1);
//     CHECK(player1.getSettlementCount() == 0); // The settlement was upgraded to a city
//     CHECK(player1.getCityCount() == 1);
// }

// // // TEST_CASE("Buying and using development cards")
// // // {
// // //     Player player1("Player1");

// // //     player1.addResource(ResourceType::Iron, 1);
// // //     player1.addResource(ResourceType::Wool, 1);
// // //     player1.addResource(ResourceType::Oat, 1);

// // //     player1.buyDevelopmentCard();
// // //     CHECK(player1.hasDevelopmentCard(DevelopmentCardType::Knight) ||
// // //           player1.hasDevelopmentCard(DevelopmentCardType::Monopoly) ||
// // //           player1.hasDevelopmentCard(DevelopmentCardType::RoadBuilding) ||
// // //           player1.hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) ||
// // //           player1.hasDevelopmentCard(DevelopmentCardType::VictoryPoint));

// // // if (player1.hasDevelopmentCard(DevelopmentCardType::Knight))
// // // {
// // //     player1.useDevelopmentCard(0, players, board);
// // //     CHECK(!player1.hasDevelopmentCard(DevelopmentCardType::Knight));
// // // }
// // }

// TEST_CASE("Resource distribution based on dice roll")
// {
//     Board board;
//     board.initializeBoard();

//     Player player1("Player1");
//     Player player[1]("player[1]");

//     std::vector<Player> players = {Player("Player1"), Player("player[1]")};

//     board.initializePlayerSettlementsAndRoads(player1, 3, 6, 28, 36);
//     board.initializePlayerSettlementsAndRoads(player[1], 13, 14, 41, 55);

//     CHECK(player1.getResourceCount(ResourceType::Wood) == 1);
//     CHECK(player[1].getResourceCount(ResourceType::Wood) == 0);

//     board.distributeResources(9, players);

//     CHECK(player1.getResourceCount(ResourceType::Wood) == 2);
//     CHECK(player[1].getResourceCount(ResourceType::Wood) == 0);
// }
