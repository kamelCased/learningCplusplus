#include <iostream>
using namespace std;

int main() {
  
  int year;
  bool leapYear;

  cout << "Please enter a year:" << endl;
  cin >> year;

  if (year % 4 == 0) {
    
    if (year % 100 == 0) {
      
      if (year % 400 == 0) {
        leapYear = true;
      } 
      
      else {
        leapYear = false;
      }

    } 
    
    else {
      leapYear = true;
    }

  } 

  else {
    leapYear = false;
  }
  
  if (leapYear) {
    cout << year << " was a leap year" << endl; 

  } else {
    cout << year << " was not a leap year" << endl; 
  }

  return 0;
}