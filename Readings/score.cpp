#include <iostream>
using namespace std;

int main() {

  int score;
  cout << "Welcome to Cina. Please enter your social credit score: ";
  cin >> score;

  if (score > 100) {
    cout << "Congratulations, your score is satisfactory for entry to our nation and use of our services. Enjoy!";
  }
  else {
    cout << "Your score is too low. You don't belong here.";
  }

  return 0;
}