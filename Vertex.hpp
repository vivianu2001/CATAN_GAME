#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "Player.hpp"
#include "Edge.hpp"
#include "Enums.hpp"

// Forward declaration of Edge class
class Edge;
class Vertex
{
public:
    // Enum to represent the type of building on the vertex
    enum BuildingType
    {
        None,
        Settlement,
        City
    };

    // Constructor that initializes the vertex with a unique ID
    Vertex(int id);

    // Check if the vertex is occupied by any building
    bool isOccupied() const;

    // Build a settlement or city on the vertex and assign it to a player
    void build(BuildingType type, int playerId);

    void upgradeToCity();

    bool isCity() const;

    // Get the unique ID of the vertex
    int getId() const;

    // Get the type of building on this vertex
    BuildingType getBuildingType() const;

    // Get the ID of the player who owns the building on this vertex
    int getOwner() const;
    int getEdge1() const;
    int getEdge2() const;

    void setEdge_1(Edge *e1);
    void setEdge_2(Edge *e1);
    void setOwner(int id);
    void addAdjacentTile(int tileId);
    std::vector<int> getAdjacentTiles() const;

private:
    int id;                                         // Unique identifier for the vertex
    bool occupied = false;                          // Flag to check if there is a building
    BuildingType buildingType = BuildingType::None; // Type of building on the vertex
    int ownerPlayerId = -1;
    Edge *edge1 = NULL;
    Edge *edge2 = NULL; // ID of the player who owns the building, -1 if no owner
    std::vector<int> adjacentTiles;
};
#endif // VERTEX_HPP