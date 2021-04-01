#include <iostream>
using namespace std;

class CounterType {
    int count;
    bool check_count(int val) {
        if (val < 0) {
            return false;
        }
        else {
            return true;
        }
    }
public:
    CounterType(): count(0) {}
    CounterType(int initCount) {
        if (check_count(initCount))
            count = initCount;
        else
            count = 0;
    }

    void increment() {count+= 1;}
    void decrement() {
        int val = count - 1;
        if (check_count(val)) {
            count -= 1;
        }
    }
    int getCount() {return count;}
    void output (ostream& o) {
        o << "The count is: " << getCount() << endl;
    }
};


int main() {

    int n;
    cout << "Please enter the initial count:" << endl;
    cin >> n;

    CounterType counter(n);

    int inc;
    cout << "Please enter the number of times to increment the count:" << endl;
    cin >> inc;

    for (int i = 0; i < inc; i++) {
        counter.increment();
    }

    int dec;
    cout << "Please enter the number of times to decrement the count:" << endl;
    cin >> dec;

    for (int i = 0; i < dec; i++) {
        counter.decrement();
    }

    counter.output(cout);

    return 0;
}


