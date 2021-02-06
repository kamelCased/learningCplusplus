// Assignment: NYU Tandon Bridge Homework 2 Question 2
// Author: Kamel Gazzaz
// Due Date: 01/22/2021
#include <iostream>
using namespace std;

// Constants hold standard coin values
const int CENTS_IN_A_DOLLAR = 100;
const int CENTS_IN_A_QUARTER = 25;
const int CENTS_IN_A_DIME = 10;
const int CENTS_IN_A_NICKEL = 5;

int main() {

    int dollars, cents;

    // Get the dollar and cent values via user I/O
    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    // Calculate the number of coins from the inputted dollars and cents values
    int remainingTotalInCents, quarters, dimes, nickels, pennies; // Variables to hold calculated coin quantities
    remainingTotalInCents = (dollars * CENTS_IN_A_DOLLAR) + cents;
    // quarters
    quarters = remainingTotalInCents / CENTS_IN_A_QUARTER;
    remainingTotalInCents = remainingTotalInCents % CENTS_IN_A_QUARTER;
    // dimes
    dimes = remainingTotalInCents / CENTS_IN_A_DIME;
    remainingTotalInCents = remainingTotalInCents % CENTS_IN_A_DIME;
    // nickels
    nickels = remainingTotalInCents / CENTS_IN_A_NICKEL;
    remainingTotalInCents = remainingTotalInCents % CENTS_IN_A_NICKEL;
    // pennies
    pennies = remainingTotalInCents;

    // Output the number of coins
    cout << dollars << " dollars and " << cents << " cents are:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels;
    cout << " nickels and " << pennies << " pennies" << endl;

    return 0;
}
