#include <iostream>
#include <vector>
using namespace std;

int getGCD (int n, int d) {
    vector<int> denom;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            denom.push_back(i);
    }
    int gcd = 1;
    for (int el: denom) {
        if (d % el == 0) {
            gcd = el;
        }
    }

    return gcd;
}

class Rational {
    int numerator;
    int denominator;
public:
    Rational(int num, int den): numerator(num), denominator(den) {if (den == 0){cout << "Zero denominator" << endl; exit(1);}}
    Rational(): numerator(0), denominator(1) {}
    friend istream& operator>>(istream& i, Rational& r);
    friend ostream& operator<<(ostream& o, const Rational& r);
    Rational operator+(const Rational& r2) const;
    Rational operator-(const Rational& r2) const;
    Rational operator*(const Rational& r2) const;
    Rational operator/(const Rational& r2) const;
    Rational operator-() const {return Rational(numerator * -1, denominator);}
    bool operator<(const Rational& r2) const;
    bool operator==(const Rational& r2) const;
};
istream& operator>>(istream& i, Rational& r) {
    int n,d;
    char slash;
    i >> n >> slash >> d;
    r = Rational(n,d);
    return i;
}
ostream& operator<<(ostream& o, const Rational& r) {
    o << r.numerator << '/' << r.denominator;
    return o;
}
Rational Rational::operator+(const Rational& r2) const {
    int n = (this->numerator * r2.denominator + this->denominator * r2.numerator);
    int d = (this->denominator * r2.denominator);

    int gcd = getGCD(n, d);

    n /= gcd;
    d /= gcd;

    Rational sum(n,d);

    return sum;
}
Rational Rational::operator-(const Rational& r2) const {

    int n = (this->numerator * r2.denominator - this->denominator * r2.numerator);
    int d = (this->denominator * r2.denominator);

    int gcd = getGCD(n, d);

    n /= gcd;
    d /= gcd;

    Rational diff(n,d);

    return diff;
}
Rational Rational::operator*(const Rational& r2) const {

    int n = (this->numerator * r2.numerator);
    int d = (this->denominator * r2.denominator);

    int gcd = getGCD(n, d);

    n /= gcd;
    d /= gcd;

    Rational prod(n,d);

    return prod;
}
Rational Rational::operator/(const Rational& r2) const {

    int n = (this->numerator * r2.denominator);
    int d = (this->denominator * r2.numerator);

    int gcd = getGCD(n, d);

    n /= gcd;
    d /= gcd;

    Rational quotient(n,d);

    return quotient;
}
bool Rational::operator<(const Rational& r2) const {
    int n1 = this->numerator;
    int d1 = this->denominator;
    int n2 = r2.numerator;
    int d2 = r2.denominator;

    if ((n1 * d2) < (d1 * n2)) {
        return true;
    }
    return false;
}
bool Rational::operator==(const Rational& r2) const {
    int n1 = this->numerator;
    int d1 = this->denominator;
    int n2 = r2.numerator;
    int d2 = r2.denominator;

    if ((n1 * d2) == (d1 * n2)) {
        return true;
    }
    return false;
}

int main() {

    Rational r;
    cout << "Welcome, fellow rational mind!" << endl;
    cout << "Please enter a rational number (in the form a/b):" << endl;
    cin >> r;

    bool done = false;
    while (!done) {
        int choice;
        cout << "What would you like to do?" << endl;
        cout << "1. Add a rational number" << endl;
        cout << "2. Subtract a rational number" << endl;
        cout << "3. Multiply by a rational number" << endl;
        cout << "4. Divide by a rational number" << endl;
        cout << "5. Check if smaller than a rational number" << endl;
        cout << "6. Check if equal to a rational number" << endl;
        cout << "7. Change the sign of your rational number" << endl;
        cout << "-1. Exit calculator" << endl;
        cin >> choice;
        if (choice == -1) {
            done = true;
            cout << "Exiting. Thank you for using the rational calculator" << endl;
        }
        else if (choice == 7) {
            cout << r << " * -1 = " << -r << endl;
        }
        else {
            Rational r2;
            cout << "Great, please enter the other rational number: " << endl;
            cin >> r2;
            switch (choice) {
                case 1:
                    cout << r << " + " << r2 << " = " << r + r2 << endl;
                    break;
                case 2:
                    cout << r << " - " << r2 << " = " << r - r2 << endl;
                    break;
                case 3:
                    cout << r << " * " << r2 << " = " << r * r2 << endl;
                    break;
                case 4:
                    cout << r << " / " << r2 << " = " << r / r2 << endl;
                    break;
                case 5:
                    if (r < r2) {
                        cout << r << " < " << r2 << endl;
                    }
                    else {
                        cout << r2 << " <= " << r << endl;
                    }
                    break;
                case 6:
                    if (r == r2) {
                        cout << r << " = " << r2 << endl;
                    }
                    else {
                        cout << r << " != " << r2 << endl;
                    }
                    break;
            }
        }
    }

    return 0;
}

