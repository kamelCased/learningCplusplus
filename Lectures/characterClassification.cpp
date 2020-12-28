#include <iostream>
using namespace std;

const char NUMBERS_START_INDEX = '0';
const char NUMBERS_END_INDEX = '9';

const char UPPER_START_INDEX = 'A';
const char UPPER_END_INDEX = 'Z';

const char LOWER_START_INDEX = 'a';
const char LOWER_END_INDEX = 'z';

int main() {

  char character;

  cout << "Please enter any single character" << endl;
  cin >> character;

  if ((character >= NUMBERS_START_INDEX) && (character <= NUMBERS_END_INDEX)) {
    cout << character << " is a digit!" << endl;
  } 
  
  else if ((character >= UPPER_START_INDEX) && (character <= UPPER_END_INDEX)) {
    cout << character << " is an upper case letter!" << endl;
  } 
  
  else if ((character >= LOWER_START_INDEX) && (character <= LOWER_END_INDEX)) {
    cout << character << " is a lower case letter!" << endl;
  } 
  
  else {
    cout << character << " is not an alpha-numeric character!" << endl;
  }

  return 0;

}
