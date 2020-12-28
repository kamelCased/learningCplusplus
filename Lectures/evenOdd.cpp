#include <iostream>
using namespace std;

int main() {
  int inputInt;

  cout << "Please enter a positive integer:" << endl;
  cin >> inputInt;

  if (inputInt % 2 == 0) {
    cout << inputInt << " is an even number!" << endl;
  } else {
    cout << inputInt << " is an odd number!" << endl;
  }

  return 0;

}
