// Assignment: NYU Tandon Bridge Homework 8 Question 5
// Author: Kamel Gazzaz
// Due Date: 03/05/2021
#include <iostream>
#include <string>
using namespace std;

const string MIDDLE_INITIAL_PERIOD = ".";

int main() {

    // Get the full name from the user
    string firstName, middleNameInitial, lastName;
    cout << "Please enter your first name, middle name (or initial), and last name:" << endl;
    cin >> firstName >> middleNameInitial >> lastName;

    // Get middle initial
    middleNameInitial = middleNameInitial[0];

    // Add period
    middleNameInitial += MIDDLE_INITIAL_PERIOD;

    // Output the name arranged as last_name, first_name middle_initial
    cout << lastName << ", " << firstName << " " << middleNameInitial << endl;

    return 0;
}
