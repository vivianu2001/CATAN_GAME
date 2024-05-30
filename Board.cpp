// board.cpp
#include "Board.hpp"

// Helper function to add a tile
void addTile(std::vector<std::shared_ptr<Tile>> &tiles, ResourceType resource, int number)
{
    tiles.push_back(std::make_shared<Tile>(resource, number));
}

Board::Board()
{
    initializeBoard();
}

void Board::initializeBoard()
{
    // Example initialization of 19 tiles with resources and numbers
    tiles.emplace_back(ResourceType::Iron, 10);
    tiles.emplace_back(ResourceType::Wool, 2);
    tiles.emplace_back(ResourceType::Wood, 9);
    tiles.emplace_back(ResourceType::Oat, 12);
    tiles.emplace_back(ResourceType::Brick, 6);
    tiles.emplace_back(ResourceType::Wool, 4);
    tiles.emplace_back(ResourceType::Brick, 10);
    tiles.emplace_back(ResourceType::Oat, 9);
    tiles.emplace_back(ResourceType::Wood, 11);
    tiles.emplace_back(ResourceType::None, 0); // Desert
    tiles.emplace_back(ResourceType::Wood, 3);
    tiles.emplace_back(ResourceType::Iron, 8);
    tiles.emplace_back(ResourceType::Wood, 8);
    tiles.emplace_back(ResourceType::Iron, 3);
    tiles.emplace_back(ResourceType::Oat, 4);
    tiles.emplace_back(ResourceType::Wool, 5);
    tiles.emplace_back(ResourceType::Brick, 5);
    tiles.emplace_back(ResourceType::Oat, 6);
    tiles.emplace_back(ResourceType::Wool, 11);

    // Initialize vertices and edges
    for (int i = 0; i < 53; ++i)
    {
        vertices.emplace_back();
    }
    for (int i = 0; i < 71; ++i)
    {
        edges.emplace_back();
    }

    // Define the vertex and edge indices for each tile
    std::vector<std::vector<int>> tileVertices = {
        {0, 1, 2, 7, 6, 13},
        {2, 3, 4, 9, 8, 15},
        {4, 5, 6, 11, 10, 17},
        {6, 7, 8, 13, 12, 19},
        {8, 9, 10, 15, 14, 21},
        {10, 11, 12, 17, 16, 23},
        {12, 13, 14, 19, 18, 25},
        {14, 15, 16, 21, 20, 27},
        {16, 17, 18, 23, 22, 29},
        {18, 19, 20, 25, 24, 31},
        {20, 21, 22, 27, 26, 33},
        {22, 23, 24, 29, 28, 35},
        {24, 25, 26, 31, 30, 37},
        {26, 27, 28, 33, 32, 39},
        {28, 29, 30, 35, 34, 41},
        {30, 31, 32, 37, 36, 43},
        {32, 33, 34, 39, 38, 45},
        {34, 35, 36, 41, 40, 47},
        {36, 37, 38, 43, 42, 49, 50, 51, 52, 53}};

    std::vector<std::vector<int>> tileEdges = {
        {0, 1, 2, 3, 4, 5},
        {2, 6, 7, 8, 9, 10},
        {7, 11, 12, 13, 14, 15},
        {12, 16, 17, 18, 19, 20},
        {17, 21, 22, 23, 24, 25},
        {22, 26, 27, 28, 29, 30},
        {27, 31, 32, 33, 34, 35},
        {32, 36, 37, 38, 39, 40},
        {37, 41, 42, 43, 44, 45},
        {42, 46, 47, 48, 49, 50},
        {47, 51, 52, 53, 54, 55},
        {52, 56, 57, 58, 59, 60},
        {57, 61, 62, 63, 64, 65},
        {62, 66, 67, 68, 69, 70},
        {67, 71, 72, 73, 74, 75},
        {72, 76, 77, 78, 79, 80},
        {77, 81, 82, 83, 84, 85},
        {82, 86, 87, 88, 89, 90},
        {87, 91, 92, 93, 94, 95}};

    tiles[0].addVertex(0);
    tiles[0].addVertex(1);
    tiles[0].addVertex(2);
    tiles[0].addVertex(3);
    tiles[0].addVertex(4);
    tiles[0].addVertex(5);

    tiles[0].addEdge(0);
    tiles[0].addEdge(1);
    tiles[0].addEdge(2);
    tiles[0].addEdge(3);
    tiles[0].addEdge(4);
    tiles[0].addEdge(5);

    tiles[1].addVertex(2);
    tiles[1].addVertex(3);
    tiles[1].addVertex(6);
    tiles[1].addVertex(7);
    tiles[1].addVertex(8);
    tiles[1].addVertex(9);
    tiles[1].addEdge(5);
    tiles[1].addEdge(6);
    tiles[1].addEdge(7);
    tiles[1].addEdge(8);
    tiles[1].addEdge(9);
    tiles[1].addEdge(10);

    tiles[2].addVertex(7);
    tiles[2].addVertex(8);
    tiles[2].addVertex(10);
    tiles[2].addVertex(11);
    tiles[2].addVertex(12);
    tiles[2].addVertex(13);
    tiles[2].addEdge(8);
    tiles[2].addEdge(11);
    tiles[2].addEdge(12);
    tiles[2].addEdge(13);
    tiles[2].addEdge(14);
    tiles[2].addEdge(15);

    tiles[3].addVertex(4);
    tiles[3].addVertex(5);
    tiles[3].addVertex(14);
    tiles[3].addVertex(15);
    tiles[3].addVertex(16);
    tiles[3].addVertex(17);

    tiles[3].addEdge(3);
    tiles[3].addEdge(16);
    tiles[3].addEdge(17);
    tiles[3].addEdge(18);
    tiles[3].addEdge(19);
    tiles[3].addEdge(20);

    tiles[4].addVertex(3);
    tiles[4].addVertex(5);
    tiles[4].addVertex(9);
    tiles[4].addVertex(17);
    tiles[4].addVertex(18);
    tiles[4].addVertex(19);

    tiles[4].addEdge(4);
    tiles[4].addEdge(6);
    tiles[4].addEdge(20);
    tiles[4].addEdge(21);
    tiles[4].addEdge(22);
    tiles[4].addEdge(23);

    tiles[5].addVertex(8);
    tiles[5].addVertex(9);
    tiles[5].addVertex(13);
    tiles[5].addVertex(19);
    tiles[5].addVertex(20);
    tiles[5].addVertex(21);

    tiles[5].addEdge(7);
    tiles[5].addEdge(14);
    tiles[5].addEdge(23);
    tiles[5].addEdge(24);
    tiles[5].addEdge(25);
    tiles[5].addEdge(26);

    tiles[6].addVertex(12);
    tiles[6].addVertex(13);
    tiles[6].addVertex(21);
    tiles[6].addVertex(22);
    tiles[6].addVertex(23);
    tiles[6].addVertex(24);
    tiles[6].addEdge(15);
    tiles[6].addEdge(26);
    tiles[6].addEdge(27);
    tiles[6].addEdge(28);
    tiles[6].addEdge(29);
    tiles[6].addEdge(71);

    tiles[7].addVertex(15);
    tiles[7].addVertex(16);
    tiles[7].addVertex(25);
    tiles[7].addVertex(26);
    tiles[7].addVertex(27);
    tiles[7].addVertex(28);
    tiles[7].addEdge(18);
    tiles[7].addEdge(31);
    tiles[7].addEdge(32);
    tiles[7].addEdge(33);
    tiles[7].addEdge(34);
    tiles[7].addEdge(35);

    tiles[8].addVertex(16);
    tiles[8].addVertex(17);
    tiles[8].addVertex(18);
    tiles[8].addVertex(28);
    tiles[8].addVertex(29);
    tiles[8].addVertex(30);
    tiles[8].addEdge(19);
    tiles[8].addEdge(21);
    tiles[8].addEdge(35);
    tiles[8].addEdge(36);
    tiles[8].addEdge(37);
    tiles[8].addEdge(38);

    tiles[9].addVertex(18);
    tiles[9].addVertex(19);
    tiles[9].addVertex(20);
    tiles[9].addVertex(30);
    tiles[9].addVertex(31);
    tiles[9].addVertex(32);
    tiles[9].addEdge(22);
    tiles[9].addEdge(24);
    tiles[9].addEdge(38);
    tiles[9].addEdge(39);
    tiles[9].addEdge(40);
    tiles[9].addEdge(41);

    tiles[10].addVertex(20);
    tiles[10].addVertex(21);
    tiles[10].addVertex(22);
    tiles[10].addVertex(32);
    tiles[10].addVertex(33);
    tiles[10].addVertex(34);
    tiles[10].addEdge(25);
    tiles[10].addEdge(28);
    tiles[10].addEdge(41);
    tiles[10].addEdge(42);
    tiles[10].addEdge(44);
    tiles[10].addEdge(43);

    tiles[11].addVertex(22);
    tiles[11].addVertex(23);
    tiles[11].addVertex(34);
    tiles[11].addVertex(35);
    tiles[11].addVertex(36);
    tiles[11].addVertex(37);
    tiles[11].addEdge(29);
    tiles[11].addEdge(30);
    tiles[11].addEdge(44);
    tiles[11].addEdge(45);
    tiles[11].addEdge(46);
    tiles[11].addEdge(47);

    tiles[12].addVertex(27);
    tiles[12].addVertex(28);
    tiles[12].addVertex(29);
    tiles[12].addVertex(38);
    tiles[12].addVertex(39);
    tiles[12].addVertex(40);
    tiles[12].addEdge(34);
    tiles[12].addEdge(36);
    tiles[12].addEdge(48);
    tiles[12].addEdge(49);
    tiles[12].addEdge(50);
    tiles[12].addEdge(51);

    tiles[13].addVertex(29);
    tiles[13].addVertex(30);
    tiles[13].addVertex(31);
    tiles[13].addVertex(40);
    tiles[13].addVertex(41);
    tiles[13].addVertex(48);
    tiles[13].addEdge(51);
    tiles[13].addEdge(37);
    tiles[13].addEdge(39);
    tiles[13].addEdge(52);
    tiles[13].addEdge(53);
    tiles[13].addEdge(54);

    tiles[14].addVertex(31);
    tiles[14].addVertex(32);
    tiles[14].addVertex(33);
    tiles[14].addVertex(41);
    tiles[14].addVertex(42);
    tiles[14].addVertex(43);
    tiles[14].addEdge(40);
    tiles[14].addEdge(42);
    tiles[14].addEdge(54);
    tiles[14].addEdge(55);
    tiles[14].addEdge(56);
    tiles[14].addEdge(57);

    tiles[15].addVertex(33);
    tiles[15].addVertex(34);
    tiles[15].addVertex(35);
    tiles[15].addVertex(43);
    tiles[15].addVertex(44);
    tiles[15].addVertex(53);
    tiles[15].addEdge(43);
    tiles[15].addEdge(45);
    tiles[15].addEdge(57);
    tiles[15].addEdge(59);
    tiles[15].addEdge(58);
    tiles[15].addEdge(60);

    tiles[16].addVertex(39);
    tiles[16].addVertex(40);
    tiles[16].addVertex(48);
    tiles[16].addVertex(45);
    tiles[16].addVertex(46);
    tiles[16].addVertex(47);
    tiles[16].addEdge(50);
    tiles[16].addEdge(52);
    tiles[16].addEdge(61);
    tiles[16].addEdge(62);
    tiles[16].addEdge(63);
    tiles[16].addEdge(64);

    tiles[17].addVertex(48);
    tiles[17].addVertex(41);
    tiles[17].addVertex(42);
    tiles[17].addVertex(47);
    tiles[17].addVertex(50);
    tiles[17].addVertex(49);
    tiles[17].addEdge(53);
    tiles[17].addEdge(55);
    tiles[17].addEdge(64);
    tiles[17].addEdge(65);
    tiles[17].addEdge(66);
    tiles[17].addEdge(67);

    tiles[18].addVertex(42);
    tiles[18].addVertex(43);
    tiles[18].addVertex(50);
    tiles[18].addVertex(51);
    tiles[18].addVertex(52);
    tiles[18].addVertex(53);
    tiles[18].addEdge(56);
    tiles[18].addEdge(59);
    tiles[18].addEdge(67);
    tiles[18].addEdge(68);
    tiles[18].addEdge(69);
    tiles[18].addEdge(70);
}

std::vector<Tile> Board::getTiles() const
{
    return tiles;
}

std::vector<Vertex> Board::getVertices() const
{
    return vertices;
}

std::vector<Edge> Board::getEdges() const
{
    return edges;
}