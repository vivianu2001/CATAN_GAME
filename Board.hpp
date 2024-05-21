#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Board {
public:
    Board();
    void initializeBoard();
    void draw(sf::RenderWindow& window);

private:
    std::vector<Tile> tiles;
    std::vector<sf::ConvexShape> hexShapes;
    std::vector<sf::Text> hexTexts;
    sf::Font font;

    std::string getTerrainString(const Tile& tile) const;
    sf::Color getTerrainColor(const Tile& tile) const;
    void createHexShapes();
};

#endif // BOARD_H
