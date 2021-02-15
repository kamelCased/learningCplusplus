// Date: 02/10/2021
// Assignment NYU Tandon Bridge Winter 2021 Practice Exam 1
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Please enter a positive integer:" << endl;
    cin >> num;

    // Loop through digits
    int iterable = num;
    int sumDigitFactorial = 0;
    while (iterable > 0) {
        // get digit
        int digit = iterable % 10;
        // get factorial of digit
        int digitFactorial = 1;
        for (int i = 1; i <= digit; i++) {
            digitFactorial *= i;
        }
        // add the digit's factorial to the total
        sumDigitFactorial += digitFactorial;
        // update num
        iterable /= 10;
    }

    // factorion
    if (sumDigitFactorial == num) {
        cout << num << " is a factorion" << endl;
    }
    // not
    else {
        cout << num << " is not a factorion" << endl;
    }

    return 0;
}
