/* CSC 134
M6HW1
Curtis Cooper
1 DEC 2025
Avengers Battle Game
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Directions
enum Direction { NORTH = 0, EAST, SOUTH, WEST, NUM_DIRECTIONS };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

// Rooms (Battle Zones)
enum Room { HQ = 0, NEW_YORK, WAKANDA, VILLAIN_LAIR, NUM_ROOMS };

int main() {
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

    // Room connections
    int connections[NUM_ROOMS][NUM_DIRECTIONS] = {
        { NEW_YORK, WAKANDA, -1, -1 },  // HQ
        { -1, -1, HQ, -1 },             // New York
        { -1, VILLAIN_LAIR, -1, HQ },   // Wakanda
        { -1, -1, -1, WAKANDA }         // Villain's Lair
    };

    // Game state
    int currentRoom = HQ;
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