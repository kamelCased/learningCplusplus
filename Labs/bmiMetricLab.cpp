#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  float height, weight;
  float bmi;
  cout << "Please enter weight in kilograms:" << endl;
  cin >> weight;

  cout << "Please enter height in meters:" << endl;
  cin >> height;

  bmi = weight / (height * height);

  cout << "Your BMI is: " << fixed << setprecision(2) <<  bmi << endl;

  return 0;
}