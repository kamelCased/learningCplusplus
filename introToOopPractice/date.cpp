#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    string makeTwoDigit(int val) const; //helper function
public:

    // Constructors
    Date() :day(1), month(1), year(1970) {}
    Date(int newYear) : day(1), month(1), year(newYear) {}

    // Mutators
    void setYear(int newYear) {year = newYear;}
    void setMonth(int newMonth);
    void setDay(int newDay);

    // Accessors
    int getDay()const { return day; }
    int getMonth()const { return month; }
    int getYear()const { return year; }

    // Output
    void printSQLDate() const;
    void printAmericanDate() const;
};

string Date::makeTwoDigit(int val) const{

    if (val >= 10)
        return to_string(val);

    // Add a 0 to one digit values
    else
        return '0' + to_string(val);

}

void Date::setMonth(int newMonth) {

    // Modify month
    if (newMonth > 0 && newMonth <= 12)
        month = newMonth;
}
void Date::setDay(int newDay) {

    // Modify day in the calling object
    if (newDay > 0 && newDay <= 31)
        day = newDay;
}
void Date::printAmericanDate() const {

    //  MM/DD/YYYY
    cout << makeTwoDigit(month) << "/" << makeTwoDigit(day) << "/" << makeTwoDigit(year);
}
void Date::printSQLDate() const{

    // YYYY-MM-DD
    cout << makeTwoDigit(getYear()) << "-" << makeTwoDigit(getMonth()) << "-" << makeTwoDigit(getDay());
}

int main() {

    Date item; //Automatic call to the DEFAULT constructor
    item.setDay(10); //Calling object: item
    Date other(2021); //Automatic call to the ONE INT ARGUMENT constructor
    other.setDay(20); //Calling object: other
    item.setDay(14);
    item.setMonth(4);
    item.setYear(2021);
    item.printSQLDate();
    cout << endl;
    other.printAmericanDate();

    Date itemCopy(item); //copy constructor
    itemCopy = item; // Assignment Operator
    Date otherCopy = other; //copy constructor

    return 0;
}