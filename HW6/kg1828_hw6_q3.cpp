// Assignment: NYU Tandon Bridge Homework 6 Question 3
// Author: Kamel Gazzaz
// Due date: 02/19/2021
#include <iostream>
using namespace std;

// eApprox: produces the approximate value of e according to n+1 addends to the formula 1 + 1/k! ... + 1/n!
// input: n (the number of addends to the formula - 1)
// output: e (return value)
// assumptions: n is a positive integer
double eApprox(int n);

int main() {

    // Get n from the user
    int n;
    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    // Calculate the approximate value of e
    double e = eApprox(n);

    // Output the value of e
    cout << "The approximate value of e according to " << n + 1 << " addends is " << e << endl;

    return 0;
}

double eApprox(int n) {

    double e = 0.0;
    int factorial = 1;

    // Calculate e to the accuracy of n+1 addends
    for (int term = 1; term <= (n + 1); term++) {

        // Add the additional accuracy to e
        e += (1.0 / factorial);

        // Update the factorial denominator incrementally
        factorial *= term;
    }

    return e;
}