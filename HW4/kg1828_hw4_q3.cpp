// Assignment: NYU Tandon Bridge Homework 4 Question 3
// Author: Kamel Gazzaz
// Due date: 02/05/2021
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Get a decimal number via user I/O
    int decimal;
    cout << "Enter decimal number:" << endl;
    cin >> decimal;

    // Determine the largest power of 2 that can fit in the decimal
    // (Note: In this implementation, the algorithm determines the smallest power of 2 that doesn't fit in the decimal)
    int maxPower;
    for(int powerOf2 = decimal; pow(2, powerOf2) > decimal; powerOf2--) {
        maxPower = powerOf2;
    }

    // Output message (to be preceded by binary number)
    cout << "The binary representation of " << decimal << " is ";

    // Determine the binary equivalent using the exponent strategy
    for(int powerOf2 = maxPower - 1; powerOf2 >= 0; powerOf2--) {
        // current powerOf2 fits in remaining decimal
        if (decimal >= pow(2, powerOf2)) {
            // This powerOf2 position gets a one
            cout << 1;
            // Decrement the remaining decimal
            decimal = decimal  - pow(2, powerOf2);
        }
        // current powerOf2 doesn't fit in remaining decimal
        else {
            // This powerOf2 position gets a zero
            cout << 0;
        }
    }

    return 0;
}