#include <iostream>
using namespace std;

int main() {
  
  int num1, num2, num3, num4, numEvens = 0, numOdds = 0;
  
  cout << "Please enter 4 positive integers, separated by a space:" << endl;
  cin >> num1 >> num2 >> num3 >> num4;
 
  int nums[4] = {num1, num2, num3, num4};

  for (int i = 0; i < 4; i++) {
    if ((nums[i]) % 2 == 0){
      numEvens +=1; 
    } else {
      numOdds +=1;
    }
  }

  if (numEvens > numOdds) {
    cout << "More evens" << endl;
  } else if (numOdds > numEvens) {
    cout << "More odds" << endl;
  } else {
    cout << "Same number of evens and odds" << endl;
  }

  return 0;
}

