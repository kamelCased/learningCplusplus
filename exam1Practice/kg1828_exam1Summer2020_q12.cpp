#include <iostream>
using namespace std;

int main() {

    cout << "Please enter a sequence of positive integers, each one in a separate line." << endl;
    cout << "End your sequence by typing -1:" << endl;

    bool endOfSequence = false;
    int num, moreEvensCount = 0;

    while (!endOfSequence) {
         // input number
         cin >> num;
         // end of sequence
         if (num == -1) {
             endOfSequence = true;
         }
         // not end of sequence
         else {
             int evens = 0, odds = 0;
             // loop through digits
             while (num > 0) {
                 int digit = num % 10;
                 // odd digit
                 if (digit % 2) {
                     odds++;
                 }
                 // even digit
                 else {
                     evens++;
                 }
                 // next digit
                 num /= 10;
             }
             // more-even
             if (evens > odds) {
                 moreEvensCount ++;
             }
         }
    }

    cout << "You entered " << moreEvensCount << " more-evens numbers" <<endl;

    return 0;
}
