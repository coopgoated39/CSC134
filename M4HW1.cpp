/* CSC 134
 M4HW1 - Bronze
 Curtis Cooper
 2 NOV 2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {

    // *******Question 1 *****

    // The number for the times table
    int number = 5;  
    // Counter starting at 1
    int i = 1;       

    // While loop to print 5 times table from 1 to 12
    while (i <= 12) {
        cout << number << " times " << i << " is " << number * i << "." << endl;
        i++; // Increment counter
    }
    
    return 0;
}