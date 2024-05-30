#include "Board.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

Board::Board()
{
    initializeBoard();
    if (!font.loadFromFile("SociollaRegular-5yayL.ttf"))
    { // Ensure the path is correct
        std::cerr << "Failed to load font" << std::endl;
    }
    createHexShapes();
}

void Board::initializeBoard()
{
    tiles = {
        {Tile(Tile::MOUNTAINS, 10), Tile(Tile::PASTURES, 2), Tile(Tile::FORESTS, 9),
         Tile(Tile::FIELDS, 12), Tile(Tile::HILLS, 6),
         Tile(Tile::PASTURES, 4), Tile(Tile::HILLS, 10), 
         Tile(Tile::FIELDS, 9), Tile(Tile::FORESTS, 11), Tile(Tile::DESERT, 0),
         Tile(Tile::FORESTS, 3), Tile(Tile::MOUNTAINS, 8), Tile(Tile::FORESTS,8), Tile(Tile::MOUNTAINS, 3), Tile(Tile::FIELDS, 4),
         Tile(Tile::PASTURES, 5), Tile(Tile::HILLS, 5), Tile(Tile::FIELDS, 6), Tile(Tile::PASTURES, 11)}};
}

std::string Board::getTerrainString(const Tile &tile) const
{
    std::string terrain;
    switch (tile.getTerrain())
    {
    case Tile::FIELDS:
        terrain = "F(" + std::to_string(tile.getNumber()) + ")";
        break;
    case Tile::FORESTS:
        terrain = "Fo(" + std::to_string(tile.getNumber()) + ")";
        break;
    case Tile::MOUNTAINS:
        terrain = "M(" + std::to_string(tile.getNumber()) + ")";
        break;
    case Tile::HILLS:
        terrain = "H(" + std::to_string(tile.getNumber()) + ")";
        break;
    case Tile::PASTURES:
        terrain = "P(" + std::to_string(tile.getNumber()) + ")";
        break;
    case Tile::DESERT:
        terrain = "D(" + std::to_string(tile.getNumber()) + ")";
        break;
    }
    return terrain;
}

sf::Color Board::getTerrainColor(const Tile &tile) const
{
    switch (tile.getTerrain())
    {
    case Tile::FIELDS:
        return sf::Color::Yellow;
    case Tile::FORESTS:
        return sf::Color::Green;
    case Tile::MOUNTAINS:
        return sf::Color(139, 69, 19);
    case Tile::HILLS:
        return sf::Color(165, 42, 42);
    case Tile::PASTURES:
        return sf::Color::Cyan;
    case Tile::DESERT:
        return sf::Color(210, 180, 140);
    default:
        return sf::Color::White;
    }
}
void Board::createHexShapes()
{
    float hexSize = 50.0f;
    float xOffset = hexSize * 1.5f;
    float yOffset = hexSize * std::sqrt(3) / 2;
    int tileIndex = 0;

    sf::Vector2f startPosition(200.0f, 100.0f); // Center the grid on the screen

    // Calculate the hexagon positions
    std::vector<sf::Vector2f> positions = {
        startPosition + sf::Vector2f(1 * xOffset, 0 * yOffset),    // Hexagon 0
        startPosition + sf::Vector2f(2.15 * xOffset, 0 * yOffset), // Hexagon 1
        startPosition + sf::Vector2f(3.37 * xOffset, 0 * yOffset), // Hexagon 2

        startPosition + sf::Vector2f(0.40 * xOffset, 1.8 * yOffset),  // Hexagon 3
        startPosition + sf::Vector2f(1.54 * xOffset, 1.79 * yOffset), // Hexagon 4
        startPosition + sf::Vector2f(2.75 * xOffset, 1.79 * yOffset), // Hexagon 5
        startPosition + sf::Vector2f(3.95 * xOffset, 1.79 * yOffset), // Hexagon 6

        sf::Vector2f(2.5 * xOffset, 6 * yOffset),                     // Hexagon 7
        startPosition + sf::Vector2f(0.95 * xOffset, 3.6 * yOffset),  // Hexagon 8
        startPosition + sf::Vector2f(2.15 * xOffset, 3.58 * yOffset), // Hexagon 9
        startPosition + sf::Vector2f(3.35 * xOffset, 3.6 * yOffset),
        startPosition + sf::Vector2f(4.5 * xOffset, 3.6 * yOffset),

        startPosition + sf::Vector2f(0.37 * xOffset, 5.4 * yOffset),
        startPosition + sf::Vector2f(1.56* xOffset, 5.4 * yOffset),

        startPosition + sf::Vector2f(2.74 * xOffset, 5.4 * yOffset),
        
        startPosition + sf::Vector2f(3.9* xOffset, 5.4 * yOffset),

        startPosition + sf::Vector2f(1 * xOffset, 7.1* yOffset),
        startPosition + sf::Vector2f(2.15 * xOffset, 7.1 * yOffset),
        startPosition + sf::Vector2f(3.3* xOffset, 7.1 * yOffset),
        // startPosition + sf::Vector2f(2.5f * xOffset, 5 * yOffset),
        // startPosition + sf::Vector2f(3.5f * xOffset, 5 * yOffset),
        // startPosition + sf::Vector2f(1 * xOffset, 6 * yOffset),
        // startPosition + sf::Vector2f(2 * xOffset, 6 * yOffset),
        // startPosition + sf::Vector2f(3 * xOffset, 6 * yOffset),
        // startPosition + sf::Vector2f(1.5f * xOffset, 7 * yOffset), s
        // startPosition + sf::Vector2f(2.5f * xOffset, 7 * yOffset),
        // startPosition + sf::Vector2f(2 * xOffset, 8 * yOffset),
    };

    for (const auto &position : positions)
    {
        float x = position.x;
        float y = position.y;

        sf::ConvexShape hex;
        hex.setPointCount(6);
        hex.setPoint(0, sf::Vector2f(0.0f, -hexSize));
        hex.setPoint(1, sf::Vector2f(hexSize * std::sqrt(3) / 2, -hexSize / 2));
        hex.setPoint(2, sf::Vector2f(hexSize * std::sqrt(3) / 2, hexSize / 2));
        hex.setPoint(3, sf::Vector2f(0.0f, hexSize));
        hex.setPoint(4, sf::Vector2f(-hexSize * std::sqrt(3) / 2, hexSize / 2));
        hex.setPoint(5, sf::Vector2f(-hexSize * std::sqrt(3) / 2, -hexSize / 2));
        hex.setPosition(x, y);
        hex.setFillColor(getTerrainColor(tiles[tileIndex]));
        hex.setOutlineThickness(2);
        hex.setOutlineColor(sf::Color::Black);
        hexShapes.push_back(hex);

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(tiles[tileIndex].getNumber()));
        text.setCharacterSize(18); // Adjust font size to fit within hexagon
        text.setFillColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(hex.getPosition().x, hex.getPosition().y); // Center text in hexagon
        hexTexts.push_back(text);

        tileIndex++;
    }
}

void Board::draw(sf::RenderWindow &window)
{
    for (const auto &hex : hexShapes)
    {
        window.draw(hex);
    }
    for (const auto &text : hexTexts)
    {
        window.draw(text);
    }
}