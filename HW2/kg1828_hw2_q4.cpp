// Assignment: NYU Tandon Bridge Homework 2 Question 4
// Author: Kamel Gazzaz
// Due Date: 01/22/2021
#include <iostream>
using namespace std;

int main() {

    // Variables to hold user inputted positive integers
    int firstInt, secondInt;

    // Get two numbers via user I/O
    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> firstInt >> secondInt;

    // output the result of arithmetic operations
    cout << firstInt << " + " << secondInt << " = " << firstInt + secondInt << endl; // sum
    cout << firstInt << " - " << secondInt << " = " << firstInt - secondInt << endl; // difference
    cout << firstInt << " * " << secondInt << " = " << firstInt * secondInt << endl; // product
    cout << firstInt << " / " << secondInt << " = " << double(firstInt) / double(secondInt) << endl; // quotient
    cout << firstInt << " div " << secondInt << " = " << firstInt / secondInt << endl; // div
    cout << firstInt << " mod " << secondInt << " = " << firstInt % secondInt << endl; // mod

    return 0;
}
