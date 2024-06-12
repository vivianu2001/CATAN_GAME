//umanskyvivian@gmail.com
#include "Vertex.hpp"

Vertex::Vertex(int id) : id(id), ownerPlayerId(-1) {}

// Settle a vertex with a building
void Vertex::build(BuildingType type, int playerId)
{

    buildingType = type;
    ownerPlayerId = playerId;
}
void Vertex::upgradeToCity()
{
    if (ownerPlayerId != -1) // Ensure the vertex has an owner before upgrading
    {
        buildingType = City;
    }
}

bool Vertex::isCity() const
{
    if (buildingType == City)
    {
        return true;
    }
    return false;
}
int Vertex::getId() const
{
    return id;
}

// Get the building type on this vertex
Vertex::BuildingType Vertex::getBuildingType() const
{
    return buildingType;
}

// Get the ID of the player who owns this vertex
int Vertex::getOwner() const
{
    return ownerPlayerId;
}

void Vertex::setOwner(int id)
{
    ownerPlayerId = id;
    buildingType = Settlement;
}

std::vector<int> Vertex::getAdjacentTiles() const
{
    return adjacentTiles;
}

void Vertex::addAdjacentTile(int tileId)
{
    adjacentTiles.push_back(tileId);
}
void Vertex::addEdge(Edge *edge)
{
    if (edge)
    {
        adjacentEdges.push_back(edge->getId());
    }
}

const std::vector<int> &Vertex::getAdjacentEdges() const
{
    return adjacentEdges;
}