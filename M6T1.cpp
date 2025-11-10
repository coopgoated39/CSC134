/* CSC 134
 M6T1-arrays
 Curtis Cooper
 10 NOV 2025
*/

#include <iostream>
using namespace std;

void method1(); 
void method2();

int main () {
    method1();
    method2();

    return 0;
}
//function declarations
void method1() {
    cout << "Enter each pokemon found per day." << endl;
    cout << "Day 0 = Monday, Day 4 = friday" << endl;
    const int size = 5;
    int count = 0;
    int poke_today;
    int poke_total = 0;
    double poke_avg = 0;
    
    while (count < size) {
        cout << "Day " << count << ": ";
        cin >> poke_today;
        poke_total += poke_today;
        count++;
    }
    cout << "Total = " << poke_total <<  endl;
    poke_avg = poke_total / size;
    cout << "The average is " << poke_avg << endl;
}
void method2() {

    //method 2 uses arrays:
    //names of days 
    //#pokemon found on the days
    const int size = 5;
    string days[size] = {"M", "T", "W", "Th", "Fri"};
    int pokemon[size];
    int poke_total = 0;
    double poke_avg = 0.0;

    cout << "Day\tPokemon" << endl;
    for (int i=0; i < size; i++) {
        cout << "number of pokemon seen" << days[i] << ": ";
        cin >> pokemon[i];
        cout << days[i]  << "\t" << pokemon[i] << endl;
        poke_total += pokemon[i];
        
    }

    poke_avg = (double)poke_total / size; 
    cout << "Total = " << poke_total << endl; 
    cout << "The average is " << poke_avg << endl;


}