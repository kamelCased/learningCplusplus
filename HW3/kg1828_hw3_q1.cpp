// Assignment: NYU Tandon Bridge Homework 3 Question 1
// Author: Kamel Gazzaz
// Due Date: 01/29/2021
#include <iostream>
#include <iomanip>
using namespace std;

const char UPPER_YES = 'Y';
const char LOWER_YES = 'y';
// const char UPPER_NO = 'N'; // Check with TAs if need them for wrong input
// const char LOWER_NO = 'n';

const double HALF_OFF = 0.5;
const double CLUB_MEMBER_DISCOUNT = 0.9;
const double PERCENT = 100.0;

int main() {
  
  // Get purchase info from user 
  double firstItemPrice, secondItemPrice;
  cout << "Enter price of first item: ";
  cin >> firstItemPrice;
  cout << "Enter price of second item: ";
  cin >> secondItemPrice;
  
  char hasClubCard;
  cout << "Does customer have a club card? (Y/N): ";
  cin >> hasClubCard;
  
  double taxRate;
  cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
  cin >> taxRate;
  
  // Calculate base price without discounts
  double basePrice = firstItemPrice + secondItemPrice;
  
  // Apply discount  
  double discountedPrice;
  if (firstItemPrice > secondItemPrice) {
    secondItemPrice = HALF_OFF * secondItemPrice;
  }
  else {
    firstItemPrice = HALF_OFF * firstItemPrice;
  }
  discountedPrice = firstItemPrice + secondItemPrice;

  // More discount for club members
  if ((hasClubCard == 'Y') || (hasClubCard == 'y')) {
    discountedPrice = CLUB_MEMBER_DISCOUNT * discountedPrice;
  }

  // Add tax
  double totalPriceWithTax = discountedPrice + (discountedPrice * taxRate / PERCENT);

  // Output price
  cout << setprecision(2) << fixed;
  cout << "Base price: " << basePrice << endl;
  cout << "Price after discounts: " << discountedPrice << endl;
  cout << "Total price: " << totalPriceWithTax << endl;

  return 0;
}
