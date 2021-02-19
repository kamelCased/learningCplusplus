#include <iostream>
using namespace std;

// raiseToPower: raises number to the power powerValue
double raiseToPower(double base, int powerValue);

// getFactorial: produces the value of num factorial
long getFactorial(int num);

// cos: gives the cosine value of an angle rad with approx accuracy (in runtime n^2)
double cos (double rad, int approx);

// linearCos: gives the cosine value of an angle rad with approx accuracy (in runtime n)
double linearCos (double rad, int approx);


int main() {
    double radians;
    cout << "Please enter the angle in radians: ";
    cin >> radians;

    /*
    int accuracyTerms;
    cout << "Please enter the number of terms in your cosine approximation: ";
    cin >> accuracyTerms;
    */
    double cosine;
    for (int accuracyTerms = 1; accuracyTerms <= 10; accuracyTerms++) {
        cosine = cos(radians, accuracyTerms);
        cout << "The slow cosine of " << radians << " is " << cosine << endl;
        cosine = linearCos(radians, accuracyTerms);
        cout << "The fast cosine of " << radians << " is " << cosine << endl;
    }

    return 0;
}


double raiseToPower(double base, int powerValue) {

    double product = 1.0;

    for (int pow = 1; pow <= powerValue; pow++) {
        product *= base;
    }

    return product;
}


long getFactorial(int num) {

    long factorial = 1;

    for (int fact = 1; fact <= num; fact++) {
        factorial *= fact;
    }

    return factorial;
}


double cos (double rad, int approx) {

    double cosine = 0.0;

    for (int term = 0; term <= approx - 1; term++){

        double pow = raiseToPower(rad,2 * term);
        double f = getFactorial (2 * term);

        if (term % 2) {
            cosine -= (pow / f);
        }
        else  {
            cosine += (pow / f);
        }
    }

    return cosine;
}

double linearCos (double rad, int approx) {

    double cosine = 0.0;
    double currentPower = 1.0;
    double currentFactorial = 1.0;

    for (int term = 0; term <= (approx - 1); term++) {

        if (term % 2) {
            cosine -= (currentPower / currentFactorial);
        }
        else  {
            cosine += (currentPower / currentFactorial);
        }

        currentPower *= (rad * rad);
        currentFactorial *= ((2 * term + 1) * (2 * term + 2));
    }

    return cosine;
}