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
