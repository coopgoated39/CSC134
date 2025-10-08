/*
CSC 134,M3LAB1
Curtis Cooper
9/24/25
Game.
*/

// this game will include options person who want to take shortcuts in life instead of working towards what they want to do.

# include <iostream>
#include <ctime>
#include <cstdlib>
 using namespace std;
 
 // ========== FUNCTION PROTOTYPES ==========
// Declare all your "rooms" up here
int start = 1; 
void Doctor(); // A possible path
void Depressed_worker(); // Another path
void Criminal(); // possible path
void gameOver(); // An ending
void victory(); // Another ending
int roll(); //funtion for dice roll

int roll() {
    int roll = (rand() % 3) + 1;
    return roll;
}

// ========== MAIN FUNCTION ==========
int main() {

    srand(static_cast<unsigned int>(time(0)));

    cout << "You have chosen to come see the wonderful wizard of oz" << endl;
    cout << "You have expressed a disire to forgo the rest of your FTCC classes for a chance to expedite your success" << endl;
    cout << "This is a risk you are prepared to take" << endl;
    cout << " Be warned avoiding hard work may come with a price" << endl; 
    cout << "==================================" << endl;
    cout << " Here is the Dice it is your time to fulfil your destiny ! " << endl;
    cout << "==================================" << endl;
    cout << "when ready to start just type 1 ?";
    cin >> start;
    if (start == 1) { // Compare against the value 1
        int diceRoll = roll(); // Call the function and store the result
        cout << "You rolled a " << diceRoll << "!" << endl; 
    } 

}




















