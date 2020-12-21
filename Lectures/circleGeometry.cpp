#include <iostream>
#include <cmath>
using namespace std;

int main() {

  float radius, perimeter, area;

  cout << "Please enter the radius of your circle!" << endl;
  cin >> radius;

  perimeter = 2 * M_PI * radius;

  area = M_PI * (radius * radius);

  cout << "Your circle has perimeter " << perimeter << " and area " << area << "!" << endl;

  return 0;
}