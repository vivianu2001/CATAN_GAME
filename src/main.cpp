//umanskyvivian@gmail.com
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "catan.hpp"
#include <cstdlib>
#include <ctime>


int main() {
    std::srand(std::time(0));
    std::vector<Player> players;
    Board board;

    setupGame(players, board);

    while (true) {
        for (auto &player : players) {
            playerTurn(player, players, board);

            if (player.getVictoryPoints() >= 10) {
                std::cout << "Player " << player.getName() << " has won the game with " << player.getVictoryPoints() << " victory points!" << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
