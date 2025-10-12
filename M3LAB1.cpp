/*
CSC 134
M3LAB1
Curtis Cooper
Game: The Wizard of Oz Life Choices
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// ========== FUNCTION PROTOTYPES ==========
void Doctor();            // A possible path
void Depressed_worker();  // Another path
void Criminal();          // Possible path
void gameOver();          // An ending
int roll();               // Function for dice roll

// ========== FUNCTION DEFINITIONS ==========
int roll() {
    int dice = (rand() % 3) + 1;
    return dice;
}

void Doctor() {
    cout << "You are a doctor — wise, disciplined, and successful." << endl;
    cout << "You worked hard and earned your success through persistence." << endl;
    cout << "Congratulations! You made it." << endl;
    gameOver();
}

void Depressed_worker() {
    cout << "You are a depressed worker stuck in a job you hate." << endl;
    cout << "Would you like to roll again for better luck? (1 = Yes, 0 = No): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        int diceRoll = roll();
        cout << "You rolled a " << diceRoll << "!" << endl;
        if (diceRoll == 2)
            Criminal();
        else if (diceRoll == 3)
            Doctor();
        else
            Depressed_worker();
    } else {
        gameOver();
    }
}

void Criminal() {
    cout << "You are a criminal — labeled and struggling to find your place in society." << endl;
    cout << "Sometimes shortcuts come with consequences." << endl;
    gameOver();
}

void gameOver() {
    cout << "==================================" << endl;
    cout << "           GAME OVER              " << endl;
    cout << "==================================" << endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "You have chosen to come see the wonderful Wizard of Oz!" << endl;
    cout << "You wish to skip your FTCC classes and expedite your success." << endl;
    cout << "Be warned: avoiding hard work may come with a price." << endl;
    cout << "==================================" << endl;
    cout << "Here is the Dice — it is your time to fulfill your destiny!" << endl;
    cout << "==================================" << endl;

    int start;
    cout << "When ready to start, type 1: ";
    cin >> start;

    if (start == 1) {
        int diceRoll = roll();
        cout << "You rolled a " << diceRoll << "!" << endl;

        if (diceRoll == 1)
            Depressed_worker();
        else if (diceRoll == 2)
            Criminal();
        else if (diceRoll == 3)
            Doctor();
    } else {
        cout << "Maybe next time you'll be ready for the challenge!" << endl;
    }

    return 0;
}