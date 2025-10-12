/* CSC 134
 M3HW1 - Silver
 Curtis Cooper
 12 OCT 2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    // *******Question 1 *****

    cout << "Simple Chatbot" << endl;
    cout << "---------------------------------" << endl;

    string answer;
    cout << "Hello, I'm a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no: ";
    cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        cout << "That's great, we will be the best of friends." << endl;
    } else if (answer == "no" || answer == "No") {
        cout << "Well, that sucks don't be a debbie downer." << endl;
    } else {
        cout << "If you're not sure... we can let you sleep on it." << endl;
    }

    cout << endl;

    //******* Question 2 *******

    cout <<"Receipt Calculator" << endl;
    cout <<"--------------------------------" << endl;

    double price_of_meal;
    double tax_rate = 0.08;     // 8% tax
    double tip_rate = 0.15;     // 15% tip for dine in
    double tax_amount, tip_amount = 0, total_price;
    int order_type;

    // Ask for user input
    cout << "Please enter the price of the meal: $";
    cin >> price_of_meal;

    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    cin >> order_type;

    // Calculate tax
    tax_amount = price_of_meal * tax_rate;

    // Apply tip only if dine-in
    if (order_type == 1) {
        tip_amount = price_of_meal * tip_rate;
    }

    // Calculate total
    total_price = price_of_meal + tax_amount + tip_amount;

    // Display receipt
    cout << fixed << setprecision(2);
    cout << "\n----------- RECEIPT -----------" << endl;
    cout << "Meal Price:     $" << price_of_meal << endl;
    cout << "Tax (8%):       $" << tax_amount << endl;

    if (order_type == 1)
        cout << "Tip (15%):      $" << tip_amount << endl;
    else
        cout << "Tip:            $0.00" << endl;

    cout << "-------------------------------" << endl;
    cout << "Total Due:      $" << total_price << endl;
    cout << "-------------------------------" << endl;
    cout << "Thank you for your order!" << endl;

    return 0;

    // ******* Question 4 ********

    cout << "Math Practice" << endl;
    cout << "---------------------------------" << endl;

    srand(time(0));  // seed random number generator
    int num1 = rand() % 10;  // random 0–9
    int num2 = rand() % 10;
    int userAnswer;

    cout << "What is " << num1 << " + " << num2 << "? ";
    cin >> userAnswer;

    if (userAnswer == num1 + num2) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The correct answer is " << num1 + num2 << "." << endl;
    }

    cout << endl;

    return 0;
}