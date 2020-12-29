#include <iostream>
using namespace std;

int main() {

  int students;
  double grades[students], sumGrades = 0, averageGrade;

  cout << "Please enter the number of students in the class: " << endl;
  cin >> students;

  for (int i = 0; i < students; i++){
    cout << "Please enter student " << i + 1 << "'s grade:" << endl;
    cin >> grades[i];
    sumGrades += grades[i];
  }

  averageGrade = sumGrades / students;

  cout << "The average grade for your " << students << " person class is " << averageGrade << endl;

  return 0;

}