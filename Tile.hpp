// tile.hpp
#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

enum class ResourceType
{
    Wood,
    Brick,
    Wool,
    Oat,
    Iron,
    None
};

class Tile
{
public:
    Tile(ResourceType resource, int number);

    ResourceType getResource() const;
    int getNumber() const;
    std::vector<int> getVertices() const;
    std::vector<int> getEdges() const;

    void addVertex(int vertexIndex);
    void addEdge(int edgeIndex);

private:
    ResourceType resource;
    int number;
    std::vector<int> vertices;
    std::vector<int> edges;
};

#endif // TILE_HPP
