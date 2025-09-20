/*
M2HW1 - Gold
Curtis Cooper 
9/15/2025
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void question1() {
    cout << "Question 1" << endl;
}
int main() {
        // define varibles
        double starting_account_balance;
        double deposit_amount;
        double withdrawl_amount;
        double final_account_balance
        string account_name;
        
        //get user input
        cout << "What is the name on the account ?" << endl;
        cin >> account_name;
        cout << "Hello " << account_name << endl;
        cout << "what is the account balance" << endl;
        cin >> starting_account_balance; 
        cout << "How much money does "  << account_name << "want to deposit?" << endl;
        cin >> deposit_amount;
        cout << "How much money does " << account_name << "want to withdraw?" << endl;
        cin >> withdrawl_amount;
        //cout << rand(); // TODO

        //calculations
        final_account_balance = starting_account_balance + deposit_amount - withdrawl_amount;
        
        //print statements
        cout << account_name << endl;
        cout << "-------------------" << endl;
        cout << "Account Number: " << rand() << endl;
        cout <<"--------------------" << endl;
        cout <<"Final Balance $" << final_account_balance << endl;

        return 0;
}


    void question2 () {
        cout << "Question2" <<
    }

# include <iostream>
# include <iomanip>
using namespace std; 

int main() 
{
    // Constansts for cost and amount charged 
    const double COST_PER_CUBIC_FOOT = 0.30;
    const double CHARGE_PER_CUBIC_FOOT = 0.52; 
    
    //Varibles
    double length; //The crates length
    double width; //The crates width
    double height; //The crates heght 
    double volume; //The crates volume
    double cost;  //The cost to build the crates
    double charge; //The customer charge for the crate
    double profit; // the profit made on the crate

    
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
    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT; 
    profit = charge - cost;

    //Display Calculated data
    cout << "The volume of the crate is "; 
    cout << volume << " cubic feet. \n";
    cout << "Cost to build: $" << cost << endl;
    cout << "Charge to cutomer: $" << charge << endl;
    cout << "Profit: $" << profit << endl;
    return 0;
}

    void question3 () {
        cout << "Question3" <<
    } 

# include <iostream>
using namespace std; 

int main() 
{
    //varibles
    int amount_of_pizzas;
    int amount_of_visitors;
    int slices_per_pizza;
    int total_pizza_slices_needed;
    int total_pizza_slices;
    int pizza_leftover;

    //prompt user for information
    cout <<"How many pizzas do you want to order?" << endl;
    cin >> amount_of_pizzas;
    cout <<"How many slices per Pizza do you want?" << endl;
    cin >> slices_per_pizza;
    cout <<"How many visitors are coming?" << endl;
    cin >> amount_of_visitors;

    //calculations
    total_pizza_slices_needed = amount_of_visitors * 3;
    total_pizza_slices = amount_of_pizzas * slices_per_pizza; 
    pizza_leftover = total_pizza_slices - total_pizza_slices_needed;

    //display calculations
    cout << "Each visitor gets 3 slices of pizza" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Total pizzas ordered: " << amount_of_pizzas << endl;
    cout <<"------------------------------------" << endl;
    
    if (pizza_leftover >= 0) {
        cout << "Pizza slices left: " << pizza_leftover << endl;
    }   else {
            cout >> "This is not enough for you guest, order more Pizza" >> endl;
        }
    

    return 0;
}
    
    void question4 () {
        cout << "Question4" <<
    }

# include <iostream>
using namespace std; 

int main() {

    //varibles
    string school = "FTCC";
    string team = "Trojans";

    cout << "Let's go " << school << endl;
    cout << "Let's go " << school << endl;
    cout << "Let's go " << school << endl;
    cout << "Let's go " << team << endl;

    return 0;
} 

    