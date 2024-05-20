#include "Catan.h"
#include <iostream>
#include <stdexcept>

Catan::Catan(Player &p1, Player &p2, Player &p3) {
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    currentPlayerIndex = 0;
}

void Catan::ChooseStartingPlayer() {
    std::cout << "Starting player: " << players[currentPlayerIndex].name << std::endl;
}

Board Catan::getBoard() const {
    return board;
}

void Catan::nextTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

bool Catan::checkVictory() {
    for (const auto &player : players) {
        if (player.victoryPoints >= 10) {
            std::cout << player.name << " wins!" << std::endl;
            return true;
        }
    }
    return false;
}

void Catan::printWinner() {
    if (checkVictory()) {
        std::cout << "Winner: " << players[currentPlayerIndex].name << std::endl;
    } else {
        std::cout << "No winner yet." << std::endl;
    }
}
