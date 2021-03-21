#include <iostream>

int fibo (int n);

int main() {

    //Get user input
    int n;
    std::cout << "Please enter an integer:" << std::endl;
    std::cin >> n;

    //Calculate nth fibonacci number
    int f = fibo(n);

    //Output result
    std::cout << "The " << n << "th Fibonacci number is " << f << std::endl;

    return 0;
}

int fibo (int n) {

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else {
        return fibo(n - 1) + fibo(n - 2);
    }
}



