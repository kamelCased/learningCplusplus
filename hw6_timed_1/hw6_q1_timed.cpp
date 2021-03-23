#include <iostream>
using namespace std;

int fib (int n);

int main() {

    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;

    int f = fib(n);

    cout << f << endl;

    return 0;
}

int fib (int n) {

    int fibo1 = 0;
    int fibo2 = 1;

    for (int i = 2; i <= n; i++) {
            int temp = fibo1;
            fibo1 = fibo2;
            fibo2 += temp;
    }

    return fibo2;
}