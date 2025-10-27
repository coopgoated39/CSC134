/*
CSC 134
M5Bonus - Games  
Curtis Cooper 10/27/25
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits> // For numeric_limits and robust input handling

// Use std namespace to avoid 'using namespace std;' globally, which is better practice.
using std::cout;
using std::cin;
using std::endl;
using std::string;

// ========== FUNCTION PROTOTYPES ==========
// Helper function for safe integer input
int get_user_choice(int min, int max, const string& prompt);

// Core game mechanic
int roll(int luck);

// Scenario functions
void Doctor(int &motivation, int &luck);
void Depressed_worker(int &motivation, int &luck);
void Criminal(int &motivation, int &luck);
void Entrepreneur(int &motivation, int &luck);
void Artist(int &motivation, int &luck);

// Game flow functions
bool Wizard(int &motivation, int &luck);
void display_stats(int motivation, int luck);
bool play_game(); // New function to contain the entire game loop

// ========== INPUT HELPER FUNCTION ==========

/**
 * @brief Safely reads an integer input from the user within a specified range.
 * @param min The minimum acceptable value.
 * @param max The maximum acceptable value.
 * @param prompt The message to display to the user.
 * @return int The validated user input.
 */
int get_user_choice(int min, int max, const string& prompt) {
    int choice;
    while (true) {
        cout << prompt;
        // Check if the input operation failed (e.g., non-numeric input)
        if (!(cin >> choice)) {
            cout << "\n[System] Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the error flags
            // Ignore the rest of the line to clear the bad input buffer
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (choice < min || choice > max) {
            // Check if the input is outside the acceptable range
            cout << "\n[System] Choice must be between " << min << " and " << max << ". Try again." << endl;
        } else {
            // Input is valid
            return choice;
        }
    }
}

// ========== STATS DISPLAY HELPER ==========

void display_stats(int motivation, int luck) {
    cout << "----------------------------------" << endl;
    cout << " Current Stats | Motivation: " << motivation << " | Luck: " << luck << endl;
    cout << "----------------------------------" << endl;
}

// ========== DICE ROLL MECHANIC ==========

/**
 * @brief Rolls a dice, with luck influencing the outcome.
 * Luck increases the chance of rolling higher numbers (up to a 5).
 * @param luck The player's luck stat.
 * @return int The dice roll result (1 to 5).
 */
int roll(int luck) {
    // 1. Determine the maximum possible roll.
    // Base max roll is 4. Luck gives a chance (luck * 5)% to increase the max roll to 5.
    int max_roll = ((rand() % 100) < (luck * 5)) ? 5 : 4;

    // 2. Roll the dice between 1 and the determined max_roll.
    int dice = (rand() % max_roll) + 1;

    // Output the roll result and explain the luck effect
    cout << "--- DICE ROLL ---" << endl;
    cout << "Your Luck (" << luck << ") gave you a " << (max_roll == 5 ? "small chance for a 5-roll" : "max roll of 4") << "." << endl;
    cout << "You rolled a **" << dice << "**!" << endl;
    cout << "-----------------" << endl;
    return dice;
}

// ========== SCENARIO DEFINITIONS ==========

void Doctor(int &motivation, int &luck) {
    cout << "\n[SCENARIO: DOCTOR]" << endl;
    cout << "You are a **doctor** — wise, disciplined, and successful." << endl;
    motivation += 10;
    luck += 3;
    display_stats(motivation, luck);
    cout << "Your dedication is recognized. The Wizard of Oz is impressed by your success." << endl;
}

void Depressed_worker(int &motivation, int &luck) {
    cout << "\n[SCENARIO: DEPRESSED WORKER]" << endl;
    cout << "You are a **depressed worker** stuck in a job you hate." << endl;
    motivation -= 5;
    display_stats(motivation, luck);

    cout << "You meet a mysterious stranger who offers you a chance to change your life." << endl;
    int choice = get_user_choice(0, 1, "Do you accept this risky chance? (1 = Yes, 0 = No): ");

    if (choice == 1) {
        luck += 2;
        cout << "\nYou accept the stranger's offer! Your Luck increased by 2." << endl;
        // The game flow will return to the Wizard/Roll section in the main loop
    } else {
        cout << "You choose to remain in your comfort zone. Life stays the same, and your journey ends here..." << endl;
        // To immediately end the game, we decrease motivation below the win condition
        motivation = 0;
    }
}

void Criminal(int &motivation, int &luck) {
    cout << "\n[SCENARIO: CRIMINAL]" << endl;
    cout << "You are a **criminal** — labeled and struggling to find your place in society." << endl;
    motivation -= 3;
    luck += 1;
    display_stats(motivation, luck);

    cout << "The Wizard offers you redemption if you prove your courage." << endl;
    int choice = get_user_choice(0, 1, "Do you accept the Wizard's challenge? (1 = Yes, 0 = No): ");

    if (choice == 0) {
        cout << "You refuse the challenge and fade into obscurity..." << endl;
        motivation = 0; // End condition
    }
}

void Entrepreneur(int &motivation, int &luck) {
    cout << "\n[SCENARIO: ENTREPRENEUR]" << endl;
    cout << "You become an **entrepreneur** — taking risks and chasing your dreams." << endl;
    motivation += 5;
    luck += 4;
    display_stats(motivation, luck);
    cout << "One day, you receive an invitation to meet the Wizard of Oz." << endl;
}

void Artist(int &motivation, int &luck) {
    cout << "\n[SCENARIO: ARTIST]" << endl;
    cout << "You choose the path of an **artist** — creative, passionate, and misunderstood." << endl;
    motivation += 7;
    luck += 2;
    display_stats(motivation, luck);
    cout << "Your art inspires others, and whispers of your work reach the Wizard himself." << endl;
}

// ========== GAME FLOW HUB (THE WIZARD) ==========

/**
 * @brief The Wizard acts as the main game checkpoint.
 * @param motivation The player's motivation stat.
 * @param luck The player's luck stat.
 * @return bool Returns true if the game should continue (i.e., roll again), false otherwise (win or quit).
 */
bool Wizard(int &motivation, int &luck) {
    cout << "\n==================================" << endl;
    cout << "     THE WONDERFUL WIZARD OF OZ!    " << endl;
    cout << "==================================" << endl;
    cout << "He says: 'All paths — success, failure, or struggle — teach wisdom.'" << endl;
    display_stats(motivation, luck);

    // WIN CONDITION CHECK
    if (motivation >= 20) {
        cout << "\n*** VICTORY ACHIEVED! ***" << endl;
        cout << "The Wizard declares you a master of perseverance and grants you eternal success!" << endl;
        return false; // Game ends
    }

    // CONTINUE OR QUIT
    cout << "\nYou have not yet reached true perseverance." << endl;
    int again = get_user_choice(0, 1, "You may choose to roll again for a new destiny. (1 = Yes, 0 = No): ");

    if (again == 1) {
        return true; // Continue to the next roll/scenario
    } else {
        cout << "You choose to stop your journey. The Wizard bids you farewell." << endl;
        return false; // Game ends
    }
}

// ========== CORE GAME LOOP ==========

/**
 * @brief Contains the main game logic and flow.
 * @return bool Returns true if the player chooses to restart the game, false otherwise.
 */
bool play_game() {
    // --- Initialization ---
    int motivation = 10;
    int luck = 5;
    bool game_running = true;

    cout << "\n##################################" << endl;
    cout << "       GAME OF DESTINY STARTED      " << endl;
    cout << "##################################" << endl;
    cout << "You have come to see the wonderful Wizard of Oz to expedite your success." << endl;
    cout << "Be warned: avoiding hard work may come with a price." << endl;
    cout << "Your starting Motivation: " << motivation << " | Starting Luck: " << luck << endl;
    cout << "----------------------------------" << endl;

    int start = get_user_choice(1, 1, "When ready to start, type 1: ");
    if (start != 1) return false; // Should not happen with current logic, but safe fail.

    // --- Main Game Loop ---
    while (game_running) {
        // 1. Roll for Destiny
        int diceRoll = roll(luck);

        // 2. Determine Scenario
        if (diceRoll == 1)
            Depressed_worker(motivation, luck);
        else if (diceRoll == 2)
            Criminal(motivation, luck);
        else if (diceRoll == 3)
            Doctor(motivation, luck);
        else if (diceRoll == 4)
            Entrepreneur(motivation, luck);
        else // diceRoll == 5 (Only possible with high luck)
            Artist(motivation, luck);

        // 3. Check with the Wizard (Central Game Hub)
        // If Wizard returns false, the game ends (Win or Manual Quit)
        if (!Wizard(motivation, luck)) {
            game_running = false;
        }

        // Additional fail-safe exit condition for scenarios that set motivation = 0
        if (motivation <= 0 && game_running) {
            cout << "\n[GAME OVER] Your motivation has dropped too low. You have given up." << endl;
            game_running = false;
        }
    }

    // --- Game Over ---
    cout << "\n==================================" << endl;
    if (motivation >= 20) {
        cout << "       *** J O U R N E Y   C O M P L E T E D *** " << endl;
    } else {
        cout << "               G A M E   O V E R                " << endl;
    }
    cout << "==================================" << endl;
    cout << "Final Motivation: " << motivation << " | Final Luck: " << luck << endl;

    int restart = get_user_choice(0, 1, "Would you like to play again? (1 = Yes, 0 = No): ");
    return (restart == 1); // Return true if player wants to restart
}

// ========== MAIN FUNCTION (RESTART MANAGER) ==========

int main() {
    // Seed the random number generator only once at the start
    srand(static_cast<unsigned int>(time(0)));

    bool play_again = true;
    while (play_again) {
        play_again = play_game();
    }

    cout << "Thanks for playing the Game of Destiny! Goodbye." << endl;
    return 0;
}