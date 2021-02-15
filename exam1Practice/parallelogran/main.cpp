#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Please enter a positive integer:" << endl;
    cin >> size;

    for (int row = 1; row <= size; row++) {

        for (int space = 0; space < (size - row); space++) {
            cout << " ";
        }

        cout << "# ";

        if ((row == 1) || (row == size)) {
            for (int star = 1; star <= size - 2; star++) {
                cout << "# ";
            }
        }
        else {
            for (int star = 1; star <= size - 2; star++) {
                cout << "* ";
            }
        }

        cout << "#" << endl;
    }

    return 0;
}
