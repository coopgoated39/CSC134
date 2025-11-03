/* CSC 134
 M5LAB2 
 Curtis Cooper
 3 NOV 2025
*/

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.


double get_length(); 
double get_width();
double get_area(double length, double width);
void display_data(double length, double width, double area);


int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = get_length();
   
   // Get the rectangle's width.
   width = get_width();
   
   // Get the rectangle's area.
   area = get_area(length, width);
   
   // Display the rectangle's data.
   display_data(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

//get_length - Ask the user to enter a rectangle's length, and return that value as a double.

double get_length(){
    double length;
    cout << "what is length ?" << endl;
    cin >> length;
    return length;
}

//get_width - Ask the user to enter a rectangle's width, and return that value as a double.
double get_width() {
    double width;
    cout << "What is the width" << endl;
    cin >> width;
    return width;
}

// get area - This  function should take two arguments, length and width. It will calculate the area and return that value as a double.
double get_area(double length, double width){
    double area;
    area = length * width;
    return area;
}

// display data - Void funtion, simply outputs the values in a readable format.
void display_data(double length, double width, double area) {
    cout << "Rectangle is " << length << " by " << width << "." << endl;
    cout << "The area is: " << area << endl;
    return; //reutrn is assumed for a void funtion.
}
