
#ifndef TILE_HPP
#define TILE_HPP

#include <string>

class Tile {
public:
    enum Terrain {
        FIELDS,
        FORESTS,
        MOUNTAINS,
        HILLS,
        PASTURES,
        DESERT
    };

    Tile(Terrain terrain, int number);

    Terrain getTerrain() const;
    int getNumber() const;

private:
    Terrain terrain;
    int number;
};

#endif 