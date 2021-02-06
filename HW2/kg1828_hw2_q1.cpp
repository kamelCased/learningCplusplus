// Assignment: NYU Tandon Bridge Homework 2 Question 1
// Author: Kamel Gazzaz
// Due Date: 01/22/2021
#include <iostream>
using namespace std;

// Declare constants to hold the values of cent denominations
const int CENTS_IN_A_QUARTER = 25;
const int CENTS_IN_A_DIME = 10;
const int CENTS_IN_A_NICKEL = 5;
const int CENTS_IN_A_PENNY = 1;
const int CENTS_IN_A_DOLLAR = 100;

int main() {

    // variables to hold the number of each coin inputted by the user.
    int quarters, dimes, nickels, pennies;

    // Get the number of coins via user I/O
    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    // Calculate the aggregated dollar and cent value from the coins
    int totalInCents, dollars, cents;
    totalInCents = (quarters * CENTS_IN_A_QUARTER) + (dimes * CENTS_IN_A_DIME) + (nickels * CENTS_IN_A_NICKEL) + (pennies * CENTS_IN_A_PENNY);
    dollars = totalInCents / CENTS_IN_A_DOLLAR; // Every 100 cents group to a dollar.
    cents = totalInCents % CENTS_IN_A_DOLLAR; // Remainder in cents.

    // Output message shows the value of the coins in dollars and cents
    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;

    return 0;
}
