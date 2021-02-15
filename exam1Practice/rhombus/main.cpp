#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Hello, World!" << endl;
    cin >> size;

    for (int row = 1; row <= size; row++) {
        // leading
        for (int left = 1; left <= size - row; left++) {
            cout << "\t";
        }

        // star
        for (int star = 1; star <= 2 * row - 1; star++) {
            cout << "*\t";
        }

        cout << endl;
    }

    for (int row = 1; row <= size; row++) {
        // leading
        for (int left = 1; left <= row; left++) {
            cout << "\t";
        }

        // star
        for (int star = 1; star <= 2 * (size - row) - 1; star++) {
            cout << "*\t";
        }

        cout << endl;
    }

    return 0;
}
