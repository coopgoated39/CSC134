/*
CSC 134,M4LAB2
Curtis Cooper
9/24/25
Game.
*/

#include <iostream>

using namespace std;

int main(){
    //declare varibles
    int length = 10;
    int width = 10;
    string tile = 🎃;

    //print horizonally
    for (int i = 0; i < length; i++) {
        cout << tile;
    }
    cout << endl;

    //Example 2: Same thing, with a while loop
    int count = 0; 
    while (count < length) {
        cout << tile;
        count++; //count from 0 to just before length

    }
    cout << endl;

    //example 3 for loop but printing in a coloumn (vertically)
    for (int i = 0; i < height; i++) {
        cout << title << endl;
    }

    //example 4: draw the entire rectangle
    cout << endl; < endl; //white space
    cout << "rectangle" << length << "x" << height << endl;
    //outer loop handles printing height number of kines.
    // inner lopp handles printing each line as length number of tiles.
    for (int i =0; i < height; i++) {
        //print the line
        for  (int j=0; j < length; j++) {
            cout << tile;
        }
    }
    cout << endl;
    return0;

}