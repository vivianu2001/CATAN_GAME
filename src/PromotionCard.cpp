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
DevelopmentCardType PromotionCard::getType() const
{
    switch (type)
    {
    case PromotionCardType::MONOPOLY:
        return DevelopmentCardType::Monopoly;
    case PromotionCardType::BUILDING_ROADS:
        return DevelopmentCardType::RoadBuilding;
    case PromotionCardType::YEAR_OF_PLENTY:
        return DevelopmentCardType::YearOfPlenty;
    default:
        return DevelopmentCardType::Knight; // or any default type if necessary
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
                if (amount == 0)
                {
                    otherPlayer.addResource(resType, -amount);
                    player.addResource(resType, 1);
                }
                else
                {
                    otherPlayer.addResource(resType, -1);
                    player.addResource(resType, 1);
                }
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
PromotionCardType PromotionCard::getTypeP() const
{
    return type;
}
