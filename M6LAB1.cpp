/* CSC 134
M6LAB1
Curtis Cooper
12 NOV 2025
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <limits>
using namespace std;

// ============================================================================
// GLOBAL VARIABLES
// ============================================================================
vector<char> airsoftGun; // 'B' = Plastic BB, 'P' = Pain Shot

int playerScore = 3;
int opponentScore = 3;

string currentPlayer = "Player";
bool gameOver = false;

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
void setupGame();
void loadAirsoftGun(int bbCount, int painCount);
void shuffleAirsoftGun();
void displayGameState();
void displayGun(bool showContents);
char fireShot();
void playerTurn();
void opponentTurn();
void checkGameOver();

// ============================================================================
// MAIN
// ============================================================================
int main() {
    srand(time(0));

    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║            AIRSOFT SHOOTOUT            ║" << endl;
    cout << "║        Safe-Mode Shooting Game         ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\nRules:" << endl;
    cout << "⚪ Plastic BB = Harmless shot (you get another turn!)" << endl;
    cout << "🔴 Pain Shot = Stinging hit! (lose 1 point)" << endl;
    cout << "First to 0 points loses!\n" << endl;

    setupGame();

    while (!gameOver) {
        if (currentPlayer == "Player")
            playerTurn();
        else
            opponentTurn();

        checkGameOver();

        if (airsoftGun.empty() && !gameOver) {
            cout << "\n🔄 Magazine empty! Reloading..." << endl;
            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            setupGame();
        }
    }

    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║              GAME OVER!                ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    if (playerScore <= 0)
        cout << "🔴 You took the final pain shot! Opponent wins!" << endl;
    else
        cout << "🎉 Opponent took the final pain shot! You win!" << endl;

    return 0;
}

// ============================================================================
// GAME SETUP
// ============================================================================
void setupGame() {
    airsoftGun.clear();

    int bbCount = 1 + rand() % 3;   // 1–3 safe BB shots
    int painCount = 1 + rand() % 2; // 1–2 pain shots

    loadAirsoftGun(bbCount, painCount);
    shuffleAirsoftGun();

    cout << "\n🔫 Magazine loaded!" << endl;
    displayGun(false);
}

void loadAirsoftGun(int bbCount, int painCount) {
    for (int i = 0; i < bbCount; i++)
        airsoftGun.push_back('B');

    for (int i = 0; i < painCount; i++)
        airsoftGun.push_back('P');
}

void shuffleAirsoftGun() {
    random_shuffle(airsoftGun.begin(), airsoftGun.end());
}

// ============================================================================
// DISPLAY
// ============================================================================
void displayGameState() {
    cout << "\n┌─────────────────────────────────────┐" << endl;
    cout << "│ Player: " << playerScore << " points   Opponent: " << opponentScore << " points │" << endl;
    cout << "└─────────────────────────────────────┘" << endl;
}

void displayGun(bool showContents) {
    int bbCount = 0, painCount = 0;

    for (char c : airsoftGun) {
        if (c == 'B') bbCount++;
        else painCount++;
    }

    cout << "Magazine contents: ";
    cout << "⚪ " << bbCount << " BB rounds, ";
    cout << "🔴 " << painCount << " pain shots ";
    cout << "(" << airsoftGun.size() << " total)" << endl;

    if (showContents) {
        cout << "Actual order: ";
        for (char c : airsoftGun)
            cout << (c == 'B' ? "⚪ " : "🔴 ");
        cout << endl;
    }
}

// ============================================================================
// CORE MECHANICS
// ============================================================================
char fireShot() {
    if (airsoftGun.empty())
        return 'E';

    char round = airsoftGun.front();
    airsoftGun.erase(airsoftGun.begin());
    return round;
}

// ============================================================================
// TURN HANDLING
// ============================================================================
void playerTurn() {
    displayGameState();
    displayGun(false);

    cout << "\n>>> YOUR TURN <<<" << endl;
    cout << "Shoot at: [1] Yourself  [2] Opponent" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Invalid. Enter 1 or 2: ";
        cin >> choice;
    }

    cout << "\n🔫 *PEW!* ";
    char result = fireShot();

    if (result == 'B') {
        cout << "⚪ Safe BB hit!" << endl;
        if (choice == 1)
            cout << "You're fine! You get another turn!" << endl;
        else {
            cout << "Opponent is unharmed." << endl;
            currentPlayer = "Opponent";
        }
    }
    else if (result == 'P') {
        cout << "🔴 Pain Shot!" << endl;
        if (choice == 1) {
            cout << "Ouch! You lose 1 point!" << endl;
            playerScore--;
        } else {
            cout << "Opponent takes the hit! They lose 1 point!" << endl;
            opponentScore--;
        }
        currentPlayer = "Opponent";
    }
}

void opponentTurn() {
    displayGameState();
    displayGun(false);

    cout << "\n>>> OPPONENT'S TURN <<<" << endl;
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    int choice = 1 + rand() % 2;

    if (choice == 1)
        cout << "Opponent shoots themselves!" << endl;
    else
        cout << "Opponent fires at YOU!" << endl;

    cout << "\n🔫 *PEW!* ";
    char result = fireShot();

    if (result == 'B') {
        cout << "⚪ Safe BB hit!" << endl;
        if (choice == 1)
            cout << "Opponent is fine and takes another turn!" << endl;
        else {
            cout << "You're fine." << endl;
            currentPlayer = "Player";
        }
    }
    else if (result == 'P') {
        cout << "🔴 Pain Shot!" << endl;
        if (choice == 1) {
            cout << "Opponent takes the hit! -1 point!" << endl;
            opponentScore--;
        } else {
            cout << "You take the hit! -1 point!" << endl;
            playerScore--;
        }
        currentPlayer = "Player";
    }
}

void checkGameOver() {
    if (playerScore <= 0 || opponentScore <= 0)
        gameOver = true;
}