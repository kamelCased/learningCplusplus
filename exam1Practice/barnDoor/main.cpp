#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Please enter an odd positive integer: " << endl;
    cin >> size;

    for (int row = 1, leading = row - 2, mid = (size - row - 1); row <= size; row++) {

        // top and bottom frame
        if ((row == 1) || (row == size)) {

            for (int hash = 1; hash <= size; hash++) {
                cout << "#";
            }
        }

        // middle part
        else {

            // left frame
            cout << "#";

            // leading spaces
            for (int left = 0; left < leading; left++) {
                cout << " ";
            }

            // first dollar sign
            cout << "$";

            // middle row only has one dollar
            if (row != size/2 + 1) {

                // middle space
                for (int middle = 1; middle <= mid; middle++) {
                    cout << " ";
                }

                // second dollar sign
                cout << "$";
            }

            // trailing space
            for (int right = 0; right < leading; right++) {
                cout << " ";
            }

            // right frame
            cout << "#";
        }

        // first half: middle spaces decrement and leading/trailing spaces increment
        if (row <= size/2) {
            mid -= 2;
            leading++;
        }
        // second half: middle spaces increment and leading/trailing spaces decrement
        else {
            mid += 2;
            leading--;
        }

        // next row
        cout << endl;
    }

    return 0;
}
