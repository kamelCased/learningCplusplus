// Assignment: NYU Tandon Bridge Homework 3 Question 4
// Author: Kamel Gazzaz
// Due Date: 01/29/2021
#include <iostream>
using namespace std;

// Rounding methods menu
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

  // Get a number via user I/O
  double realNum;
  cout << "Please enter a real number:\n";
  cin >> realNum;

  // User selects a rounding method
  int roundingMethod;
  cout << "Choose your rounding method:\n";
  cout << "1. Floor round\n";
  cout << "2. Ceiling round\n";
  cout << "3. Round to the nearest whole number\n";
  cin >> roundingMethod;

  // Round the real number according to the chosen method
  // positive numbers
  if (realNum >= 0) {
    switch (roundingMethod){
      case FLOOR_ROUND:
        cout << int(realNum);
        break;
      case CEILING_ROUND:
        // number with fractional part
        if (realNum - int(realNum)) {
          cout << int(realNum + 1);
        }
        // integer
        else {
          cout << int(realNum);
        }
        break;
      case ROUND:
        cout << int(realNum + 0.5);
        break;
      default:
        cout << "Invalid choice";
        break;
    }
  }
  // negative numbers
  else {
    switch (roundingMethod){
      case FLOOR_ROUND:
        // number with fractional part
        if (realNum - int(realNum)) {
          cout << int(realNum - 1);
        }
        // integer
        else {
          cout << int(realNum);
        }
        break;
      case CEILING_ROUND:
        cout << int(realNum);
        break;
      case ROUND:
        // At least 0.5
        if ((int(realNum) - realNum) >= 0.5) {
          cout << int(realNum - 1);
        }
        // Less than 0.5
        else {
          cout << int(realNum);
        }
        break;
      default:
        cout << "Invalid choice";
        break;
    }
  }

  return 0;
}


