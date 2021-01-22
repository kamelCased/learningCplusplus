#include <iostream>
using namespace std;

int main() {
  
  int x;

  cout << "Welcome to the matrix. Please enter a number x: ";
  cin >> x;

  if (x * x - 4 * x + 3 < 0) {
    cout << "You're in negative territory. Agents incoming, run!";
  }
  else {
    cout << "Catch some 0's and 1's brother!";
  }

  return 0;
}