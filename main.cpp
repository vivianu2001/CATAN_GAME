#include <iostream>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main()
{

    std::string name;
    
    std::cout << "Enter name for Player 1: ";
    std::getline(std::cin, name);
    Player p1(name);
    
    std::cout << "Enter name for Player 2: ";
    std::getline(std::cin, name);
    Player p2(name);
    
    std::cout << "Enter name for Player 3: ";
    std::getline(std::cin, name);
    Player p3(name);
    Catan catan(p1, p2, p3);

        // Initialize players with starting settlements and roads
    catan.initializePlayers();

    // Initial game state
    catan.ChooseStartingPlayer();

    
     p1.printPoints();
    p2.printPoints();
    p3.printPoints();

    catan.printWinner();

    // catan.ChooseStartingPlayer();
    // Board board = catan.getBoard();

    // std::vector<std::string> places1 = {"Forest", "Hills"};
    // std::vector<int> placesNum1 = {5, 6};
    // p1.placeSettlement(places1, placesNum1, board);
    // p1.placeRoad(places1, placesNum1, board);

    // std::vector<std::string> places2 = {"Agricultural Land", "Desert"};
    // std::vector<int> placesNum2 = {3, 4};
    // p1.placeSettlement(places2, placesNum2, board);
    // p1.placeRoad(places2, placesNum2, board);

    // std::vector<std::string> places3 = {"Mountains", "Pasture Land"};
    // std::vector<int> placesNum3 = {4, 9};
    // p2.placeSettlement(places3, placesNum3, board);
    // p2.placeRoad(places3, placesNum3, board);

    // try
    // {
    //     p3.placeSettlement(places3, placesNum3, board);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::vector<std::string> places4 = {"Forest", "Pasture Land"};
    // std::vector<int> placesNum4 = {5, 9};
    // p2.placeSettlement(places4, placesNum4, board);
    // p2.placeRoad(places4, placesNum4, board);

    // std::vector<std::string> places5 = {"Mountains", "Pasture Land"};
    // std::vector<int> placesNum5 = {3, 8};
    // p3.placeSettlement(places5, placesNum5, board);
    // p3.placeRoad(places5, placesNum5, board);

    // std::vector<std::string> places6 = {"Agricultural Land", "Pasture Land"};
    // std::vector<int> placesNum6 = {3, 9};
    // p3.placeSettlement(places6, placesNum6, board);
    // p3.placeRoad(places6, placesNum6, board);

    // p1.rollDice();
    // p1.placeRoad({"Forest", "Hills"}, {5, 6}, board);
    // p1.endTurn();

    // p2.rollDice();
    // p2.endTurn();

    // p3.rollDice();
    // p3.endTurn();

    // try
    // {
    //     p2.rollDice();
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // p1.rollDice();
    // p1.trade(p2, "wood", "brick", 1, 1);
    // p1.endTurn();

    // p2.rollDice();
    // p2.buyDevelopmentCard();
    // p2.endTurn();

    // p1.printPoints();
    // p2.printPoints();
    // p3.printPoints();

    // catan.printWinner();

    // return 0;
}
