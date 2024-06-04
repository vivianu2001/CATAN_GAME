#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"

TEST_CASE("Test Board Initialization")
{
    Board board;
    board.initializeBoard();

    CHECK(board.getTiles().size() == TILE_COUNT);
    CHECK(board.getVertices().size() == VERTEX_COUNT);
    CHECK(board.getEdges().size() == EDGE_COUNT);
}

TEST_CASE("Test Building Settlements-STARTING POINT")
{
    Board board;
    board.initializeBoard();
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
}

TEST_CASE("Test Building Roads")
{
    /* require bricks + wood. A new road section should always be associated with a road section, settlement or
     A city in your possession.
     */
    Board board;
    board.initializeBoard();
    Player player3("Player 1");

    CHECK(board.buildRoad(player3.getPlayerId(), 5) == false); // Should fail, no adjacent settlements

    // Build settlements first
    board.buildSettlement(player3.getPlayerId(), 5, true);
    board.buildSettlement(player3.getPlayerId(), 10, true);
    CHECK(board.buildRoad(player3.getPlayerId(), 3) == true);           // Now it should succeed
    CHECK(board.buildRoad(player3.getPlayerId(), 3) == false);          // Should fail, already occupied
    CHECK(board.buildRoad(player3.getPlayerId(), -1) == false);         // Invalid edge
    CHECK(board.buildRoad(player3.getPlayerId(), EDGE_COUNT) == false); // Invalid edge
    CHECK(board.buildRoad(player3.getPlayerId(), 50) == false);

    std::vector<Edge> edges = board.getEdges();
    // CHECK(edges[3].getOwner() == 1);
}

TEST_CASE("Test Mix- Building & Roads")
{

    Board board;
    board.initializeBoard();
    Player player4("Player 1");
    Player player5("Player 1");

    // Build settlements first
    CHECK(board.buildSettlement(player4.getPlayerId(), 5, true) == true);
    CHECK(board.buildRoad(player4.getPlayerId(), 4) == true);
    CHECK(board.buildSettlement(player4.getPlayerId(), 3, false) == false);

    CHECK(board.buildRoad(player5.getPlayerId(), 3) == false); // Should fail, already occupied
    CHECK(board.buildSettlement(player5.getPlayerId(), 4, false) == false);
    CHECK(board.buildSettlement(player5.getPlayerId(), 3, false) == false);
    CHECK(board.buildSettlement(player5.getPlayerId(), 17, false) == false);

    CHECK(board.buildRoad(player4.getPlayerId(), 5) == true);
    CHECK(board.buildSettlement(player4.getPlayerId(), 2, false) == true);
}
