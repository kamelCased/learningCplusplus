#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of your barn door:" << endl;
    cin >> size;

    if (size % 2 == 0) {
        size++;
    }

    //Top
    for (int cols = 1; cols <= size; cols++) {
        cout << "#";
    }
    cout << endl;

    //Top half
    for (int rows = 1, left = 0, middle = size - 4; rows <= size - 2; rows++) {
        cout << "#";

        for (int leftSpace = 0; leftSpace < left; leftSpace++) {
            cout << " ";
        }

        cout << "$";

        if (rows != size/2) {
            for (int middleSpace = 1; middleSpace <= middle; middleSpace++) {
                cout << " ";
            }
            cout << "$";
        }

        for (int rightSpace = 0; rightSpace < left; rightSpace++) {
            cout << " ";
        }

        cout << "#";

        if (rows <= (size-2)/2) {
            middle-=2;
            left++;
        }
        else {
            middle+=2;
            left--;
        }

        cout << endl;

    }

    // Bottom
    for (int cols = 1; cols <= size; cols++) {
        cout << "#";
    }
    cout << endl;

    return 0;
}
