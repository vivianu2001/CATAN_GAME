#ifndef TILE_HPP
#define TILE_HPP

#include "ResourceType.hpp"

class Tile
{
public:
    ResourceType resource;
    int number;

    Tile(ResourceType res = ResourceType::None, int num = 0) : resource(res), number(num) {}
};

#endif // TILE_HPP
