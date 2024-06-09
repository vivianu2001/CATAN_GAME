
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "TradeManager.hpp"

TEST_CASE("Checking adding and removing sources by buying ")
{
    std::vector<Player> players = {Player("Player1"), Player("Player2")};
    Board board;
    // board.initializePlayerSettlementsAndRoads(players[0], 13, 14, 41, 55);
    // board.initializePlayerSettlementsAndRoads(players[1], 15, 18, 48, 64);
    CHECK(players[0].buildRoad(2) == false);
    CHECK(players[0].buildSettlement(2) == false);
    CHECK(players[0].buildCity(2) == false);
    CHECK(players[0].buyDevelopmentCard() == false);

    players[0].addResource(ResourceType::Wood, 1);
    players[0].addResource(ResourceType::Brick, 1);
    CHECK(players[0].buildRoad(2) == true);
    CHECK(players[0].getResourceCount(ResourceType::Wood) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 0);

    players[0].addResource(ResourceType::Wood, 1);
    players[0].addResource(ResourceType::Brick, 1);
    players[0].addResource(ResourceType::Oat, 1);
    players[0].addResource(ResourceType::Wool, 1);
    CHECK(players[0].buildSettlement(2) == true);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);

    players[0].addResource(ResourceType::Wood, 1);
    players[0].addResource(ResourceType::Brick, 1);
    players[0].addResource(ResourceType::Oat, 1);
    players[0].addResource(ResourceType::Wool, 1);
    players[0].addResource(ResourceType::Iron, 1);
    CHECK(players[0].buyDevelopmentCard() == true);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 0);

    players[0].addResource(ResourceType::Oat, 1);
    players[0].addResource(ResourceType::Oat, 1);
    players[0].addResource(ResourceType::Iron, 1);
    players[0].addResource(ResourceType::Iron, 1);
    players[0].addResource(ResourceType::Iron, 1);
    CHECK(players[0].buildCity(2) == true);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 0);
    Player::resetPlayerCount();
}

// TEST_CASE("Check player development cards")
// {
//     std::vector<Player> players = {Player("Player1"), Player("Player2"), Player("Player3")};

//     players[0].addDevelopmentCard(DevelopmentCardType::Monopoly);
//     CHECK(players[0].hasDevelopmentCard(DevelopmentCardType::Monopoly) == true);

//     players[1].addResource(ResourceType::Wood, 1);
//     players[2].addResource(ResourceType::Wood, 1);

//     Board board;
//     board.initializeBoard();
//     board.initializePlayerSettlementsAndRoads(players[0], 5, 4, 21, 28);

//     players[0].addDevelopmentCard(DevelopmentCardType::Knight);
//     players[0].addDevelopmentCard(DevelopmentCardType::Knight);
//     players[0].addDevelopmentCard(DevelopmentCardType::Knight);
//     players[0].useDevelopmentCard(1, players, board);
//     CHECK(players[0].getVictoryPoints() == 2);
//     players[0].useDevelopmentCard(2, players, board);
//     CHECK(players[0].getVictoryPoints() == 2);
//     players[0].useDevelopmentCard(3, players, board);
//     CHECK(players[0].getVictoryPoints() == 4);

//     players[0].useDevelopmentCard(0, players, board);

//     CHECK(players[1].getResourceCount(ResourceType::Wood) == 0);
//     CHECK(players[2].getResourceCount(ResourceType::Wood) == 0);

//     CHECK(players[0].getResourceCount(ResourceType::Wood) == 3);
//     players[0].addDevelopmentCard(DevelopmentCardType::RoadBuilding);
//     players[0].useDevelopmentCard(3, players, board);
//     players[0].printStatus();
//     CHECK(players[0].getRoadCount() == 4);

//     players[0].addDevelopmentCard(DevelopmentCardType::YearOfPlenty);
//     players[0].useDevelopmentCard(3, players, board);
//     CHECK(players[0].getResourceCount(ResourceType::Iron) == 2);
//     CHECK(players[0].getResourceCount(ResourceType::Oat) == 2);

