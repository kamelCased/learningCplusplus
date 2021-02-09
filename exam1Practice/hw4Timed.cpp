/*
// Question 1
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // using while
    int evens = 0;
    int num = 1;
    while (evens < n) {
        if (num % 2 == 0){
            cout << num << endl;
            evens++;
        }
        num++;
    }

    //using for
    cout << endl <<  "Enter a positive integer: ";
    cin >> n;

    for (int num = 1, evens = 0; evens < n; num++) {

        if (num % 2 == 0){
            cout << num << endl;
            evens++;
        }

    }

    return 0;
}
*/
/*
// Question 2
#include <iostream>
using namespace std;

int main() {
    int decimal;
    cout << "Enter a positive integer: ";
    cin >> decimal;

    int n = decimal;
    cout << n << " is ";

    if (n >= 1000) {
        int thousands = n / 1000;
        n = n % 1000;
        for (int i = 1; i <= thousands; i++) {
            cout << "M";
        }
    }
    if (n >= 500) {
        int fiveHundreds = n / 500;
        n = n % 500;
        for (int i = 1; i <= fiveHundreds; i++) {
            cout << "D";
        }
    }
    if (n >= 100) {
        int hundreds = n / 100;
        n = n % 100;
        for (int i = 1; i <= hundreds; i++) {
            cout << "C";
        }
    }
    if (n >= 50) {
        int fifty = n / 50;
        n = n % 50;
        for (int i = 1; i <= fifty; i++) {
            cout << "L";
        }
    }
    if (n >= 10) {
        int tens = n / 10;
        n = n % 10;
        for (int i = 1; i <= tens; i++) {
            cout << "X";
        }
    }
    if (n >= 5) {
        int fives = n / 5;
        n %= 5;
        for (int i = 1; i <= fives; i++) {
            cout << "V";
        }
    }
    int ones = n;
    for (int i = 1; i <= ones; i++) {
        cout << "I";
    }
    cout << endl;
    return 0;
}
 */
/*
//Question 3
#include <iostream>
using namespace std;

int main() {
    int decimal;
    cout << "Enter decimal number: ";
    cin >> decimal;

    cout << "The binary representation of " << decimal << " is ";

    int binary = 0;
    int power = 0;
    while (decimal > 0) {
        int bit = decimal % 2;
        binary += bit * pow(10, power);
        power++, decimal /= 2;
    }

    cout << binary << endl;

    return 0;
}
 */
/*
//Question 4
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int length;
    cout << "Enter the length of the sequence: ";
    cin >> length;

    double num;
    double geomean = 1.0;
    cout << "Enter your sequence:" << endl;
    for (int i = 1; i <= length; i++) {
        cin >> num;
        geomean *= num;
    }

    geomean = pow(geomean, 1.0/length);

    cout << "The geometric mean is " << geomean << endl;

    cout << endl;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your\n"
            "sequence by typing -1:" << endl;
    geomean = 1.0;
    length = 0;
    while (num != -1) {
        cin >> num;
        if (num != -1) {
            geomean *= num;
            length++;
        }
    }
    geomean = pow(geomean, 1.0/length);

    cout << "The geometric mean is " << geomean << endl;

    return 0;
}
 */
/*
// Question 5
#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter the size of your hourglass: ";
    cin >> size;

    for (int row = 1; row <= size; row++) {

        for (int space = 1; space < row; space++) {
            cout << " ";
        }

        for (int star = 1; star <= 2 * (size - row) + 1; star++) {
            cout << "*";
        }

        cout << endl;
    }

    for (int row = 1; row <= size; row++) {

        for (int space = 1; space <= size - row; space++) {
            cout << " ";
        }

        for (int star = 1; star <= 2 * row - 1; star++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
 */
/*
// Question 6:
#include <iostream>
using namespace std;

int main() {

    int maxNum;
    cout << "Enter  a positive integer: ";
    cin >> maxNum;

    // loop through all numbers
    for (int num = 1; num <= maxNum; num++) {

        // loop through digits in number
        int iterable = num;
        int evens = 0, odds = 0;
        while (iterable > 0) {
            // get digit
            int digit = iterable % 10;
            // odd digit
            if (digit % 2) {
                odds++;
            }
            // even digit
            else {
                evens++;
            }
            iterable /= 10;
        }

        // more even than odd digits
        if (evens > odds) {
            cout << num << endl;
        }
    }

return 0;
}
 */