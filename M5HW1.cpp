/* CSC 134
 M5HW1
 Curtis Cooper
 16 NOV 2025
 Bronze
*/

#include <iostream>
#include <iomanip>
using namespace std;

void question1 ();
void question2 ();
void question3 ();



int main() {    //I had to do it like this V so i would go on the page and not give errors

    // Call Question 1
    cout << "\n--- Question 1: Average Rainfall ---\n";
    question1();

    // Call Question 2
    cout << "\n--- Question 2: Block Volume ---\n";
    question2();

    // Call Question 3
    cout << "\n--- Question 3: ---\n";
    question3();

    return 0;
}

//*******************************Question1***********************

void question1 () {    
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
         
}


    //*************************Question2*************************

    void question2 () {
    double width, length, height;

    // Ask for width
    cout << "Enter the width of the block: ";
    cin >> width;

    // Validate width
    while (width <= 0) {
        cout << "Error, width must be greater than 0. Try again: ";
        cin >> width;
    }

    // Ask for length
    cout << "Enter the length of the block: ";
    cin >> length;

    // Validate length
    while (length <= 0) {
        cout << "Error, length must be greater than 0. Try again: ";
        cin >> length;
    }

    // Ask for height
    cout << "Enter the height of the block: ";
    cin >> height;

    // Validate height
    while (height <= 0) {
        cout << "Error, height must be greater than 0. Try again: ";
        cin >> height;
    }

    // Calculate volume
    double volume = width * length * height;

    // Display result
    cout << "\nThe volume of the block is: " << volume << endl;

}

//**************************Question3*****************************

void question3 () {
    int number;

    // Ask user for input
    cout << "Enter a number between 1 and 10: ";
    cin >> number;

    // Input validation
    while (number < 1 || number > 10) {
        cout << "Invalid input! Please enter a number between 1 and 10: ";
        cin >> number;
    }

    // Display Roman numeral using switch
    cout << "The Roman numeral version for " << number << " is: ";

    switch(number) {
        case 1: cout << "I"; break;
        case 2: cout << "II"; break;
        case 3: cout << "III"; break;
        case 4: cout << "IV"; break;
        case 5: cout << "V"; break;
        case 6: cout << "VI"; break;
        case 7: cout << "VII"; break;
        case 8: cout << "VIII"; break;
        case 9: cout << "IX"; break;
        case 10: cout << "X"; break;
    }
}



