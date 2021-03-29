#include <iostream>
using namespace std;

void printPascal(int n);

int main() {
  printPascal(5);
  return 0;
}

void printPascal(int n) {

  for (int row = 1; row <= n; row++) {

  for(int col = 1; col <= n - row; col++) {
      cout << " ";
  }
    int val = 1;
    for(int col = 1; col <= row; col++) {
      cout << val <<" ";
      val = val * (row - col) / col;
    }
    cout << endl;
  }
}