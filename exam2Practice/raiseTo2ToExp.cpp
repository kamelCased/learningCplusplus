#include <iostream>

int raiseToTwoExp(int n, int exp);

int main() {

    // Get user input
    int n, exp;
    std::cout << "Please enter a positive integer:" << std::endl;
    std::cin >> n;
    std::cout << "Please enter another positive integer:" << std::endl;
    std::cin >> exp;

    // Calculate n^(2^exp)
    int raised = raiseToTwoExp(n, exp);

    //Output result
    std::cout << n << " to the power of (2^" << exp << ") is " << raised << std::endl;

    return 0;
}

int raiseToTwoExp(int n, int exp) {

    if (exp == 0){
        return n;
    }

    else {
        int raised = raiseToTwoExp(n, exp - 1);
        return raised * raised;
    }
}
