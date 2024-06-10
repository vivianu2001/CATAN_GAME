#include <string>
#ifndef ENUMS_HPP
#define ENUMS_HPP

enum class ResourceType
{
    Wood,  // 0
    Brick, // 1
    Wool,  // 2
    Iron,  // 3
    Oat,   // 4
    None   // If you need a 'None' type
};

enum class DevelopmentCardType
{
    Knight,
    RoadBuilding,
    YearOfPlenty,
    Monopoly,
    VictoryPoint,
    None
};

inline std::string resourceTypeToString(ResourceType type)
{
    switch (type)
    {
    case ResourceType::Wood:
        return "Wood";
    case ResourceType::Brick:
        return "Brick";
    case ResourceType::Wool:
        return "Wool";
    case ResourceType::Iron:
        return "Iron";
    case ResourceType::Oat:
        return "Oat";
    case ResourceType::None:
        return "None";
    default:
        return "Unknown";
    }
}

inline std::string developmentCardTypeToString(DevelopmentCardType type)
{
    switch (type)
    {
    case DevelopmentCardType::Knight:
        return "Knight";
    case DevelopmentCardType::RoadBuilding:
        return "Road Building";
    case DevelopmentCardType::YearOfPlenty:
        return "Year of Plenty";
    case DevelopmentCardType::Monopoly:
        return "Monopoly";
    case DevelopmentCardType::VictoryPoint:
        return "Victory Point";
    default:
        return "Unknown";
    }
}

inline ResourceType stringToResourceType(const std::string &resource)
{
    if (resource == "Wood")
        return ResourceType::Wood;
    if (resource == "Brick")
        return ResourceType::Brick;
    if (resource == "Wool")
        return ResourceType::Wool;
    if (resource == "Iron")
        return ResourceType::Iron;
    if (resource == "Oat")
        return ResourceType::Oat;
    return ResourceType::None;
}

inline DevelopmentCardType stringToDevelopmentCardType(const std::string &card)
{
    if (card == "Knight")
        return DevelopmentCardType::Knight;
    if (card == "Road Building")
        return DevelopmentCardType::RoadBuilding;
    if (card == "Year of Plenty")
        return DevelopmentCardType::YearOfPlenty;
    if (card == "Monopoly")
        return DevelopmentCardType::Monopoly;
    if (card == "Victory Point")
        return DevelopmentCardType::VictoryPoint;
    throw std::invalid_argument("Unknown development card type");
}

enum class PromotionCardType
{
    MONOPOLY,
    BUILDING_ROADS,
    YEAR_OF_PLENTY
};

inline DevelopmentCardType toDevelopmentCardType(PromotionCardType type)
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
        throw std::invalid_argument("Invalid PromotionCardType");
    }
}

#endif // ENUMS_HPP
