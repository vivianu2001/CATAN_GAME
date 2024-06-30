//umanskyvivian@gmail.com
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "TradeManager.hpp"
#include "catan.hpp"


TEST_CASE("Checking adding and removing sources by buying ")
{
    std::vector<Player> players = {Player("Player1"), Player("Player2")};
    Board board;
  
    CHECK(players[0].buildRoad(2) == false);
    CHECK(players[0].buildSettlement(2) == false);
    CHECK(players[0].buildCity(2) == false);
    CHECK(players[0].buyDevelopmentCard(players, board) == false);

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
    CHECK(players[0].buyDevelopmentCard(players, board) == true);

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

// TEST_CASE("Check player development cards")  // inputs :: Wood 20,26 Iron,Oat

// {
//     std::vector<Player> players = {Player("Player1"), Player("Player2"), Player("Player3")};

//     players[0].addDevelopmentCard(DevelopmentCardType::Monopoly);
//     CHECK(players[0].hasDevelopmentCard(DevelopmentCardType::Monopoly) == true);

//     players[1].addResource(ResourceType::Wood, 1);
//     players[2].addResource(ResourceType::Wood, 1);

//     Board board;
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

TEST_CASE("Test Board Initialization")
{
    Board board;

    CHECK(board.getTiles().size() == TILE_COUNT);
    CHECK(board.getVertices().size() == VERTEX_COUNT);
    CHECK(board.getEdges().size() == EDGE_COUNT);
}

TEST_CASE("Test Building Settlements-STARTING POINT")
{

    Board board;

    Player player("Player 1");
    Player player2("Player 2");

    CHECK(board.buildSettlement(player.getPlayerId(), 5, true) == true);
    CHECK(board.buildSettlement(player.getPlayerId(), 5, true) == false);            // Should fail, already occupied
    CHECK(board.buildSettlement(player.getPlayerId(), -1, true) == false);           // Invalid vertex
    CHECK(board.buildSettlement(player.getPlayerId(), VERTEX_COUNT, true) == false); // Invalid vertex
    CHECK(board.buildSettlement(player2.getPlayerId(), 5, true) == false);
    CHECK(board.buildSettlement(player2.getPlayerId(), 2, true) == true);
    std::vector<Vertex> vertices = board.getVertices();

    CHECK(vertices[5].getOwner() == 1);
    CHECK(vertices[2].getOwner() == 2);
    Player::resetPlayerCount();
}

TEST_CASE("Test Building Roads")
{
    /* require bricks + wood. A new road section should always be associated with a road section, settlement or
     A city in your possession.
     */
    Board board;

    Player player("Player 1");

    CHECK(board.buildRoad(player.getPlayerId(), 5) == false); // Should fail, no adjacent settlements

    // Build settlements first
    board.buildSettlement(player.getPlayerId(), 5, true);
    board.buildSettlement(player.getPlayerId(), 10, true);
    CHECK(board.buildRoad(player.getPlayerId(), 3) == true);           // Now it should succeed
    CHECK(board.buildRoad(player.getPlayerId(), 3) == false);          // Should fail, already occupied
    CHECK(board.buildRoad(player.getPlayerId(), -1) == false);         // Invalid edge
    CHECK(board.buildRoad(player.getPlayerId(), EDGE_COUNT) == false); // Invalid edge
    CHECK(board.buildRoad(player.getPlayerId(), 50) == false);

    std::vector<Edge> edges = board.getEdges();
    CHECK(edges[3].getOwner() == 1);
    Player::resetPlayerCount();
}

TEST_CASE("Test Mix- Building & Roads")
{

    Board board;

    Player player4("Player 1");
    Player player5("Player 2");

    // Build settlements first
    CHECK(board.buildSettlement(player4.getPlayerId(), 5, true) == true);
    CHECK(board.buildRoad(player4.getPlayerId(), 4) == true);
    CHECK(board.buildSettlement(player4.getPlayerId(), 3, false) == false);

    CHECK(board.buildRoad(player5.getPlayerId(), 3) == false);
    CHECK(board.buildSettlement(player5.getPlayerId(), 4, false) == false);
    CHECK(board.buildSettlement(player5.getPlayerId(), 3, false) == false);
    CHECK(board.buildSettlement(player5.getPlayerId(), 17, false) == false);

    CHECK(board.buildRoad(player4.getPlayerId(), 5) == true);
    CHECK(board.buildSettlement(player4.getPlayerId(), 2, false) == true);
    Player::resetPlayerCount();
}
TEST_CASE("Board distributeResources")
{
    Board board;

    std::vector<Player> players = {Player("Player1"), Player("Player2")};

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 0);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 0);

    CHECK(players[1].getResourceCount(ResourceType::Wood) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Oat) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Iron) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Brick) == 0);

    board.initializePlayerSettlementsAndRoads(players[0], 13, 14, 41, 55);
    board.initializePlayerSettlementsAndRoads(players[1], 15, 18, 48, 64);

    CHECK(players[0].getResourceCount(ResourceType::Wood) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Wool) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);

    CHECK(players[1].getResourceCount(ResourceType::Wood) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Oat) == 1);
    CHECK(players[1].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Iron) == 1);
    CHECK(players[1].getResourceCount(ResourceType::Brick) == 1);

    board.distributeResources(9, players);
    CHECK(players[0].getResourceCount(ResourceType::Wood) == 2);
    CHECK(players[0].getResourceCount(ResourceType::Oat) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Wool) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Iron) == 1);
    CHECK(players[0].getResourceCount(ResourceType::Brick) == 1);

    CHECK(players[1].getResourceCount(ResourceType::Wood) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Oat) == 2);
    CHECK(players[1].getResourceCount(ResourceType::Wool) == 0);
    CHECK(players[1].getResourceCount(ResourceType::Iron) == 1);
    CHECK(players[1].getResourceCount(ResourceType::Brick) == 1);
    Player::resetPlayerCount();
}


TEST_CASE("Test handleRollOfSeven function") {
   std::vector<Player> players = {Player("Player1"), Player("Player2"),Player("Player3")};
    players[0].addResource(ResourceType::Wood, 8);
    players[1].addResource(ResourceType::Brick, 5);
    players[2].addResource(ResourceType::Wool, 10);

    handleRollOfSeven(players);

    CHECK(players[0].getTotalResourceCount() == 4); // Should return 4 resources
    CHECK(players[1].getTotalResourceCount() == 5); // Should return 5 resources
    CHECK(players[2].getTotalResourceCount() == 5); // Should remain unchanged
    Player::resetPlayerCount();
}
