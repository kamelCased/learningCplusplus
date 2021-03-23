#include <iostream>
using namespace std;

double eApprox(int n);

int main() {

    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double eApprox(int n) {

    double e = 1;
    double fac = 1;
    for(int i = 1; i <= n; i++) {
        fac *= i;
        e += 1.0/fac;
    }

    return e;
}
