// Assignment: NYU Tandon Bridge Homework 12
// Author: Kamel Gazzaz
// Due date: 10/04/21
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Some useful constants
const int CENTS_IN_A_DOLLAR = 100;
const double DOLLARS_IN_A_CENT = 0.01;
const double ZERO_DOLLARS_AND_CENTS = 0.0;
const int ZERO_BASE = 0;
const int TEN_CENTS = 10;

// User choice menu
const int DEPOSIT_CHOICE = 1;
const int WRITE_CHECK_CHOICE = 2;
const int BALANCE_CHOICE = 3;
const int CHECKLIST_CHOICE = 4;
const int EXIT_CHOICE = 5;

// --------------- MONEY CLASS (DEFINED IN SAVITCH p.662) -----------------

int digit_to_int(char c) {
    // Convert char digit to int
    return (static_cast<int>(c) - static_cast<int>('0'));
}

class Money {
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money();
    //Initializes the object so its value represents $0.00.
    double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
private:
    long all_cents;
};

// ----------------------- CHECK CLASS --------------------------

class Check {
private:
    int checkNumber;
    Money checkAmount;
    bool cashedStatus;
public:
    // Constructors
    Check(): checkNumber(ZERO_BASE), checkAmount(ZERO_DOLLARS_AND_CENTS), cashedStatus(false) {};
    Check(int checkNum, Money checkAmt, bool alrdyCashed);

    // Member functions

    // Accessors
    int getCheckNumber () const {return checkNumber;}
    Money getCheckAmount() const {return checkAmount;}
    bool getCashedStatus() const {return cashedStatus;}

    // Mutators
    void setCheckNumber(int checkNum) {checkNumber = checkNum;}
    void setCheckAmount(Money checkAmt);
    void setCashedStatus(bool alrdyCashed) {cashedStatus = alrdyCashed;}
};

// ------------ PROGRAM FUNCTION DECLARATIONS --------------------

Money getInitialBalance();
// Gets the initial balance from the user

void writeChecks(vector<Check>& checkLog);
// Gets a list of checks written by the user

void depositMoney(vector<Money>& outDepositsLog);
// Gets a list of money deposits made by the user

Money calculateTotal(const vector<Check>& account, bool justCashed);
// calculates the total value of checks (or the value of cashed checks if justCashed is set to true)

Money calculateTotal(const vector<Money>& deposit);
// calculates the total value deposited

ostream& operator <<(ostream& outs, const Check& check);
// Outputs check to the console

void printBalance(Money balance, const vector<Check>& account, const vector<Money>& deposits);
// prints the total value of deposits, checks cashed, account balance, and difference between balance and true balance when including uncashed checks

void outputChecks(const vector<Check>& checks);
// displays the list of checks on the console

void sort(vector<Check>& checks);
// sorts the checks by the check number

int main() {

    // ~~~~ User Input ~~~~~

    // Get initial balance from user
    Money balance = getInitialBalance();

    cout << endl;

    vector<Check> account;
    vector<Money> deposits;

    bool doneBalancingCheckbook = false;

    while (!doneBalancingCheckbook) {
        int choice;
        cout << "What would you like to do next?" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Make a deposit" << endl;
        cout << "2. Write a check" << endl;
        cout << "3. Get your account balance" << endl;
        cout << "4. See your list of checks" << endl;
        cout << "5. Exit NYU Digital Bank" << endl;
        cin >> choice;

        switch (choice) {

            case DEPOSIT_CHOICE:

                // Get deposits from user
                depositMoney(deposits);
                cout << endl;
                break;

            case WRITE_CHECK_CHOICE:

                // Get checks from user
                writeChecks(account);
                cout << endl;
                break;

            case BALANCE_CHOICE:

                printBalance(balance, account, deposits);
                cout << endl;
                break;

            case CHECKLIST_CHOICE:

                // Sort checks by check number and output them to the console
                sort(account);
                outputChecks(account);
                cout << endl;
                break;

            case EXIT_CHOICE:

                cout << "We hope you enjoyed your experience with the NYU Tandon Digital Bank." << endl;
                cout << "Please leave us a star rating 0-100 in Gradescope." << endl;
                doneBalancingCheckbook = true;
        }

    }

    return 0;
}

// ---------------- MONEY CLASS FUNCTION DEFINITIONS ---------------------

