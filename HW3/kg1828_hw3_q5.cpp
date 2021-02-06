// Assignment: NYU Tandon Bridge Homework 3 Question 5
// Author: Kamel Gazzaz
// Assignment: 01/29/2021
#include <iostream>
#include <string>
using namespace std;

// Standard imperial to metric conversions
const double POUNDS_TO_KG = 0.453592;
const double INCHES_TO_METERS = 0.0254;

// BMI cutoff weights
const double OBESITY_LIMIT = 30.0;
const double OVERWEIGHT_LIMIT = 25.0;
const double NORMAL_WEIGHT_LIMIT = 18.5;

int main() {

    double weight, height;

    // Get user's height and weight
    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    // Convert to metric
    weight = weight * POUNDS_TO_KG;
    height = height * INCHES_TO_METERS;

    // Calculate BMI
    double bmi;
    bmi = weight / (height * height);

    // Check bmi status
    string weightStatus;
    if (bmi >= OBESITY_LIMIT) {
        weightStatus = "Obese";
    }
    else if (bmi >= OVERWEIGHT_LIMIT) {
        weightStatus = "Overweight";
    }
    else if (bmi >= NORMAL_WEIGHT_LIMIT) {
        weightStatus = "Normal";
    }
    else {
        weightStatus = "Underweight";
    }

    //Output weight status
    cout << "The weight status is: " << weightStatus << endl;

    return 0;
}
