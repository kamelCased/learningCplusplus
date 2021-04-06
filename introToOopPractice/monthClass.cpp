#include <iostream>
#include <string>
using namespace std;

class Month {
    int month;
public:
    Month(): month(1) {};
    Month(int mo);
    Month(string mo);

    ostream& outputMonthNumber(ostream& o) const;
    ostream& outputMonthAbbrv(ostream& o) const;

    Month getNextMonth() const {return Month(month+1);}
};
Month::Month(int mo) {
    if (mo < 1 || mo > 12) {
        cout << "Invalid month. Set month to January by default." << endl;
        Month();
    }
    else {
        month = mo;
    }
}
Month::Month(string mo) {

    transform(mo.begin(), mo.end(), mo.begin(), ::tolower);

    if (mo == "jan") {
        month = 1;
    }
    else if (mo == "feb") {
        month = 2;
    }
    else if (mo == "mar") {
        month = 3;
    }
    else if (mo == "apr") {
        month = 4;
    }
    else if (mo == "may") {
        month = 5;
    }
    else if (mo == "jun") {
        month = 6;
    }
    else if (mo == "jul") {
        month = 7;
    }
    else if (mo == "aug") {
        month = 8;
    }
    else if (mo == "sep") {
        month = 9;
    }
    else if (mo == "oct") {
        month = 10;
    }
    else if (mo == "nov") {
        month = 11;
    }
    else if (mo == "dec") {
        month = 12;
    }
    else {
        cout << "Invalid month. Set to January by default." << endl;
        month = 1;
    }
}

ostream& Month::outputMonthNumber(ostream& o) const {
    o << month << endl;
    return o;
}
ostream& Month::outputMonthAbbrv(ostream& o) const {

    switch (month) {
        case 1:
            o << "JAN" << endl;
            break;
        case 2:
            o << "FEB" << endl;
            break;
        case 3:
            o << "MAR" << endl;
            break;
        case 4:
            o << "APR" << endl;
            break;
        case 5:
            o << "MAY" << endl;
            break;
        case 6:
            o << "JUN" << endl;
            break;
        case 7:
            o << "JUL" << endl;
            break;
        case 8:
            o << "AUG" << endl;
            break;
        case 9:
            o << "SEP" << endl;
            break;
        case 10:
            o << "OCT" << endl;
            break;
        case 11:
            o << "NOV" << endl;
            break;
        case 12:
            o << "DEC" << endl;
            break;
    }

    return o;
}

int main() {

    int m;
    cout << "Please enter the month: (1-12)" << endl;
    cin >> m;

    Month mo(m);

    cout << "The current month is:" << endl;
    mo.outputMonthAbbrv(cout);

    cout << "The next month is:" << endl;
    mo.getNextMonth().outputMonthAbbrv(cout);

    return 0;
}