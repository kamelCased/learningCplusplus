#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Please enter anm odd integer, greater or equal to 3:" << endl;
    cin >> size;

    for (int row = 1, outerSpaces = 0, innerSpaces = size - 4; row <= size; row++) {

        // top and bottom frame
        if (row == 1 || row == size) {
            for (int hash = 1; hash <= size; hash++) {
                cout << "#";
            }
        }

        else {

            // left frame
            cout << "#";

            // leading spaces
            for (int left = 0; left < outerSpaces; left++) {
                cout << " ";
            }

            // first dollar
            cout << "$";

            // no second dollar in middle row
            if (row != size / 2 + 1) {
                // middle spaces
                for (int middle = 1; middle <= innerSpaces; middle++) {
                    cout << " ";
                }

                //second dollar
                cout << "$";
            }

            // trailing spaces
            for (int right = 0; right < outerSpaces; right++) {
                cout << " ";
            }

            // right frame
            cout << "#";

            // top half
            if (row <= size / 2) {
                outerSpaces++;
                innerSpaces -= 2;
            }
                // bottom half
            else {
                outerSpaces--;
                innerSpaces += 2;
            }
        }

        // next row
        cout << endl;
    }

    return 0;
}
