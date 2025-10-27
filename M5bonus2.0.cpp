#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm> // For std::min and std::max
#include <limits>    // For numeric_limits

using namespace std;

// --- Unit Definitions based on A&A Rules ---

// 1. Define the unit types
enum UnitType { INFANTRY, TANK, FIGHTER, UNIT_COUNT };

// 2. Map unit types to their names for display
const map<UnitType, string> UNIT_NAMES = {
    {INFANTRY, "Infantry"},
    {TANK, "Tank"},
    {FIGHTER, "Fighter"}
};

// 3. Define the attack and defense values (roll <= value = hit)
// A&A values: Infantry (Att 1, Def 2), Tank (Att 3, Def 3), Fighter (Att 3, Def 4)
struct UnitStats {
    int attack_value;
    int defense_value;
};

const map<UnitType, UnitStats> UNIT_STATS = {
    {INFANTRY, {1, 2}},
    {TANK,     {3, 3}},
    {FIGHTER,  {3, 4}}
};

// --- Helper Functions ---

/**
 * @brief Rolls a standard six-sided die (D6).
 * @return int A random integer from 1 to 6.
 */
int roll_d6() {
    return (rand() % 6) + 1;
}

/**
 * @brief Safely reads an integer input (choice of 1 or 0) from the user.
 * @param prompt The message to display.
 * @return int The validated user input (1 or 0).
 */
int get_user_choice(const string& prompt) {
    int choice;
    while (true) {
        cout << prompt;
        if (!(cin >> choice) || (choice != 0 && choice != 1)) {
            cout << "\n[System] Invalid input. Please enter 1 (Yes) or 0 (No)." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        } else {
            return choice;
        }
    }
}

/**
 * @brief Displays the current composition of a force.
 * @param name The name of the force (e.g., "Allies").
 * @param force A map containing unit counts.
 */
void display_force(const string& name, const map<UnitType, int>& force) {
    cout << "\n=== " << name << " Force ===" << endl;
    bool has_units = false;
    for (const auto& pair : force) {
        if (pair.second > 0) {
            has_units = true;
            cout << "  " << UNIT_NAMES.at(pair.first) << ": " << pair.second;
            cout << " (Att $\\le$" << UNIT_STATS.at(pair.first).attack_value;
            cout << ", Def $\\le$" << UNIT_STATS.at(pair.first).defense_value << ")" << endl;
        }
    }
    if (!has_units) {
        cout << "  *** Force Eliminated ***" << endl;
    }
}

/**
 * @brief Checks if a force has any units remaining.
 * @param force The map of units.
 * @return bool True if total unit count is zero.
 */
bool is_force_eliminated(const map<UnitType, int>& force) {
    int total = 0;
    for (const auto& pair : force) {
        total += pair.second;
    }
    return total == 0;
}

/**
 * @brief Simulates one side's attack phase and returns the total hits scored.
 * @param name The name of the attacking/defending force.
 * @param attacker_force The map of units performing the attack.
 * @param is_attacking True if units use their attack value, false if they use their defense value (as defenders).
 * @return int The total number of successful hits.
 */
int resolve_attack_phase(const string& name, const map<UnitType, int>& attacker_force, bool is_attacking) {
    if (is_force_eliminated(attacker_force)) return 0;

    int total_hits = 0;
    string action = is_attacking ? "Attacking" : "Defending";
    cout << "\n[COMBAT] " << name << " " << action << "..." << endl;

    for (const auto& pair : attacker_force) {
        UnitType type = pair.first;
        int count = pair.second;
        int hit_value = is_attacking ? UNIT_STATS.at(type).attack_value : UNIT_STATS.at(type).defense_value;

        if (count > 0) {
            int unit_hits = 0;
            cout << "  - " << UNIT_NAMES.at(type) << " x" << count << " (Roll $\\le$" << hit_value << "): ";

            // Roll for each unit of this type
            for (int i = 0; i < count; ++i) {
                int roll = roll_d6();
                if (roll <= hit_value) {
                    unit_hits++;
                    cout << "($\\checkmark$" << roll << ") "; // $\checkmark$ for hit
                } else {
                    cout << "($\\times$" << roll << ") "; // $\times$ for miss
                }
            }
            cout << "-> Hits: **" << unit_hits << "**" << endl;
            total_hits += unit_hits;
        }
    }

    cout << "--- Total Hits Scored: " << total_hits << endl;
    return total_hits;
}

/**
 * @brief Allows a force to distribute and take losses based on hits scored against them.
 * @param force The map of units taking losses (modified by reference).
 * @param hits_taken The number of casualties to assign.
 */
