// Question 1
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of your hourglass:" << endl;
    cin >> size;

    for (int rows = 1; rows <= size; rows++) {

        for (int spaceCount = 0; spaceCount < rows - 1; spaceCount++) {
            cout << " ";
        }

        if (rows % 2) {
            for (int starCount = 1; starCount <= (size - rows) + 1; starCount++) {
                cout << "* ";
            }
        }
        else {
            for (int starCount = 1; starCount <= (size - rows) + 1; starCount++) {
                cout << "# ";
            }
        }

        cout << endl;
    }

    for (int rows = 1; rows <= size; rows++) {

        for (int spaceCount = 0; spaceCount < size - rows; spaceCount++) {
            cout << " ";
        }

        if (rows % 2) {
            for (int starCount = 1; starCount <= rows; starCount++) {
                cout << "* ";
            }
        }
        else {
            for (int starCount = 1; starCount <= rows; starCount++) {
                cout << "$ ";
            }
        }

        cout << endl;
    }





    return 0;
}
