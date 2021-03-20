#include <iostream>

int sumOddsUpto(int n);

int main() {

    // Get input
    int n;
    std::cout << "Hello, please enter a positive integer:" << std::endl;
    std::cin >> n;

    // Get sum of all odds up to n
    int sumOdds = sumOddsUpto(n);

    // Output results
    std::cout << "The sum of all odd numbers between 1 and " << n << " is " << sumOdds << std::endl;

    return 0;
}

int sumOddsUpto(int n) {

    if (n == 1)
        return 1;

    else {

        if (n % 2 == 0) {
            return sumOddsUpto(n - 1);
        }

        else {
            return sumOddsUpto(n - 2) + n;
        }
    }
}