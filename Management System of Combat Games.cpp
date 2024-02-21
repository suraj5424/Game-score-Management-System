#include <iostream> // added library for input and aoutput string
#include <string> // to handle string values
#include <limits> // for numeric limit functioning

using namespace std; // to use standard namespace

const int maximumPlayers = 6; // maximum 6 player are allowed.
const int maximumCombat_result = 100000; // to store the combat results.

// created Player class.
class Player {
    
    //added necessary attributes.
    private:
    int number;
    string surname;
    string firstname;
    int height;
    int weight;
    int birthYear;
    int combatCount;   // for participation in combats
    int wonCount;
    int loseCount;
    int drawCount;
    int totalPoints;
    
    public:
    Player(int num) : number(num) {
        
        // added default values as 0 for INITIALIZATION.
        combatCount = 0;
        wonCount = 0;
        drawCount = 0;
        loseCount = 0;
        totalPoints = 0;
    }
    
    // default constructor for player class.
    Player() {
        number = 0;
    }
    
    // to fetch the number of a player.
    int getNumber() const {
        return number;
    }
    
    //Overloaded the INPUT OPERATOR for class PLayer.
    friend istream& operator>>(istream& in, Player& player);
    
    //Overloaded the OUTPUT OPERATOR for class PLayer.
    friend ostream& operator<<(ostream& out, const Player& player) {
        out << player.number << ". " << player.firstname << " " << player.surname << ", "
        << player.birthYear << ", " << player.height << "cm, " << player.weight << "kg, "
        << "participated in " << player.combatCount << " combat games: " << player.wonCount
        << " x won, " << player.loseCount << " x lose, " << player.drawCount << " x tie = " << player.totalPoints << " points";
        return out;
    }
    
    //Overloaded the OPERATOR(>=) dress PLayer.
    
    // 'const Player& other' denotes a constant reference to another Player object which has been compared.
    bool operator>=(const Player& other) const {
        // checking if the weight of the current object is greater than or equal to the weight of the compared object,
        if (weight >= other.weight || height >= other.height ) {
            return true;
        } else {
            return false;
        }
    }
    
    
    // below are the methods used to update players property.
    void won() {
        wonCount++;
        totalPoints += 10;
    }
    
    void lose() {
        loseCount++;
        totalPoints += 0;
    }
    
    int getnum()  {
        return number;
    }    
    
    void draw() {
        drawCount++;
        totalPoints += 5;
    }
    
    void updateCombat() {
        combatCount++;
    }
    
    // to fetch SOME information of players.
    string getPlayerInfo() const {
        return firstname + " " + surname + ", " + to_string(birthYear) + ", "
        + to_string(height) + "cm, " + to_string(weight) + "kg";
    }
    
    // methods to get the details of players.
    string getfirstname() const{
        return firstname;
    }
    
    string getsurname() const{
        return surname;
    }    
    
    int getHeight() const {
        return height;
    }
    
    int getWeight() const {
        return weight;
    }
    
    int getCombatCount() const{
        return combatCount;
    }
};

istream& operator>>(istream& in, Player& player) {
    
    cout << ":::Confirm your UNIQUE number again!!: "; // also for verification purpose.
    while (!(in >> player.number)) { // handling numerical values
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
    }
    cout<<"Okay!! you entered: "<<player.number<<endl;
    cout << ":::Please enter Surname: ";
    in >> player.surname;
    cout << ":::Please enter First Name: ";
    in >> player.firstname;
    cout << ":::Please enter Height (in cm): ";
    while (!(in >> player.height)) { // handling numerical values
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
    }        
    cout << ":::Please enter Weight (in kg): ";
    while (!(in >> player.weight)) {  // handling numerical values
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
    }         
    cout << ":::Please enter Year of Birth: ";
    while (!(in >> player.birthYear)) {  // handling numerical values
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
    }
    cout<<"\n-:-With the UNIQUE number "<<player.number<<" "<<player.firstname<<" "<<player.surname<<", born in "<<player.birthYear<<", "<<player.height<<"cm tall and weighs "<<player.weight<<"kg, "<<"has been successfully registered for the game!!!."<<endl;
    return in;
}

