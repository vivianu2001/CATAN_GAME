// board.cpp
#include "Board.hpp"
#include <iostream>
#include "BoardConfig.hpp"

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
        if (vertices[v1].getEdge1() == -1)
        {
            vertices[v1].setEdge_1(&edges[i]);
        }
        else
        {
            vertices[v1].setEdge_2(&edges[i]);
        }
        if (vertices[v2].getEdge1() == -1)
        {
            vertices[v2].setEdge_1(&edges[i]);
        }
        else
        {
            vertices[v2].setEdge_2(&edges[i]);
        }
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
bool Board::buildSettlement(int playerId, int vertexId)
{
    if (vertexId < 0 || vertexId >= vertices.size())
    {
        std::cout << "Invalid vertex ID" << std::endl;
        return false;
    }

    if (vertices[vertexId].getOwner() != -1)
    {
        std::cout << "Settlement is already " << std::endl;
        return false;
    }
    else
    {
        vertices[vertexId].setOwner(playerId);
        std::cout << "Settlement is ready " << std::endl;
        return true;
    }
}

bool Board::buildRoad(int playerId, int edgeId)
{
    int vertex1 = edges[edgeId].getVertex1();
    int vertex2 = edges[edgeId].getVertex2();

    if (edgeId < 0 || edgeId >= edges.size())
    {
        std::cout << "Invalid edge ID" << std::endl;
        return false;
    }

    if (vertices[vertex1].getOwner() == playerId || vertices[vertex2].getOwner() == playerId)
    {
        edges[edgeId].setOwner(playerId);
        std::cout << "Road placed successfully" << std::endl;
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

    if (buildSettlement(player, vertex_id))
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
