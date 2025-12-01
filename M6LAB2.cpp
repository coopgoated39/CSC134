/* CSC 134
M6LAB2
Curtis Cooper
1 DEC 2025
*/

//interactions are look, take, or quit anything else is an unknown command//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Directions
enum Direction { NORTH = 0, EAST, SOUTH, WEST, NUM_DIRECTIONS };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

// Rooms (Exhibit Halls)
enum Room { LOBBY = 0, DINOSAUR_HALL, ART_GALLERY, SPACE_EXHIBIT, STORAGE_ROOM, NUM_ROOMS };

int main() {
    // Room names
    string roomNames[NUM_ROOMS] = {
        "Museum Lobby",
        "Dinosaur Hall",
        "Art Gallery",
        "Space Exhibit",
        "Storage Room"
    };

    // Room descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "A bright lobby with brochures and information signs.",
        "Fossil skeletons stand proudly under spotlights.",
        "Famous paintings hang from quiet white walls.",
        "Models of planets and rockets fill the dark room.",
        "A cluttered storage area with unused display pieces."
    };

    // Objects in rooms
    string roomObjects[NUM_ROOMS] = {
        "brochure",       // Lobby
        "dinosaur fossil",// Dino Hall
        "painting",       // Art Gallery
        "moon rock",      // Space Exhibit
        "old crate"       // Storage Room
    };

    // Room connections
    int connections[NUM_ROOMS][NUM_DIRECTIONS] = {
        { DINOSAUR_HALL, ART_GALLERY, -1, -1 },      // Lobby
        { -1, -1, LOBBY, -1 },                       // Dinosaur Hall
        { -1, SPACE_EXHIBIT, -1, LOBBY },            // Art Gallery
        { -1, -1, -1, ART_GALLERY },                 // Space Exhibit
        { -1, -1, -1, -1 }                           // Storage Room (no exits)
    };

    // Game state
    int currentRoom = LOBBY;
    vector<string> inventory;
    bool running = true;

    cout << "\nWelcome to the Interactive Museum!\n";

    while (running) {
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
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

    cout << "\nThanks for visiting the museum!\n";
    return 0;
}