// created ONE MORE CLASS to display the winners.
class CombatResult {
    private:
    const Player* winner;
    const Player* loser;
    
    public:
    
    //constructor of class CombatResult.
    CombatResult(const Player* winnerPlayer, const Player* loserPlayer) : winner(winnerPlayer), loser(loserPlayer) {}
    
    //Overloaded the OUTPUT OPERATOR for class CombatResult.
    friend ostream& operator<<(ostream& out, const CombatResult& combat) {
        out << "Winner: " << (*combat.winner).getPlayerInfo() << ", Loser: " << (*combat.loser).getPlayerInfo();
        return out;
    }
    
};
// to find the player from the array.
bool checkByNumber(Player players[], int count, int number, int& index) {
    for (int i = 0; i < count; ++i) {
        if (players[i].getNumber() == number) {
            index = i;
            return true; // Player found
        }
    }
    return false; // Player not found
}

// To show the Details of the registered players and their combats. 
void printPlayers(Player players[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << players[i] << endl;
    }
}

// To show the Details of WINNERS of each successful combats.
void printCombatResults(Player players[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << players[i].getPlayerInfo() << endl;
    }
}

// displays the appropriate comment after the successful combat.
// p1index is Index of 1st selected player and p2index is Index of 2nd selected player.
void displayerPlayer(ostream& out, Player players[], int result, int p1index, int p2index) {
    if (result == 1) {
        if (players[p1index] >= players[p2index]) {
            int heightDiff = players[p1index].getHeight() - players[p2index].getHeight();
            int weightDiff = players[p1index].getWeight() - players[p2index].getWeight();
            
            cout << "Player " << players[p1index].getfirstname() << " " << players[p1index].getsurname() << " has won, ";
            cout << "he is " << heightDiff << " cm " << ((heightDiff > 0) ? "taller" : "shorter");
            cout << " and " << weightDiff << " kg " << ((weightDiff > 0) ? "heavier" : "lighter");
            cout << " than player " << players[p2index].getfirstname() << " " << players[p2index].getsurname() << "." << endl;
        } 
    }
    if (result == 2) {
        if (players[p2index] >= players[p1index]) {
            int heightDiff = players[p2index].getHeight() - players[p1index].getHeight();
            int weightDiff = players[p2index].getWeight() - players[p1index].getWeight();
            
            cout << "Player " << players[p2index].getfirstname() << " " << players[p2index].getsurname() << " has won, ";
            cout << "he is " << heightDiff << " cm " << ((heightDiff > 0) ? "taller" : "shorter");
            cout << " and " << weightDiff << " kg " << ((weightDiff > 0) ? "heavier" : "lighter");
            cout << " than player " << players[p1index].getfirstname() << " " << players[p1index].getsurname() << "." << endl;
        }
    }        
    if (result == 3) {
        out << "The match has been tied" << endl;
        out<< "\nTheir PREVIOUS details are given below:\n";
        out << players[p1index] << endl;
        out << players[p2index] << endl;        
    }
}

