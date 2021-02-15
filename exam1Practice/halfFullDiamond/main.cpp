#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Hello, World!" << endl;
    cin >> size;

    // full half
    for (int row = 1; row <= size; row++) {

        for (int left = 1; left <= size - row; left++) {
            cout << " ";
        }

        for (int stars = 1; stars <= row; stars++) {
            cout << "* ";
        }

        cout << endl;
    }

    // empty half
    for (int row = 1; row < size; row++) {

        for (int left = 1; left <= row; left++) {
            cout << " ";
        }

        cout << "*";

        if (row != size - 1) {
            for (int middle = 1; middle <= 2 * (size - row - 1) - 1; middle++) {
                cout << " ";
            }

            cout << "*";
        }

        cout << endl;
    }




    return 0;
}
