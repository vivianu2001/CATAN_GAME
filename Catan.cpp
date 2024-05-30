#include "Catan.hpp"
#include <iostream>
#include <cstdlib>

Catan::Catan(Player &p1, Player &p2, Player &p3)
{
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    startingPlayer = &players[0]; // Default to first player
}

void Catan::ChooseStartingPlayer()
{
    int randomIndex = rand() % players.size();
    startingPlayer = &players[randomIndex];
    std::cout << "Starting player is " << startingPlayer->getName() << std::endl;
}

Board Catan::getBoard() const
{
    return board;
}

void Catan::printWinner() const
{
    // Check and print the winner if any player has 10 or more victory points
    for (const Player &player : players)
    {
        if (player.getVictoryPoints() >= 10)
        {
            std::cout << player.getName() << " is the winner!" << std::endl;
            return;
        }
    }
    std::cout << "No player has won yet." << std::endl;
}
void Catan::initializePlayers()
{
    for (Player &player : players)
    {
        player.addSettlement();
        player.addSettlement();
        player.addRoad();
        player.addRoad();
        player.addVictoryPoints(2); // Each player starts with 2 victory points for 2 settlements
    }
}