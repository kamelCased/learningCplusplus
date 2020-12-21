#include <iostream>
#include <string>
using namespace std;

int main() {

  string userName,standardGreeting, personalizedGreeting;

  standardGreeting = "Nice to meet you ";

  cout << "What is your name?" << endl;
  cin >> userName;

  personalizedGreeting = standardGreeting + userName + "!";

  cout << personalizedGreeting << endl;

  return 0;

}