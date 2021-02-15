//Question 11
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Please enter an integer, greater than or equal to 2:" << endl;
    cin >> size;

    for (int row = 1; row <= size; row++) {
        //first row
        if (row == 1) {
            for (int star = 1; star <= 2*size -1; star++) {
                cout << "*";
            }
        }
        // other rows
        else {

            //left space
            for (int left = 1; left <= row - 1; left++) {
                cout << " ";
            }

            // first star
            cout << "*";

            if (row != size) {
                //middle space
                for (int middle = 1; middle <= 2 * (size - row) - 1; middle++) {
                    cout << " ";
                }

                //second star
                cout << "*";
            }
        }

        cout << endl;
    }


    return 0;
}
