/*
CSC 134,M2T1
Curtis Cooper
9/3/25
revision of "sales" program from M1, now with user input.
*/

#include <iostream>
using namespace std;

int main() {
    // Declare varibles//
    string name = "Curtis Cooper";

    string item = "Apple";
    
    int apples = 100;

    int amountpurchased;

    double priceperApple = .25;
    //varible for user input//
    double totalprice = amountpurchased * priceperApple;   
    //Greet user//
    cout << "Welcome to " << name;

    cout << "'s Orchard" << endl;

    cout << "Each " << item << " cost" << priceperApple <<endl;

    cout << " How many would like to buy?" <<endl;

    cin >> amountpurchased ; 

    cout << "Apples are currently $";
    cout << priceperApple <<endl;

    cout << "you purchased" << amountpurchased << " " << item << endl;

    cout << "the total is  $" << totalprice << endl;
    return 0;
}

