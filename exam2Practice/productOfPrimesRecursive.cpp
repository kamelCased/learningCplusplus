#include <iostream>

bool isPrime(int n);
int productOfPrimes(int n);

int main() {

    //Get input
    int n;
    std::cout << "Please enter a positive integer:" << std::endl;
    std::cin >> n;

    // Calculate product of primes
    int primeProd = productOfPrimes(n);

    // Output results
    std::cout << "The product of all prime numbers up to " << n << " is " << primeProd << std::endl;

    return 0;
}

int productOfPrimes(int n) {

    if (n == 1){
        return n;
    }

    else {
        if (isPrime(n)) {
            return productOfPrimes(n - 1) * n;
        }
        else {
            return productOfPrimes(n - 1);
        }
    }
}

bool isPrime(int n) {

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
