/* CSC 134
 M5HW1
 Curtis Cooper
 16 NOV 2025
 Bronze
*/

#include <iostream>
#include <iomanip>
using namespace std;



//Question 1

int main() {
    string month1, month2, month3;
    double rain1, rain2, rain3;

    // Get month names
    cout << "Enter name of month 1: ";
    cin >> month1;
    cout << "Enter rainfall for " << month1 << " (in inches): ";
    cin >> rain1;

    cout << "Enter name of month 2: ";
    cin >> month2;
    cout << "Enter rainfall for " << month2 << " (in inches): ";
    cin >> rain2;

    cout << "Enter name of month 3: ";
    cin >> month3;
    cout << "Enter rainfall for " << month3 << " (in inches): ";
    cin >> rain3;

    // Calculate average
    double average = (rain1 + rain2 + rain3) / 3.0;

    // Display result
    cout << fixed << setprecision(2);  // round to 2 decimals
    cout << "\nThe average rainfall for " 
         << month1 << ", " << month2 << ", and " << month3 
         << " is " << average << " inches.\n";

    return 0;
}



