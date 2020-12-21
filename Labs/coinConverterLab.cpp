#include <iostream>
using namespace std;

const double QUARTER_VALUE =  0.25;
const double DIME_VALUE =  0.10;
const double NICKEL_VALUE =  0.05;
const double PENNY_VALUE =  0.01;

int main() {
  double price, paid, change;
  int quarters, dimes, nickels, pennies; 
  
  cout << "Please enter the price of the item you are purchasing:" << endl;
  cin >> price;

  cout << "Please enter the amount of money you have:" << endl;
  cin >> paid;

  while (paid < price){
    cout << "You need to pay at least the price of your item. Please enter the amount you want to pay:" << endl;
    cin >> paid;
  } 

  change = paid - price;

  quarters = change / QUARTER_VALUE;
  change = change - (quarters * QUARTER_VALUE);

  dimes = change / DIME_VALUE;
  change = change - (dimes * DIME_VALUE);

  nickels = change / NICKEL_VALUE;
  change = change - (nickels * NICKEL_VALUE);

  pennies = 1 + change / PENNY_VALUE;
  
  cout << "Here you go! " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies is your change. Thank you and come again!" << endl;

}