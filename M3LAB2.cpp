/*
CSC 134,M3LAB2
Curtis Cooper
9/28/25
Letter Grades.
*/

#include <iostream>
using namespace std;

void letter_grade();  // function prototype

int main() {
    letter_grade();   // call the function
    return 0;
}

// Function definition
void letter_grade() {

    double num_grade;
    string letter;
    const double A_Grade = 90;
    const double B_Grade = 80;
    const double C_Grade = 70;
    const double D_Grade = 60;

    cout << "Enter a number grade (0-100): ";
    cin >> num_grade;

    if (num_grade >= A_Grade) {
        letter = "A";
    }
    else if (num_grade >= B_Grade) {
        letter = "B";
    }
    else if (num_grade >= C_Grade) {
        letter = "C";
    }
    else if (num_grade >= D_Grade) {
        letter = "D";
    }
    else {
        letter = "F";
    }

    cout << "A number grade of " << num_grade << " is: " << letter << endl;
}

