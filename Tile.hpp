#pragma once
#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"

enum class ResourceType
{
    Iron,
    Wool,
    Wood,
    Oat,
    Brick,
    None
};

class Tile
{
public:
    Tile(ResourceType resource, int number);

    void addVertex(Vertex *vertex);
    void addEdge(Edge *edge);

    const std::vector<Vertex *> &getVertices() const;
    const std::vector<Edge *> &getEdges() const;

private:
    ResourceType resource;
    int number;
    std::vector<Vertex *> vertices;
    std::vector<Edge *> edges;
};
