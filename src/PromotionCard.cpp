#include "PromotionCard.hpp"
#include <iostream>
#include "Player.hpp"
#include "Board.hpp"
PromotionCard::PromotionCard(PromotionCardType type) : type(type)
{
    switch (type)
    {
    case PromotionCardType::MONOPOLY:
        std::cout << "Monopoly card created" << std::endl;
        break;
    case PromotionCardType::BUILDING_ROADS:
        std::cout << "Building Roads card created" << std::endl;
        break;
    case PromotionCardType::YEAR_OF_PLENTY:
        std::cout << "Year of Plenty card created" << std::endl;
        break;
    }
}

void PromotionCard::useCard(Player &player, std::vector<Player> &players, Board &board)
{
    switch (type)
    {
    case PromotionCardType::MONOPOLY:
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

    case PromotionCardType::BUILDING_ROADS:
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

    case PromotionCardType::YEAR_OF_PLENTY:
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
    }
}
PromotionCardType PromotionCard::getType() const
{
    return type;
}