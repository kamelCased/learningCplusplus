#include <iostream>
#include <cmath>

void getInt(int*& num);
void reverseDigits(int* num, int*& reverse);
// Note: ignores leading 0's
int getOrderOfMagnitude(int tempNum);

int main() {

    // Get a number from the user
    int* num = new int;
    getInt(num);

    // Get the reverse
    int* reverse;
    reverseDigits(num, reverse);

    // Output result
    std::cout << "The reverse of " << *num << " is " << *reverse << std::endl;

    // free memory
    delete reverse, num;
    reverse = num = nullptr;

    return 0;
}

void reverseDigits(int* num, int*& reverse) {

    reverse = new int;
    *reverse = 0;

    int tempNum = *num;
    int multiplier = pow(10, getOrderOfMagnitude(tempNum));


    while (tempNum > 0) {
        int digit = tempNum % 10;
        *reverse += (digit * multiplier);
        multiplier /= 10;
        tempNum /= 10;
    }
}

void getInt(int*& num) {

    std::cout << "Please enter a positive integer:" <<std::endl;
    std::cin >> *num;
}

int getOrderOfMagnitude(int tempNum) {

    int order = 0;

    while (tempNum >= 10) {
        tempNum /= 10;
        order++;
    }

    return order;
}