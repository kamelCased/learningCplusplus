#include <iostream>
#include <iomanip>
using namespace std;

const double MINIMUM_TAXABLE_EARNINGS = 15000.00;
const double MINIMUM_TAX_RATE = 0.05;
const double HIGHER_BRACKET_TAXABLE_EARNINGS = 25000.00;
const double HIGHER_BRACKET_TAX_RATE = 0.10;

int main() {

  double earnings, tax;

  cout << "Please enter your total earnings in the 2020 tax year:\n";
  cin >> earnings;


  if (earnings < MINIMUM_TAXABLE_EARNINGS) {
    tax = 0;
  }
  else if ((earnings >= MINIMUM_TAXABLE_EARNINGS) && (earnings < HIGHER_BRACKET_TAXABLE_EARNINGS)) {
    tax = (earnings - MINIMUM_TAXABLE_EARNINGS) * MINIMUM_TAX_RATE;
  }
  else {
    tax = ((HIGHER_BRACKET_TAXABLE_EARNINGS - MINIMUM_TAXABLE_EARNINGS) * MINIMUM_TAX_RATE) + ((earnings - HIGHER_BRACKET_TAXABLE_EARNINGS) * HIGHER_BRACKET_TAX_RATE); 
  }

  cout << fixed << setprecision(2) << " Your state taxes are: $" << tax << endl;

  return 0;
}