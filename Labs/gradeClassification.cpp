#include <iostream>
using namespace std;

int main() {

  float midtermGrade, finalGrade;
  
  cout << "Please enter your midterm grade" <<endl;
  cin >> midtermGrade;

  cout << "Please enter your final grade" <<endl;
  cin >> finalGrade;

  if ((midtermGrade < 60) && finalGrade < 60) {
    cout << "Sorry, you failed the class!" << endl;
  } 
  
  else if ((midtermGrade > 95) && finalGrade > 95) {
    cout << "Congratulations, you passed the class with honors!" << endl;
  } 
  
  else {
    cout << "You passed the class!" << endl;
  }

  return 0;
}