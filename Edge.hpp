#pragma once

class Edge
{
public:
    Edge(int id); // Constructor for the edge.

    bool hasRoad() const;         // Returns true if there is a road on this edge.
    void buildRoad(int playerId); // Builds a road on this edge and assigns it to a player.
    int getOwner() const;         // Returns the ID of the player who owns the road on this edge.
    int getId() const;

private:
    int id;
    bool road = false;      // True if there is a road on the edge.
    int ownerPlayerId = -1; // ID of the player who owns the road, -1 if no owner.
};
