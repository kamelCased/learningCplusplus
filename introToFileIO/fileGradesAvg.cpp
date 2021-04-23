#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void openFile(T& fstr);

template <class T>
void getClassGrades(ifstream& gradeBook, vector<vector<T>>& classGrades);

template <class T>
void getAverages(vector<vector<T>>& classGrades);

template <class T>
void writeGrades(ofstream& gradeBook, vector<vector<T>>& classGrades);

int main() {

    vector<vector<double>> classGrades;

    ifstream gradeBook;
    openFile(gradeBook);

    getClassGrades(gradeBook, classGrades);

    gradeBook.close();

    getAverages(classGrades);

    ofstream finalGradeBook;
    openFile(finalGradeBook);

    writeGrades(finalGradeBook, classGrades);

    finalGradeBook.close();

    return 0;
}

template <class T>
void openFile(T& fstr) {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    fstr.open(filename);

    while(!fstr) {

        cout << "File failed to open" << endl;
        cout << "Enter file name: ";
        cin >> filename;

        fstr.clear();
        fstr.open(filename);
    }

    cout << "Successfully opened file" << endl;
}

template <class T>
void getClassGrades(ifstream& gradeBook, vector<vector<T>>& classGrades) {

    int temp;
    while (gradeBook >> temp) {

        vector<double> student;
        student.push_back(temp);

        while(student.size() < 10 && gradeBook >> temp) {
            student.push_back(temp);
        }

        classGrades.push_back(student);
    }

    cout << "Successfully retrieved grades" << endl;
}

template <class T>
void getAverages(vector<vector<T>>& classGrades) {

    for (auto& student: classGrades) {

        double average = 0;
        for (auto grade: student) {
            average += grade;
        }
        average /= student.size();

        student.push_back(average);
    }

    cout << "Successfully calculated student averages" << endl;
}

template <class T>
void writeGrades(ofstream& finalGradeBook, vector<vector<T>>& classGrades) {

    for (auto student: classGrades) {

        for (auto grade: student) {
            finalGradeBook << grade << " ";
        }

        finalGradeBook << endl;
    }

    cout << "Successfully wrote final grades to the gradebook" << endl;
}