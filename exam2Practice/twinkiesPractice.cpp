#include <iostream>

const double TWINKIE_PRICE = 350;
const int CENTS_IN_A_QUARTER = 25;
const int CENTS_IN_A_DIME = 10;
const int CENTS_IN_A_NICKEL = 5;
const int MENU_QUARTER = 1;
const int MENU_DIME = 2;
const int MENU_NICKEL = 3;
const int MENU_PENNY = 4;

void getTwinkie ();
void updateBalance (int nextCoin, int& amountPaid);
int checkForChange (int amountPaid);
void dispenseTwinkieAndReturnChange(int totalChange);

int main() {

    getTwinkie();

    return 0;
}

void getTwinkie () {

    std::cout << "Welcome to the deep-fried twinkie vending machine! It costs $3.50 for a delicious deep-fried twinkie!" << std::endl;

    int amountPaid = 0;
    int nextCoin;
    int totalChange = 0;

    while (amountPaid < TWINKIE_PRICE) {

        std::cout << "You've paid $" << (double)amountPaid / 100.0 << " and have $" << double(TWINKIE_PRICE - amountPaid) / 100.0 << " left." << std::endl;
        std::cout << "Please enter your next coin: (Select 1 for quarter, 2 for dime, 3 for nickel, 4 for pennie)" << std::endl;
        std::cin >> nextCoin;

        updateBalance (nextCoin, amountPaid);

        totalChange = checkForChange(amountPaid);
    }

    dispenseTwinkieAndReturnChange(totalChange);
}

void updateBalance (int nextCoin, int& amountPaid) {

    switch (nextCoin) {
        case MENU_QUARTER:
            amountPaid += CENTS_IN_A_QUARTER;
            break;
        case MENU_DIME:
            amountPaid += CENTS_IN_A_DIME;
            break;
        case MENU_NICKEL:
            amountPaid += CENTS_IN_A_NICKEL;
            break;
        case MENU_PENNY:
            amountPaid++;
            break;
        default:
            std::cout << "Invalid coin!" << std::endl;
            break;
    }
}

int checkForChange (int amountPaid) {

    if (amountPaid > TWINKIE_PRICE) {
        return amountPaid - TWINKIE_PRICE;
    }
    else {
        return 0;
    }
}

void dispenseTwinkieAndReturnChange(int totalChange) {

    int pennies = totalChange;
    int quarters = pennies / CENTS_IN_A_QUARTER;
    pennies %= CENTS_IN_A_QUARTER;
    int dimes = pennies / CENTS_IN_A_DIME;
    pennies %= CENTS_IN_A_QUARTER;
    int nickels = pennies / CENTS_IN_A_NICKEL;
    pennies %= CENTS_IN_A_QUARTER;

    std::cout << "There you go! One deep-fried twinkie" << std::endl;
    std::cout << "Your change is $" << (double)totalChange / 100.0 << std::endl;
    std::cout << "Here are " << quarters << " quarters, " << dimes << " dimes, " ;
    std::cout << nickels << " nickels, and " << pennies << " pennies" << std::endl;
    std::cout << "Have a fantastic day!" << std::endl;
}