Money operator +(const Money& amount1, const Money& amount2) {

    // Add the money together
    long totalInCents = amount1.all_cents + amount2.all_cents;

    // Split the result into dollars and cents
    long dollars = totalInCents / CENTS_IN_A_DOLLAR;
    int cents = totalInCents % CENTS_IN_A_DOLLAR;

    // Return the sum
    return Money(dollars, cents);
}

Money operator -(const Money& amount1, const Money& amount2) {

    // Subtract the second amount of Money from the first amount of Money
    long diffInCents = amount1.all_cents - amount2.all_cents;

    // Split the result into dollars and cents
    long dollars = diffInCents / CENTS_IN_A_DOLLAR;
    int cents = diffInCents % CENTS_IN_A_DOLLAR;

    // Return the difference
    return Money(dollars, cents);
}

Money operator -(const Money& amount) {

    // Multiply by -1 to change sign
    long cents = amount.all_cents * (-1);

    // Split into dollars and cents
    long dollars = cents / CENTS_IN_A_DOLLAR;
    cents = cents % CENTS_IN_A_DOLLAR;

    // Return a negated value
    return Money(dollars, cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {

    // Same amount
    if (amount1.all_cents == amount2.all_cents) {
        return true;
    }

        // Different amount
    else {
        return false;
    }
}

bool operator <(const Money& amount1, const Money& amount2) {

    // amount1 is less than amount2
    if (amount1.all_cents < amount2.all_cents) {
        return true;
    }

        // amount1 is not less than amount2
    else {
        return false;
    }
}

Money::Money(long dollars, int cents) {

    // Dollars and cents have mismatching signs
    if (dollars * cents < ZERO_BASE) {
        cout << "Invalid dollars and cents amount inputted to Money class" << endl;
        exit(1);
    }

        // Both dollars and cents have same sign
    else {
        // Store the total in cents
        this->all_cents = dollars * CENTS_IN_A_DOLLAR + cents;
    }
}

Money::Money(long dollars) {

    // Store the total in cents
    this->all_cents = dollars * CENTS_IN_A_DOLLAR;
}

Money::Money() {

    // Store 0 cents (to represent $0.00).
    this->all_cents = ZERO_BASE;
}

double Money::get_value() const {
    // Convert to dollars and cents
    return (this->all_cents * DOLLARS_IN_A_CENT);
}

istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point,
            digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative; //set to true if input is negative.
    ins >> one_char;
    if (one_char == '-') {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    // if input is legal, then one_char == '$'
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * TEN_CENTS + digit_to_int(digit2);
    amount.all_cents = dollars * CENTS_IN_A_DOLLAR + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / CENTS_IN_A_DOLLAR;
    cents = positive_cents % CENTS_IN_A_DOLLAR;

    if (amount.all_cents < ZERO_DOLLARS_AND_CENTS)
        outs << "− $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < TEN_CENTS)
        outs << '0';
    outs << cents;

    return outs;
}

// ---------------- CHECK CLASS FUNCTION DEFINITIONS ---------------------

Check::Check(int checkNum, Money checkAmt, bool alrdyCashed){
    if (checkAmt.get_value() <= ZERO_DOLLARS_AND_CENTS) {
        cout << "Invalid check amount. Will not accept this check." << endl;
    }
    else {
        checkNumber = checkNum;
        checkAmount = checkAmt;
        cashedStatus = alrdyCashed;
    }
}

void Check::setCheckAmount(Money checkAmt) {

    // Valid check amount
    if (checkAmt.get_value() > ZERO_DOLLARS_AND_CENTS) {
        checkAmount = checkAmt;
    }

        // Invalid check amount
    else {
        cout << "$" << fixed << setprecision(2) << checkAmt.get_value() << " is an invalid check amount." << endl;
    }
}

ostream& operator <<(ostream& outs, const Check& check) {

    const int cashed = 1;

    // Output check details
    if (check.getCashedStatus() == cashed) {

        // Just for better formatting

        // Less than $1,000
        if (check.getCheckAmount() < CENTS_IN_A_DOLLAR * TEN_CENTS) {
            outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t\t\t" << "Cashed" << endl;
        }
        // Less than $10,000,000
        else if (check.getCheckAmount() < CENTS_IN_A_DOLLAR * CENTS_IN_A_DOLLAR * CENTS_IN_A_DOLLAR * TEN_CENTS){
            outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t\t" << "Cashed" << endl;
        }
        // $10,000,000 or more
        else {
            outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t" << "Cashed" << endl;
        }
    }
    else {

        // Less than $1,000
        if (check.getCheckAmount() < CENTS_IN_A_DOLLAR * TEN_CENTS) {
            outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t\t\t" << "Not Cashed" << endl;
        }
        // Less than $10,000,000
        else if (check.getCheckAmount() < CENTS_IN_A_DOLLAR * CENTS_IN_A_DOLLAR * CENTS_IN_A_DOLLAR * TEN_CENTS){
            outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t\t" << "Not Cashed" << endl;
        }
        // $1,000,000 or more
        else {
            outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t" << "Not Cashed" << endl;
        }
    }

    return outs;
}

// --------------- OTHER PROGRAM FUNCTION DEFINITIONS --------------------

Money getInitialBalance() {

    cout << "Welcome to the NYU Tandon Digital Bank.\nLet me get some details about your checking account.\n\n";

    Money balance;
    cout << "Please enter your initial account balance (in the format $X.XX): ";
    cin >> balance;

    return balance;
}

void writeChecks(vector<Check>& outCheckAccount) {

    vector<Check> checkAccount;
    bool firstTry = true;

    bool doneWritingChecks = false;
    while (!doneWritingChecks) {

        char answer = 'y';
        if (firstTry) {
            firstTry = false;
        }
        else {
            cout << "Do you want to write another check? (y/n) ";

            // Get user choice
            cin >> answer;
        }

        // Done writing checks
        if (answer == 'n' || answer == 'N') {
            doneWritingChecks = true;
        }

            // Write another check
        else {

            // Check number
            int checkNumber;
            cout << "Please enter the check number (1-999 e.g. 12): "; // I set this limit so the check list format is nicely output at the end, can be removed
            cin >> checkNumber;

            // Make sure check not already added
            bool checkNumAlreadyUsed = false;
            for (Check c: checkAccount) {
                if (c.getCheckNumber() == checkNumber) {
                    checkNumAlreadyUsed = true;
                }
            }

            // Not used
            if (!checkNumAlreadyUsed) {
                // Check value
                Money checkAmount;
                cout << "Please enter the check amount (in the format $X.XX): ";
                cin >> checkAmount;

                // Check cashed status
                bool cashedCheck;
                cout << "Is the check already cashed? (Enter 1 for yes, 0 for no): ";
                cin >> cashedCheck;

                // Create check
                checkAccount.push_back(Check(checkNumber, checkAmount, cashedCheck));
            }

            // Already used check #
            else {
                cout << "Check number " << checkNumber << " was already used. You can not reuse the same check number." << endl;
            }
        }
    }

    for (auto check: checkAccount) {
        outCheckAccount.push_back(check);
    }
}

void depositMoney(vector<Money>& outDepositsLog) {

    vector<Money> depositsLog;
    bool firstTry = true;

    bool doneDepositing = false;
    while (!doneDepositing) {

        char answer;
        if (firstTry) {
            answer = 'y';
            firstTry = false;
        }
        else {
            // Get user choice
            cout << "Do you want to make another deposit? (y/n) ";
            cin >> answer;
        }

        // Done making deposits
        if (answer == 'n' || answer == 'N') {
            doneDepositing = true;
        }

            // Make another deposit
        else {

            // Get deposit
            Money depositAmount;
            cout << "Please enter the deposit amount (in the format $X.XX): ";
            cin >> depositAmount;

            // Make deposit
            depositsLog.push_back(depositAmount);
        }
    }

    for (auto deposit: depositsLog){
        outDepositsLog.push_back(deposit);
    }
}

Money calculateTotal(const vector<Check>& account, bool onlyCashed) {

    Money total;

    // Sum up cashed checks
    if (onlyCashed) {

        for (int i = 0; i < account.size(); i++) {

            if (account[i].getCashedStatus()) {
                total = total + account[i].getCheckAmount();
            }
        }
    }

        // Sum up all checks
    else {
        for (int i = 0; i < account.size(); i++) {
            total = total + account[i].getCheckAmount();
        }
    }

    return total;
}

Money calculateTotal(const vector<Money>& deposit) {

    Money total;

    // Sum up cashed checks
    for (int i = 0; i < deposit.size(); i++) {
        total = total + deposit[i];
    }

    return total;
}

void printBalance(Money balance, const vector<Check>& account, const vector<Money>& deposits) {

    // Calculate the sum of the cashed checks
    bool onlyCashedChecks = true;
    Money totalChecksCashed = calculateTotal(account, onlyCashedChecks);
    cout << "The total value of checks cashed is: " << totalChecksCashed << endl;

    // Calculate the sum of the deposits
    Money totalDeposited = calculateTotal(deposits);
    cout << "The total value deposited into your checking account is: " << totalDeposited << endl;

    // Calculate the bank balance (Note to TAs: I know the homework asked for this to be inputted by the user but this makes more sense for this implementation)
    Money newBalance = balance + totalDeposited - totalChecksCashed;
    cout << "Your checking account's new balance is: " << newBalance << endl;

    // Calculate what the balance should be if all checks were cashed
    onlyCashedChecks = false;
    Money totalChecks = calculateTotal(account, onlyCashedChecks);
    Money trueBalance = balance + totalDeposited - totalChecks;
    cout << "Your checking account's new balance should be: " << trueBalance << endl;

    // Calculate difference between the two balances
    Money balanceDifference = newBalance - trueBalance;
    cout << "The difference is: " << balanceDifference << endl;
}

void outputChecks(const vector<Check>& checks) {

    // Print cashed checks
    cout << "List of cashed checks:\n";
    cout << "---------------------\n";
    cout << "Check#\t\tAmount\t\t\tCheck Status\t\t\n";
    for (int i = 0; i < checks.size(); i++) {
        if (checks[i].getCashedStatus()) {
            cout << checks[i];
        }
    }

    cout << endl;

    // Print uncashed checks
    cout << "List of uncashed checks:\n";
    cout << "-----------------------\n";
    cout << "Check#\t\tAmount\t\t\tCheck Status\t\t\n";
    for (int i = 0; i < checks.size(); i++) {
        if (!checks[i].getCashedStatus()) {
            cout << checks[i];
        }
    }

}

void sort(vector<Check>& checks) {

    // Loop through list of checks
    for (int i = 0; i < checks.size(); i++) {

        int minIndex = i;

        // Find next minimum check number
        for(int j = i; j < checks.size(); j++) {
            if (checks[minIndex].getCheckNumber() > checks[j].getCheckNumber()) {
                minIndex = j;
            }
        }

        // Swap minimum and current element
        Check temp = checks[i];
        checks[i] = checks[minIndex];
        checks[minIndex] = temp;
    }
}


// First try with Pointers and Dynamic Arrays

//#include <iostream>
//#include <cstdlib>
//#include <iomanip>
//using namespace std;
//
//// Some useful constants
//const int CENTS_IN_A_DOLLAR = 100;
//const double DOLLARS_IN_A_CENT = 0.01;
//const int ZERO_DOLLARS = 0;
//const double ZERO_DOLLARS_AND_CENTS = 0.0;
//
//// --------------- MONEY CLASS (DEFINED IN SAVITCH p.662) -----------------
//
//int digit_to_int(char c) {
//    // Convert char digit to int
//    return (static_cast<int>(c) - static_cast<int>('0'));
//}
//
//class Money {
//public:
//    friend Money operator +(const Money& amount1, const Money& amount2);
//    //Returns the sum of the values of amount1 and amount2.
//    friend Money operator -(const Money& amount1, const Money& amount2);
//    //Returns amount1 minus amount2.
//    friend Money operator -(const Money& amount);
//    //Returns the negative of the value of amount.
//    friend bool operator ==(const Money& amount1, const Money& amount2);
//    //Returns true if amount1 and amount2 have the same value; false otherwise.
//    friend bool operator <(const Money& amount1, const Money& amount2);
//    //Returns true if amount1 is less than amount2; false otherwise.
//    Money(long dollars, int cents);
//    //Initializes the object so its value represents an amount with
//    //the dollars and cents given by the arguments. If the amount
//    //is negative, then both dollars and cents should be negative.
//    Money(long dollars);
//    //Initializes the object so its value represents $dollars.00.
//    Money();
//    //Initializes the object so its value represents $0.00.
//    double get_value() const;
//    //Returns the amount of money recorded in the data portion of the calling
//    //object.
//    friend istream& operator >>(istream& ins, Money& amount);
//    //Overloads the >> operator so it can be used to input values of type
//    //Money. Notation for inputting negative amounts is as in − $100.00.
//    //Precondition: If ins is a file input stream, then ins has already been
//    //connected to a file.
//
//    friend ostream& operator <<(ostream& outs, const Money& amount);
//    //Overloads the << operator so it can be used to output values of type
//    //Money. Precedes each output value of type Money with a dollar sign.
//    //Precondition: If outs is a file output stream, then outs has already been
//    //connected to a file.
//private:
//    long all_cents;
//};
//
//// ----------------------- CHECK CLASS --------------------------
//
//class Check {
//private:
//    int checkNumber;
//    Money checkAmount;
//    bool cashedStatus;
//public:
//    // Constructors
//    Check(): checkNumber(0), checkAmount(0.0), cashedStatus(false) {};
//    Check(int checkNum, Money checkAmt, bool alrdyCashed);
//
//    // Member functions
//
//    // Accessors
//    int getCheckNumber () const {return checkNumber;}
//    Money getCheckAmount() const {return checkAmount;}
//    bool getCashedStatus() const {return cashedStatus;}
//
//    // Mutators
//    void setCheckNumber(int checkNum) {checkNumber = checkNum;}
//    void setCheckAmount(Money checkAmt);
//    void setCashedStatus(bool alrdyCashed) {cashedStatus = alrdyCashed;}
//};
//
//// ------------ PROGRAM FUNCTION DECLARATIONS --------------------
//
//Money getInitialBalance();
//// Gets the initial balance from the user
//
//void writeChecks(Check*& outCheckLog, int& outCheckLogSize);
//// Gets a list of checks written by the user
//
//void depositMoney(Money*& outDepositsLog, int& outDepositsLogSize);
//// Gets a list of money deposits made by the user
//
//Money calculateNewBalance(const Money oldBalance, const Check* account, int accountSize, const Money* deposits, int depositsSize);
//// Calculates the new balance by adding the deposits and subtracting the checks from the original balance
//
//Money calculateTotal(const Check* account, int accountSize, bool justCashed);
//// calculates the total value of checks (or the value of cashed checks if justCashed is set to true)
//
//Money calculateTotal(const Money* deposit, int depositSize);
//// calculates the total value deposited
//
//void outputChecks(const Check* checks, int checkSize, bool cashed);
//// displays the list of checks on the console
//
//void sort(Check*& checks, int checkSize);
//// sorts the checks by the check number
//
//// ---------------- MAIN --------------------
//
//int main() {
//
//    // ~~~~ User Input ~~~~~
//
//    // Get initial balance from user
//    Money balance = getInitialBalance();
//
//    cout << endl;
//
//    // Get deposits from user
//    Money* deposits;
//    int depositsSize;
//    depositMoney(deposits, depositsSize);
//
//    cout << endl;
//
//    // Get checks from user
//    Check* account;
//    int accountSize;
//    writeChecks(account, accountSize);
//
//    cout << endl;
//
//    // ~~~~ Output account details ~~~~~
//
//    // Calculate the sum of the cashed checks
//    bool onlyCashedChecks = true;
//    Money totalChecksCashed = calculateTotal(account, accountSize, onlyCashedChecks);
//    cout << "The total value of checks cashed is: " << totalChecksCashed << endl;
//
//    // Calculate the sum of the deposits
//    Money totalDeposited = calculateTotal(deposits, depositsSize);
//    cout << "The total value deposited into your checking account is: " << totalDeposited << endl;
//
//    // (free dynamic memory)
//    delete[] deposits;
//    deposits = nullptr;
//
//    // Calculate the bank balance (Note to TAs: I know the homework asked for this to be inputted by the user but this makes more sense)
//    Money newBalance = balance + totalDeposited - totalChecksCashed;
//    cout << "Your checking account's new balance is: " << newBalance << endl;
//
//    // Calculate what the balance should be if all checks were cashed
//    onlyCashedChecks = false;
//    Money totalChecks = calculateTotal(account, accountSize, onlyCashedChecks);
//    Money trueBalance = balance + totalDeposited - totalChecks;
//    cout << "Your checking account's new balance should be: " << trueBalance << endl;
//
//    // Calculate difference between the two balances
//    Money balanceDifference = newBalance - trueBalance;
//    cout << "The difference is: " << balanceDifference << endl;
//
//    cout << endl;
//
//    // ~~~~ Output check lists ~~~~~
//
//    // Sort checks by check number
//    sort(account, accountSize);
//
//    // Output list of ordered cashed checks
//    bool cashed = true;
//    outputChecks(account, accountSize, cashed);
//
//    cout << endl;
//
//    // Output list of ordered uncashed checks
//    cashed = false;
//    outputChecks(account, accountSize, cashed);
//
//    // (free dynamic memory)
//    delete[] account;
//    account = nullptr;
//
//    return 0;
//}
//
//// ---------------- MONEY CLASS FUNCTION DEFINITIONS ---------------------
//
//Money operator +(const Money& amount1, const Money& amount2) {
//
//    // Add the money together
//    long totalInCents = amount1.all_cents + amount2.all_cents;
//
//    // Split the result into dollars and cents
//    long dollars = totalInCents / CENTS_IN_A_DOLLAR;
//    int cents = totalInCents % CENTS_IN_A_DOLLAR;
//
//    // Return the sum
//    return Money(dollars, cents);
//}
//
//Money operator -(const Money& amount1, const Money& amount2) {
//
//    // Subtract the second amount of Money from the first amount of Money
//    long diffInCents = amount1.all_cents - amount2.all_cents;
//
//    // Split the result into dollars and cents
//    long dollars = diffInCents / CENTS_IN_A_DOLLAR;
//    int cents = diffInCents % CENTS_IN_A_DOLLAR;
//
//    // Return the difference
//    return Money(dollars, cents);
//}
//
//Money operator -(const Money& amount) {
//
//    // Multiply by -1 to change sign
//    long cents = amount.all_cents * (-1);
//
//    // Split into dollars and cents
//    long dollars = cents / CENTS_IN_A_DOLLAR;
//    cents = cents % CENTS_IN_A_DOLLAR;
//
//    // Return a negated value
//    return Money(dollars, cents);
//}
//
//bool operator ==(const Money& amount1, const Money& amount2) {
//
//    // Same amount
//    if (amount1.all_cents == amount2.all_cents) {
//        return true;
//    }
//
//    // Different amount
//    else {
//        return false;
//    }
//}
//
//bool operator <(const Money& amount1, const Money& amount2) {
//
//    // amount1 is less than amount2
//    if (amount1.all_cents < amount2.all_cents) {
//        return true;
//    }
//
//    // amount1 is not less than amount2
//    else {
//        return false;
//    }
//}
//
//Money::Money(long dollars, int cents) {
//
//    // Dollars and cents have mismatching signs
//    if (dollars * cents < ZERO_DOLLARS) {
//        cout << "Invalid dollars and cents amount inputted to Money class" << endl;
//        exit(1);
//    }
//
//        // Both dollars and cents have same sign
//    else {
//        // Store the total in cents
//        this->all_cents = dollars * CENTS_IN_A_DOLLAR + cents;
//    }
//}
//
//Money::Money(long dollars) {
//
//    // Store the total in cents
//    this->all_cents = dollars * CENTS_IN_A_DOLLAR;
//}
//
//Money::Money() {
//
//    // Store 0 cents (to represent $0.00).
//    this->all_cents = ZERO_DOLLARS;
//}
//
//double Money::get_value() const {
//    // Convert to dollars and cents
//    return (this->all_cents * DOLLARS_IN_A_CENT);
//}
//
//istream& operator >>(istream& ins, Money& amount) {
//    char one_char, decimal_point,
//            digit1, digit2; //digits for the amount of cents
//    long dollars;
//    int cents;
//    bool negative; //set to true if input is negative.
//    ins >> one_char;
//    if (one_char == '-') {
//        negative = true;
//        ins >> one_char; //read '$'
//    }
//    else
//        negative = false;
//    // if input is legal, then one_char == '$'
//    ins >> dollars >> decimal_point >> digit1 >> digit2;
//    if (one_char != '$' || decimal_point != '.'
//        || !isdigit(digit1) || !isdigit(digit2)) {
//        cout << "Error illegal form for money input\n";
//        exit(1);
//    }
//    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
//    amount.all_cents = dollars * CENTS_IN_A_DOLLAR + cents;
//    if (negative)
//        amount.all_cents = -amount.all_cents;
//    return ins;
//}
//
//ostream& operator <<(ostream& outs, const Money& amount) {
//    long positive_cents, dollars, cents;
//    positive_cents = labs(amount.all_cents);
//    dollars = positive_cents / CENTS_IN_A_DOLLAR;
//    cents = positive_cents % CENTS_IN_A_DOLLAR;
//
//    if (amount.all_cents < 0)
//        outs << "− $" << dollars << '.';
//    else
//        outs << "$" << dollars << '.';
//
//    if (cents < 10)
//        outs << '0';
//    outs << cents;
//
//    return outs;
//}
//
//// ---------------- CHECK CLASS FUNCTION DEFINITIONS ---------------------
//
//Check::Check(int checkNum, Money checkAmt, bool alrdyCashed){
//    if (checkAmt.get_value() <= ZERO_DOLLARS_AND_CENTS) {
//        cout << "Invalid check amount. Will not accept this check." << endl;
//    }
//    else {
//        checkNumber = checkNum;
//        checkAmount = checkAmt;
//        cashedStatus = alrdyCashed;
//    }
//}
//
//void Check::setCheckAmount(Money checkAmt) {
//
//    // Valid check amount
//    if (checkAmt.get_value() > ZERO_DOLLARS_AND_CENTS) {
//        checkAmount = checkAmt;
//    }
//
//    // Invalid check amount
//    else {
//        cout << "$" << fixed << setprecision(2) << checkAmt.get_value() << " is an invalid check amount." << endl;
//    }
//}
//
//ostream& operator <<(ostream& outs, const Check& check) {
//
//    const int cashed = 1;
//
//    // Output check details
//    if (check.getCashedStatus() == cashed) {
//        outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t\t" << "Yes" << endl;
//    }
//    else {
//        outs << check.getCheckNumber() << "\t\t\t" << check.getCheckAmount() << "\t\t" << "No" << endl;
//    }
//
//    return outs;
//}
//
//// --------------- OTHER PROGRAM FUNCTION DEFINITIONS --------------------
//
//void writeChecks(Check*& outCheckAccount, int& outCheckAccountSize) {
//
//    int checkBookCapacity = 1;
//    Check* account = new Check[checkBookCapacity];
//    int checkCount = 0;
//
//    bool firstTry = true;
//    cout << "You now have the option to write some checks." << endl;
//
//    bool doneWritingChecks = false;
//    while (!doneWritingChecks) {
//
//        if (firstTry) {
//            cout << "Do you want to write a check? (y/n) ";
//            firstTry = false;
//        }
//        else {
//            cout << "Do you want to write another check? (y/n) ";
//        }
//
//        // Get user choice
//        char answer;
//        cin >> answer;
//
//        // Done writing checks
//        if (answer == 'n' || answer == 'N') {
//            doneWritingChecks = true;
//        }
//
//        // Write another check
//        else {
//
//            // Check number
//            int checkNumber;
//            cout << "Please enter the check number (1-999 e.g. 12): "; // I set this limit so the check list format is nicely output at the end, can be removed
//            cin >> checkNumber;
//
//            // Make sure check not already added
//            bool checkNumAlreadyUsed = false;
//            for (int i = 0; i < checkCount; i++) {
//                if (checkNumber == account[i].getCheckNumber()) {
//                    checkNumAlreadyUsed = true;
//                }
//            }
//
//            // Not used
//            if (!checkNumAlreadyUsed) {
//                // Check value
//                Money checkAmount;
//                cout << "Please enter the check amount (in the format $X.XX): ";
//                cin >> checkAmount;
//
//                // Check cashed status
//                bool cashedCheck;
//                cout << "Is the check already cashed? (Enter 1 for yes, 0 for no): ";
//                cin >> cashedCheck;
//
//                // Increase checkbook size if necessary
//                if (checkCount == checkBookCapacity) {
//
//                    Check* temp = new Check[checkBookCapacity * 2];
//
//                    for (int i = 0; i < checkCount; i++) {
//                        temp[i] = account[i];
//                    }
//
//                    delete[] account;
//                    account = temp;
//                    checkBookCapacity *= 2;
//                }
//
//                // Create check
//                account[checkCount] = Check(checkNumber, checkAmount, cashedCheck);
//                checkCount++;
//            }
//
//            // Already used check #
//            else {
//                cout << "Check number " << checkNumber << " was already used. You can not reuse the same check number." << endl;
//            }
//        }
//    }
//
//    outCheckAccountSize = checkCount;
//    outCheckAccount = account;
//}
//
//void depositMoney(Money*& outDepositsLog, int& outDepositsLogSize) {
//
//    int maxDeposits = 1;
//    Money* depositsLog = new Money[maxDeposits];
//    int depositCount = 0;
//
//    bool firstTry = true;
//    cout << "You can now make deposits into your checking account." << endl;
//
//    bool doneDepositing = false;
//    while (!doneDepositing) {
//
//        if (firstTry) {
//            cout << "Do you want to make a deposit? (y/n) ";
//            firstTry = false;
//        }
//        else {
//            cout << "Do you want to make another deposit? (y/n) ";
//        }
//
//        // Get user choice
//        char answer;
//        cin >> answer;
//
//        // Done making deposits
//        if (answer == 'n' || answer == 'N') {
//            doneDepositing = true;
//        }
//
//        // Make another deposit
//        else {
//
//            // Get deposit
//            Money depositAmount;
//            cout << "Please enter the deposit amount (in the format $X.XX): ";
//            cin >> depositAmount;
//
//            // Increase deposit log size if necessary
//            if (depositCount == maxDeposits) {
//
//                Money* temp = new Money[maxDeposits * 2];
//
//                for (int i = 0; i < depositCount; i++) {
//                    temp[i] = depositsLog[i];
//                }
//
//                delete[] depositsLog;
//                depositsLog = temp;
//                maxDeposits *= 2;
//            }
//
//            // Create check
//            depositsLog[depositCount] = depositAmount;
//            depositCount++;
//        }
//    }
//
//    outDepositsLogSize = depositCount;
//    outDepositsLog = depositsLog;
//}
//
//Money getInitialBalance() {
//
//    cout << "Welcome to the NYU Tandon Digital Bank. Let me get some details about your checking account.\n\n";
//
//    Money balance;
//    cout << "Please enter your initial account balance (in the format $X.XX): ";
//    cin >> balance;
//
//    return balance;
//}
//
//Money calculateTotal(const Check* account, int accountSize, bool onlyCashed) {
//
//    Money total;
//
//    // Sum up cashed checks
//    if (onlyCashed) {
//
//        for (int i = 0; i < accountSize; i++) {
//
//            if (account[i].getCashedStatus()) {
//                total = total + account[i].getCheckAmount();
//            }
//        }
//    }
//
//    // Sum up all checks
//    else {
//        for (int i = 0; i < accountSize; i++) {
//            total = total + account[i].getCheckAmount();
//        }
//    }
//
//    return total;
//}
//
//Money calculateTotal(const Money* deposit, int depositSize) {
//
//    Money total;
//
//    // Sum up cashed checks
//    for (int i = 0; i < depositSize; i++) {
//        total = total + deposit[i];
//    }
//
//    return total;
//}
//
//void outputChecks(const Check* checks, int checkSize, bool cashed) {
//
//    // Print cashed checks
//    if (cashed) {
//        cout << "List of cashed checks:\n";
//        cout << "Check#\t\tAmount\t\tCashed\t\t\n";
//        for (int i = 0; i < checkSize; i++) {
//            if (checks[i].getCashedStatus()) {
//                cout << checks[i];
//            }
//        }
//    }
//
//    // Print uncashed checks
//    else {
//        cout << "List of uncashed checks:\n";
//        cout << "Check#\t\tAmount\t\tCashed\n";
//        for (int i = 0; i < checkSize; i++) {
//            if (!checks[i].getCashedStatus()) {
//                cout << checks[i];
//            }
//        }
//    }
//}
//
//void sort(Check*& checks, int checkSize) {
//
//    // Loop through list of checks
//    for (int i = 0; i < checkSize; i++) {
//
//        int minIndex = i;
//
//        // Find next minimum check number
//        for(int j = i; j < checkSize; j++) {
//            if (checks[minIndex].getCheckNumber() > checks[j].getCheckNumber()) {
//                minIndex = j;
//            }
//        }
//
//        // Swap minimum and current element
//        Check temp = checks[i];
//        checks[i] = checks[minIndex];
//        checks[minIndex] = temp;
//    }
//}