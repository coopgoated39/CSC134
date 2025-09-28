/*
CSC 134,M3T2
Curtis Cooper
9/28/25
Game.
*/

// this is crap game that gives player the option to keep playing.

# include <iostream>
#include <cmath>
#include <ctime>
#include <string>
 using namespace std;

 int main() {
    const int SIDES = 6; // yours will differ!

    //int seed = 19;
    int seed = time(0);

    // seed the random number generator
    srand(seed);

    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, total;
    char answer;

    do {
         // roll two dice
         roll1 = ( (rand() % SIDES)+1 );
         cout <<"Your roll is: " << roll1 << endl;
         
         roll2 = ((rand() % SIDES)+1 );
         cout <<"Your roll is: " << roll2 << endl;
         total = roll1 + roll2;
         
         //declare the rules and give options to keep rolling dice
         if (total == 7 || total == 11) {
            cout <<"You won: Would you like to roll again? (y/n)" << endl;
            cin >> answer;
        }
        
        else if (total == 2 ) {
            cout << "Snake Eyes, You crapped out, Would you like to roll again? (y/n)" << endl;
            cin >> answer;
        }
        else if (total != 2 && total != 7 && total != 11) {
            cout << "You crapped out looser, Would you like to roll again? (y/n)" << endl;
            cin >> answer;
        }
    }
    //continue game until customer wants to stop
    while (answer == 'y' || answer == 'Y');

    //exit statement
    cout << "Thanks for playing !" << endl;

    return 0;
        
    
    

 }