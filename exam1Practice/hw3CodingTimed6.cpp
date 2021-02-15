#include <iostream>
#include <string>
using namespace std;

int main() {
    string day;
    cout << "Enter day of call: ";
    cin >> day;

    int hour, minute;
    char colon;
    cout << "Enter start time of call in 24h notation: ";
    cin >> hour >> colon >> minute;

    int duration;
    cout << "Enter call duration in minutes: ";
    cin >> duration;

    double price;
    if (day == "Sa" || day == "Su") {
        price = 0.15 * duration;
    }
    else{
        if ((hour >= 8) || (hour < 16) || (hour == 16 && minute == 0)) {
            price = 0.40 * duration;
        }
        else  {
            price = 0.25 * duration;
        }
    }

    cout << "The price of the call is: "  << price << endl;

    return 0;
}
