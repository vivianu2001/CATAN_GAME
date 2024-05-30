#include "Tile.hpp"

Tile::Tile(ResourceType resource, int number)
    : resource(resource), number(number) {}

ResourceType Tile::getResource() const
{
    return resource;
}

int Tile::getNumber() const
{
    return number;
}

std::vector<int> Tile::getVertices() const
{
    return vertices;
}

std::vector<int> Tile::getEdges() const
{
    return edges;
}

void Tile::addVertex(int vertexIndex)
{
    vertices.push_back(vertexIndex);
}

void Tile::addEdge(int edgeIndex)
{
    edges.push_back(edgeIndex);
}
