#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Board.hpp"
#include "Enums.hpp"
#include "TradeManager.hpp"

int rollDice();
int main(int argc, char **argv)
{
    std::srand(std::time(0));
    std::vector<Player> players;
    std::string name;

    std::cout << "Welcome to Catan! Please enter the names of three players." << std::endl;
    for (int i = 1; i <= 3; ++i)
    {
        std::cout << "Enter name for Player " << i << ": ";
        std::getline(std::cin, name);
        players.emplace_back(name);
    }

    Board board;
    board.initializeBoard();

    std::cout << "\nPlayers have joined the game!\n-----------------------------------\n";

    board.initializePlayerSettlementsAndRoads(players[0], 3, 6, 28, 36);
    board.initializePlayerSettlementsAndRoads(players[1], 13, 14, 41, 55);
    board.initializePlayerSettlementsAndRoads(players[2], 40, 52, 43, 57);

    while (true)
    {
        for (auto &player : players)
        {
            std::cout << "\n"
                      << player.getName() << "'s turn. Press Enter to roll dice.";
            std::cin.ignore();

            int diceRoll = rollDice();
            std::cout << player.getName() << " rolled a " << diceRoll << "." << std::endl;

            board.distributeResources(diceRoll, players);
            player.printStatus();

            std::string action;
            while (true)
            {
                std::cout << "\nChoose an action: trade, build_road, trade_development, build_settlement, build_city, buy_development_card, use_development_card, end_turn: ";
                std::getline(std::cin, action);

                if (action == "trade")
                {
                    std::string tradeWith;
                    std::cout << "Enter the name of the player you want to trade with: ";
                    std::getline(std::cin, tradeWith);

                    if (tradeWith == player.getName())
                    {
                        std::cout << "You cannot trade with yourself." << std::endl;
                        continue;
                    }

                    bool playerFound = false;
                    for (auto &otherPlayer : players)
                    {
                        if (otherPlayer.getName() == tradeWith)
                        {
                            std::string tradeType;
                            std::cout << "Enter trade type (resource/development): ";
                            std::getline(std::cin, tradeType);

                            if (tradeType == "resource")
                            {
                                std::string resource1, resource2;
                                int amount1, amount2;

                                std::cout << "Enter the resource you want to trade (Wood, Brick, Wool, Iron, Oat): ";
                                std::getline(std::cin, resource1);
                                std::cout << "Enter the amount: ";
                                std::cin >> amount1;
                                std::cin.ignore();

                                std::cout << "Enter the resource you want to receive (Wood, Brick, Wool, Iron, Oat): ";
                                std::getline(std::cin, resource2);
                                std::cout << "Enter the amount: ";
                                std::cin >> amount2;
                                std::cin.ignore();

                                ResourceType res1 = stringToResourceType(resource1);
                                ResourceType res2 = stringToResourceType(resource2);

                                TradeManager::tradeResources(player, res1, amount1, otherPlayer, res2, amount2);
                            }
                            else if (tradeType == "development")
                            {
                                std::string cardType1, cardType2;

                                std::cout << "Enter the type of development card you want to trade: ";
                                std::getline(std::cin, cardType1);
                                std::cout << "Enter the type of development card you want to receive: ";
                                std::getline(std::cin, cardType2);

                                DevelopmentCardType card1 = stringToDevelopmentCardType(cardType1);
                                DevelopmentCardType card2 = stringToDevelopmentCardType(cardType2);

                                TradeManager::tradeDevelopmentCards(player, otherPlayer, card1, card2);
                            }
                            else
                            {
                                std::cout << "Invalid trade type." << std::endl;
                            }

                            playerFound = true;
                            break;
                        }
                    }

                    if (!playerFound)
                    {
                        std::cout << "Player not found. Please try again." << std::endl;
                    }
                }

                else if (action == "build_road")
                {
                    int edgeId;
                    std::cout << "Enter edge ID to build road: ";
                    std::cin >> edgeId;
                    std::cin.ignore();
                    if (board.buildRoad(player.getPlayerId(), edgeId))
                    {
                        player.buildRoad(edgeId);
                    }

                    else
                    {
                        std::cout << "Player cannot build road." << std::endl;
                    }
                }
                else if (action == "build_settlement")
                {
                    int vertexId;
                    std::cout << "Enter vertex ID to build settlement: ";
                    std::cin >> vertexId;
                    std::cin.ignore();
                    if (board.buildSettlement(player.getPlayerId(), vertexId, false))
                    {
                        player.buildSettlement(vertexId);
                    }

                    else
                    {
                        std::cout << "Player cannot build settlement." << std::endl;
                    }
                }
                else if (action == "build_city")
                {
                    int vertexId;
                    std::cout << "Enter vertex ID to build city: ";
                    std::cin >> vertexId;
                    std::cin.ignore();
                    if (board.buildCity(player.getPlayerId(), vertexId))
                    {
                        player.buildCity(vertexId);
                    }

                    else
                    {
                        std::cout << "Player cannot build city." << std::endl;
                    }
                }

                else if (action == "buy_development_card")
                {
                    player.buyDevelopmentCard();
                }
                else if (action == "use_development_card")
                {
                    int cardIndex;
                    std::cout << "Enter the index of the development card to use: ";
                    std::cin >> cardIndex;
                    std::cin.ignore();
                    player.useDevelopmentCard(cardIndex, players, board);
                }
                else if (action == "end_turn")
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid action. Please try again.";
                }
            }

            std::cout << "\nStatus of Player " << player.getName() << " after turn:\n";
            player.printStatus();
            std::cout << "-----------------------------------\n";

            if (player.getVictoryPoints() >= 10)
            {
                std::cout << "Player " << player.getName() << " has won the game with " << player.getVictoryPoints() << " victory points!" << std::endl;
                return 0;
            }
        }
    }

    return 0;
}

int rollDice()
{
    int die1 = std::rand() % 6 + 1;
    int die2 = std::rand() % 6 + 1;
    return die1 + die2;
}
