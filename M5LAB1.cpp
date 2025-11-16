/* CSC 134
 M5LAB1
 Curtis Cooper
 5 NOV 2025
*/

#include <iostream>
using namespace std;

// Function declarations
int  getPlayerChoice(int maxChoice); // let player choose options
void showChoices(string choice1, string choice2, string choice3);  // display the player choice menus
// Story choices
void game_start();
void game_front_door();
void choice_back_door();
void choice_go_home();
void final_showdown();     // NEW – exciting ending
void secret_basement();
const int MAX = 3; // max possible choices per node


// main()
int main() {
    /*
    int choice;
    int max = 3;
    showChoices("1","2","3");
    choice = getPlayerChoice(max);
    cout << "You chose: " << choice << endl;
    */
    // Start the game
    game_start();


    // ending
    return 0;
}

// Function definitions
/**
 * Get a valid choice from the player.
 * example: if maxChoice is 3, they can choose 1, 2, or 3.
 */
int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Your choice: ";
        cin >> choice;
        // You can add extra validation if you want.

        // Validate range 
        if (choice >= 1 && choice <= maxChoice) {
            return choice; // same number they enter
        }

        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}

void showChoices(string choice1, string choice2, string choice3) {
    // A quick menu. If a choice is empty ("") it's not shown
    // but there must always be at least one choice.
    // Example: showChoices("run","fight","hide");
    cout << "---- MAKE YOUR CHOICE ----" << endl;
    int num = 1;
    cout << num << ". " << choice1 << endl;
    num++;

    if (choice2 != "") {
        cout << num << ". " << choice2 << endl;
        num++;
    }

    if (choice3 != "") {
        cout << num << ". " << choice3 << endl;
        num++;
    }

}

//////////////////////////////////////////////////////////
// Story-related functions
// Each story choice leads to a new function
// with new text, and new choices.
//////////////////////////////////////////////////////////

// Game start
void game_start() {
    /* Every node of the story does this:
        - describe what's going on using the R"(message)" 
                cout method.
        - showChoices() with up to 3 strings included
        - getPlayerChoice() with the max set to up to 3
        - if statements to branch to other nodes

    */
   int choice;
   // R for Raw -- print every line as is until it ends
   cout << R"(while Home shoping, you arrive at a home that is not listed in the MLS but has a big For Sale sign in the front with 
    a very reasonable price. This home is your dream home from curb appeal. It appears to have a pool in the backyard, a patio for the grill, 
    everything you invisioned when thinking about buying a home.It appears to be well manicured and maintained, However this home does not have 
    any sale history. It sits in the back of a Cul-de-sac infront of a cemetery reportedly people have had weird paranormal experiences with in the past.
    The sign states there is an open house feel free to walk in and check things out. You think you see a light on in the living room, but no vehicle in the
    drive way. it is late in the evening the sun is about to go down...?
    )";
    // show choices
    showChoices("Go check the front door.",
                "Walk around back and check the garden",
                "Forget it and go home.");
    // make choices
    choice = getPlayerChoice(MAX);
    // branch from here
    // in your program, call another story function!
   if (choice == 1) {
        game_front_door();
    }
    if (choice == 2) {
        choice_back_door();
    }
    if (choice == 3) {
        choice_go_home();
}
void game_front_door() {
    int choice;

    cout << R"(You walk up to the front door. It's cracked open, just barely.
A cold breeze escapes through the gap. The porch light flickers even though
the wind is completely still. Something inside the darkness shifts.

Do you enter?
)";

    showChoices("Push the door open.",
                "Knock politely.",
                "Call out: ‘Hello? Anyone here?’");

    choice = getPlayerChoice(MAX);

    if (choice == 1) {
        cout << "You push it open... and feel something brush past your leg. A shadow darts deeper inside." << endl;
        secret_basement();
    }
    else if (choice == 2) {
        cout << "You knock. The door swings open wider... as if inviting you in." << endl;
        secret_basement();
    }
    else if (choice == 3) {
        cout << "Your voice echoes. Something upstairs answers with a faint whisper: 'Come find me...'" << endl;
        secret_basement();
    }
}

void choice_back_door() {
    int choice;

    cout << R"(You walk around back. The garden is perfectly trimmed…
too perfect. No weeds, no insects, no signs of life.

Then a motion light pops on.
Something moves behind the shed.
A low growl vibrates the air.
)";

    showChoices("Investigate behind the shed.",
                "Check the shed itself.",
                "Retreat to the front door.");

    choice = getPlayerChoice(MAX);

    if (choice == 1) {
        cout << "You step behind the shed—fresh footprints lead to a cellar door you hadn't seen before." << endl;
        secret_basement();
    }
    else if (choice == 2) {
        cout << "The shed is empty... except for a long staircase descending into darkness." << endl;
        secret_basement();
    }
    else if (choice == 3) {
        cout << "You hurry to the front. The door is open now… waiting." << endl;
        secret_basement();
    }
}

void choice_go_home() {
    int choice;

    cout << R"(As you turn to leave, something whispers behind you:
"Don't go..."

Cold air wraps around your neck.
Your car suddenly feels miles away.
)";

    showChoices("Turn around.",
                "Run for the car.",
                "");

    choice = getPlayerChoice(2);

    if (choice == 1) {
        cout << "You turn… the house’s front door is now wide open. A silhouette stands inside." << endl;
        secret_basement();
    }
    else if (choice == 2) {
        cout << "You sprint! But every step feels heavier. You trip—something drags you back toward the house." << endl;
        secret_basement();
    }
}

//////////////////////////////////////////////////////////
// FINAL BRANCHES
//////////////////////////////////////////////////////////

void secret_basement() {
    int choice;

    cout << R"(You find yourself at the entrance to a hidden basement.
A staircase descends into total darkness. The smell of earth and old wood fills the air.
A distant humming pulses beneath the ground—steady, unnatural.

Something *down there* is awake.
)";

    showChoices("Descend into the basement.",
                "Call out again into the dark.",
                "Try to leave the house.");

    choice = getPlayerChoice(MAX);

    if (choice == 1) {
        cout << "You walk down the steps... each creak echoes like a scream." << endl;
        final_showdown();
    }
    else if (choice == 2) {
        cout << "Your voice echoes… then stops abruptly, cut short by a whisper beside your ear: 'Finally...'" << endl;
        final_showdown();
    }
    else if (choice == 3) {
        cout << "You turn to flee—but the door slams shut. Locks click from the inside." << endl;
        final_showdown();
    }
}

void final_showdown() {
    cout << R"(
At the bottom of the staircase, a massive chamber opens before you.
Candles circle the room, forming strange symbols carved into the dirt.
In the center stands a tall figure, faceless and shifting like smoke.

It raises an arm toward you.  
The humming stops.

For a moment, the world is silent.

Then every candle goes out.

A voice—hundreds of voices layered together—whispers:

        "Welcome home."

The floor gives way beneath your feet.
You fall into darkness.
Your last thought is that the house wasn't abandoned…
It was waiting.
)";

    cout << "\n\n--- THE END ---\n";
}