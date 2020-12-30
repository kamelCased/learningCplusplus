#include <iostream>
using namespace std;

int main() {

  int n, fiboMinus2, fiboMinus1, fibo;

  cout << "Please enter a positive integer:" << endl;
  cin >> n;

  cout << "Here are the first " << n << " Fibonacci numbers: " << endl;

  for (int i = 0; i < n; i++) {
    
    if (i == 0) {
      fibo = 0;
    }

    else if (i <= 2) {
      fiboMinus1 = 1;
      fibo = 1;
    } 
    
    else {
      fiboMinus2 = fiboMinus1;
      fiboMinus1 = fibo;
      fibo = fiboMinus1 + fiboMinus2;
    }
    
    cout << fibo << endl;
  }

  return 0;
}