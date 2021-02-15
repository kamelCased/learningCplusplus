// Assignment: NYU Tandon Bridge Homework 4 Question 5
// Author: Kamel Gazzaz
// Due date: 02/05/2021
#include <iostream>
using namespace std;

int main() {

    // Get hour glass size from user I/O
    int halfHourGlass;
    cout << "Please enter a positive integer: ";
    cin >> halfHourGlass;

    // Top half
    for (int lineCount = 1; lineCount <= halfHourGlass; lineCount++) {

        // Add spaces
        for (int spaceCount = 0; spaceCount < lineCount - 1; spaceCount++) {
            cout << " ";
        }

        // Add stars
        for (int starCount = 1; starCount <= 2 * (halfHourGlass - lineCount) + 1; starCount++) {
            cout << "*";
        }
        
        // Next line
        cout << endl;
    }

    // Bottom Half
    for (int lineCount = 1; lineCount <= halfHourGlass; lineCount++) {

        // Add spaces
        for (int spaceCount = 0; spaceCount < (halfHourGlass - lineCount); spaceCount++) {
            cout << " ";
        }

        // Add stars
        for (int starCount = 1; starCount <= 2 * lineCount - 1; starCount++) {
                cout << "*";
        }

        // Next line
        cout << endl;
    }

    return 0;
}
