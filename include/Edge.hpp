//umanskyvivian@gmail.com
#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include "Player.hpp"
#include "Vertex.hpp"

// Forward declaration of Vertex class
class Vertex;

class Edge
{
public:
    Edge(int id); // Constructor for the edge.

    bool hasRoad() const; // Returns true if there is a road on this edge.
    int getOwner() const; // Returns the ID of the player who owns the road on this edge.
    int getId() const;
    void setVertices(Vertex *v1, Vertex *v2);
    int getVertex1() const;
    int getVertex2() const;
    void setOwner(int id);

private:
    int id;
    bool road = false;      // True if there is a road on the edge.
    int ownerPlayerId = -1; // ID of the player who owns the road, -1 if no owner.
    Vertex *vertex1;
    Vertex *vertex2;
};
#endif // EDGE_HPP