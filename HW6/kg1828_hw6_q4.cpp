// Assignment: NYU Tandon Bridge Homework 6 Question 4
// Author: Kamel Gazzaz
// Due date: 02/19/2021
#include <iostream>
#include <cmath>
using namespace std;

// printDivisors: Prints the divisors of the number num in ascending order
// inputs: num
// outputs: the divisors of num (console print)
// assumptions: num is a positive integer greater than or equal to 2
void printDivisors(int num);

int main() {

    // Get n from user
    int n;
    cout << "Please enter a positive integer >= 2: ";
    cin >> n;

    // Get the divisors of n
    printDivisors(n);

    return 0;
}

void printDivisors(int num) {

    // Get all divisors less than sqrt(num)
    for (int tentativeDivisor = 1; tentativeDivisor < sqrt(num); tentativeDivisor++) {

        // output divisors
        if (num % tentativeDivisor == 0) {
            cout << tentativeDivisor << " ";
        }
    }

    // Get all divisors greater than or equal to sqrt(num)
    for (int divisor = sqrt(num); divisor > 0; divisor--) {

        // For each divisor smaller than sqrt(num)
        if (num % divisor == 0) {

            // Get complementary divisor
            int complementaryDivisor = num / divisor;

            // output divisors
            cout << complementaryDivisor << " ";
        }
    }
}