//     players[0].addDevelopmentCard(DevelopmentCardType::VictoryPoint);
//     players[0].useDevelopmentCard(3, players, board);
//     CHECK(players[0].getVictoryPoints() == 5);
//     Player::resetPlayerCount();
// }

TEST_CASE("Trade resources")
{
    std::vector<Player> players = {Player("Player1"), Player("Player2")};

    players[0].addResource(ResourceType::Brick, 3);
    players[0].addResource(ResourceType::Oat, 3);
    players[0].addResource(ResourceType::Iron, 3);

    players[1].addResource(ResourceType::Wood, 3);
    players[1].addResource(ResourceType::Wool, 3);

    bool tradeSuccess = TradeManager::tradeResources(players[0], ResourceType::Brick, 2, players[1], ResourceType::Wood, 2);
    CHECK(tradeSuccess);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 2);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 3);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 3);

    CHECK(players[1].getResourceCount(ResourceType::Wood) == 1);
    CHECK(players[1].getResourceCount(ResourceType::Brick) == 2);
    CHECK(players[1].getResourceCount(ResourceType::Oat) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Iron) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Wool) == 3);

    bool tradeSuccess_2 = TradeManager::tradeResources(players[0], ResourceType::Iron, 3, players[1], ResourceType::Brick, 2);
    CHECK(tradeSuccess_2);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 2);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 3);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 3);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 0);

    CHECK(players[1].getResourceCount(ResourceType::Wood) == 1);
    CHECK(players[1].getResourceCount(ResourceType::Brick) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Oat) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Iron) == 3);
    CHECK(players[1].getResourceCount(ResourceType::Wool) == 3);
    Player::resetPlayerCount();
}

TEST_CASE("Trade resources-Edge case")
{
    std::vector<Player> players = {Player("Player1"), Player("Player2")};

    players[0].addResource(ResourceType::Brick, 3);
    players[0].addResource(ResourceType::Oat, 3);
    players[0].addResource(ResourceType::Iron, 3);

    players[1].addResource(ResourceType::Wood, 3);
    players[1].addResource(ResourceType::Wool, 3);

    bool tradeSuccess = TradeManager::tradeResources(players[0], ResourceType::Brick, 4, players[1], ResourceType::Wood, 2);
    CHECK_FALSE(tradeSuccess);

    bool tradeSuccess_2 = TradeManager::tradeResources(players[0], ResourceType::Wool, 4, players[1], ResourceType::Wood, 2);
    CHECK_FALSE(tradeSuccess_2);

    bool tradeSuccess_3 = TradeManager::tradeResources(players[0], ResourceType::Wool, 4, players[1], ResourceType::Wood, 2);
    CHECK_FALSE(tradeSuccess_3);
    bool tradeSuccess_4 = TradeManager::tradeResources(players[0], ResourceType::Brick, 3, players[1], ResourceType::Iron, 2);
    CHECK_FALSE(tradeSuccess_4);

    bool tradeSuccess_5 = TradeManager::tradeResources(players[0], ResourceType::Brick, 3, players[1], ResourceType::Wood, 4);
    CHECK_FALSE(tradeSuccess_5);

    bool tradeSuccess_6 = TradeManager::tradeResources(players[0], ResourceType::Brick, 0, players[1], ResourceType::Wood, 0);
    CHECK_FALSE(tradeSuccess_6);

    Player::resetPlayerCount();
}

TEST_CASE("Trade-development cards knights")

{
    Board board;
    std::vector<Player> players = {Player("Player1"), Player("Player2")};
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].useDevelopmentCard(0, players, board);
    players[0].useDevelopmentCard(1, players, board);
    players[0].useDevelopmentCard(2, players, board);
    CHECK(players[0].getVictoryPoints() == 2);

    players[1].addDevelopmentCard(DevelopmentCardType::Knight);
    players[1].addDevelopmentCard(DevelopmentCardType::Knight);
    players[1].addDevelopmentCard(DevelopmentCardType::Monopoly);
    players[1].useDevelopmentCard(0, players, board);
    players[1].useDevelopmentCard(1, players, board);
    CHECK(players[1].getVictoryPoints() == 0);
    bool tradeSuccess = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::Knight, DevelopmentCardType::Monopoly);
    CHECK(tradeSuccess);
    players[1].useDevelopmentCard(2, players, board);
    CHECK(players[0].getVictoryPoints() == 0);
    CHECK(players[1].getVictoryPoints() == 2);
    Player::resetPlayerCount();
}

