// Assignment: NYU Tandon Bridge Homework 3 Question 6
// Author: Kamel Gazzaz
// Due Date: 01/29/2021
#include <iostream>
#include <iomanip>
using namespace std;

// Long-distance call rates per minute
const double WEEK_DAY_CALL_RATE = 0.40;
const double WEEK_NIGHT_CALL_RATE = 0.25;
const double WEEKEND_CALL_RATE = 0.15;

const string SATURDAY = "Sa";
const string SUNDAY = "Su";

// Day-night call rate time limits
const int WORKDAY_START = 8;
const int WORKDAY_END = 18;
const int TOP_OF_THE_HOUR = 0;

int main() {
  
  // Get the call info from user
  string dayOfWeek;
  cout << "Please enter the day of the week (Su Mo Tu We Th Fr Sa):" << endl;
  cin >> dayOfWeek;

  int callStartHour, callStartMinute;
  char timeColon;
  cout << "Please enter the call start time (in 24 hour notation i.e. 13:30):" << endl;
  cin >> callStartHour >> timeColon >> callStartMinute;

  double callDuration;
  cout << "Please enter the call duration in minutes:" << endl;
  cin >> callDuration;

  // Calculate call cost
  double callCost;
  // Weekend call
  if ((dayOfWeek == SATURDAY) || (dayOfWeek == SUNDAY)) {
    callCost = callDuration * WEEKEND_CALL_RATE;
  }
  // Weekday call
  else {
    // Weekday call between 8 am and 6 pm
    if (((callStartHour >= WORKDAY_START) && (callStartHour < WORKDAY_END)) ||
        ((callStartHour == WORKDAY_END) && (callStartMinute == TOP_OF_THE_HOUR))) {
      callCost = callDuration * WEEK_DAY_CALL_RATE;
    }
    // Week night call outside of 8 am and 6 pm
    else {
      callCost = callDuration * WEEK_NIGHT_CALL_RATE;
    }
  }

  //Output the cost
  cout << setprecision(2) << fixed << "Your call will cost: $" << callCost << endl;

  return 0;
}
