/*
CSC 134,M3LAB2
Curtis Cooper
9/28/25
Letter Grades.
*/

# include <iostream>
#include <cmath>
#include <ctime>
#include <string>
 using namespace std;
 void letter_grade();

 int main() {
    letter_grade();
    return 0;
 }

void letter_grade() {
        double num_grade;
        string letter_grade;
        const double A_Grade = 90;
        const double B_Grade = 80;
        const double C_Grade = 70;
        const double D_Grade = 60;

        cout << "Enter a number grade 0-100: ";
        cin >> num_grade;

        if (num_grade >= A_Grade) {
            letter_grade = "A";
        }
        else if (num_grade >= B_Grade) {
            letter_grade = "B";
        }
        else if (num_grade >= C_Grade) {
            letter_grade = "C";
        }
        else if (num_grade >= D_Grade) {
            letter_grade = "D";
        }
        else { 
            letter_grade = "F";
        }

        cout << "A number grade of " << num_grade << " is: " << letter_grade;
        cout << endl << endl;

}

 