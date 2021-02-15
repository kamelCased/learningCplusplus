// Assignment: NYU Tandon Bridge Homework 4 Question 6
// Author: Kamel Gazzaz
// Due date: 02/05/2021
#include <iostream>
using namespace std;

int main() {

    // Get max number from user
    int maxNum;
    cout << "Please enter a positive integer: ";
    cin >> maxNum;

    // Loop through all positive integers until the maximum number
    for (int currentNumber = 1; currentNumber <= maxNum; currentNumber++)  {

        int numberIterate = currentNumber;
        int odds = 0, evens = 0;
        
        // Loop through digits
        while (numberIterate > 0) {
            
            int digit = numberIterate % 10;
            
            // digit is odd
            if (digit % 2) {
                odds += 1;
            }
            
            // digit is even
            else {
                evens += 1;
            }
            
            // next digit
            numberIterate = numberIterate / 10;
        }

        // Number has more even than odd digits
        if (evens > odds) {
            // Output the number
            cout << currentNumber << endl;
        }
    }

    return 0;
}
