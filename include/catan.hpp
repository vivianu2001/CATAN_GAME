#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "Player.hpp"
#include "Board.hpp"

void setupGame(std::vector<Player> &players, Board &board);
void buildRoad(Player &player, Board &board);
void buildSettlement(Player &player, Board &board);
void buildCity(Player &player, Board &board);
void playerTurn(Player &player, std::vector<Player> &players, Board &board) ;
int rollDice() ;
void trade(Player &player, std::vector<Player> &players);
void buyDevelopmentCard(Player &player, std::vector<Player> &players, Board &board);

DevelopmentCardType useDevelopmentCard(Player &player, std::vector<Player> &players, Board &board);
#endif // CATAN_HPP