void take_losses(map<UnitType, int>& force, int hits_taken) {
    if (hits_taken <= 0) {
        cout << "No losses taken." << endl;
        return;
    }

    cout << "Taking " << hits_taken << " losses." << endl;
    int losses_remaining = hits_taken;

    // Loss priority: Infantry (cheapest) -> Tank -> Fighter (most expensive/valuable)
    // Fighters are often considered most valuable in A&A and are taken last.
    vector<UnitType> loss_order = {INFANTRY, TANK, FIGHTER};

    for (UnitType type : loss_order) {
        if (losses_remaining <= 0) break;

        int available_units = force[type];
        int units_lost = min(losses_remaining, available_units);

        force[type] -= units_lost;
        losses_remaining -= units_lost;

        if (units_lost > 0) {
            cout << "  - Lost " << units_lost << " " << UNIT_NAMES.at(type) << "." << endl;
        }
    }
}

// --- Main Execution ---

int main() {
    // Initialize RNG seed
    srand(static_cast<unsigned int>(time(0)));

    cout << "=== AXIS & ALLIES 10-MINUTE COMBAT SIMULATOR ===" << endl;
    cout << "This simulates a full battle until one side is eliminated or the attacker retreats." << endl;
    cout << "Attacker rolls $\\le$ Attacker's value; Defender rolls $\\le$ Defender's value." << endl;

    // Define starting forces (Allies are the Attacker, Axis are the Defender)
    map<UnitType, int> allied_force = {
        {INFANTRY, 5},
        {TANK, 1},
        {FIGHTER, 1}
    };

    map<UnitType, int> axis_force = {
        {INFANTRY, 4},
        {TANK, 2},
        {FIGHTER, 1}
    };

    display_force("Starting Allied (Attacker)", allied_force);
    display_force("Starting Axis (Defender)", axis_force);
    
    // Prompt to start
    int start = get_user_choice("\nType '1' to start the combat round (0 to quit): ");
    if (start == 0) {
        cout << "Exiting simulator." << endl;
        return 0;
    }

    bool battle_continues = true;
    int round_count = 1;

    // --- Core Battle Loop ---
    while (battle_continues) {
        cout << "\n##########################################" << endl;
        cout << "            ROUND " << round_count++ << " START" << endl;
        cout << "##########################################" << endl;
        
        display_force("Allied (Attacker)", allied_force);
        display_force("Axis (Defender)", axis_force);

        if (is_force_eliminated(allied_force) || is_force_eliminated(axis_force)) {
            // One side was already eliminated (e.g., from the previous round)
            break;
        }

        // 1. Resolve Combat Simultaneously
        int allies_hits = resolve_attack_phase("Allies", allied_force, true);
        int axis_hits = resolve_attack_phase("Axis", axis_force, false);

        // 2. Take Losses
        cout << "\n<<< Allied (Attacker) Taking Losses >>>" << endl;
        take_losses(allied_force, axis_hits);

        cout << "\n<<< Axis (Defender) Taking Losses >>>" << endl;
        take_losses(axis_force, allies_hits);

        cout << "\n==========================================" << endl;
        cout << "          ROUND RESOLUTION COMPLETE" << endl;
        cout << "==========================================" << endl;

        // 3. Check for Battle Conclusion
        if (is_force_eliminated(axis_force)) {
            // Allied Victory - Defender eliminated
            break; 
        }

        if (is_force_eliminated(allied_force)) {
            // Axis Victory - Attacker eliminated
            break;
        }

        // 4. Attacker decides to Retreat (Crucial for a quick game)
        int retreat_choice = get_user_choice("\nDo the Allied forces continue the attack? (1 = Yes, 0 = Retreat): ");
        if (retreat_choice == 0) {
            cout << "\n[RETREAT] The Allied Attacker chooses to withdraw their remaining forces." << endl;
            battle_continues = false;
        }
    }

    // --- Final Outcome ---
    cout << "\n==========================================" << endl;
    cout << "             BATTLE CONCLUDED" << endl;
    cout << "==========================================" << endl;

    display_force("Final Allied (Attacker)", allied_force);
    display_force("Final Axis (Defender)", axis_force);

    if (is_force_eliminated(axis_force) && !is_force_eliminated(allied_force)) {
        cout << "\n*** ALLIED MAJOR VICTORY! *** The territory is secured." << endl;
    } else if (is_force_eliminated(allied_force) && !is_force_eliminated(axis_force)) {
        cout << "\n*** AXIS DEFENSIVE VICTORY! *** The attack was repelled." << endl;
    } else if (is_force_eliminated(allied_force) && is_force_eliminated(axis_force)) {
         cout << "\n*** MUTUAL ANNIHILATION! *** Neither side survived the battle." << endl;
    } else {
        // Only possible if Attacker retreated
        cout << "\n*** AXIS VICTORY BY RETREAT! *** The Allied forces withdrew." << endl;
    }
    
    return 0;
}
