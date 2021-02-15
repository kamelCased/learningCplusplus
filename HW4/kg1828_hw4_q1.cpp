// Assignment: NYU Tandon Bridge Homework 4 Question 1
// Author: Kamel Gazzaz
// Due Date: 02/05/2021
#include <iostream>
using namespace std;

int main() {

    // Part a: print the first "evenCount" even numbers using a while loop
    cout << "V1: Using While" << endl << endl;

    // Ask the user for a number "evenCount"
    int evenCount;
    cout << "Please enter a positive integer: ";
    cin >> evenCount;

    // Print the first "evenCount" positive even numbers
    int counter = 1;
    int evenNumber = 2;
    while (counter <= evenCount) {
        cout << evenNumber << endl;
        evenNumber += 2;
        counter++;
    }

    /* -------------------------------------------------------------------------- */

    // Part b: print the first "evenCount" even numbers using a for loop
    cout << endl << "V2: Using For" << endl << endl;

    // Ask the user for a number "evenCount"
    cout << "Please enter a positive integer: ";
    cin >> evenCount;

    // Print the first "evenCount" positive even numbers
    for(int counter = 1, evenNumber = 2; counter <= evenCount; counter++, evenNumber += 2) {
        cout << evenNumber << endl;
    }

    return 0;
}
