#ifndef HEX_HPP
#define HEX_HPP

#include <string>
#include <vector>

// Define the structure for a Hexagon tile
struct Hex
{
    std::string resource;
    int number;
    Hex(std::string res, int num) : resource(res), number(num) {}
};

#endif // HEX_HPP
