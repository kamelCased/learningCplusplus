// Assignment: NYU Tandon Bridge Homework 4 Question 2
// Author: Kamel Gazzaz
// Due Date: 02/05/2021
#include <iostream>
using namespace std;

// Constants hold the symbol and value for the Roman numerals
const char ROMAN_ONE = 'I';
const int I_CUTOFF = 1;

const char ROMAN_FIVE = 'V';
const int V_CUTOFF = 5;

const char ROMAN_TEN = 'X';
const int X_CUTOFF = 10;

const char ROMAN_FIFTY = 'L';
const int L_CUTOFF = 50;

const char ROMAN_HUNDRED = 'C';
const int C_CUTOFF = 100;

const char ROMAN_FIVE_HUNDRED = 'D';
const int D_CUTOFF = 500;

const char ROMAN_THOUSAND = 'M';
const int M_CUTOFF = 1000;

int main() {

    // Get number via user I/O
    int decimal;
    cout << "Enter decimal number:" << endl;
    cin >> decimal;

    // Output message (followed by Roman number)
    cout << decimal << " is ";

    // Represent the number in simplified Roman numeral system
    while (decimal > 0) {
        /* General strategy:
        1. Find largest denomination
        2. Represent it using Roman symbol
        3. Decrement the decimal number
        */
        // Thousand
        if (decimal >= M_CUTOFF) {
            cout << ROMAN_THOUSAND;
            decimal -= M_CUTOFF;
        }
        // Five hundred
        else if (decimal >= D_CUTOFF) {
            cout << ROMAN_FIVE_HUNDRED;
            decimal -= D_CUTOFF;
        }
        // Hundred
        else if (decimal >= C_CUTOFF) {
            cout << ROMAN_HUNDRED;
            decimal -= C_CUTOFF;
        }
        // Fifty
        else if (decimal >= L_CUTOFF) {
            cout << ROMAN_FIFTY;
            decimal -= L_CUTOFF;
        }
        // Ten
        else if (decimal >= X_CUTOFF) {
            cout << ROMAN_TEN;
            decimal -= X_CUTOFF;
        }
        // Five
        else if (decimal >= V_CUTOFF) {
            cout << ROMAN_FIVE;
            decimal -= V_CUTOFF;
        }
        // One
        else {
            cout << ROMAN_ONE;
            decimal -= I_CUTOFF;
        }
    }

    return 0;
}
