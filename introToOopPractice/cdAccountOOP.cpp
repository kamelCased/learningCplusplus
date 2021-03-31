#include <iostream>
using namespace std;

class CDAccount{
private:
    double balance;
    double interest_rate;
    int term; //months until maturity
public:
    CDAccount(): balance(0.0), interest_rate(0.0), term(0) {}
    CDAccount(double initBalance, double initRate, int initTerm): balance(initBalance), interest_rate(initRate), term(initTerm) {}
    double get_init_balance() const {return balance;}
    double get_maturity_balance() const {
        double temp = balance;
        for(int i = 1; i <= term; i++)
            temp *= (1 + interest_rate / 100.0 / 12.0);
        return temp;
    }
    double get_interest_rate() const {return interest_rate;}
    int get_term() const {return term;}
};

void get_data(CDAccount& the_account);

int main( ) {

    CDAccount meloAccount;
    get_data(meloAccount);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "When your CD matures in " << meloAccount.get_term() << " months,\n" << "it will have a balance of $" << meloAccount.get_maturity_balance() << endl;
    return 0;
}

//Uses iostream:
void get_data(CDAccount& the_account) {
    double b, r;
    int t;
    cout << "Enter account balance: $";
    cin >> b;
    cout << "Enter account interest rate: ";
    cin >> r;
    cout << "Enter the number of months until maturity: ";
    cin >> t;
    CDAccount temp(b,r,t);
    the_account = temp;
}