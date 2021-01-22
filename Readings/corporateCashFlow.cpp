#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  double savings, expenses;

  cout << "Welcome to Goldman Facts. Please enter your corporate savings in dollars: ";
  cin >> savings;

  cout << "Thanks. Please enter your corporate expenses: ";
  cin >> expenses;

  if (savings >= expenses) {
    savings -= expenses;
    expenses = 0;
    cout << fixed << setprecision(2);
    cout << "Thank you. I've updated your financials."; cout << "Your remaining savings are $" << savings;
    cout << " and your expenses are back to $" << expenses;cout << " We appreciate your business!" << endl; 
  }
  else {
    cout << " Your company is bankrupt";
    cout << " I'll help you file a chapter 9." << endl;
  }

  return 0;
}