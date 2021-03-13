#include <iostream>

void getNumber(int* num);
void getFactorial(int* number, int*& factorial);

int main() {

    // Get number from user
    int* num = new int;
    getNumber(num);

    // Calculate factorial
    int* factorial;
    getFactorial(num, factorial);

    // Output result
    std::cout << *num << "! = " << *factorial << std::endl;

    // free memory
    delete num, factorial;
    num = factorial = nullptr;

    return 0;
}

void getFactorial(int* number, int*& factorial) {

    factorial = new int;
    *factorial = 1;

    for (int i = *number; i > 0; i--) {
        *factorial *= i;
    }
}

void getNumber(int* num) {

    int input;

    std::cout << "Please enter a positive integer:" << std::endl;
    std::cin >> input;

    *num = input;
}
