class DevelopmentCard
{
public:
    enum class CardType
    {
        Monopoly,
        RoadBuilding,
        YearOfPlenty,
        Knight,
        VictoryPoint
    };
    CardType type;

    DevelopmentCard(CardType cardType) : type(cardType) {}
};
