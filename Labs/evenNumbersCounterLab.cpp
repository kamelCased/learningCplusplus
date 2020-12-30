#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Please enter a positive integer: " << endl;
  cin >> n;

  for (int i = 2; i <= (2 * n); i += 2) {
    cout << i << endl;
  }

  return 0;
}