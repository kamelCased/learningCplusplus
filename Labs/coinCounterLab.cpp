#include <iostream>
using namespace std;

const float QUARTER_VALUE =  0.25;
const float DIME_VALUE =  0.10;
const float NICKEL_VALUE =  0.05;
const float PENNY_VALUE =  0.01;

int main() {

  int quarters, dimes, nickels, pennies;
  float totalMoney;
  int dollars, cents;

  cout << "Hey, please enter the number of quarters you have: " << endl;
  cin >> quarters;

  cout << "Thanks, now please enter the number of dimes you have: " << endl;
  cin >> dimes;

  cout << "Awesome, please enter the number of nickels you have: " << endl;
  cin >> nickels;
   cout << "Great, lastly, how many pennies do you have?" << endl;
  cin >> pennies;

  totalMoney = (quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) + (nickels * NICKEL_VALUE) + (pennies * PENNY_VALUE);

  dollars = int(totalMoney);
  cents = (totalMoney - float(dollars)) * 100;

  cout << "You have " << dollars << " dollars and " << cents << " cents!";
  return 0;

}