#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Please enter your name: ";
    cin >> name;

    int grad;
    cout << "Please enter your graduation year: ";
    cin >> grad;

    int year;
    cout << "Please enter current year: ";
    cin >> year;

    if (year >= grad){
        cout << name << ", you graduated";
    }
    else if (year - grad == 1) {
        cout << name << ", you are a Senior";
    }
    else if (year - grad == 2) {
        cout << name << ", you are a Junior";
    }
    else if (year - grad == 3) {
        cout << name << ", you are a Sophomore";
    }
    else if (year - grad == 4) {
        cout << name << ", you are a Freshman";
    }
    else {
        cout << name << ", you are not in school yet";
    }

    return 0;
}
