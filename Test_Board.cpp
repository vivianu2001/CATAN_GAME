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

TEST_CASE("Test Building Settlements")
{
    Board board;
    board.initializeBoard();
    Player player("Player 1");

    CHECK(board.buildSettlement(player.getPlayerId(), 5) == true);
    CHECK(board.buildSettlement(player.getPlayerId(), 5) == false);            // Should fail, already occupied
    CHECK(board.buildSettlement(player.getPlayerId(), -1) == false);           // Invalid vertex
    CHECK(board.buildSettlement(player.getPlayerId(), VERTEX_COUNT) == false); // Invalid vertex
}

TEST_CASE("Test Building Roads")
{
    Board board;
    board.initializeBoard();
    Player player("Player 1");

    CHECK(board.buildRoad(player.getPlayerId(), 5) == false); // Should fail, no adjacent settlements

    // Build settlements first
    board.buildSettlement(player.getPlayerId(), 5);
    board.buildSettlement(player.getPlayerId(), 10);
    CHECK(board.buildRoad(player.getPlayerId(), 3) == true);           // Now it should succeed
    CHECK(board.buildRoad(player.getPlayerId(), 3) == false);          // Should fail, already occupied
    CHECK(board.buildRoad(player.getPlayerId(), -1) == false);         // Invalid edge
    CHECK(board.buildRoad(player.getPlayerId(), EDGE_COUNT) == false); // Invalid edge
}

TEST_CASE("Test Player Resources and Constructions")
{
    Player player("Player 1");

    // Adding resources
    player.addResource(ResourceType::Wood, 3);
    player.addResource(ResourceType::Brick, 2);
    player.addResource(ResourceType::Wool, 1);

    CHECK(player.getResourceCount(ResourceType::Wood) == 3);
    CHECK(player.getResourceCount(ResourceType::Brick) == 2);
    CHECK(player.getResourceCount(ResourceType::Wool) == 1);

    // Print player status (manual verification)
    player.printStatus();

    // Build settlements and roads
    player.addSettlement(5);
    player.addRoad(10);

    CHECK(player.getSettlementCount() == 1);
    CHECK(player.getRoadCount() == 1);
}
