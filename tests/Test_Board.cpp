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

    Player player1("Player1");
    Player player2("Player2");
    std::vector<Player> players = {player1, player2};

    // Distribute resources for dice roll 6
    board.distributeResources(6, players);

    // Check if Player1 received 1 Wood
    CHECK(player1.getResourceCount(ResourceType::Wood) == 0);
    CHECK(player1.getResourceCount(ResourceType::Oat) == 0);
    CHECK(player1.getResourceCount(ResourceType::Wool) == 0);
    CHECK(player1.getResourceCount(ResourceType::Iron) == 0);
    CHECK(player1.getResourceCount(ResourceType::Brick) == 0);

    CHECK(player2.getResourceCount(ResourceType::Wood) == 0);
    CHECK(player2.getResourceCount(ResourceType::Oat) == 0);
    CHECK(player2.getResourceCount(ResourceType::Wool) == 0);
    CHECK(player2.getResourceCount(ResourceType::Iron) == 0);
    CHECK(player2.getResourceCount(ResourceType::Brick) == 0);

    board.initializePlayerSettlementsAndRoads(player2, 13, 14, 41, 55);

    // CHECK(board.buildSettlement(player1.getPlayerId(), 3, true) == true);
    // CHECK(board.buildRoad(player1.getPlayerId(), 6) == true);
    // CHECK(board.buildSettlement(player1.getPlayerId(), 28, true) == true);
    // CHECK(board.buildRoad(player1.getPlayerId(), 36) == true);

    // CHECK(board.buildSettlement(player2.getPlayerId(), 13, true) == true);
    // CHECK(board.buildRoad(player2.getPlayerId(), 14) == true);
    // CHECK(board.buildSettlement(player2.getPlayerId(), 41, true) == true);
    // CHECK(board.buildRoad(player2.getPlayerId(), 55) == true);

    // board.distributeResources(9, players);
    // CHECK(player1.getResourceCount(ResourceType::Wood) == 0);
    // CHECK(player1.getResourceCount(ResourceType::Oat) == 0);
    // CHECK(player1.getResourceCount(ResourceType::Wool) == 0);
    // CHECK(player1.getResourceCount(ResourceType::Iron) == 0);
    // CHECK(player1.getResourceCount(ResourceType::Brick) == 0);

    // CHECK(player2.getResourceCount(ResourceType::Wood) == 0);
    // CHECK(player2.getResourceCount(ResourceType::Oat) == 0);
    // CHECK(player2.getResourceCount(ResourceType::Wool) == 0);
    // CHECK(player2.getResourceCount(ResourceType::Iron) == 0);
    // CHECK(player2.getResourceCount(ResourceType::Brick) == 0);
}