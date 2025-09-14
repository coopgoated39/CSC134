/*
CSC 134,M2T1
Curtis Cooper
9/14/25
Receipt Calculator.
*/
# include <iostream>
 using namespace std;

 int main () {
    //Define varibles//
    double price_before_tax = 5.99;
    double tax_amount =.08;
    
    //calculate//
    double amount_of_tax = price_before_tax * tax_amount;
    double total_price = price_before_tax + tax_amount;
    
    //display results//
    cout << tax_amount << " % Taxes on an item costing $" << price_before_tax << endl;
    cout << "is $" << amount_of_tax << end1;
    cout << "The total price is $" << total_price << endl;
 }




