/* CSC 134
 M5T1
  Curtis Cooper
   6 NOV 2025
   */

#include <iostream>
using namespace std;

void say_hello(); // says hi

int retrieve_the_answer(); // provides answer to everything

int double_a_number(int num); // num times two

int main()
{
    // This program does nothing useful
    int my_number;
    int another_num;

    say_hello();
    cout << "Enter a number." << endl;
    cin >> my_number;

    my_number = double_a_number(my_number);
    cout << "Double the number is: " << my_number << endl;
    cout << "But the only answer you need is: ";
    cout << retrieve_the_answer() << endl;
}

// Functions Definitions used ^

void say_hello()
{
    // greets user
    cout << "Hello, I hope you are having a great day" << endl;
}

int retrieve_the_answer()
{
    // gives an answer
    return 39;
}

int double_a_number(int num)
{
    // multiply by 2
    return num * 2;
}