/*
CSC 134
M5_LABA - Loop Fundamentals  
Curtis Cooper 10/29/25
*/

#include <iostream>

using namespace std;

//Question 1//

int main() {
    int maxHP = 100;
    int hp = 30;
    const int healing = 10;

    cout << "Resting until healed." << endl;
    while (hp < maxHP) {
        hp += healing;
        cout << "HP: " << hp << "/" << maxHP << endl;
    }
    cout << "Fully rested." << endl;
    
}

int max_levl = 10;
int start_level = 1;
int strength = 10 + (start_level *2);
int dexterity = 8 + (start_level * 3);
int intelligence = 12 + (start_level * 1);

while 
