#include "Edge.hpp"

Edge::Edge(int id) : id(id), road(false), ownerPlayerId(-1) {} // Initialize members to default values.

bool Edge::hasRoad() const
{
    return road; // Return whether there is a road on this edge.
}

void Edge::buildRoad(int playerId)
{
    road = true;              // Mark the edge as having a road.
    ownerPlayerId = playerId; // Assign the road to the given player.
}

int Edge::getOwner() const
{
    return ownerPlayerId; // Return the ID of the player who owns the road.
}

int Edge::getId() const
{
    return id;
}
