// Assignment: NYU Tandon Bridge Homework 2 Question 3
// Author: Kamel Gazzaz
// Due Date: 01/22/2021
#include <iostream>
using namespace std;

// Declare standard time conversion constants
const int MINUTES_IN_AN_HOUR = 60;
const int HOURS_IN_A_DAY = 24;

int main() {

    // Get John's work schedule via user I/O
    int johnWorkDays, johnWorkHours, johnWorkMinutes;
    
    cout << "Please enter the number of days John has worked: ";
    cin >> johnWorkDays;
    cout << "Please enter the number of hours John has worked: ";
    cin >> johnWorkHours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> johnWorkMinutes;
    cout << endl;

    // Get Bill's work schedule via user I/O
    int billWorkDays, billWorkHours, billWorkMinutes;
    
    cout << "Please enter the number of days Bill has worked: ";
    cin >> billWorkDays;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> billWorkHours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> billWorkMinutes;
    cout << endl;

    // Calculate the combined work time for John and Bill
    int combinedDays, combinedHours, combinedMinutes; // John and Bill's total work time
    int hoursCarriedOver, daysCarriedOver; // time carried over by summing smaller time denominations
    // Minutes
    hoursCarriedOver = (johnWorkMinutes + billWorkMinutes) / MINUTES_IN_AN_HOUR;
    combinedMinutes =  (johnWorkMinutes + billWorkMinutes) % MINUTES_IN_AN_HOUR;
    // Hours
    daysCarriedOver = (johnWorkHours + billWorkHours + hoursCarriedOver) / HOURS_IN_A_DAY;
    combinedHours = (johnWorkHours + billWorkHours + hoursCarriedOver) % HOURS_IN_A_DAY;
    // Days
    combinedDays = johnWorkDays + billWorkDays + daysCarriedOver;

    // Output the combined work time for John and Bill
    cout << "The total time both of them worked together is: " << combinedDays << " days, ";
    cout << combinedHours << " hours and " << combinedMinutes << " minutes." << endl;

    return 0;
}
