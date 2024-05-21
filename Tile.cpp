#include "Tile.hpp"

Tile::Tile(Terrain terrain, int number)
    : terrain(terrain), number(number) {}

Tile::Terrain Tile::getTerrain() const {
    return terrain;
}

int Tile::getNumber() const {
    return number;
}