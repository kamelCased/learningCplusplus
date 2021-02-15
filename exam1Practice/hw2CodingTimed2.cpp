/*
// Question 1
#include <iostream>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies;
    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    pennies = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
    int dollars = pennies / 100;
    pennies %= 100;

    cout << "The total is " << dollars << " dollars and " << pennies << " cents" << endl;

    return 0;
}
*/
/*
// Question 2
#include <iostream>
using namespace std;

int main() {

    int dollars, cents;
    cout << "Please enter number of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    cents = dollars * 100 + cents;

    int quarters = cents / 25;
    cents -= quarters * 25;

    int dimes = cents / 10;
    cents -= dimes * 10;

    int nickels = cents / 5;
    cents -= nickels * 5;

    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << ", nickels and " << cents << " pennies"
         << endl;

    return 0;
}
 */
/*
// Question 3
#include <iostream>
using namespace std;

int main() {

    int johnDays, johnHours, johnMins;
    cout << "Please enter the number of days John worked: ";
    cin >> johnDays;
    cout << "Please enter the number of hours John worked: ";
    cin >> johnHours;
    cout << "Please enter the number of minutes John worked: ";
    cin >> johnMins;
    cout << endl;

    int billDays, billHours, billMins;
    cout << "Please enter the number of days Bill worked: ";
    cin >> billDays;
    cout << "Please enter the number of hours Bill worked: ";
    cin >> billHours;
    cout << "Please enter the number of minutes Bill worked: ";
    cin >> billMins;
    cout << endl;

    int combinedMins = johnDays * 1440 + johnHours * 60 + johnMins + billDays * 1440 + billHours * 60 + billMins;

    int combinedDays = combinedMins / 1440;
    combinedMins -= combinedDays * 1440;

    int combinedHours = combinedMins / 60;
    combinedMins -= combinedHours * 60;

    cout << "The total time both of them worked together is: ";
    cout << combinedDays << " days, " << combinedHours << ", hours and ";
    cout << combinedMins << " minutes." << endl;

    return 0;
}
 */
/*
// Question 4
#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Please enter two positive integers separated by a space:" << endl;
    cin >> num1 >> num2;

    cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
    cout << num1 << " / " << num2 << " = " << (double)num1/num2 << endl;
    cout << num1 << " div " << num2 << " = " << num1/num2 << endl;
    cout << num1 << " mod " << num2 << " = " << num1%num2 << endl;

    return 0;

}
 */