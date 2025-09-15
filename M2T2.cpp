/*
CSC 134,M2T1
Curtis Cooper
9/14/25
Receipt Calculator.
*/
# include <iostream>
# include <iomanip>
 using namespace std;

 int main () {
    //Define varibles//
    double price_before_tax = 5.99;
    double tax_amount =.08;
    
    //calculate//
    double amount_of_tax = price_before_tax * tax_amount;
    double total_price = price_before_tax + amount_of_tax;
    
    //display results//
    cout << setprecision(2) << fixed;
    cout << tax_amount << " % Taxes on a meal costing $" << price_before_tax <<
    " is $" << amount_of_tax << endl;
    cout << "The total price for the meal is $" << total_price << endl;
 }




