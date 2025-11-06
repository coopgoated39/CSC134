/* CSC 134
M4Bonus
Curtis Cooper
6 NOV 2025
the crossroads twine story
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function declarations
void clearScreen();
void waitForEnter();
int getChoice(int min, int max);
void start();
void door1();
void door2();
void door3();
void powerEnding();
void wisdomEnding();
void correctAnswer();
void wrongAnswer();
void giveUp();
void safeEnding();
void wonderEnding();
void neutralEnding();

int main() {
    cout << "=================================\n";
    cout << "      THE CROSSROADS GAME\n";
    cout << "=================================\n\n";
    
    start();
    
    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int getChoice(int min, int max) {
    int choice;
    while (true) {
        cout << "\nEnter your choice (" << min << "-" << max << "): ";
        cin >> choice;
        
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

void start() {
    clearScreen();
    cout << "You stand in a mysterious hallway with three doors before you.\n\n";
    cout << "Door 1 is painted bright red and feels warm to the touch.\n";
    cout << "Door 2 is old and wooden, with strange carvings.\n";
    cout << "Door 3 is made of crystal and shimmers with light.\n\n";
    
    cout << "Do you choose:\n\n";
    cout << "[1] Door 1\n";
    cout << "[2] Door 2\n";
    cout << "[3] Door 3\n";
    
    int choice = getChoice(1, 3);
    
    switch(choice) {
        case 1: door1(); break;
        case 2: door2(); break;
        case 3: door3(); break;
    }
}

void door1() {
    clearScreen();
    cout << "You open the red door and feel a wave of heat.\n";
    cout << "Inside is a fire spirit dancing among flames.\n\n";
    cout << "\"Welcome, brave one! I can grant you power or wisdom.\"\n\n";
    
    cout << "Do you choose:\n\n";
    cout << "[1] Ask for power\n";
    cout << "[2] Ask for wisdom\n";
    cout << "[3] Leave quietly\n";
    
    int choice = getChoice(1, 3);
    
    switch(choice) {
        case 1: powerEnding(); break;
        case 2: wisdomEnding(); break;
        case 3: neutralEnding(); break;
    }
}

void door2() {
    clearScreen();
    cout << "Behind the wooden door is a vast library filled with ancient books.\n";
    cout << "A mysterious figure in robes appears.\n\n";
    cout << "\"Solve my riddle: What has keys but no locks,\n";
    cout << "space but no room, and you can enter but not go inside?\"\n\n";
    
    cout << "Do you choose:\n\n";
    cout << "[1] Answer: \"A keyboard\"\n";
    cout << "[2] Answer: \"A piano\"\n";
    cout << "[3] Give up\n";
    
    int choice = getChoice(1, 3);
    
    switch(choice) {
        case 1: correctAnswer(); break;
        case 2: wrongAnswer(); break;
        case 3: giveUp(); break;
    }
}

void door3() {
    clearScreen();
    cout << "The crystal door opens into a magical garden where everything sparkles.\n";
    cout << "A fairy hovers before you.\n\n";
    cout << "\"Welcome! I can send you home now, or show you more wonders.\"\n\n";
    
    cout << "Do you choose:\n\n";
    cout << "[1] Go home\n";
    cout << "[2] See more wonders\n";
    
    int choice = getChoice(1, 2);
    
    switch(choice) {
        case 1: safeEnding(); break;
        case 2: wonderEnding(); break;
    }
}

void powerEnding() {
    clearScreen();
    cout << "The fire spirit grants you incredible power!\n";
    cout << "Flames dance at your fingertips as you leave the hallway.\n\n";
    cout << "** THE END - Power Acquired! **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void wisdomEnding() {
    clearScreen();
    cout << "The fire spirit fills your mind with ancient knowledge.\n";
    cout << "You understand truths that few mortals ever learn.\n\n";
    cout << "** THE END - Wisdom Gained! **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void correctAnswer() {
    clearScreen();
    cout << "\"Correct!\" The figure smiles and hands you a magical book.\n";
    cout << "The book contains secrets of the universe.\n\n";
    cout << "** THE END - Victory! **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void wrongAnswer() {
    clearScreen();
    cout << "\"Incorrect,\" the figure says sadly.\n";
    cout << "You are gently escorted out of the library.\n\n";
    cout << "** THE END - Better Luck Next Time **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void giveUp() {
    clearScreen();
    cout << "You admit you don't know the answer.\n";
    cout << "The figure nods and shows you the exit.\n\n";
    cout << "** THE END - Honest Departure **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void safeEnding() {
    clearScreen();
    cout << "The fairy waves her wand and you're instantly transported home.\n";
    cout << "You wake up in your bed, wondering if it was all a dream.\n\n";
    cout << "** THE END - Safe Journey **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void wonderEnding() {
    clearScreen();
    cout << "The fairy takes you on an incredible journey through magical realms.\n";
    cout << "You see wonders beyond imagination and return home changed forever.\n\n";
    cout << "** THE END - Wonder and Magic! **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}

void neutralEnding() {
    clearScreen();
    cout << "You quietly back away from the fire spirit.\n";
    cout << "The door closes behind you and you find yourself back home.\n\n";
    cout << "** THE END - Peaceful Departure **\n\n";
    
    cout << "Play again? [1] Yes [2] No: ";
    int choice = getChoice(1, 2);
    if (choice == 1) start();
}