// initialisation of main function.
int main() {
    Player players[maximumPlayers]; // arrary to store the info of players.
    CombatResult* combatResults[maximumCombat_result]; // array of pointers to store combat results
    int combatResultsCount = 0; //to keep track of combat results count
    int playerCount = 0;
    int choice;
    
    
    cout<<"------:Welcome to the \"Management System of Combat Games\":------"<<endl;
    // loop controlled program for menu
    do {
        cout << "\n:::::Menu:::::\n";
        cout<< "1. Create player\n";
        cout<< "2. Manage combat game\n";
        cout<< "3. Output all players\n";
        cout<< "4. Output winner\n";
        cout<< "5. Program exit\n";
        cout<< ":::Please enter the INTEGER from the above list of your choice: ";
        while (!(cin >> choice)) {     // handling numerical values
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
        }
        
        
        switch (choice) {
            case 1: {
                
                // code to Creat player successfully with appropriate data.
                
                if (playerCount >= maximumPlayers) {
                    cout << "Maximum 6 players allowed to creat!" << endl;
                    break;
                }
                
                int number;
                cout << ":::Please enter Number: ";
                while (!(cin >> number)) {    // handling numerical values
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
                }                
                int existingPlayerIndex;
                
                // /to check if number entered is not registerd.
                if (checkByNumber(players, playerCount, number, existingPlayerIndex)) {
                    cout << "Number is already registered!" << endl;
                    break;
                }
                
                // this will add the players information.
                players[playerCount] = Player(number);
                cin >> players[playerCount];
                playerCount++;
                break;
            }
            case 2: {
                
                // main code function  ccode to manage the combats.
                // checks if minimum two players are registered or not.
                if (playerCount < 2) {
                    cout << "Minimum two players required!" << endl;
                    break;
                }
                
                // TO TAKE THE NUMBER OF TWO PLAYERS FOR COMBAT.
                int player1Number, player2Number;
                cout << ":::Please enter numbers of two players between whom you want to have a combat:\n";
                cout << "Available Players:\n";
                printPlayers(players, playerCount);   //TO show the registered players and their UNIQUE NUMBERS.
                
                cout << ":::Please enter number of challenger player: ";
                while (!(cin >> player1Number)) {  // handling numerical values
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
                }
                
                cout << ":::Please enter number of opponent player: ";
                while (!(cin >> player2Number)) {   // handling numerical values
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
                } 
                
                
                int p1index, p2index;
                
                // to check the existance of the player using their numbers.
                if (!checkByNumber(players, playerCount, player1Number, p1index) ||
                !checkByNumber(players, playerCount, player2Number, p2index)) {
                    cout << "Atlest one player you entered is not registred." << endl;
                    break;
                }
                // to check if both entered players are DIFFERENT or not!!.
                if (players[p1index].getnum() == players[p2index].getnum()) {
                    cout << "Players can not have combat with each other" << endl;
                    break;
                }                 
                
                // this will check if any of the entered players has participated in th combat more than 3 times. 
                if (players[p1index].getCombatCount() >= 3 || players[p2index].getCombatCount() >= 3) {
                    cout << "One or both players have reached the maximum participation limit (3 times)!" << endl;
                    break;
                }                
                
                int result;
                // displays the list of results.
                cout << "Combat Result:\n"
                << "1. Player " << player1Number << " won\n"
                << "2. Player " << player2Number << " won\n"
                << "3. Draw\n"
                << ":::Please enter your choice: ";
                while (!(cin >> result)) {  // handling numerical values
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered Wrong. Please enter an appropriate INTEGER: ";
                }                   
                
                displayerPlayer(cout, players, result, p1index, p2index);
                
                
                if (result == 1) {
                    
                    //this will create new combatresult object with 1st player winner and 2nd as loser.
                    combatResults[combatResultsCount] = new CombatResult(&players[p1index], &players[p2index]);
                    combatResultsCount++; // will inreament the index for the next result
                } else if (result == 2) {
                    
                    //this will create new combatresult object with 2nd player winner and 1st as loser.                    
                    combatResults[combatResultsCount] = new CombatResult(&players[p2index], &players[p1index]);
                    combatResultsCount++; // will inreament the index for the next result
                }
                
                // to update the number of participation in the combat. for both players.
                players[p1index].updateCombat();
                players[p2index].updateCombat();
                
                // to update the result according to the results selected by the user.
                if (result == 1) {
                    players[p1index].won();
                    players[p2index].lose();
                } else if (result == 2) {
                    players[p2index].won();
                    players[p1index].lose();
                } else if (result == 3) {
                    players[p1index].draw();
                    players[p2index].draw();
                } else {
                    cout << "Wrong selection!!" << endl;
                }
                
                break;
            }
            case 3: {
                
                // to show the COMPLETE infromation about all the players in the combat so far.
                printPlayers(players, playerCount);
                break;
            }
            case 4: {
                // to show the WINNERS and LOSERS of each combat which had held. 
                for (int i = 0; i < combatResultsCount; ++i) {
                    cout << *(combatResults[i]) << endl;
                }
                break;
            }
            case 5: {
                
                // to exit from the program.
                cout << "Exiting program..." << endl;
                break;
            }
            default:
            
            // // handling numerical values
            cout << "Wrong selection!!" << endl;
        }
    } while (choice != 5);
    
    return 0;
}

// program ended.