#include <iostream>
using namespace std;

class Grades {
    double quiz1;
    double quiz2;
    double midterm;
    double final;
public:
    Grades(): quiz1(0.0), quiz2(0.0), midterm(0.0), final(0.0) {};
    Grades(double q1, double q2, double mt, double fn);

    double getQuiz1 () const {return quiz1;}
    double getQuiz2 () const {return quiz2;}
    double getMidterm () const {return midterm;}
    double getFinal () const {return final;}

    void setQuiz1(double score);
    void setQuiz2(double score);
    void setMidterm(double score);
    void setFinal(double score);

    double calculateFinalGrade () const;
    char getLetterGrade(double finalGrade) const;
};
Grades::Grades(double q1, double q2, double mt, double fn) {

    if (q1 < 0 || q1 > 10) {
        cout << "Invalid score for quiz 1. Grades range between 0-10. Grade set to 0" << endl;
        quiz1 = 0.0;
    }
    else {
        quiz1 = q1;
    }

    if (q2 < 0 || q2 > 10) {
        cout << "Invalid score for quiz 2. Grades range between 0-10. Grade set to 0" << endl;
        quiz2 = 0.0;
    }
    else {
        quiz2 = q2;
    }

    if (mt < 0 || mt > 100) {
        cout << "Invalid score for midterm. Grades range between 0-100. Grade set to 0" << endl;
        midterm = 0.0;
    }
    else {
        midterm = mt;
    }

    if (fn < 0 || fn > 100) {
        cout << "Invalid score for final. Grades range between 0-100. Grade set to 0" << endl;
        final = 0.0;
    }
    else {
        final = fn;
    }
}
void Grades::setQuiz1(double score) {
    if (score < 0 || score > 10) {
        cout << "Invalid score for quiz 1. Grades range between 0-10." << endl;
    }
    else {
        quiz1 = score;
    }
}
void Grades::setQuiz2(double score) {
    if (score < 0 || score > 10) {
        cout << "Invalid score for quiz 2. Grades range between 0-10." << endl;
    }
    else {
        quiz2 = score;
    }
}
void Grades::setMidterm(double score) {
    if (score < 0 || score > 100) {
        cout << "Invalid score for midterm. Grades range between 0-100." << endl;
    }
    else {
        midterm = score;
    }
}
void Grades::setFinal(double score) {
    if (score < 0 || score > 100) {
        cout << "Invalid score for final. Grades range between 0-100." << endl;
    }
    else {
        final = score;
    }
}
double Grades::calculateFinalGrade() const{
    return quiz1 * 10 * 0.125 + quiz2 * 10 * 0.125 + midterm * 0.25 + final * 0.5;
}
char Grades::getLetterGrade(double finalGrade) const {
    if (finalGrade < 0 || finalGrade > 100){
        cout << "Invalid numerical grade value." << endl;
        return 'I';
    }
    else if (finalGrade >= 90) {
        return 'A';
    }
    else if (finalGrade >= 80) {
        return 'B';
    }
    else if (finalGrade >= 70) {
        return 'C';
    }
    else if (finalGrade >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}
istream& operator>>(istream& i, Grades& g) {
    double q1, q2, mt, fn;
    i >> q1 >> q2 >> mt >> fn;
    g = Grades(q1, q2, mt, fn);
    return i;
}

int main () {

    Grades student_record;
    cout << "Welcome teacher, let's enter your student's grades on quiz 1, quiz 2, midterm and final." << endl;
    cout << "Please separate each entry by a space." << endl;
    cin >> student_record;

    double numGrade = student_record.calculateFinalGrade();
    char letterGrade = student_record.getLetterGrade(numGrade);

    cout << "Your student's final grade is " << numGrade << ", they get a " << letterGrade << " in the class." << endl;

    return 0;
}

