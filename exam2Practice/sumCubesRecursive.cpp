#include <iostream>
using namespace std;

int sumCubes(int n);

int main() {

    // Get input from user
    int n;
    cout << "Hello, please enter a positive integer:" << endl;
    cin >> n;

    // compute the sum of the cubes until the input integer
    int sum = sumCubes(n);

    // Output result
    cout << "The sum of the cubes from 1 to " << n << " equal " << sum << endl;

    return 0;
}

int sumCubes(int n) {

    if (n == 1) {
        return 1;
    }
    else {
        return sumCubes(n - 1) + (n * n * n);
    }
}