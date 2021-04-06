#include <iostream>
using namespace std;

struct Grades {
    double quiz1;
    double quiz2;
    double midterm;
    double final;
};

char calculateFinalGrade(const Grades record);

int main() {
    Grades record;
    cout << "Please enter the student's grade on quiz 1" << std::endl;
    cin >> record.quiz1;
    cout << "Please enter the student's grade on quiz 2" << std::endl;
    cin >> record.quiz2;
    cout << "Please enter the student's grade on the midterm" << std::endl;
    cin >> record.midterm;
    cout << "Please enter the student's grade on the final" << std::endl;
    cin >> record.final;

    char letterGrade = calculateFinalGrade(record);

    cout << "The student's final grade is " << letterGrade << endl;

    return 0;
}

char calculateFinalGrade(const Grades record) {

    double numGrade = (record.quiz1 * 10 * 0.125) + (record.quiz2 * 10 * 0.125) + (record.midterm * 0.25) + (record.final * 0.5);

    if (numGrade > 100) {
        cout << "Impossible grade." << endl;
        return 'I';
    }
    else if (numGrade >= 90) {
        return 'A';
    }
    else if (numGrade >= 80) {
        return 'B';
    }
    else if (numGrade >= 70) {
        return 'C';
    }
    else if (numGrade >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}