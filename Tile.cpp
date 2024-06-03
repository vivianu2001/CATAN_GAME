#include "Tile.hpp"

Tile::Tile(ResourceType resource, int number) : resource(resource), number(number) {}

void Tile::addVertex(Vertex *vertex)
{
    vertices.push_back(vertex);
}

void Tile::addEdge(Edge *edge)
{
    edges.push_back(edge);
}

const std::vector<Vertex *> &Tile::getVertices() const
{
    return vertices;
}

const std::vector<Edge *> &Tile::getEdges() const
{
    return edges;
}
ResourceType Tile::getResource() const
{
    return resource; // Add this line
}
