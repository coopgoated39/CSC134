/* CSC 134
M5T1
Curtis Cooper
6 NOV 2025
*/

#include <iostream>
using namespace std;

void say_hello(); // greet the user

int retrieve_the_answer(); // Gives the goated number

int double_a_number(int num); // Multiply by 2

int main()
{
    // Generic for assigment
    int my_number;

    say_hello();
    cout << "Enter a number." << endl;
    cin >> my_number;

    my_number = double_a_number(my_number);
    cout << "Double the number is: " << my_number << endl;
    cout << "But the real goated number is: ";
    cout << retrieve_the_answer() << endl;
}


// Functions Definitions used ^

void say_hello() {
    // greets user
    cout << "Hello, I hope you are having a great day" << endl;
}

int retrieve_the_answer() {
    // gives an answer
    return 39;
}

int double_a_number(int num) {
    // multiply by 2
    return num * 2;
}