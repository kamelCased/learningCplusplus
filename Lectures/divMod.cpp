#include <iostream>
using namespace std;

const int WEEK_LENGTH = 7;

int main() {

  int days, weeks, remaining_days;

  cout << "How many days are you traveling for?" << endl;
  cin>>days;

  weeks = days / WEEK_LENGTH;
  remaining_days = days % WEEK_LENGTH;

  cout << "You are traveling for "<< weeks << " week(s) and "<< remaining_days << " day(s)!" <<endl;

  return 0;
}