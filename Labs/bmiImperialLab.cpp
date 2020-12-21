#include <iostream>
#include <iomanip>

using namespace std;

const double WEIGHT_CONVERSION = 0.453592;
const double HEIGHT_CONVERSION = 0.0254;

int main() {
  float height, weight;
  float bmi;
  cout << "Please enter weight in pounds:" << endl;
  cin >> weight;

  cout << "Please enter height in inches:" << endl;
  cin >> height;

  height = height * HEIGHT_CONVERSION; 
  weight = weight * WEIGHT_CONVERSION; 

  bmi = weight / (height * height);

  cout << "Your BMI is: " << fixed << setprecision(2) <<  bmi << endl;

  return 0;
}