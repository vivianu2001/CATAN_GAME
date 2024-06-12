#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Board.hpp"
#include "Enums.hpp"
#include "TradeManager.hpp"
#include "catan.hpp"
#include <limits>
#include <random>
#include <unordered_map>
#include <algorithm>



void setupGame(std::vector<Player> &players, Board &board) {
    std::string name;
    std::cout << "Welcome to Catan! Enter the names of three players." << std::endl;
    for (int i = 1; i <= 3; ++i) {
        std::cout << "Player " << i << " name: ";
        std::getline(std::cin, name);
        players.emplace_back(name);
    }

    std::cout << "\nPlayers have joined the game!\n-----------------------------------\n";

    board.initializePlayerSettlementsAndRoads(players[0], 3, 6, 28, 36);
    board.initializePlayerSettlementsAndRoads(players[1], 13, 14, 41, 55);
    board.initializePlayerSettlementsAndRoads(players[2], 40, 52, 43, 57);
}

void playerTurn(Player &player, std::vector<Player> &players, Board &board) {
    std::cout << "\n" << player.getName() << "'s turn. Press Enter to roll dice.";
    std::cin.ignore();

    int diceRoll = rollDice();
    std::cout << player.getName() << " rolled a " << diceRoll << "." << std::endl;

    board.distributeResources(diceRoll, players);
    player.printStatus();

    bool endTurn = false;
    while (!endTurn) {
        std::string action;
        std::cout << "\nAction (t: trade, r: road, s: settlement, c: city, b: buy card, u: use card, e: end turn): ";
        std::getline(std::cin, action);

        if (action == "t") {
            trade(player, players);
            endTurn = true;
        } else if (action == "r") {
            buildRoad(player, board);
            endTurn = true;
        } else if (action == "s") {
            buildSettlement(player, board);
            endTurn = true;
        } else if (action == "c") {
            buildCity(player, board);
            endTurn = true;
        } else if (action == "b") {
            buyDevelopmentCard(player, players, board);
            endTurn = true;
        } else if (action == "u") {
            DevelopmentCardType cardType = useDevelopmentCard(player, players, board);
            if (cardType != DevelopmentCardType::YearOfPlenty) {
                endTurn = true;
            }
        } else if (action == "e") {
            endTurn = true;
        } else {
            std::cout << "Invalid action. Try again.";
        }
    }

    std::cout << "\nStatus of Player " << player.getName() << " after turn:\n";
    player.printStatus();
    std::cout << "-----------------------------------\n";
}

int rollDice() {
    int die1 = std::rand() % 6 + 1;
    int die2 = std::rand() % 6 + 1;
    return die1 + die2;
}

void trade(Player &player, std::vector<Player> &players)
{
    std::string tradeWith;
    std::cout << "Player to trade with: ";
    std::getline(std::cin, tradeWith);

    if (tradeWith == player.getName())
    {
        std::cout << "You cannot trade with yourself." << std::endl;
        return;
    }

    for (auto &otherPlayer : players)
    {
        if (otherPlayer.getName() == tradeWith)
        {
            std::string tradeType;
            std::cout << "Trade type (r/d): ";
            std::getline(std::cin, tradeType);

            if (tradeType == "r")
            {
                std::string resource1, resource2;
                int amount1, amount2;

                std::cout << "Your resource (Wood, Brick, Wool, Iron, Oat): ";
                std::getline(std::cin, resource1);
                std::cout << "Amount: ";
                std::cin >> amount1;
                std::cin.ignore();

                std::cout << "Their resource (Wood, Brick, Wool, Iron, Oat): ";
                std::getline(std::cin, resource2);
                std::cout << "Amount: ";
                std::cin >> amount2;
                std::cin.ignore();

                ResourceType res1 = stringToResourceType(resource1);
                ResourceType res2 = stringToResourceType(resource2);

                TradeManager::tradeResources(player, res1, amount1, otherPlayer, res2, amount2);
            }
            else if (tradeType == "d")
            {
                std::string cardType1, cardType2;

                std::cout << "Your card type: ";
                std::getline(std::cin, cardType1);
                std::cout << "Their card type: ";
                std::getline(std::cin, cardType2);

                DevelopmentCardType card1 = stringToDevelopmentCardType(cardType1);
                DevelopmentCardType card2 = stringToDevelopmentCardType(cardType2);

                TradeManager::tradeDevelopmentCards(player, otherPlayer, card1, card2);
            }
            else
            {
                std::cout << "Invalid trade type." << std::endl;
            }
            return;
        }
    }

    std::cout << "Player not found." << std::endl;
}

