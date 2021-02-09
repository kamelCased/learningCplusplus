#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Please enter the size of your diamond" << endl;
    cin >> size;

    //top half
    for (int rows = 1; rows <= size; rows++) {

        for (int spaceCount = 1; spaceCount <= size - rows; spaceCount++) {
            cout << " ";
        }

        if (rows % 2) {
            for (int starCount = 1; starCount <= rows; starCount++) {
                cout << "* ";
            }
        }
        else {
            for (int starCount = 1; starCount <= rows; starCount++) {
                cout << "@ ";
            }
        }



        cout << endl;
    }

    // bottom half
    for (int rows = 1; rows <= size; rows++) {

        for (int spaceCount = 1; spaceCount <= rows; spaceCount++) {
            cout << " ";
        }

        if (rows % 2) {
            for (int starCount = 1; starCount <= (size - rows); starCount++) {
                cout << "* ";
            }
        }
        else {
            for (int starCount = 1; starCount <= (size - rows); starCount++) {
                cout << "+ ";
            }

        }


        cout << endl;
    }

    return 0;
}
