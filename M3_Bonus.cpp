/*
CSC 134,M3T2
Curtis Cooper
10/1/25
Bonus Game.
*/

// This is custom crap game that has an initial buy in of 100 dollars player. Per roll cost 10$, 
// winning results in 100% profit, loosing reults in 100% lost of per roll amount. options to walk away will be given after each roll. 

# include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
 using namespace std;

 int main() {
    const int SIDES = 6;
    const int Bet_Amount = 10;
    const int Buy_In = 100; 

    //int seed = 19;
    int seed = time(0);

    // seed the random number generator
    srand(seed);

    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, total;
    char answer;
    int bankroll = Buy_In;

    cout <<"Welcome to the COOP_Goated crap game!"  << endl;
    cout <<"You brought in for $" << Buy_In << ". Each roll cost $" << Bet_Amount << endl;

    if (bankroll < Bet_Amount) {
        cout <<"You do not have enough money to place a $" << Bet_Amount << endl;
    }

    do {

        if (bankroll < Bet_Amount){ 
            cout <<"You only have $" << bankroll << "You need $" << Bet_Amount << " to roll.";
            break;
        }
        cout << "--------------------------------------------" << endl;
        cout <<"Place a $" << Bet_Amount << " bet. Your current bank roll is $" << bankroll <<endl;

         // roll two dice for the crap game 
         roll1 = ( (rand() % SIDES)+1 );
         cout <<"Your roll is: " << roll1 << endl;
         
         roll2 = ((rand() % SIDES)+1 );
         cout <<"Your roll is: " << roll2 << endl;
         total = roll1 + roll2;

         cout <<"---------------------------------------------" << endl;
         cout <<"the Total is " << total << endl;
         
         //declare the rules and give options to keep rolling dice
         if (total == 7 || total == 11) {
            int winnings = Bet_Amount * 2; bankroll += winnings; 
            cout <<"You won $" << Bet_Amount <<"Would you like to roll again? (y/n)" << endl;
            cin >> answer;
        }
        
        else if (total == 2 ) {
            cout << "Snake Eyes, You crapped out, you lost $" << Bet_Amount << endl;
            
        }
        else if (total != 2 && total != 7 && total != 11) {
            cout << "You crapped out looser, you lost $" << Bet_Amount << endl;
        }

            else { 
                cout << "Points: " << total << endl;

                cout <<"Your new bank roll is $" << bankroll << "." << endl;

            if (bankroll >= Bet_Amount) {
                cout << "Would you like to roll again? (y/n)" << endl;
                cin >> answer; 
            } else { 
                cout << "You can not aford the next to keep rolling" << endl;
                answer = 'n';
            }

                
            }
        
    }
    //continue game until player wants to stop
    while (answer == 'y' || answer == 'Y');

    //exit statements
    cout << "Thanks for playing !" << endl;

    int profit = bankroll - Buy_In;
    if (profit > 0) {
        cout <<"You made $ " << profit << endl;
    } else if (profit < 0) {
        cout <<"You lost $ " << abs(profit) <<'.' << endl;
    } else {
        cout <<"You broke even" << endl;
    }

    return 0;
        
    
    

 }