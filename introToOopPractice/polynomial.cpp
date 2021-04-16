#include <iostream>
#include <vector>
using namespace std;

class Polynomial {

    // Polynomial coefficients (at appropriate index)
    vector<double> coefficients;

public:

    // Constructors
    Polynomial() {coefficients.push_back(0);}
    Polynomial(const Polynomial& model): coefficients(model.coefficients) {}
    Polynomial(vector<double> coeff): coefficients(coeff) {}

    // Addition
    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator+(const double& rhs) const;
    friend Polynomial operator+(const double& lhs, const Polynomial& rhs);

    // Subtraction
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator-(const double& rhs) const;
    friend Polynomial operator-(const double& lhs, const Polynomial& rhs);

    // Multiplication
    Polynomial operator*(const Polynomial& rhs) const;
    Polynomial operator*(const double& rhs) const;
    friend Polynomial operator*(const double& lhs, const Polynomial& rhs);

    // Access/Mutate coefficient
    void setCoeff(double newCoeff, int index);
    double getCoeff(int index) const;

    // Evaluate Polynomial
    double getValueAt(double x) const;

    // Output equation
    void output() const;
};
Polynomial Polynomial::operator+(const Polynomial& rhs) const {

    vector<double> vec;

    for (int i = 0; i < min(coefficients.size(), rhs.coefficients.size()); i++) {
        vec.push_back(coefficients[i] + rhs.coefficients[i]);
    }
    if (coefficients.size() < rhs.coefficients.size()) {
        for (int i = coefficients.size(); i < rhs.coefficients.size(); i++)
            vec.push_back(rhs.coefficients[i]);
    }
    else {
        for (int i = rhs.coefficients.size(); i < coefficients.size(); i++)
            vec.push_back(coefficients[i]);
    }

    Polynomial p (vec);
    return p;
}
Polynomial Polynomial::operator+(const double& rhs) const {

    vector<double> vec = coefficients;
    vec[0] += rhs;
    Polynomial p (vec);
    return p;
}
Polynomial operator+(const double& lhs, const Polynomial& rhs) {
    vector<double> vec = rhs.coefficients;
    vec[0] += lhs;
    Polynomial p (vec);
    return p;
}
Polynomial Polynomial::operator-(const Polynomial& rhs) const {

    vector<double> vec;

    for (int i = 0; i < min(coefficients.size(), rhs.coefficients.size()); i++) {
        vec.push_back(coefficients[i] - rhs.coefficients[i]);
    }
    if (coefficients.size() < rhs.coefficients.size()) {
        for (int i = coefficients.size(); i < rhs.coefficients.size(); i++)
            vec.push_back(-rhs.coefficients[i]);
    }
    else {
        for (int i = rhs.coefficients.size(); i < coefficients.size(); i++)
            vec.push_back(coefficients[i]);
    }

    Polynomial p (vec);
    return p;
}
Polynomial Polynomial::operator-(const double& rhs) const {

    vector<double> vec = coefficients;
    vec[0] -= rhs;
    Polynomial p (vec);
    return p;
}
Polynomial operator-(const double& lhs, const Polynomial& rhs) {
    vector<double> vec = rhs.coefficients;
    vec[0] -= lhs;
    Polynomial p (vec);
    return p;
}
Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    vector<double> vec(rhs.coefficients.size() + coefficients.size(), 0);
    for (int i = 0; i < coefficients.size(); i++) {
        for (int j = 0; j < rhs.coefficients.size(); j++) {
            vec[i+j] += coefficients[i] * rhs.coefficients[j];
        }
    }

    Polynomial p (vec);
    return p;
}
Polynomial Polynomial::operator*(const double& rhs) const {
    vector<double> vec = coefficients;
    for (int i = 0; i < coefficients.size(); i++) {
        vec[i] *= rhs;
    }

    Polynomial p (vec);
    return p;
}
Polynomial operator*(const double& lhs, const Polynomial& rhs) {
    vector<double> vec = rhs.coefficients;
    for (int i = 0; i < rhs.coefficients.size(); i++) {
        vec[i] *= lhs;
    }

    Polynomial p (vec);
    return p;
}
void Polynomial::setCoeff(double newCoeff, int index) {
    if (index >= 0) {
        if (index < coefficients.size())
            coefficients[index] = newCoeff;
        else {
            for (int i = coefficients.size(); i < index; i++) {
                coefficients.push_back(0);
            }
            coefficients.push_back(newCoeff);
        }
    }
}
double Polynomial::getCoeff(int index) const {
    if (index < 0) {
        cout << "Invalid index";
        exit(1);
    }
    else {
        if (index < coefficients.size()) {
            return coefficients[index];
        }
        else {
            return 0;
        }
    }
}
double Polynomial::getValueAt(double x) const {
    int result = 0;
    for (int i = 0; i < coefficients.size(); i++) {
        result += coefficients[i] * pow(x,i);
    }

    return result;
}

void Polynomial::output() const {

    cout << "f(x)= ";

    int i = coefficients.size() - 1;
    while (coefficients[i] == 0)
        i--;

    for (int j = i; j >= 0; j--) {
        if (j == i) {
            cout << coefficients[j] << "x^" << j;
        }
        else if (j == 0) {
            if (coefficients[j] > 0)
                cout << " + " << coefficients[j];
            else if (coefficients[j] < 0)
                cout << " " << coefficients[j];
        }
        else  {
            if (coefficients[j] > 0)
                cout << " + " << coefficients[j] << "x^" << j;
            else if (coefficients[j] < 0)
                cout << " " << coefficients[j] << "x^" << j;
        }
    }

    cout << endl;
}

int main() {

    vector<double> v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(1);
    Polynomial p1(v1);

    vector<double> v2;
    v2.push_back(3);
    v2.push_back(2);
    v2.push_back(0);
    v2.push_back(2);
    Polynomial p2(v2);
    Polynomial p3 = p1 * p2;

    p3.output();
    cout << "At x=2, f(x)=" << p3.getValueAt(2) << endl;

    return 0;
}