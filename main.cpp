#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Catan.hpp"
#include "Board.hpp"

int main()
{
    // std::string name;
    // std::cout << "Enter name for player 1: ";
    // std::getline(std::cin, name);
    // Player p1(name);

    // std::cout << "Enter name for player 2: ";
    // std::getline(std::cin, name);
    // Player p2(name);

    // std::cout << "Enter name for player 3: ";
    // std::getline(std::cin, name);
    // Player p3(name);

    // Catan catan(p1, p2, p3);
    // catan.chooseStartingPlayer();   // Print the name of the starting player
    // Board board = catan.getBoard(); // Get the board of the game

    // // Players place their initial settlements and roads
    // for (int i = 0; i < 2; ++i)
    // {
    //     for (Player &player : {p1, p2, p3})
    //     {
    //         std::vector<std::string> places;
    //         std::vector<int> placesNum;
    //         std::string place;
    //         int placeNum;

    //         std::cout << player.getName() << ", choose 2 locations for your settlement:\n";
    //         for (int j = 0; j < 2; ++j)
    //         {
    //             std::cout << "Location " << (j + 1) << ": ";
    //             std::getline(std::cin, place);
    //             places.push_back(place);
    //             std::cout << "Number " << (j + 1) << ": ";
    //             std::cin >> placeNum;
    //             std::cin.ignore(); // Ignore the newline character
    //             placesNum.push_back(placeNum);
    //         }

    //         player.placeSettlement(places, placesNum, board);

    //         std::cout << player.getName() << ", choose 2 locations for your road:\n";
    //         places.clear();
    //         placesNum.clear();
    //         for (int j = 0; j < 2; ++j)
    //         {
    //             std::cout << "Location " << (j + 1) << ": ";
    //             std::getline(std::cin, place);
    //             places.push_back(place);
    //             std::cout << "Number " << (j + 1) << ": ";
    //             std::cin >> placeNum;
    //             std::cin.ignore(); // Ignore the newline character
    //             placesNum.push_back(placeNum);
    //         }

    //         player.placeRoad(places, placesNum, board);
    //     }
    // }

    return 0;
}
