#include <iostream>
using namespace std;

int main() {
  int inputInt, absoluteInt;

  cout << "Please enter a positive or negative integer:" << endl;
  cin >> inputInt;

  if (inputInt < 0) {
    absoluteInt = inputInt * (-1);
  } else {
    absoluteInt = inputInt;
  }

  cout << "The absolute value of " << inputInt << " is " << absoluteInt << endl;

  return 0;
}