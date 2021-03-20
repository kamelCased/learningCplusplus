#include <iostream>

int calculateSum (int a, int b);

int main() {

    // Get two numbers from user
    int a, b;
    std::cout << "Enter first integer: ";
    std::cin >> a;
    std::cout << "Enter second integer: ";
    std::cin >> b;

    // Get sum
    int sum = calculateSum(a,b);

    // Output result
    std::cout << "The sum of " << a << " and " << b << " is " << sum << std::endl;

    return 0;
}

int calculateSum (int a, int b) {

    if (b == 0) {
        return a;
    }

    else if (a == 0) {
        return b;
    }

    else {
        if (a < b) {
            return calculateSum(a, b-1) + 1;
        }
        else {
            return calculateSum(a-1, b) + 1;
        }
    }
}
