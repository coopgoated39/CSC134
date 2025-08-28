/*
CSC 134
M1HW1 - Movies  
Curtis Cooper 8/28/25
*/

#include <iostream>
using namespace std;

int main() {
 string bestmovie = "Avengers";
 string releasedate = "May 4, 2012";
 int ticketssold = 806000;
 double priceperticket = 8.00; 
 double approximategross = priceperticket * ticketssold;   

 cout << "One of my favorite movies from Marvel is " << bestmovie << endl; 
 cout << "It was released " << releasedate << endl;
 cout << "In the first weekend, The movie made approximately in the state of North Carolina $" << approximategross;}