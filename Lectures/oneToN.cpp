#include <iostream>
using namespace std;

int main() {
  
  int inputValue;
  
  cout << "Please enter a positive integer:" << endl;
  cin >> inputValue; 

  for (int i = 1; i <= inputValue; i++) {
    cout << i << endl;
  }

  return 0;
}