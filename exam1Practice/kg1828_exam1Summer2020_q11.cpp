#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Please enter a positive integer:" << endl;
    cin >> size;

    for (int rows = 1; rows <= size; rows++) {
        // odd row numbers start with x
        if (rows % 2) {
            for (int col = 1; col <= size; col++) {

                if (col % 2) {
                    cout << "X";
                }
                else{
                    cout << "O";
                }

            }
        }
        // even row numbers start with o
        else {
            for (int col = 1; col <= size; col++) {

                if (col % 2) {
                    cout << "O";
                }
                else{
                    cout << "X";
                }

            }
        }

        cout << endl;
    }

    return 0;
}
