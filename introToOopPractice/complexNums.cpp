#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:

    // Constructors
    Complex(double r, double i): real(r), imaginary(i) {};
    Complex(double r): real(r), imaginary(0.0) {};
    Complex(): real(0.0), imaginary(0.0) {};

    // Operators
    bool operator==(const Complex& rhs) const {return this->real == rhs.real && this->imaginary == rhs.imaginary;}
    Complex operator+(const Complex& rhs) const {Complex c(real + rhs.real, imaginary + rhs.imaginary); return c;}
    Complex operator-(const Complex& rhs) const {Complex c(real - rhs.real, imaginary - rhs.imaginary); return c;}
    Complex operator*(const Complex& rhs) const {Complex c(real * rhs.real, imaginary * rhs.imaginary); return c;}

    friend ostream& operator<< (ostream& o, const Complex& complex);
    friend istream& operator>> (istream& i, const Complex& complex);
};

ostream& operator<< (ostream& o, const Complex& complex) {

    if (complex.imaginary >= 0) {
        o << "C = " << complex.real << " + " << complex.imaginary  << "i" << endl;
    }

    else {
        o << "C = " << complex.real << " " << complex.imaginary  << "i" << endl;
    }

    return o;
}

istream& operator>> (istream& i, const Complex& complex) {

    cout << "Please enter the real portion:" << endl;
    i >> complex.real;

    cout << "Please enter the imaginary portion:" << endl;
    i >> complex.imaginary;

    return i;
}
