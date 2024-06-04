#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"

// TEST_CASE("Test Board Initialization")
// {
//     Board board;
//     board.initializeBoard();

//     CHECK(board.getTiles().size() == TILE_COUNT);
//     CHECK(board.getVertices().size() == VERTEX_COUNT);
//     CHECK(board.getEdges().size() == EDGE_COUNT);
// }

// TEST_CASE("Test Building Settlements-STARTING POINT")
// {

//     Board board;
//     board.initializeBoard();
//     Player player("Player 1");
//     Player player2("Player 2");

//     CHECK(board.buildSettlement(player.getPlayerId(), 5, true) == true);
//     CHECK(board.buildSettlement(player.getPlayerId(), 5, true) == false);            // Should fail, already occupied
//     CHECK(board.buildSettlement(player.getPlayerId(), -1, true) == false);           // Invalid vertex
//     CHECK(board.buildSettlement(player.getPlayerId(), VERTEX_COUNT, true) == false); // Invalid vertex
//     CHECK(board.buildSettlement(player2.getPlayerId(), 5, true) == false);
//     CHECK(board.buildSettlement(player2.getPlayerId(), 2, true) == true);
//     std::vector<Vertex> vertices = board.getVertices();

//     CHECK(vertices[5].getOwner() == 1);
//     CHECK(vertices[2].getOwner() == 2);
//     Player::resetPlayerCount();
// }

// TEST_CASE("Test Building Roads")
// {
//     /* require bricks + wood. A new road section should always be associated with a road section, settlement or
//      A city in your possession.
//      */
//     Board board;
//     board.initializeBoard();
//     Player player("Player 1");

//     CHECK(board.buildRoad(player.getPlayerId(), 5) == false); // Should fail, no adjacent settlements

//     // Build settlements first
//     board.buildSettlement(player.getPlayerId(), 5, true);
//     board.buildSettlement(player.getPlayerId(), 10, true);
//     CHECK(board.buildRoad(player.getPlayerId(), 3) == true);           // Now it should succeed
//     CHECK(board.buildRoad(player.getPlayerId(), 3) == false);          // Should fail, already occupied
//     CHECK(board.buildRoad(player.getPlayerId(), -1) == false);         // Invalid edge
//     CHECK(board.buildRoad(player.getPlayerId(), EDGE_COUNT) == false); // Invalid edge
//     CHECK(board.buildRoad(player.getPlayerId(), 50) == false);

//     std::vector<Edge> edges = board.getEdges();
//     CHECK(edges[3].getOwner() == 1);
//     Player::resetPlayerCount();
// }

// TEST_CASE("Test Mix- Building & Roads")
// {

//     Board board;
//     board.initializeBoard();
//     Player player4("Player 1");
//     Player player5("Player 2");

//     // Build settlements first
//     CHECK(board.buildSettlement(player4.getPlayerId(), 5, true) == true);
//     CHECK(board.buildRoad(player4.getPlayerId(), 4) == true);
//     CHECK(board.buildSettlement(player4.getPlayerId(), 3, false) == false);

//     CHECK(board.buildRoad(player5.getPlayerId(), 3) == false); // Should fail, already occupied
//     CHECK(board.buildSettlement(player5.getPlayerId(), 4, false) == false);
//     CHECK(board.buildSettlement(player5.getPlayerId(), 3, false) == false);
//     CHECK(board.buildSettlement(player5.getPlayerId(), 17, false) == false);

//     CHECK(board.buildRoad(player4.getPlayerId(), 5) == true);
//     CHECK(board.buildSettlement(player4.getPlayerId(), 2, false) == true);
//     Player::resetPlayerCount();
// }
TEST_CASE("Board distributeResources")
{
    Board board;
    board.initializeBoard();

    // Using pointers to store references to Player objects
    std::vector<Player> players = {Player("Player1"), Player("Player2")};

    // Distribute resources for dice roll 6

    // Check if Player1 received 1 Wood
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
}