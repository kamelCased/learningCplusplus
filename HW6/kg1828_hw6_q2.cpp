// Assignment: NYU Tandon Bridge Homework 6 Question 2
// Author: Kamel Gazzaz
// Due Date: 02/19/2021
#include <iostream>
using namespace std;

// printShiftedTriangle: outputs a triangle consisting of symbol of size n shifted by m spaces
// input: n (), m (leading spaces offset), symbol (character to make up triangle)
// output: triangle with specified details (console output)
// assumptions: n is at least 2, m is a non-negative integer, symbol is a valid character.
void printShiftedTriangle(int n, int m, char symbol);

// printPineTree: outputs n consecutive triangles consisting of the symbol.
// input: n (number of triangles), symbol (character to make up the triangles)
// output: n triangles one after the other in the shape of a pine tree (console output)
// assumptions: n is at least 1, symbol is a valid character.
void printPineTree(int n, char symbol);


int main() {

    int triangleCount;
    char treeSymbol;

    // Get the pine tree details from the user
    cout << "Please enter the number of triangles in the pine tree: ";
    cin >> triangleCount;
    cout << "Please enter the symbol that will fill your pine tree (eg. ‘*' or ’+’ or ‘$', etc): ";
    cin >> treeSymbol;

    // Create the pine tree per the user's specs
    printPineTree(triangleCount, treeSymbol);

    return 0;
}


void printShiftedTriangle(int n, int m, char symbol) {

    // Make triangle
    for (int row = 1; row <= n; row++) {

        // Leading spaces
        for (int space = 1; space < m + (n - row + 1); space++) {
            cout << " ";
        }

        // Symbols
        for (int leaves = 1; leaves <= 2 * row - 1; leaves++) {
            cout << symbol;
        }

        // next row
        cout << endl;
    }
}


void printPineTree(int n, char symbol){

    // Make n triangles
    for (int numTriangles = 1; numTriangles <= n; numTriangles++) {

        printShiftedTriangle(numTriangles + 1, n - numTriangles, symbol);
    }
}
