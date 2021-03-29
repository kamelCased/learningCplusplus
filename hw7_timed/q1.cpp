#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);

int main() {

    printYearCalender(2015, 5);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

    for (int i = 1; i < startingDay; i++) {
        cout << "\t";
    }

    for (int i = 1; i <= numOfDays; i++) {

        if (((i + startingDay - 1) % 7 == 0) && ((i + startingDay) >= 7)) {
            cout << i << endl;
        }
        else {
            cout << i << "\t";
        }
    }
    cout << endl << endl;
    return (numOfDays+startingDay - 1) % 7;
}

void printYearCalender(int year, int startingDay) {

    int startDay = startingDay;

    for (int i = 1; i <= 12; ++i) {

        switch(i) {

            case 1:
                cout << "January " << year << endl;
                startDay = printMonthCalender(31, startDay);
                break;
            case 2:
                cout << "Feb " << year << endl;
                if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))) {
                    startDay = printMonthCalender(29, startDay+1);
                }
                else {
                    startDay = printMonthCalender(28, startDay+1);
                }
                break;
            case 3:
                cout << "March " << year << endl;
                startDay = printMonthCalender(31, startDay+1);
                break;
            case 4:
                cout << "April " << year << endl;
                startDay = printMonthCalender(30, startDay+1);
                break;
            case 5:
                cout << "May " << year << endl;
                startDay = printMonthCalender(31, startDay+1);
                break;
            case 6:
                cout << "June " << year << endl;
                startDay = printMonthCalender(30, startDay+1);
                break;
            case 7:
                cout << "July " << year << endl;
                startDay = printMonthCalender(31, startDay+1);
                break;
            case 8:
                cout << "August " << year << endl;
                startDay = printMonthCalender(31, startDay+1);
                break;
            case 9:
                cout << "September " << year << endl;
                startDay = printMonthCalender(30, startDay+1);
                break;
            case 10:
                cout << "October " << year << endl;
                startDay = printMonthCalender(31, startDay+1);
                break;
            case 11:
                cout << "November " << year << endl;
                startDay = printMonthCalender(30, startDay+1);
                break;
            case 12:
                cout << "December " << year << endl;
                startDay = printMonthCalender(31, startDay+1);
                break;
        }
    }
}