#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Figure {

public:

    virtual void erase() const = 0;
    virtual void draw() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Rectangle: public Figure {

    double side1;
    double side2;

public:
    Rectangle(double s1, double s2): side1(s1), side2(s2) {}

    void draw() const {cout << "Drawing rectangle" << endl;}
    void erase() const {cout << "Erasing rectangle" << endl;}

    double getArea() const {return side1 * side2;}
    double getPerimeter() const {return 2 * side1 + 2 * side2;}
};

class Triangle: public Figure {

    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3): side1(s1), side2(s2), side3(s3) {}

    void draw() const {cout << "Drawing triangle" << endl;}
    void erase() const {cout << "Erasing triangle" << endl;}

    double getArea() const;
    double getPerimeter() const {return side1 + side2 + side3;}
};
double Triangle::getArea() const {

    double semi = getPerimeter() / 2.0;
    return sqrt(semi * (semi - side1) * (semi - side2) * (semi - side3));
}

int main() {

    cout << "Hello, welcome to the figure maker!" << endl;

    vector<Figure*> figures;

    bool done;
    while (!done) {

        int choice;
        cout << "Enter next choice:" << endl;
        cout << "1. Triangle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. No more" << endl;
        cin >> choice;

        if (choice == 3) {
            done = true;
        }

        else if (choice == 2) {

            double s1, s2;
            cout << "Enter the values of the sides of your rectangle separated by a space" << endl;
            cin >> s1 >> s2;

            Rectangle* r = new Rectangle(s1, s2);

            figures.push_back(r);
        }

        else if (choice == 1) {

            double s1, s2, s3;
            cout << "Enter the values of the 3 sides of your triangle separated by a space" << endl;
            cin >> s1 >> s2 >> s3;

            Triangle* s = new Triangle(s1, s2, s3);

            figures.push_back(s);
        }
    }

    for (auto fig: figures) {

        fig->draw();
        cout << "Area: " << fig->getArea() << endl;
        cout << "Perimeter: " << fig->getPerimeter() << endl;
        cout << endl;
    }

    for (auto fig: figures) {

        fig->erase();
        delete fig;
        fig = nullptr;
    }

    return 0;
}
