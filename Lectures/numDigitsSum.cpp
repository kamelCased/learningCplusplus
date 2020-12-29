#include <iostream>
#include <string>

using namespace std;

int main() {

  string inputValue;
  int sum = 0;

  cout << "Please enter a positive integer:" << endl;
  cin >> inputValue;

  for (int i=0; i < inputValue.length(); i++) {
    sum += inputValue[i] - '0';  
  } 

  cout << inputValue << " has " << inputValue.length() << " digits and their sum is " << sum << endl;

  return 0;
}