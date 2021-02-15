#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a;
    cout << "Please enter value of a: ";
    cin >> a;
    double b;
    cout << "Please enter value of b: ";
    cin >> b;
    double c;
    cout << "Please enter value of c: ";
    cin >> c;

    double discriminant = b*b -4*a*c;
    double root1, root2;

    if ((a==0) && (b==0) && (c==0)) {
        cout << "Infinite solutions" << endl;
    }
    else if ((a==0) && (b==0)) {
        cout << "No solutions" << endl;
    }
    else if (discriminant < 0) {
        cout << "No real solutions" << endl;
    }
    else if (discriminant == 0) {
        root1 = -b/(2*a);
        cout << "One real solution x=" << root1 << endl;
    }
    else if ((a==0) && (b!=0)) {
        root1 = -b/c;
        cout << "One real solution x=" << root1 << endl;
    }
    else {
        root1 = (-b - pow(discriminant, 0.5))/(2*a);
        root2 = (-b + pow(discriminant, 0.5))/(2*a);
        cout << "Two real solutions x1=" << root1 << " and x2=" << root2 << endl;
    }

    return 0;
}