TEST_CASE("Trade-development cards Victory points")

{
    Board board;
    std::vector<Player> players = {Player("Player1"), Player("Player2")};
    players[0].addDevelopmentCard(DevelopmentCardType::VictoryPoint);
    players[0].addDevelopmentCard(DevelopmentCardType::VictoryPoint);
    players[0].useDevelopmentCard(0, players, board);
    players[0].useDevelopmentCard(0, players, board);
    players[0].useDevelopmentCard(1, players, board);
    CHECK(players[0].getVictoryPoints() == 2);
    players[0].addDevelopmentCard(DevelopmentCardType::YearOfPlenty);

    players[1].addDevelopmentCard(DevelopmentCardType::VictoryPoint);
    players[1].useDevelopmentCard(0, players, board);

    CHECK(players[1].getVictoryPoints() == 1);
    bool tradeSuccess = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::YearOfPlenty, DevelopmentCardType::VictoryPoint);
    CHECK(tradeSuccess);
    players[0].useDevelopmentCard(2, players, board);
    CHECK(players[0].getVictoryPoints() == 3);
    CHECK(players[1].getVictoryPoints() == 0);
    CHECK(players[1].hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) == true);

    Player::resetPlayerCount();
}

TEST_CASE("Trade-development cards mix")

{
    Board board;
    std::vector<Player> players = {Player("Player1"), Player("Player2")};
    players[0].addDevelopmentCard(DevelopmentCardType::VictoryPoint);
    players[0].addDevelopmentCard(DevelopmentCardType::RoadBuilding);
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].useDevelopmentCard(0, players, board);

    players[1].addDevelopmentCard(DevelopmentCardType::YearOfPlenty);

    CHECK(players[0].getVictoryPoints() == 1);
    bool tradeSuccess = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::Knight, DevelopmentCardType::YearOfPlenty);
    CHECK(tradeSuccess);

    CHECK(players[1].hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) == false);
    CHECK(players[1].hasDevelopmentCard(DevelopmentCardType::Knight) == true);
    CHECK(players[0].hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) == true);

    bool tradeSuccess_2 = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::YearOfPlenty, DevelopmentCardType::Knight);
    CHECK(tradeSuccess_2);

    CHECK(players[1].hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) == true);
    CHECK(players[1].hasDevelopmentCard(DevelopmentCardType::Knight) == false);
    CHECK(players[0].hasDevelopmentCard(DevelopmentCardType::YearOfPlenty) == false);
    CHECK(players[0].hasDevelopmentCard(DevelopmentCardType::Knight) == true);

    Player::resetPlayerCount();
}

TEST_CASE("Trade-development cards edge cases")

{
    Board board;
    std::vector<Player> players = {Player("Player1"), Player("Player2")};
    players[0].addDevelopmentCard(DevelopmentCardType::VictoryPoint);
    players[0].addDevelopmentCard(DevelopmentCardType::RoadBuilding);
    players[0].addDevelopmentCard(DevelopmentCardType::Knight);
    players[0].useDevelopmentCard(0, players, board);

    players[1].addDevelopmentCard(DevelopmentCardType::YearOfPlenty);

    bool tradeSuccess = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::Monopoly, DevelopmentCardType::YearOfPlenty);
    CHECK_FALSE(tradeSuccess);
    bool tradeSuccess_2 = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::YearOfPlenty, DevelopmentCardType::YearOfPlenty);
    CHECK_FALSE(tradeSuccess_2);

    bool tradeSuccess_3 = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::VictoryPoint, DevelopmentCardType::Knight);
    CHECK_FALSE(tradeSuccess_3);

    bool tradeSuccess_4 = TradeManager::tradeDevelopmentCards(players[0], players[1], DevelopmentCardType::Monopoly, DevelopmentCardType::Knight);
    CHECK_FALSE(tradeSuccess_4);

    Player::resetPlayerCount();
}