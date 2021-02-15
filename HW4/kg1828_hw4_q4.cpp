// Assignment: NYU Tandon Bridge Homework 4 Question 4
// Author: Kamel Gazzaz
// Due date: 02/05/2021
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    // V1: Using predetermined sequence length

    // Get the sequence length from the user
    int seqLength;
    cout << "Please enter the length of the sequence: ";
    cin >> seqLength;

    // Get the elements in the sequence from the user
    cout << "Please enter your sequence:" << endl;
    int total = 1; // total of all the sequence items multiplied together, starts at one due to multiplication
    for (int i = 0; i < seqLength; i++) {
        int num;
        cin >> num; // Enter a new item in the sequence
        total *= num; // Multiply the sequence total by the item
    }

    // Calculate the geometric mean
    double geoMean = pow(double(total), 1.0/double(seqLength));

    // Output the result
    cout << fixed << setprecision(4) << "The geometric mean is: " << geoMean << endl << endl;

    /* -------------------------------------------------------------------------------------------------------- */

    // V2: Using a stop value
    cout << "Please enter a non-empty sequence of positive integers, ";
    cout << "each one in a separate line. End your sequence by typing -1:" << endl;

    // Get sequence from user
    int total2 = 1;
    int num, counter = 0;
    bool endOfSequence = false;
    
    // As long as the stop value is not inputted
    while (!endOfSequence) {
        // User enters a number
        cin >> num;
        // Stop value
        if (num == -1) {
            endOfSequence = true;
        }
        // If the number is valid
        else {
            // Multiply the sequence total by the item
            total2 *= num;
            // increment the number of items
            counter++;
        }
    }

    // Calculate the geometric mean
    double geoMean2 = pow(double(total2), 1.0/double(counter));

    // Output the result
    cout << fixed << setprecision(4) << "The geometric mean is: " << geoMean2 << endl;

    return 0;
}
