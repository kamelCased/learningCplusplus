#include <iostream>
#include <cmath>

void computeAreaPerimeter(double a, double b, double c, double &area, double &perimeter);

int main() {

    // Get input
    double length1, length2, length3;
    std::cout << "Enter the length of the first side: ";
    std::cin >> length1;
    std::cout << "Enter the length of the second side: ";
    std::cin >> length2;
    std::cout << "Enter the length of the third side: ";
    std::cin >> length3;

    // Compute area and perimeter
    double triangleArea = -1; // for invalid side lengths
    double trianglePerimeter;
    computeAreaPerimeter(length1, length2, length3, triangleArea, trianglePerimeter);

    // Output result
    if (triangleArea != -1) {
        std::cout << "Area: " << triangleArea << std::endl;
        std::cout << "Perimeter: " << trianglePerimeter << std::endl;
    }
    else {
        std::cout << "Not a triangle" << std::endl;
    }

    return 0;
}

void computeAreaPerimeter(double a, double b, double c, double &area, double &perimeter) {

    if ((b > a + c) || (a > b + c) || (c > a + b)) {
        return;
    }

    perimeter = a + b + c;
    double semiperimeter = perimeter / 2.0;

    area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
}