void buildRoad(Player &player, Board &board)
{
    int edgeId;
    std::cout << "Edge ID: ";
    while (!(std::cin >> edgeId) || edgeId < 0 || edgeId > 71) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid edge ID. It must be an integer between 0 and 71. Please try again: ";
    }
    std::cin.ignore();

    if (board.buildRoad(player.getPlayerId(), edgeId))
    {
        player.buildRoad(edgeId);
    }
    else
    {
        std::cout << "Cannot build road." << std::endl;
    }
}

void buildSettlement(Player &player, Board &board)
{
    int vertexId;
    std::cout << "Vertex ID: ";
    while (!(std::cin >> vertexId) || vertexId < 0 || vertexId > 53) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid vertex ID. It must be an integer between 0 and 53. Please try again: ";
    }
    std::cin.ignore();

    if (board.buildSettlement(player.getPlayerId(), vertexId, false))
    {
        player.buildSettlement(vertexId);
    }
    else
    {
        std::cout << "Cannot build settlement." << std::endl;
    }
}

void buildCity(Player &player, Board &board)
{
    int vertexId;
    std::cout << "Vertex ID: ";
    while (!(std::cin >> vertexId) || vertexId < 0 || vertexId > 53) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid vertex ID. It must be an integer between 0 and 53. Please try again: ";
    }
    std::cin.ignore();

    if (board.buildCity(player.getPlayerId(), vertexId))
    {
        player.buildCity(vertexId);
    }
    else
    {
        std::cout << "Cannot build city." << std::endl;
    }
}

void buyDevelopmentCard(Player &player, std::vector<Player> &players, Board &board)
{
    player.buyDevelopmentCard(players, board);
}

DevelopmentCardType useDevelopmentCard(Player &player, std::vector<Player> &players, Board &board)
{
    int cardIndex;
    std::cout << "Card index: ";
    while (!(std::cin >> cardIndex)) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid card index. It must be an integer. Please try again: ";
    }
    std::cin.ignore();
    return player.useDevelopmentCard(cardIndex, players, board);
}
void handleRollOfSeven(std::vector<Player>& players) {
    for (Player& player : players) {
        int totalResources = player.getTotalResourceCount();
        if (totalResources > 7) {
            int resourcesToReturn = totalResources / 2;
            std::cout << player.getName() << " must return " << resourcesToReturn << " resources to the pile." << std::endl;

            // Collect all resource types the player has
            std::vector<ResourceType> playerResources;
            for (const auto& resource : {ResourceType::Wood, ResourceType::Brick, ResourceType::Wool, ResourceType::Iron, ResourceType::Oat}) {
                int count = player.getResourceCount(resource);
                for (int i = 0; i < count; ++i) {
                    playerResources.push_back(resource);
                }
            }

            // Randomly shuffle the resources
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(playerResources.begin(), playerResources.end(), g);

            // Remove the resources from the player, ensuring we do not remove more than the player has
            std::unordered_map<ResourceType, int> resourcesRemoved;
            for (int i = 0; i < resourcesToReturn; ++i) {
                ResourceType resource = playerResources[i];
                player.addResource(resource, -1);
                resourcesRemoved[resource]++;
            }

            // Output the resources removed for verification
            std::cout << player.getName() << " returned:";
            for (const auto& entry : resourcesRemoved) {
                std::cout << " " << entry.second << " " << resourceTypeToString(entry.first);
            }
            std::cout << std::endl;
        }
    }
}