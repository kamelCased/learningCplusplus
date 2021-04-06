#include <iostream>
using namespace std;

class Counter {
    int firstDigit;
    int secondDigit;
    int thirdDigit;
    int fourthDigit;
public:
    Counter(): firstDigit(0), secondDigit(0), thirdDigit(0), fourthDigit(0) {};

    void reset();
    void incr1();
    void incr10();
    void incr100();
    void incr1000();

    friend void operator<<(ostream& o, Counter c);

    bool overflow();
};
void Counter::reset() {
    firstDigit = 0;
    secondDigit = 0;
    thirdDigit = 0;
    fourthDigit = 0;
}
void Counter::incr1() {
    firstDigit++;
    overflow();
}
void Counter::incr10() {
    secondDigit++;
    overflow();
}
void Counter::incr100() {
    thirdDigit++;
    overflow();
}
void Counter::incr1000() {
    fourthDigit++;
    overflow();
}
bool Counter::overflow() {

    if (firstDigit > 9) {
        secondDigit += firstDigit / 10;
        firstDigit %= 10;
    }

    if (secondDigit > 9) {
        thirdDigit += secondDigit / 10;
        secondDigit %= 10;
    }

    if (thirdDigit > 9) {
        fourthDigit += thirdDigit / 10;
        thirdDigit %= 10;
    }

    if (fourthDigit > 9) {
        firstDigit = 9;
        secondDigit = 9;
        thirdDigit = 9;
        fourthDigit = 9;
        return true;
    }

    return false;
}
void operator<<(ostream& o, Counter c) {
    o << "$" << c.fourthDigit << c.thirdDigit << "." << c.secondDigit << c.firstDigit << endl;
}

void add_to_cart(double price, int qty, Counter& count);

int main() {

    Counter cart;

    cout << "Hello, welcome to our supermarket!" << endl;
    cout << "We sell 4 things:" << endl;
    cout << "1. Bananas $1.19/each" << endl;
    cout << "2. Apples $1.59/each" << endl;
    cout << "3. Almonds $4.99/lb" << endl;

    bool done = false;
    while (!done) {

        int item;
        cout << "Enter the number of the item you want to buy: (Enter -1 to finish shopping)" << endl;
        cin >> item;

        int qty;
        double price;
        switch(item) {
            case 1:
                cout << "How many bananas would you like to buy?" << endl;
                cin >> qty;
                price = 1.19;
                add_to_cart(price, qty, cart);
                break;
            case 2:
                cout << "How many apples would you like to buy?" << endl;
                cin >> qty;
                price = 1.59;
                add_to_cart(price, qty, cart);
                break;
            case 3:
                cout << "How many lbs of almonds would you like to buy?" << endl;
                cin >> qty;
                price = 4.99;
                add_to_cart(price, qty, cart);
                break;
            default:
                done = true;
                break;
        }
    }

    cout << "Thank you for shopping. Your total is " << cart;

    return 0;
}


void add_to_cart(double price, int qty, Counter& count) {

    int toBeAdded = price * qty * 100;
    cout << toBeAdded << endl;

    int fourthDigitIncrements = toBeAdded / 1000;
    toBeAdded %= 1000;
    cout << fourthDigitIncrements << endl;

    int thirdDigitIncrements = toBeAdded / 100;
    toBeAdded %= 100;

    cout << thirdDigitIncrements << endl;

    int secondDigitIncrements = toBeAdded / 10;
    toBeAdded %= 10;

    cout << secondDigitIncrements << endl;

    int firstDigitIncrements = toBeAdded;

    for (int i = 0; i < fourthDigitIncrements; i++) {
        count.incr1000();
    }
    for (int i = 0; i < thirdDigitIncrements; i++) {
        count.incr100();
    }
    for (int i = 0; i < secondDigitIncrements; i++) {
        count.incr10();
    }
    for (int i = 0; i < firstDigitIncrements; i++) {
        count.incr1();
    }
}