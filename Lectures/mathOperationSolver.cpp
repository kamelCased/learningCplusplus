#include <iostream>
using namespace std;

int main() {
  char op;
  double arg1, arg2, answer;

  cout << "Please enter an arithmetic operation with the form \n 'Argument1 Operation Argument2'" << endl;
  cin >> arg1 >> op >> arg2; 
    
  switch(op) {
    case '+':
      answer = arg1 + arg2;
      cout << arg1 << " " <<  op << " " << arg2 << " = " << answer << endl;
      break;
    case '-':
      answer = arg1 - arg2;
      cout << arg1 << " " <<  op << " " << arg2 << " = " << answer << endl;
      break;
    case '*':
      answer = arg1 * arg2;
      cout << arg1 << " " <<  op << " " << arg2 << " = " << answer << endl;
      break;
    case '/':
      if (arg2 == 0) {
        cout << "Illegal expression" << endl;
      } else {
        answer = arg1 / arg2;
        cout << arg1 << " " <<  op << " " << arg2 << " = " << answer << endl;
      }
      break;
    default:
      cout << "Illegal Operation" << endl;
      break;
  } 

  return 0;
}
  