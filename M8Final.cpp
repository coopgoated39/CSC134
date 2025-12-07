/* CSC 134
M8Final
Curtis Cooper
1 DEC 2025
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
using namespace std;

// Directions
enum Direction { NORTH = 0, EAST, SOUTH, WEST, NUM_DIRECTIONS };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

// Rooms (Battle Zones)
enum Room { HQ = 0, NEW_YORK, WAKANDA, VILLAIN_LAIR, NUM_ROOMS };

int main() {
    srand(time(0)); // Seed random

    // Room names
    string roomNames[NUM_ROOMS] = {
        "Avengers HQ",
        "New York City",
        "Wakanda",
        "Villain's Lair"
    };

    // Room descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "The Avengers HQ is buzzing with activity. Heroes gather here to plan.",
        "The streets of New York are chaotic with villains attacking civilians.",
        "Wakanda's advanced tech city glows with energy. Allies stand ready.",
        "The villain's lair is dark and full of traps. Danger lurks everywhere."
    };

    // Objects in rooms
    string roomObjects[NUM_ROOMS] = {
        "Mjolnir",      // HQ
        "Shield",       // New York
        "Vibranium Suit", // Wakanda
        "Infinity Stone" // Villain's Lair
    };

    // Villain HP in each room (-1 = no villain)
    int villainHP[NUM_ROOMS] = { -1, 30, 40, 50 };

    // Room connections
    int connections[NUM_ROOMS][NUM_DIRECTIONS] = {
        { NEW_YORK, WAKANDA, -1, -1 },  // HQ
        { -1, -1, HQ, -1 },             // New York
        { -1, VILLAIN_LAIR, -1, HQ },   // Wakanda
        { -1, -1, -1, WAKANDA }         // Villain's Lair
    };

    // Game state
    int currentRoom = HQ;
    int playerHP = 100;
    vector<string> inventory;
    bool running = true;

    cout << "\nWelcome to the Avengers Battle!\n";

    while (running) {
        cout << "\nYou are in " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;

        // Show objects
        cout << "You see a " << roomObjects[currentRoom] << " here.\n";

        // Exits
        cout << "Exits: ";
        for (int d = 0; d < NUM_DIRECTIONS; d++)
            if (connections[currentRoom][d] != -1)
                cout << DIRECTION_NAMES[d] << " ";
        cout << endl;

        // Villain encounter
        if (villainHP[currentRoom] > 0) {
            cout << "A villain appears with " << villainHP[currentRoom] << " HP!\n";
            while (villainHP[currentRoom] > 0 && playerHP > 0) {
                cout << "\nYour HP: " << playerHP << " | Villain HP: " << villainHP[currentRoom] << endl;
                cout << "Do you want to 'attack' or 'run'? ";
                string action;
                cin >> action;

                if (action == "attack") {
                    int playerDamage = rand() % 20 + 5; // Base 5-24
                    int villainDamage = rand() % 15 + 5; // Base 5-19

                    // Apply item effects for attack
                    if (find(inventory.begin(), inventory.end(), "Mjolnir") != inventory.end()) playerDamage += 10;
                    if (find(inventory.begin(), inventory.end(), "Infinity Stone") != inventory.end()) playerDamage += 20;

                    // Apply item effects for defense
                    if (find(inventory.begin(), inventory.end(), "Shield") != inventory.end()) villainDamage -= 5;
                    if (find(inventory.begin(), inventory.end(), "Vibranium Suit") != inventory.end()) villainDamage -= 10;
                    if (villainDamage < 0) villainDamage = 0;

                    villainHP[currentRoom] -= playerDamage;
                    cout << "You deal " << playerDamage << " damage to the villain!\n";

                    if (villainHP[currentRoom] > 0) {
                        playerHP -= villainDamage;
                        cout << "The villain hits back for " << villainDamage << " damage!\n";
                    } else {
                        cout << "You defeated the villain!\n";
                    }
                }
                else if (action == "run") {
                    cout << "You retreat to the previous room.\n";
                    if (connections[currentRoom][SOUTH] != -1) currentRoom = connections[currentRoom][SOUTH];
                    else if (connections[currentRoom][WEST] != -1) currentRoom = connections[currentRoom][WEST];
                    else if (connections[currentRoom][NORTH] != -1) currentRoom = connections[currentRoom][NORTH];
                    else if (connections[currentRoom][EAST] != -1) currentRoom = connections[currentRoom][EAST];
                    break;
                }
                else {
                    cout << "Unknown action.\n";
                }

                if (playerHP <= 0) {
                    cout << "You were defeated! Game over.\n";
                    running = false;
                    break;
                }
            }
            if (!running) break;
        }

        // Player command
        string cmd;
        cout << "\nWhat do you do? ";
        cin >> cmd;

        // Movement
        if (cmd == "north" || cmd == "n")
            if (connections[currentRoom][NORTH] != -1) currentRoom = connections[currentRoom][NORTH];
            else cout << "You can't go that way.\n";

        else if (cmd == "east" || cmd == "e")
            if (connections[currentRoom][EAST] != -1) currentRoom = connections[currentRoom][EAST];
            else cout << "You can't go that way.\n";

        else if (cmd == "south" || cmd == "s")
            if (connections[currentRoom][SOUTH] != -1) currentRoom = connections[currentRoom][SOUTH];
            else cout << "You can't go that way.\n";

        else if (cmd == "west" || cmd == "w")
            if (connections[currentRoom][WEST] != -1) currentRoom = connections[currentRoom][WEST];
            else cout << "You can't go that way.\n";

        // Interactions
        else if (cmd == "look") {
            cout << "You inspect the " << roomObjects[currentRoom] << ".\n";
        }
        else if (cmd == "take") {
            cout << "You take the " << roomObjects[currentRoom] << ".\n";
            inventory.push_back(roomObjects[currentRoom]);
        }
        else if (cmd == "quit" || cmd == "q") {
            running = false;
        }
        else {
            cout << "Unknown command.\n";
        }
    }

    cout << "\nThanks for playing the Avengers Battle!\n";
    
    return 0;
}