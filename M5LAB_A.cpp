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
    
    return 0; 
    
}


