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
    letter_grade()
    void combat();
    return 0;
 }

//void letter_grade() {
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

void combat() {

    //a simple d&d style demo

    int attack_roll
    int attack_bonus
    int enemy_armor

    cout <<"You are fighting a goblin." << endl;
    cout << "Enter you roll." << endl;
    cin >> attack_roll;
    cout <<"enter attack bonus" << endl; 
    cin >> attack_bonus;
    cout << "enemy armour class" << endl;
    cin >> enemy_armor;

    if (attack_roll + attack_bonus >= enemy_armor) {
        cout << "Hit !" << endl;
    }
    else { 
        cout <<"Miss!" << endl;
    }

    //try again?
    cout << "Again ? (y/n): ";
    string again;
    cin >> again;
    if (again == "y") {
        //call function again
        combat();
    }
}

int roll () { 
    const int SIDES = 6;
    int my_roll;
    my_roll = (rand() % SIDES)+1;
         return my_roll;
}
         
         
 