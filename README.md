# Combat Game Management System

This project is a **Combat Game Management System** written in C++. The program manages the registration of players, handles combat games between them, and tracks their performance. The program ensures that a player can participate in a maximum of three combat games, records combat results, and allows viewing the list of registered players and winners of each game.

## Features

- **Player Registration**: You can register up to 6 players with unique player numbers.
- **Combat Game Management**: Allows the management of combat games between two registered players, ensuring no player exceeds their combat participation limit (3 combats).
- **Results Tracking**: Displays combat results, including the winner and loser of each game. 
- **Player Information**: Allows the viewing of registered players' details and their combat history (wins, losses, and draws).
- **Combat Rules**: 
  - 10 points are awarded for a win.
  - 5 points are awarded for a draw.
  - No points are given for a loss.

## Classes and Functions

### 1. **Player Class**
This class stores all the details related to a player:
- Player number
- Surname and first name
- Height and weight
- Year of birth
- Combat history (participations, wins, losses, draws, total points)

#### Key Methods:
- `won()`: Updates win count and adds 10 points.
- `lose()`: Updates loss count.
- `draw()`: Updates draw count and adds 5 points.
- `updateCombat()`: Increments the player's combat participation count.
- `getPlayerInfo()`: Returns a string with the player's name, birth year, height, and weight.

### 2. **CombatResult Class**
This class stores the result of a combat between two players, with pointers to the winner and loser.

### 3. **Helper Functions**
- `checkByNumber()`: Checks if a player with a specific number exists in the registered players list.
- `printPlayers()`: Prints details of all registered players.
- `printCombatResults()`: Prints the results of all completed combats.

### 4. **Main Function**
The main function controls the flow of the program, offering the following options to the user:
- Register a new player.
- Manage a combat between two registered players.
- Output all players' information.
- Output the winners and losers of combat games.
- Exit the program.

## Program Flow

1. **Create Player**: The program allows users to create up to 6 players. Each player must have a unique number. The user provides the player's surname, first name, height, weight, and birth year.
   
2. **Manage Combat**: Users can select two registered players to engage in a combat. The user chooses the result: either one of the players wins, or the combat is a draw. The system updates both players' records accordingly.
   
3. **View All Players**: The program outputs a list of all registered players, showing their combat history (wins, losses, draws, and total points).

4. **View Combat Results**: Displays the winners and losers of all completed combats.

## Getting Started

### Prerequisites
You need a C++ compiler to compile and run this program, such as:

- GCC (GNU Compiler Collection)
- Visual Studio with C++ support
- Xcode (for macOS)

### Compilation

To compile the program, use the following command (assuming you're using GCC):

```bash
g++ combat_game.cpp -o combat_game
```

### Running the Program

After compilation, you can run the program by executing the compiled file:

```bash
./combat_game
```

### Example Program Output

```
------:Welcome to the "Management System of Combat Games":------

:::::Menu:::::
1. Create player
2. Manage combat game
3. Output all players
4. Output winner
5. Program exit
:::Please enter the INTEGER from the above list of your choice: 
```

## Example Usage

1. **Create Player**: Enter unique player information such as number, surname, first name, height, weight, and birth year.
2. **Manage Combat**: Select two players and choose the combat result. The system will update the combat history for both players.
3. **View Players and Results**: List all players and view the winners of previous combats.

## Future Improvements

- Add functionality to handle player removal.
- Improve error handling for invalid user input.
- Implement more complex combat mechanics or player stats.
  
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
