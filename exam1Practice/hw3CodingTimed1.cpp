#include <iostream>
using namespace std;

int main() {
    double firstPrice, secondPrice;
    cout << "Enter price of first item: ";
    cin >> firstPrice;
    cout << "Enter price of second item: ";
    cin >> secondPrice;

    char clubCard;
    cout << "Does customer have a club card (Y/N): ";
    cin >> clubCard;

    double taxRate;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    double total = firstPrice + secondPrice;
    cout << "Base price: " <<  total << endl;

    if (firstPrice > secondPrice) {
        secondPrice *= 0.5;
    }
    else {
       firstPrice *= 0.5;
    }

    total = firstPrice + secondPrice;

    if (clubCard == 'y' || clubCard == 'Y') {
        total *= 0.9;
    }

    cout << "Price after discount: " << total << endl;

    total *= (1 + taxRate/100);
    cout << "Total price: " << total << endl;

    return 0;
}
