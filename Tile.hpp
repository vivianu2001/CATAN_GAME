#ifndef TILE_HPP
#define TILE_HPP

#include "Resource.hpp"

class Tile
{
public:
    enum Terrain
    {
        FIELDS,
        FORESTS,
        MOUNTAINS,
        HILLS,
        PASTURES,
        DESERT
    };

    Tile(Terrain terrain, int number); // Declare the constructor

    Terrain getTerrain() const; // Declare getTerrain method
    int getNumber() const; // Declare getNumber method

    Resource::Type getResource() const
    {
        switch (terrain)
        {
        case FIELDS:
            return Resource::GRAIN;
        case FORESTS:
            return Resource::WOOD;
        case MOUNTAINS:
            return Resource::ORE;
        case HILLS:
            return Resource::BRICK;
        case PASTURES:
            return Resource::WOOL;
        case DESERT:
        default:
            return Resource::NONE;
        }
    }

private:
    Terrain terrain;
    int number;
};

#endif // TILE_HPP
