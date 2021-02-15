// Assignment: NYU Tandon Bridge Exam 1 Question 11
// Author: Kamel Gazzaz
// Date: 02/11/2021
#include <iostream>
using namespace std;

const char FIRST_LOWER_LETTER = 'a';
const char FIRST_UPPER_LETTER = 'A';

int main() {

    // Get the lowercase letter from the user
    char inLetter;
    cout << "Please enter a lower-case letter:" << endl;
    cin >> inLetter;

    // Determine the size of the isosceles triangle
    int maxRows = inLetter - FIRST_LOWER_LETTER + 1;

    // Draw the triangle
    for (char row = 1; row <= maxRows; row++) {

        // leading spaces
        for (int space = 1; space <= (maxRows - row); space++) {
            cout << " ";
        }

        // odd row number
        if (row % 2) {

            // print 2n-1 lowercase letters
            for (int col = 1; col <= 2 * row - 1; col++) {

                // letter is determined by the row number
                cout << char (FIRST_LOWER_LETTER + row - 1);
            }
        }

        // even row number
        else {

            // print 2n-1 uppercase letters
            for (int col = 1; col <= 2 * row - 1; col++) {

                // letter is determined by the row number
                cout << char (FIRST_UPPER_LETTER + row - 1);
            }
        }

        // next row
        cout << endl;
    }

    return 0;
}
