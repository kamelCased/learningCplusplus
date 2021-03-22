#include <iostream>

int nChooseR(int n, int r);

int main() {

    // Get user input
    int n, r;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter r: ";
    std::cin >> r;

    // Calculate combinations
    int subsets = nChooseR(n, r);

    // Output result
    std::cout << n << " choose " << r << " = " << subsets << std::endl;

    return 0;
}

int nChooseR(int n, int r) {

    // Base case
    if (n == r) {
        return 1;
    }

    else {

        if (r >= n/2) {

            // Recursive call
            int nMinus1ChooseR = nChooseR(n - 1, r);

            // multiply by n and divide by (n-r) according to formula
            int nChooseR = nMinus1ChooseR * n;
            nChooseR /= (n - r);

            // return combinations
            return nChooseR;
        }

        else {

            // identity: n choose r == n choose n - r
            int nFac = nChooseR(n, n-r);
            return nFac;
        }
    }
}