// Assignment: NYU Tandon Bridge Homework 5 Question 1
// Author: Kamel Gazzaz
// Due Date: 02/12/2021
#include <iostream>
using namespace std;

int main() {

    // Get multiplication table size via user I/O
    int n;
    cout << "Please enter a positive integer" << endl;
    cin >> n;

    // Create multiplication table from 1 to n
    for (int row = 1; row <= n; row++) {

        for (int col = 1, multiple = row; col <= n; col++, multiple = row * col) {
            cout << multiple << "\t";
        }

        cout << endl;
    }

    return 0;
}
