#include "Vertex.hpp"

Vertex::Vertex(int id) : id(id), occupied(false), ownerPlayerId(-1) {}

// Returns true if there is a building on the vertex
bool Vertex::isOccupied() const
{
    return buildingType != BuildingType::None;
}

// Settle a vertex with a building
void Vertex::build(BuildingType type, int playerId)
{
    occupied = true;
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

void Vertex::setEdge_1(Edge *e1)
{

    edge1 = e1;
}
void Vertex::setEdge_2(Edge *e2)
{

    edge2 = e2;
}
void Vertex::setOwner(int id)
{
    ownerPlayerId = id;
    buildingType = Settlement;
}
int Vertex::getEdge1() const
{
    if (edge1 != NULL)
    {
        return edge1->getId();
    }
    else
    {
        return -1;
    }
}
int Vertex::getEdge2() const
{
    if (edge2 != NULL)
    {
        return edge2->getId();
    }
    else
    {
        return -1;
    }
}
std::vector<int> Vertex::getAdjacentTiles() const
{
    return adjacentTiles;
}

void Vertex::addAdjacentTile(int tileId)
{
    adjacentTiles.push_back(tileId);
}