#include "Edge.hpp"

Edge::Edge(int id) : id(id), road(false), ownerPlayerId(-1) {} // Initialize members to default values.

bool Edge::hasRoad() const
{
    return road; // Return whether there is a road on this edge.
}

int Edge::getOwner() const
{
    return ownerPlayerId; // Return the ID of the player who owns the road.
}

int Edge::getId() const
{
    return id;
}
void Edge::setVertices(Vertex *v1, Vertex *v2)
{
    vertex1 = v1;
    vertex2 = v2;
}

int Edge::getVertex1() const
{
    return vertex1 ? vertex1->getId() : -1; // Check for nullptr before dereferencing
}

int Edge::getVertex2() const
{
    return vertex2 ? vertex2->getId() : -1; // Check for nullptr before dereferencing
}

void Edge::setOwner(int owner)
{
    ownerPlayerId = owner;
    road = true;
}