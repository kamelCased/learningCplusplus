#include <iostream>
using namespace std;

const int LOWERCASE_LETTERS_START_INDEX = 97;
const int LOWERCASE_LETTERS_END_INDEX = 122;
const int ASCII_TABLE_DEPTH = 32;

int main() {

  char lower, upper;

  cout << "Please enter a lowercase letter" << endl;
  cin >> lower;

  if ((LOWERCASE_LETTERS_START_INDEX <= (int)lower) && ((int)lower <= LOWERCASE_LETTERS_END_INDEX)) {
    upper = lower - ASCII_TABLE_DEPTH;
    cout << lower << " in upper case is " << upper << endl;
  }

  else {
    cout << lower << " is not a lower case letter " << endl;
  }
  
  return 0;
}