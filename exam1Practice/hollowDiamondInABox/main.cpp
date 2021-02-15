#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Hello, World!" << endl;
    cin >> size;

    if (size % 2 == 0) {
        size--;
    }


    int leftCount = 1;
    for (int row = 1; row <= 2 * size + 1; row++) {
        if ((row == 1) || (row == 2 * size + 1)) {
            for (int col = 1; col <= 2 * size; col++) {
                cout << "# ";
            }
        }
        else {

            if (row <= size + 1) {
                cout << "# ";
                for (int left = 1; left <= (size - row) + 1; left++) {
                    cout << "* ";
                }
                for (int middle = 1; middle <= 4 * (row - 2); middle++) {
                    cout << " ";
                }
                for (int right = 1; right <= size - row + 1; right++) {
                    cout << "* ";
                }
                cout << "# ";
            }
            else {
                cout << "# ";

                for (int left = 1; left <= leftCount; left++) {
                    cout << "* ";
                }
                for (int middle = 1; middle <= 2 * (2 * size - row); middle++) {
                    cout << " ";
                }
                for (int middle = 1; middle <= 2 * (2 * size - row); middle++) {
                    cout << " ";
                }
                for (int right = 1; right <= leftCount; right++) {
                    cout << "* ";
                }
                cout << "# ";
                leftCount++;
            }
        }
        cout << endl;
    }

    return 0;
}
