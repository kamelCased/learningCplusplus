#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int classSize;
    cout << "How many students do you wish to enter?" << endl;
    cin >> classSize;

    for (int student = 1; student <= classSize; student++) {

        cout << endl << "Enter list of grades, separated by a space. End the grades list by typing -1:" << endl;
        bool endOfGrades = false;
        double grade, total = 0;
        int gradeCount = 0;
        while (!endOfGrades) {
            cin >> grade;
            if (grade == -1) {
                endOfGrades = true;
            }
            else {
                total += grade;
                gradeCount++;
            }
        }

        double avg = total / gradeCount;

        cout << "Average of student #" <<student << " is " << setprecision(1) << fixed << avg << endl;
    }

    return 0;
}
