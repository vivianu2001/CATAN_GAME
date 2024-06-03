#pragma once

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
    VictoryPoint
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