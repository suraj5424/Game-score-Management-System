## Combat Game Management Program Description

The task was to develop a C++ program to efficiently manage combat games, transitioning from a paper-based system to a digital one. The program is designed to handle up to six participants, or players, in a combat game, facilitating the recording, managing, and outputting of player data and game outcomes.

### Program Features

- **Player Data Entry**: For each of the six players, the program captures and stores essential details such as a unique number, surname, first name, height (in cm), weight (in kg), points accumulated, and year of birth. This data entry is facilitated through the overloading of the istream (`>>`) operator, ensuring a streamlined process.

- **Combat Game Management**: The program allows for the entry of combat game results, dynamically adjusting players' points based on the outcomes (win, tie, or loss). Each player can participate in up to three fights, with points awarded as follows: 10 points for a win, 5 points for a tie, and no points for a loss. The program then identifies and displays the game winner.

- **Comparison Operator Overloading**: Through the overloading of the `>=` operator, the program can compare the physical attributes (height and weight) of the combatants, outputting the comparative advantage of the winner over the loser.

- **Players Output**: Utilizing the ostream (`<<`) operator overloading, the program outputs detailed information on all players, including their personal details, the number of games participated in, the outcomes of these games, and the total points earned.

- **Winner Announcement**: The program includes a feature to announce the overall winner based on the points accumulated.

- **Program Exit**: Users can easily exit the program once they have completed their tasks.

### Technical Implementation

The program is dynamically constructed using pointers to ensure efficient memory management and scalability. This dynamic approach allows for modifications and expansions, such as adding more players or adjusting the game rules, without significant rework.

Messages are displayed throughout the program to guide the user during data entry, combat management, and when outputting results, ensuring a user-friendly experience.

**Note**: As specified, the program does not include permanent data storage capabilities. All player data and game outcomes are only available during the runtime of the application, meeting the project's requirements for simplicity and focus on in-memory data management.

This program represents a significant improvement in managing combat games, offering a digital solution that is both efficient and scalable.
