#include <iostream>
using namespace std;

int main() {
    int height, weight;
    cout << "Enter your height in inches" << std::endl;
    cin >> height;
    std::cout << "Enter your weight in lbs" << std::endl;
    cin >> weight;

    double bmi = (double) weight / (height * height);

    if (bmi >= 30) {
        cout << "The weight status is: Obese" << endl;
    }
    else if (bmi >= 25) {
        cout << "The weight status is: Overweight" << endl;
    }
    else if (bmi >= 18.5) {
        cout << "The weight status is: Normal" << endl;
    }
    else {
        cout << "The weight status is: Underweight" << endl;
    }

    return 0;
}
