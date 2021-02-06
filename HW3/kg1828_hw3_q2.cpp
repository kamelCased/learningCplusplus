// Assignment: NYU Tandon Bridge Homework 3 Question 2
// Author: Kamel Gazzaz
// Due Date: 01/29/2021
#include <iostream>
using namespace std;

const int FRESHMAN_STANDING_DIFF = 4;
const int SOPHOMORE_STANDING_DIFF = 3;
const int JUNIOR_STANDING_DIFF = 2;
const int SENIOR_STANDING_DIFF = 1;

int main() {
  
  string userName;
  int gradYear, currentYear;

  cout << "Please enter your name: ";
  cin >> userName;
  cout << "Please enter your graduation year: ";
  cin >> gradYear;
  cout << "Please enter current year: ";
  cin >> currentYear; 
  
  if (gradYear - currentYear > FRESHMAN_STANDING_DIFF) {
    cout << userName << ", you are not in college yet" << endl;
  }
  else if (gradYear - currentYear == FRESHMAN_STANDING_DIFF) {
    cout << userName << ", you are a Freshman" << endl;
  }
  else if (gradYear - currentYear == SOPHOMORE_STANDING_DIFF) {
    cout << userName << ", you are a Sophomore" << endl;
  }
  else if (gradYear - currentYear == JUNIOR_STANDING_DIFF) {
    cout << userName << ", you are a Junior" << endl;
  }
  else if (gradYear - currentYear == SENIOR_STANDING_DIFF) {
    cout << userName << ", you are a Senior" << endl;
  }
  else {
    cout << userName << ", you Graduated" << endl;
  }

  return 0;
}
