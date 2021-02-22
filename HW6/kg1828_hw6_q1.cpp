// Assignment: NYU Tandon Bridge Homework 6 Question 1
// Author: Kamel Gazzaz
// Due Date: 02/19/2021
#include <iostream>
using namespace std;

// fib: produces the n-th element of the Fibonacci sequence
// input: n - position of the element
// output: element of the Fibonacci sequence in position n (return value)
// Assumptions: n is a positive integer
int fib (int n);

int main() {

    // Get the position n from the user
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;

    // Find the fibonacci element at position n
    int fibonacciElement = fib(n);

    // Output the result to the user
    cout << fibonacciElement << endl;

    return 0;
}


int fib (int n) {

    // fibo1 is 1 and fibo2 is 1 initially
    int fibo1 = 1, fibo2 = 1;

    // Update fibo1 and fibo2 according to the Fibonacci sequence
    for (int i = 3; i <= n; i++) {
        int temp = fibo2;
        fibo2 += fibo1;
        fibo1 = temp;
    }

    // Return the number fibo2 at position n
    return fibo2;
}



