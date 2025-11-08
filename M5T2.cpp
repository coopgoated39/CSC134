/* CSC 134
M5T2
Curtis Cooper
8 NOV 2025
squares of numbers
*/


#include <iostream>
using namespace std;

// value returning function
int squared(int n) {
    return n * n;
}

// void function to print a single line
void PrintAnswerLine(int num, int sq) {
    cout << num << " squared is " << sq << endl;
}

int main() {
    // loop from 1 to 10 and use the functions and the count ++
    for (int i = 1; i <= 10; i++) {
        int result = squared(i);
        PrintAnswerLine(i, result);
    }

    return 0;
}