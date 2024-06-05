// board.cpp
#include "Board.hpp"
#include <iostream>
#include <set>

Board::Board()
{
}

void Board::initializeBoard()
{
    initializeVertices();
    initializeEdges();
    initializeTiles();
    linkVerticesAndEdges();
    linkTiles();
}

void Board::initializeVertices()
{
    vertices.reserve(VERTEX_COUNT);
    for (int i = 0; i < VERTEX_COUNT; ++i)
    {
        vertices.emplace_back(i);
    }
}

void Board::initializeEdges()
{
    edges.reserve(EDGE_COUNT);
    for (int i = 0; i < EDGE_COUNT; ++i)
    {
        edges.emplace_back(i);
    }
}

void Board::initializeTiles()
{
    tiles.reserve(TILE_COUNT);
    tiles.emplace_back(ResourceType::Iron, 10);
    tiles.emplace_back(ResourceType::Wool, 2);
    tiles.emplace_back(ResourceType::Wood, 9);
    tiles.emplace_back(ResourceType::Oat, 12);
    tiles.emplace_back(ResourceType::Brick, 6);
    tiles.emplace_back(ResourceType::Wool, 4);
    tiles.emplace_back(ResourceType::Brick, 10);
    tiles.emplace_back(ResourceType::Oat, 9);
    tiles.emplace_back(ResourceType::Wood, 11);
    tiles.emplace_back(ResourceType::None, 0); // Desert
    tiles.emplace_back(ResourceType::Wood, 3);
    tiles.emplace_back(ResourceType::Iron, 8);
    tiles.emplace_back(ResourceType::Wood, 8);
    tiles.emplace_back(ResourceType::Iron, 3);
    tiles.emplace_back(ResourceType::Oat, 4);
    tiles.emplace_back(ResourceType::Wool, 5);
    tiles.emplace_back(ResourceType::Brick, 5);
    tiles.emplace_back(ResourceType::Oat, 6);
    tiles.emplace_back(ResourceType::Wool, 11);
}

void Board::linkVerticesAndEdges()
{
    for (size_t i = 0; i < edgeToVertices.size(); ++i)
    {
        int v1 = edgeToVertices[i].first;
        int v2 = edgeToVertices[i].second;
        edges[i].setVertices(&vertices[v1], &vertices[v2]);
        vertices[v1].addEdge(&edges[i]);
        vertices[v2].addEdge(&edges[i]);
    }
}

void Board::linkTiles()
{
    for (size_t i = 0; i < vertexToTiles.size(); ++i)
    {
        for (int tileId : vertexToTiles[i])
        {
            vertices[i].addAdjacentTile(tileId);
            tiles[tileId].addVertex(&vertices[i]);
        }
    }
}
const std::vector<Tile> &Board::getTiles() const
{ // Match the declaration: const function returning a const reference.
    return tiles;
}
const std::vector<Edge> &Board::getEdges() const
{ // Match the declaration: const function returning a const reference.
    return edges;
}
const std::vector<Vertex> &Board::getVertices() const
{ // Match the declaration: const function returning a const reference.
    return vertices;
}
bool Board::isTwoRoadSegmentsAway(int vertexId) const
{
    for (const auto &edgeId : vertices[vertexId].getAdjacentEdges())
    {
        int neighbor1 = edges[edgeId].getVertex1(); //
        int neighbor2 = edges[edgeId].getVertex2();
        int neighborVertexId = (neighbor1 == vertexId) ? neighbor2 : neighbor1;

        if (vertices[neighborVertexId].getOwner() != -1)
        {
            return false;
        }
    }
    return true;
}

bool Board::buildSettlement(int playerId, int vertexId, bool start)
{
    if (vertexId < 0 || vertexId >= vertices.size())
    {
        std::cout << "Invalid vertex ID" << std::endl;
        return false;
    }

    if (vertices[vertexId].getOwner() != -1)
    {
        // std::cout << "Settlement is already built at this vertex" << std::endl;
        return false;
    }
    if (!start)
    {
        // Check if at least one road leads to the vertex
        bool hasConnectingRoad = false;
        for (const auto &edgeId : vertices[vertexId].getAdjacentEdges())
        {
            if (edges[edgeId].getOwner() == playerId)
            {
                hasConnectingRoad = true;
                break;
            }
        }

        if (!hasConnectingRoad)
        {
            std::cout << "No connecting road to build the settlement" << std::endl;
            return false;
        }

        // Check if the vertex is at least two road segments away from another settlement
        if (!isTwoRoadSegmentsAway(vertexId))
        {
            std::cout << "Vertex is too close to another settlement" << std::endl;
            return false;
        }
    }
    vertices[vertexId].setOwner(playerId);
    std::cout << "Settlement is ready" << std::endl;
    return true;
}

