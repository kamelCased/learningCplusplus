#include <iostream>
using namespace std;

const int PASS_GRADE = 60;
const int MIN_PROJECTS = 10;

int main() {

  int exam, projects;

  cout << "Welcome to NYU Tandon Bridge. Please enter your exam grade: " << endl;
  cin >> exam;

  cout << "Please enter the number of coding proijects you've completed: " << endl;
  cin >> projects;

  if ((exam >= PASS_GRADE) && (projects >= MIN_PROJECTS)){
    cout << "Congratulations. You've passed the Bridge program and are offered admission to the NYU Tandon School of Engineering!";
  }
  else {
    cout << "I'm sorry. You didn't meet the passing criteria for the Bridge program. You will need to repeat the program to be offered admission to the NYU Tandon School of Engineering.";
  }

}