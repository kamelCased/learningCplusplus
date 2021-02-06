// Assignment: NYU Tandon Bridge Homework 3 Question 3
// Author: Kamel Gazzaz
// Due Date: 01/29/2021
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Get parameters for binomial ax^2 + bx + c from user
    double a, b, c;
    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    // Determine the number of roots
    double discriminant = (b*b - 4 * a * c);
    // Horizontal line at 0
    if ((a == 0) && (b == 0) && (c == 0)) {
        cout << "This equation has an infinite number of solutions" << endl;
    }
    // Non-zero horizontal line
    else if ((a == 0) && (b == 0) && (c != 0)) {
        cout << "This equation has no solution" << endl;
    }
    // parabola doesn't cross x axis (note that this includes the case where b==0 and a!=0 and c!=0)
    else if (discriminant < 0) {
        cout << "This equation has no real solutions" << endl;
    }
    // non-horizontal straight line crosses x axis at the origin
    else if ((a == 0) && (b != 0) && (c == 0)) {
        double root = c;
        cout << "This equation has a single real solution x=" << root << endl;
    }
    // non-horizontal straight line crosses x axis at one point (not origin)
    else if ((a == 0) && (b != 0)) {
        double root = -c/b;
        cout << "This equation has a single real solution x=" << root << endl;
    }
    // parabola touches x axis at one point
    else if (discriminant == 0) {
        double root = (-b) / (2 * a);
        cout << "This equation has a single real solution x=" << root << endl;
    }
    // parabola crosses x axis at two points
    else {
        double root1 = ((-b) - sqrt(discriminant)) / (2 * a);
        double root2 = ((-b) + sqrt(discriminant)) / (2 * a);
        cout << "This equation has two real solutions x1=" << root1 << " and x2=" << root2 << endl;
    }

    return 0;
}
