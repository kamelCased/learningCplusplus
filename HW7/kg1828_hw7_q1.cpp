// Assignment: NYU Tandon Bridge Homework 7 Question 1
// Author: Kamel Gazzaz
// Due date: 02/26/2021
#include <iostream>

int printMonthCalendar(int numOfDays, int startingDay);
// printMonthCalendar: outputs a calendar month to the console and returns the day of the week of the last day of the month
// input: 1. int numOfDays: The number of days in that month
//        2. int startingDay: The day in the week of the first day in that month (1 for Monday, 2 for Tuesday, etc.)
// output: 1.The formatted monthly calendar	of that	month (console output)
//         2. int (return value) -- the day in the week of the last day in that month (1 for Monday, etc.)
// assumptions: 1. numOfDays is an int that is either 28,30, or 31
//              2. startingDay is an int between 1-7

bool isLeapYear(int year);
// isLeapYear: determines if the year in question is a leap year
// input: int year
// output: bool -- true if year is a leap year and false if year is not a leap year (return value)

void printYearCalendar(int year, int startingDay);
// printYearCalendar: outputs a formatted calendar year to the console
// input: 1. int year: The calendar year to be displayed
//        2. int startingDay: The day in the week of the first day in the year (1 for Monday, 2 for Tuesday, etc.)
// output: 1. The formatted calendar of every month in the specified year (console output)
// assumptions: 1. year is an integer
//              2. startingDay is an int between 1-7

const int DAYS_IN_A_WEEK = 7;
const int WEEKS_IN_A_MONTH = 4;
const int HIGH_DAYS_IN_MONTH = 31;
const int LOW_DAYS_IN_MONTH = 30;
const int DAYS_IN_FEBRUARY_NOT_LEAP = 28;
const int DAYS_IN_FEBRUARY_LEAP = 29;

const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;

int main() {

    // Get the year info from the user
    int year, startDay;
    std::cout << "Enter the year: " << std::endl;
    std::cin >> year;
    std::cout << "Enter the day of the week of the first day of " << year << " (Monday is 1, Tuesday is 2 ...Sunday is 7):" << std::endl;
    std::cin >> startDay;

    // print the corresponding formatted calendar
    printYearCalendar(year, startDay);

    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {

    // print header
    std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << std::endl;

    // print empty spaces
    for (int tab = 0; tab < startingDay - 1; tab++) {
        std::cout << "\t";
    }

    // print days of the month
    for (int dayOfMonth = 1; dayOfMonth <= numOfDays; dayOfMonth++) {

        // Print the day
        std::cout << dayOfMonth << "\t";

        // Next week
        if (((dayOfMonth + startingDay - 1) % DAYS_IN_A_WEEK == 0) && (dayOfMonth != numOfDays)) {
            std::cout << std::endl;
        }

    }

    std::cout << std::endl << std::endl;

    // return the last day of the month
    int lastDay = (numOfDays + startingDay - 1) % DAYS_IN_A_WEEK;
    return lastDay;
}

bool isLeapYear(int year) {

    if (year % 4 == 0) {

        if (year % 100 == 0) {

            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else  {
        return false;
    }
}

void printYearCalendar(int year, int startingDay) {

    int firstDayOfMonth;

    for (int month = 1; month <= 12; month++) {

        switch (month) {

            case JAN:
                std::cout << "January " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, startingDay) + 1;
                break;

            case FEB:
                std::cout << "February " << year << std::endl;
                if (isLeapYear(year)) {
                    firstDayOfMonth = printMonthCalendar(DAYS_IN_FEBRUARY_LEAP, firstDayOfMonth) + 1;
                }
                else {
                    firstDayOfMonth = printMonthCalendar(DAYS_IN_FEBRUARY_NOT_LEAP, firstDayOfMonth) + 1;
                }
                break;

            case MAR:
                std::cout << "March " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case APR:
                std::cout << "April " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(LOW_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case MAY:
                std::cout << "May " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case JUN:
                std::cout << "June " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(LOW_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case JUL:
                std::cout << "July " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case AUG:
                std::cout << "August " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case SEP:
                std::cout << "September " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(LOW_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case OCT:
                std::cout << "October " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case NOV:
                std::cout << "November " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(LOW_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;

            case DEC:
                std::cout << "December " << year << std::endl;
                firstDayOfMonth = printMonthCalendar(HIGH_DAYS_IN_MONTH, firstDayOfMonth) + 1;
                break;
        }
    }
}
