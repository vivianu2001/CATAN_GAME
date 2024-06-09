# Catan Game🎲🛤️


This project is an implementation of a simplified version of the Settlers of Catan board game for three players. The game includes basic rules for resource gathering, trading, building roads, settlements, cities, and using development cards. This README file provides details about the rules, class hierarchy, libraries used, and methods implemented.

## Game Rules

### Basic Rules

- **Players**: The game is designed for three players.
- **Setup**:
  - Each player starts with 2 settlements and 2 roads.
  - Players receive starting resources based on their initial settlements.
- **Turn Structure**:
  - Roll two six-sided dice to determine resource distribution.
  - Players can trade, build, and use development cards during their turn.
  - Each action (except using the Year of Plenty card) ends the player's turn.
- **Victory Points**:
  - Players earn points for building settlements and cities, and for holding certain development cards.
  - The first player to reach 10 victory points wins the game.

### Actions

- **Trade**: Players can trade resources and development cards with other players.
- **Build Road**: Players can build roads on specified edges of the board.
- **Build Settlement**: Players can build settlements on specified vertices of the board.
- **Build City**: Players can upgrade settlements to cities on specified vertices.
- **Buy Development Card**: Players can purchase development cards using resources.
- **Use Development Card**: Players can use development cards they have acquired.
- **End Turn**: Players can end their turn.

## Class Hierarchy

- **Board**: Manages the game board, resource distribution, and player settlements/roads.
- **Player**: Represents a player in the game, managing resources, development cards, and actions.
- **DevelopmentCard**: Abstract base class for development cards.
  - **KnightCard**: Derived class representing the Knight card.
  - **VictoryPointCard**: Derived class representing the Victory Point card.
  - **PromotionCard**: Derived class representing promotion cards (Monopoly, Road Building, Year of Plenty).
- **TradeManager**: Handles trading of resources and development cards between players.
- **Enums**: Defines enums for resource types and development card types.

## Libraries Used

- Standard Library (`iostream`, `vector`, `string`, `cstdlib`, `ctime`)
- Custom header files (`Player.hpp`, `Board.hpp`, `DevelopmentCard.hpp`, `TradeManager.hpp`, `Enums.hpp`)

## Methods Implemented

### Board Class

- **initializeBoard**: Sets up the initial state of the game board.
- **initializePlayerSettlementsAndRoads**: Places initial settlements and roads for players.
- **distributeResources**: Distributes resources to players based on dice roll and board state.
- **buildRoad**: Allows a player to build a road on a specified edge.
- **buildSettlement**: Allows a player to build a settlement on a specified vertex.
- **buildCity**: Allows a player to upgrade a settlement to a city on a specified vertex.

### Player Class

- **getName**: Returns the player's name.
- **getPlayerId**: Returns the player's ID.
- **getVictoryPoints**: Returns the player's current victory points.
- **getResourceCount**: Returns the count of a specific resource the player has.
- **addResource**: Adds a specified amount of a resource to the player's inventory.
- **addDevelopmentCard**: Adds a development card to the player's inventory.
- **useDevelopmentCard**: Uses a development card from the player's inventory and returns its type.
- **buildRoad**: Adds a road to the player's list of roads.
- **buildSettlement**: Adds a settlement to the player's list of settlements.
- **buildCity**: Upgrades a settlement to a city.
- **buyDevelopmentCard**: Buys a development card for the player.
- **printStatus**: Prints the player's current status (resources, victory points, etc.).

### DevelopmentCard Class

- **useCard**: Pure virtual function to be overridden by derived classes to define card usage.
- **getType**: Pure virtual function to be overridden by derived classes to return the card type.

### Derived Development Card Classes

- **KnightCard::useCard**: Implements usage for the Knight card.
- **VictoryPointCard::useCard**: Implements usage for the Victory Point card.
- **PromotionCard::useCard**: Implements usage for promotion cards (Monopoly, Road Building, Year of Plenty).
- **PromotionCard::getTypeP**: Returns the specific type of promotion card.

### TradeManager Class

- **tradeResources**: Facilitates trading resources between players.
- **tradeDevelopmentCards**: Facilitates trading development cards between players.
- **verifyTradeResources**: Verifies if a resource trade can be made.
- **verifyTradeDevelopmentCards**: Verifies if a development card trade can be made.

### Main Game Loop

- Initializes the board and players.
- Manages the turn structure, player actions, and victory condition.
- Implements the logic for trading, building, and using development cards.
- Ends the game when a player reaches 10 victory points.

## Usage Instructions

1. **Clone the Repository**: Clone the repository from GitHub.
   ```sh
   git clone https://github.com/vivianu2001/CATAN_GAME.git
   cd CATAN_GAME
