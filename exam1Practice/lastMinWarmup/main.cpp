/*
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Please enter a positive integer:" << endl;
    cin >> size;

    for (int row = 1; row <= size; row++) {

        if (row % 2) {
            for (int col = 1; col <= size; col++) {
                if (col % 2) {
                    cout << "X";
                }
                else {
                    cout << "O";
                }
            }
        }
        else{
            for (int col = 1; col <= size; col++) {
                if (col % 2) {
                    cout << "O";
                }
                else {
                    cout << "X";
                }
            }

        }
        cout << endl;
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {

    cout << "Please enter a sequence of positive integers, each one separated by a line" << endl;
    cout << "End your sequence by typing -1:" << endl;

    bool endOfSequence = false;
    int num, sumMoreEvens = 0;

    while (!endOfSequence) {
        cin >> num;
        if (num == -1) {
            endOfSequence = true;
        }
        else {
            int evens = 0, odds = 0;
            while (num > 0) {
                int digit = num % 10;
                if (digit % 2) {
                    odds++;
                }
                else {
                    evens++;
                }
                num /= 10;
            }
            if (evens > odds) {
                sumMoreEvens++;
            }
        }
    }

    cout << "You entered " << sumMoreEvens << " more-even numbers" << endl;

    return 0;
}
 */
/*
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Please enter an odd positive integer, greater than or equal to 3:" << endl;
    cin >> size;

    for (int row = 1, outerSpace = 0, innerSpace = size - 4; row <= size; row++) {

        // top and bottom frame
        if (row == 1 || row == size) {
            for (int col = 1; col <= size; col++) {
                cout << "#";
            }
        }

        // middle part
        else {

            // left frame
            cout << "#";

            // leading space
            for (int left = 1; left <= outerSpace; left++) {
                cout << " ";
            }

            // first dollar
            cout << "$";

            // middle row has one dollar sign
            if (row != size/2 + 1) {
                // middle space
                for (int mid = 1; mid <= innerSpace; mid++) {
                    cout << " ";
                }

                //second dollar
                cout << "$";
            }

            // trailing space
            for (int right = 1; right <= outerSpace; right++) {
                cout << " ";
            }

            // right frame
            cout << "#";

            // update spaces
            if (row <= size/2) {
                innerSpace -= 2;
                outerSpace++;
            }
            else{
                innerSpace += 2;
                outerSpace--;
            }
        }

        //next row
        cout << endl;

    }

    return 0;
}
 */
/*
#include <iostream>
using namespace std;

int main () {

    int classSize;
    cout << "How many students do you wish to enter?" << endl;
    cin >> classSize;

    for (int student = 1; student <= classSize; student++) {

        cout << endl << "Enter list of grades, separated by a space. End the grades list by typing -1:" << endl;

        bool endOfGrades = false;
        double grade, sumGrades = 0.0;
        int counter = 0;

        while (!endOfGrades) {
            cin >> grade;
            if (grade == -1) {
                endOfGrades = true;
            }
            else {
                sumGrades += grade;
                counter++;
            }
        }

        double avgGrade = sumGrades / counter;

        cout << "Average of student #" << student << " is " << avgGrade << endl;
    }

    return 0;
}
 */