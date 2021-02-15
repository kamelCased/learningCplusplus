/*
// Question 1
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Please enter the size of diamond:" << endl;
    cin >> size;

    for (int row = 1; row <= size; row++) {

        for (int space = 1; space <= (size - row); space++) {
            cout << " ";
        }

        for (int star = 1; star <= row; star++) {
            cout << "* ";
        }

        cout << endl;
    }

    for (int row = 1; row < size; row++) {

        for (int space = 1; space <= row; space++) {
            cout << " ";
        }

        for (int star = 1; star <= size - row; star++) {
            cout << "* ";
        }

        cout << endl;
    }


    return 0;
}
*/
/*
// Question 2
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Please enter positive integer:" << endl;
    cin >> num;

    int iterable = num;
    int total = 0;

    while (iterable > 0) {
        int digit = iterable % 10;
        total += digit;
        iterable /= 10;
    }

    cout << "The sum of the digits of " << num << " is " << total << endl;

    return 0;
}
 */