bool Board::buildRoad(int playerId, int edgeId)
{
    if (edgeId < 0 || edgeId >= edges.size())
    {
        std::cout << "Invalid edge ID" << std::endl;
        return false;
    }

    int vertex1 = edges[edgeId].getVertex1();
    int vertex2 = edges[edgeId].getVertex2();

    bool vertex1OwnedByPlayer = vertices[vertex1].getOwner() == playerId;
    bool vertex2OwnedByPlayer = vertices[vertex2].getOwner() == playerId;

    bool connectedToPlayerRoad = false;

    for (int adjacentEdgeId : vertices[vertex1].getAdjacentEdges())
    {
        if (edges[adjacentEdgeId].getOwner() == playerId)
        {
            connectedToPlayerRoad = true;
            break;
        }
    }

    if (!connectedToPlayerRoad)
    {
        for (int adjacentEdgeId : vertices[vertex2].getAdjacentEdges())
        {
            if (edges[adjacentEdgeId].getOwner() == playerId)
            {
                connectedToPlayerRoad = true;
                break;
            }
        }
    }

    if ((vertex1OwnedByPlayer || vertex2OwnedByPlayer || connectedToPlayerRoad) && edges[edgeId].getOwner() == -1)
    {
        edges[edgeId].setOwner(playerId);
        return true;
    }
    else
    {
        std::cout << "Failed to place road" << std::endl;
        return false;
    }
}

std::vector<ResourceType> Board::initializeSettlements(int player, int vertex_id)
{
    std::vector<ResourceType> resources;

    // Place settlement
    Vertex &vertex = vertices[vertex_id];

    if (buildSettlement(player, vertex_id, true))
    {
        // Distribute resources from adjacent tiles
        std::vector<int> adjacentTiles = vertex.getAdjacentTiles();
        for (int tileId : adjacentTiles)
        {
            Tile &tile = tiles[tileId];
            ResourceType resource = tile.getResource();
            resources.push_back(resource); // Collect the resource
        }
    }

    return resources;
}

void Board::distributeResources(int diceRoll, std::vector<Player> &players)
{
    for (const auto &tile : tiles)
    {
        if (tile.getNumber() == diceRoll)
        {
            for (const auto &vertex : tile.getVertices())
            {
                int owner = vertex->getOwner();
                if (owner != -1)
                {
                    for (auto &player : players)
                    {
                        if (player.getPlayerId() == owner)
                        {
                            player.addResource(tile.getResource(), vertex->isCity() ? 2 : 1);
                            std::cout << "Player " << player.getName() << " received "
                                      << (vertex->isCity() ? 2 : 1) << " "
                                      << resourceTypeToString(tile.getResource())
                                      << " from tile " << tile.getNumber() << "." << std::endl;
                        }
                    }
                }
            }
        }
    }
}

bool Board::buildCity(int playerId, int vertexId)
{
    if (vertexId < 0 || vertexId >= vertices.size())
    {
        std::cout << "Invalid vertex ID" << std::endl;
        return false;
    }

    if (vertices[vertexId].getOwner() == playerId && vertices[vertexId].isCity() == false)
    {
        vertices[vertexId].upgradeToCity();
        // std::cout << "City built successfully" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Failed to build city" << std::endl;
        return false;
    }
}
void Board::initializePlayerSettlementsAndRoads(Player &player, int settlement1, int road1, int settlement2, int road2)
{
    auto collectResources = [&player](std::vector<ResourceType> resources)
    {
        std::set<ResourceType> uniqueResources;
        for (const auto &resource : resources)
        {
            if (uniqueResources.find(resource) == uniqueResources.end() && player.getResourceCount(resource) == 0)
            {
                player.addResource(resource, 1);
                uniqueResources.insert(resource);
            }
        }
    };

    std::vector<ResourceType> resources1 = initializeSettlements(player.getPlayerId(), settlement1);
    collectResources(resources1);
    player.addSettlement(settlement1);
    if (buildRoad(player.getPlayerId(), road1))
    {
        player.addRoad(road1);
    }

    std::vector<ResourceType> resources2 = initializeSettlements(player.getPlayerId(), settlement2);
    collectResources(resources2);
    player.addSettlement(settlement2);
    if (buildRoad(player.getPlayerId(), road2))
    {
        player.addRoad(road2);
        player.addVictoryPoint(2);
    }

    player.printStatus();
    std::cout << "-----------------------------------\n";
}
