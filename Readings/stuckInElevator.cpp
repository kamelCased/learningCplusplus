#include <iostream>
using namespace std;

const int MAX_TEMP = 100; 
const int MAX_PRESSURE = 100;

int main() {

  cout << "Oh no, you're stuck in the elevator. We're calling the evac team. \n" << endl;
  
  int temperature, pressure;
  cout << "Good news, evac team will get here in 5 minutes. What is the temperature in there? ";
  cin >> temperature;

  cout << "\nAnd what's the pressure? ";
  cin >> pressure;

  if ((temperature > MAX_TEMP)||(pressure > MAX_PRESSURE) || (temperature + pressure > MAX_TEMP + MAX_PRESSURE)) {
    cout << "\nThe conditions were too grave. You didn't make it... " << endl;
  }
  else {
    cout << "\nConditions are ok. You should be able to hang on until the rescue team gets here!" << endl;
  }

  return 0;
}