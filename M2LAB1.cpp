/*
CSC 134,M2T1
Curtis Cooper
9/14/25
Case Study.
*/

# include <iostream>
# include <iomanip>
using namespace std; 

int main() 
{
    // Constansts for cost and amount charged 
    const double COST_PER_CUNIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5; 
    
    //Varibles
    int length; //The crates length
    int width; //The crates width
    int height; //The crates heght 
    int volume; //The crates volume
    double cost = ;  //The cost to build the crates
    double charge = ;
     //The customer charge for the crate
    double profit = ; // the profit made on the crate

    
    // Set the desired output formating for numbers.  
    cout << setprecision(2) << fixed << showpoint;
    
    //Prompt the user for the crates length, width,and height
    cout << "Enter the dimensions of the crate (in feet): \n"; 
    cin >> length; 
    cout << "Width: ";
    cin >> width;
    cout << "Height: "; 
    cin >> height; 
    
    //Calculate the crates's volume, the cost to produce it
    // the charge to the customer, and the profit
    cout << "The volume of the crate is "; 
    cout << Volume << " cubic feet. \n";
    cout << "Cost to build: $" << cost << endl;
    cout "Charge to cutomer: $" << charge << endl;
    cout << "Profit: $" << profit << endl;
    return 0:
} 