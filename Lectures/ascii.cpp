#include <iostream>
using namespace std;

int main() {

  char character;

  cout << "Please enter a lowercase letter, uppercase letter, digit, or symbol:" << endl;
  cin >> character;

  cout << "The ASCII representation of " << character << " is " << (int)character;
}