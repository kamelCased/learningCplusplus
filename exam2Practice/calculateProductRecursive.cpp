#include <iostream>

int calculateProduct(int a, int b);

int main() {

    // Get input
    int first, second;
    std::cout << "Please enter first integer: ";
    std::cin >> first;
    std::cout << "Please enter second integer: ";
    std::cin >> second;

    // get product of first and second
    int prod = calculateProduct(first, second);

    // Output result
    std::cout << "The product is " << prod << std::endl;

    return 0;
}

int calculateProduct(int a, int b) {

    if (b == 0) {
        return 0;
    }

    else {
        return calculateProduct(a, b - 1) + a;
    }
}