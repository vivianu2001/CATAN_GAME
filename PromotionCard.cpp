#include "PromotionCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

void PromotionCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    switch (type)
    {
    case MONOPOLY:
    {
        std::string resource;
        std::cout << "Enter the resource type (Wood, Brick, Wool, Iron, Oat): ";
        std::getline(std::cin, resource);
        ResourceType resType = stringToResourceType(resource);

        for (auto &otherPlayer : players)
        {
            if (otherPlayer.getPlayerId() != player.getPlayerId())
            {
                int amount = otherPlayer.getResourceCount(resType);
                otherPlayer.addResource(resType, -amount);
                player.addResource(resType, amount);
            }
        }
        break;
    }
    case BUILDING_ROADS:
    {
        for (int i = 0; i < 2; ++i)
        {
            int edgeId;
            std::cout << "Enter edge ID to build road: ";
            std::cin >> edgeId;
            std::cin.ignore();
            if (board.buildRoad(player.getPlayerId(), edgeId))
            {
                player.addRoad(edgeId);
            }
        }
        break;
    }
    case YEAR_OF_PLENTY:
    {
        for (int i = 0; i < 2; ++i)
        {
            std::string resource;
            std::cout << "Enter the resource type (Wood, Brick, Wool, Iron, Oat): ";
            std::getline(std::cin, resource);
            ResourceType resType = stringToResourceType(resource);
            player.addResource(resType, 1);
        }
        break;
    }
    }
}