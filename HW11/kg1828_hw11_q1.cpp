// Assignment: NYU Tandon Bridge Homework 11 Question 1
// Author: Kamel Gazzaz
// Due date: 03/21/2021
#include <iostream>
using namespace std;

void printTriangle(int numStars);
// printTriangle - prints a triangle of numStar rows and where the base has numStars stars
// input: numStars - the number of stars at the base (and rows)
// output: right triangle of stars "*" (console output)
// assumptions: n is a positive integer

void printOppositeTriangles(int numStars);
// printOppositeTriangles - prints 2 triangle of numStar rows
//                          The first triangle decrements the number of stars per row from numStars to 1
//                          The second triangle increments the number of stars per row from 1 to numStars
// input: numStars - the number of stars at the base of each triangle (and rows per triangle)
// output: 2 mirror image right triangles of stars "*" (console output)
// assumptions: n is a positive integer

void printRuler(int n);
// printRuler: outputs a vertical ruler of 2^n-1 lines to the console
// input: n - the integer determining the size of the ruler (used in 2^n-1)
// output: vertical ruler (console output)
// assumptions: n is a nonnegative integer

int main() {

    // -------- Part A ----------

    // Get number of stars
    int numStars;
    cout << "Please enter the size of your triangle:" << endl;
    cin >> numStars;

    // Print triangle with numStars stars
    cout << "Triangle:\n";
    printTriangle(numStars);

    // -------- Part B ----------

    // Get number of stars
    cout << "\nPlease enter the size of your opposite triangles:" << endl;
    cin >> numStars;

    // Print opposite triangles with numStar stars per triangle
    cout << "Opposite triangles:\n";
    printOppositeTriangles(numStars);

    // -------- Part C ----------

    // Get ruler size from user
    int n;
    cout << "\nPlease enter the size of your ruler:\n";
    cin >> n;

    // Print ruler
    printRuler(n);

    return 0;
}


void printTriangle(int n) {

    // Base case (also added negatives for error handling)
    if(n <= 0) {
        cout << "";
    }

    // Recursive Step
    else {

        // Recursive Hypothesis: Call on printTriangle with k rows will print triangle with k rows
        printTriangle(n - 1);

        // Print row of stars
        for(int i = 0; i < n; i++) {
            cout << "*";
        }

        // Next row
        cout << endl;
    }
}

// Technically also recursive:
//void printTriangle(int numStars) {
//
//    // Base Case
//    if (numStars == 1) {
//        cout << "*";
//    }
//
//    // Recursive Step
//    else {
//
//        // Rows
//        for (int i = 1; i <= numStars; i++) {
//
//            // Cols
//            for(int j = 1; j <= i; j++) {
//
//                // recursive call
//                printTriangle(1);
//            }
//
//            // Next row
//            cout << endl;
//        }
//    }
//}

void printOppositeTriangles(int n) {

    // Error handling, no need
    if (n <= 0) {
        return;
    }

    // Base Case: one row per triangle
    if(n == 1) {
        cout << "*\n*" << endl;
    }

    // Recursive step: More than one row
    else {

        // First triangle
        for(int i = n; i > 0; i--) {
            cout << "*";
        }

        // Recursive hypothesis: Calling printOppositeTriangles with k-1 rows prints opposite triangles with k-1 rows
        cout << endl;
        printOppositeTriangles(n - 1);

        // Second triangle
        for(int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Technically also recursive
//void printOppositeTriangles(int numStars) {
//
//    // Base Case
//    if (numStars == 1) {
//        cout << "*";
//    }
//
//    // Recursive Step
//    else {
//
//        // ---- First half ----
//        // Rows
//        for (int i = 1; i <= numStars; i++) {
//
//            // Cols
//            for(int j = 1; j <= (numStars - i + 1); j++) {
//
//                // recursive call
//                printTriangle(1);
//            }
//
//            // Next row
//            cout << endl;
//        }
//
//        // ---- Second half ----
//        // Rows
//        for (int i = 1; i <= numStars; i++) {
//
//            // Cols
//            for(int j = 1; j <= i; j++) {
//
//                // recursive call
//                printTriangle(1);
//            }
//
//            // Next row
//            cout << endl;
//        }
//    }
//}

void printRuler(int n) {

    // Base case
    if (n == 0) {
        cout << "";
    }

    // Recursive step
    else {

        // Recursive hypothesis: Print the ruler of size n - 1
        printRuler(n - 1);

        // Print the middle line
        for(int i = 0; i < n; ++i) {
            cout << "-";
        }
        cout << endl;

        // Recursive hypothesis: Print the ruler of size n - 1
        printRuler(n - 1);
    }
}