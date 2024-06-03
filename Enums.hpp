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