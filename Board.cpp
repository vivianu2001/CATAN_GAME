// board.cpp
#include "Board.hpp"
#include <iostream>

Board::Board()
{
    // initializeBoard();
}

void Board::initializeBoard()
{
    // std::vector<Vertex> vertices;
    vertices.reserve(54);
    for (int i = 0; i < 54; ++i)
    {
        vertices.emplace_back(i);
    }

    // std::vector<Edge> edges;
    edges.reserve(71);
    for (int i = 0; i < 71; ++i)
    {
        edges.emplace_back(i);
    }

    // Example initialization of 19 tiles with resources and numbers
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

    tiles[0].addVertex(&vertices[0]);
    vertices[0].setEdges(&edges[0], &edges[1]);
    edges[0].setVertices(&vertices[0], &vertices[4]);
    edges[1].setVertices(&vertices[0], &vertices[1]);

    tiles[0].addVertex(&vertices[1]);
    vertices[1].setEdges(&edges[1], &edges[2]);

    tiles[0].addVertex(&vertices[2]);
    tiles[0].addVertex(&vertices[3]);
    tiles[0].addVertex(&vertices[4]);
    tiles[0].addVertex(&vertices[5]);

    tiles[0].addEdge(&edges[0]);
    tiles[0].addEdge(&edges[1]);
    tiles[0].addEdge(&edges[2]);
    tiles[0].addEdge(&edges[3]);
    tiles[0].addEdge(&edges[4]);
    tiles[0].addEdge(&edges[5]);

    tiles[1].addVertex(&vertices[2]);
    tiles[1].addVertex(&vertices[3]);
    tiles[1].addVertex(&vertices[6]);
    tiles[1].addVertex(&vertices[7]);
    tiles[1].addVertex(&vertices[8]);
    tiles[1].addVertex(&vertices[9]);
    tiles[1].addEdge(&edges[5]);
    tiles[1].addEdge(&edges[6]);
    tiles[1].addEdge(&edges[7]);
    tiles[1].addEdge(&edges[8]);
    tiles[1].addEdge(&edges[9]);
    tiles[1].addEdge(&edges[10]);

    tiles[2].addVertex(&vertices[7]);
    tiles[2].addVertex(&vertices[8]);
    tiles[2].addVertex(&vertices[10]);
    tiles[2].addVertex(&vertices[11]);
    tiles[2].addVertex(&vertices[12]);
    tiles[2].addVertex(&vertices[13]);
    tiles[2].addEdge(&edges[8]);
    tiles[2].addEdge(&edges[11]);
    tiles[2].addEdge(&edges[12]);
    tiles[2].addEdge(&edges[13]);
    tiles[2].addEdge(&edges[14]);
    tiles[2].addEdge(&edges[15]);

    tiles[3].addVertex(&vertices[4]);
    tiles[3].addVertex(&vertices[5]);
    tiles[3].addVertex(&vertices[14]);
    tiles[3].addVertex(&vertices[15]);
    tiles[3].addVertex(&vertices[16]);
    tiles[3].addVertex(&vertices[17]);

    tiles[3].addEdge(&edges[3]);
    tiles[3].addEdge(&edges[16]);
    tiles[3].addEdge(&edges[17]);
    tiles[3].addEdge(&edges[18]);
    tiles[3].addEdge(&edges[19]);
    tiles[3].addEdge(&edges[20]);

    tiles[4].addVertex(&vertices[3]);
    tiles[4].addVertex(&vertices[5]);
    tiles[4].addVertex(&vertices[9]);
    tiles[4].addVertex(&vertices[17]);
    tiles[4].addVertex(&vertices[18]);
    tiles[4].addVertex(&vertices[19]);

    tiles[4].addEdge(&edges[4]);
    tiles[4].addEdge(&edges[6]);
    tiles[4].addEdge(&edges[20]);
    tiles[4].addEdge(&edges[21]);
    tiles[4].addEdge(&edges[22]);
    tiles[4].addEdge(&edges[23]);

    tiles[5].addVertex(&vertices[8]);
    tiles[5].addVertex(&vertices[9]);
    tiles[5].addVertex(&vertices[13]);
    tiles[5].addVertex(&vertices[19]);
    tiles[5].addVertex(&vertices[20]);
    tiles[5].addVertex(&vertices[21]);

    tiles[5].addEdge(&edges[7]);
    tiles[5].addEdge(&edges[14]);
    tiles[5].addEdge(&edges[23]);
    tiles[5].addEdge(&edges[24]);
    tiles[5].addEdge(&edges[25]);
    tiles[5].addEdge(&edges[26]);

    tiles[6].addVertex(&vertices[12]);
    tiles[6].addVertex(&vertices[13]);
    tiles[6].addVertex(&vertices[21]);
    tiles[6].addVertex(&vertices[22]);
    tiles[6].addVertex(&vertices[23]);
    tiles[6].addVertex(&vertices[24]);
    tiles[6].addEdge(&edges[15]);
    tiles[6].addEdge(&edges[26]);
    tiles[6].addEdge(&edges[27]);
    tiles[6].addEdge(&edges[28]);
    tiles[6].addEdge(&edges[29]);
    tiles[6].addEdge(&edges[71]);

    tiles[7].addVertex(&vertices[15]);
    tiles[7].addVertex(&vertices[16]);
    tiles[7].addVertex(&vertices[25]);
    tiles[7].addVertex(&vertices[26]);
    tiles[7].addVertex(&vertices[27]);
    tiles[7].addVertex(&vertices[28]);
    tiles[7].addEdge(&edges[18]);
    tiles[7].addEdge(&edges[31]);
    tiles[7].addEdge(&edges[32]);
    tiles[7].addEdge(&edges[33]);
    tiles[7].addEdge(&edges[34]);
    tiles[7].addEdge(&edges[35]);

    tiles[8].addVertex(&vertices[16]);
    tiles[8].addVertex(&vertices[17]);
    tiles[8].addVertex(&vertices[18]);
    tiles[8].addVertex(&vertices[28]);
    tiles[8].addVertex(&vertices[29]);
    tiles[8].addVertex(&vertices[30]);
    tiles[8].addEdge(&edges[19]);
    tiles[8].addEdge(&edges[21]);
    tiles[8].addEdge(&edges[35]);
    tiles[8].addEdge(&edges[36]);
    tiles[8].addEdge(&edges[37]);
    tiles[8].addEdge(&edges[38]);

    tiles[9].addVertex(&vertices[18]);
    tiles[9].addVertex(&vertices[19]);
    tiles[9].addVertex(&vertices[20]);
    tiles[9].addVertex(&vertices[30]);
    tiles[9].addVertex(&vertices[31]);
    tiles[9].addVertex(&vertices[32]);
    tiles[9].addEdge(&edges[22]);
    tiles[9].addEdge(&edges[24]);
    tiles[9].addEdge(&edges[38]);
    tiles[9].addEdge(&edges[39]);
    tiles[9].addEdge(&edges[40]);
    tiles[9].addEdge(&edges[41]);

    tiles[10].addVertex(&vertices[20]);
    tiles[10].addVertex(&vertices[21]);
    tiles[10].addVertex(&vertices[22]);
    tiles[10].addVertex(&vertices[32]);
    tiles[10].addVertex(&vertices[33]);
    tiles[10].addVertex(&vertices[34]);
    tiles[10].addEdge(&edges[25]);
    tiles[10].addEdge(&edges[28]);
    tiles[10].addEdge(&edges[41]);
    tiles[10].addEdge(&edges[42]);
    tiles[10].addEdge(&edges[44]);
    tiles[10].addEdge(&edges[43]);

    tiles[11].addVertex(&vertices[22]);
    tiles[11].addVertex(&vertices[23]);
    tiles[11].addVertex(&vertices[34]);
    tiles[11].addVertex(&vertices[35]);
    tiles[11].addVertex(&vertices[36]);
    tiles[11].addVertex(&vertices[37]);
    tiles[11].addEdge(&edges[29]);
    tiles[11].addEdge(&edges[30]);
    tiles[11].addEdge(&edges[44]);
    tiles[11].addEdge(&edges[45]);
    tiles[11].addEdge(&edges[46]);
    tiles[11].addEdge(&edges[47]);

    tiles[12].addVertex(&vertices[27]);
    tiles[12].addVertex(&vertices[28]);
    tiles[12].addVertex(&vertices[29]);
    tiles[12].addVertex(&vertices[38]);
    tiles[12].addVertex(&vertices[39]);
    tiles[12].addVertex(&vertices[40]);
    tiles[12].addEdge(&edges[34]);
    tiles[12].addEdge(&edges[36]);
    tiles[12].addEdge(&edges[48]);
    tiles[12].addEdge(&edges[49]);
    tiles[12].addEdge(&edges[50]);
    tiles[12].addEdge(&edges[51]);

    tiles[13].addVertex(&vertices[29]);
    tiles[13].addVertex(&vertices[30]);
    tiles[13].addVertex(&vertices[31]);
    tiles[13].addVertex(&vertices[40]);
    tiles[13].addVertex(&vertices[41]);
    tiles[13].addVertex(&vertices[48]);
    tiles[13].addEdge(&edges[51]);
    tiles[13].addEdge(&edges[37]);
    tiles[13].addEdge(&edges[39]);
    tiles[13].addEdge(&edges[52]);
    tiles[13].addEdge(&edges[53]);
    tiles[13].addEdge(&edges[54]);

    tiles[14].addVertex(&vertices[31]);
    tiles[14].addVertex(&vertices[32]);
    tiles[14].addVertex(&vertices[33]);
    tiles[14].addVertex(&vertices[41]);
    tiles[14].addVertex(&vertices[42]);
    tiles[14].addVertex(&vertices[43]);
    tiles[14].addEdge(&edges[40]);
    tiles[14].addEdge(&edges[42]);
    tiles[14].addEdge(&edges[54]);
    tiles[14].addEdge(&edges[55]);
    tiles[14].addEdge(&edges[56]);
    tiles[14].addEdge(&edges[57]);

    tiles[15].addVertex(&vertices[33]);
    tiles[15].addVertex(&vertices[34]);
    tiles[15].addVertex(&vertices[35]);
    tiles[15].addVertex(&vertices[43]);
    tiles[15].addVertex(&vertices[44]);
    tiles[15].addVertex(&vertices[53]);
    tiles[15].addEdge(&edges[43]);
    tiles[15].addEdge(&edges[45]);
    tiles[15].addEdge(&edges[57]);
    tiles[15].addEdge(&edges[59]);
    tiles[15].addEdge(&edges[58]);
    tiles[15].addEdge(&edges[60]);

    tiles[16].addVertex(&vertices[39]);
    tiles[16].addVertex(&vertices[40]);
    tiles[16].addVertex(&vertices[48]);
    tiles[16].addVertex(&vertices[45]);
    tiles[16].addVertex(&vertices[46]);
    tiles[16].addVertex(&vertices[47]);
    tiles[16].addEdge(&edges[50]);
    tiles[16].addEdge(&edges[52]);
    tiles[16].addEdge(&edges[61]);
    tiles[16].addEdge(&edges[62]);
    tiles[16].addEdge(&edges[63]);
    tiles[16].addEdge(&edges[64]);

    tiles[17].addVertex(&vertices[48]);
    tiles[17].addVertex(&vertices[41]);
    tiles[17].addVertex(&vertices[42]);
    tiles[17].addVertex(&vertices[47]);
    tiles[17].addVertex(&vertices[50]);
    tiles[17].addVertex(&vertices[49]);
    tiles[17].addEdge(&edges[53]);
    tiles[17].addEdge(&edges[55]);
    tiles[17].addEdge(&edges[64]);
    tiles[17].addEdge(&edges[65]);
    tiles[17].addEdge(&edges[66]);
    tiles[17].addEdge(&edges[67]);

    tiles[18].addVertex(&vertices[42]);
    tiles[18].addVertex(&vertices[43]);
    tiles[18].addVertex(&vertices[50]);
    tiles[18].addVertex(&vertices[51]);
    tiles[18].addVertex(&vertices[52]);
    tiles[18].addVertex(&vertices[53]);
    tiles[18].addEdge(&edges[56]);
    tiles[18].addEdge(&edges[59]);
    tiles[18].addEdge(&edges[67]);
    tiles[18].addEdge(&edges[68]);
    tiles[18].addEdge(&edges[69]);
    tiles[18].addEdge(&edges[70]);
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