/*
CSC 134,M3T1
Curtis Cooper
9/17/25
Simple Comparison.
*/

# include <iostream>
 using namespace std;

 int main () {

    //get info on two rectangles
    double length1, length2, width1,width2;
    double area1, area2;
    cout << "Enter the lenght and width of two rectangles" << endl;
    cout << "First rectangle" << endl;
    cout << "Length: ";
    cin >> length1;
    cout << "Width: ";
    cin >> width1;
    cout << endl;
    cout << "Second rectangle" << endl;
    cout << "Length: ";
    cin >> length2;
    cout << "Width: ";
    cin >> width2;


    //calculate the area
    area1 = length1 * width1;
    area2 = length2 * width2;

    //print the output
    cout << "First rectangle area = " << area1 << endl;
    cout << "Second rectangle area = " << area2 << endl;

    return 0; 


 }