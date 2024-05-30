#include "Catan.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Catan::Catan(Player &p1, Player &p2, Player &p3) : players{p1, p2, p3}, startingPlayer(nullptr)
{
    std::srand(std::time(nullptr)); // Seed random number generator
}

void Catan::chooseStartingPlayer()
{
    int index = std::rand() % players.size();
    startingPlayer = &players[index];
    std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
}

Board Catan::getBoard() const
{
    return board;
}
