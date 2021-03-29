#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

const vector<int> pin = {1,2,3,4,5};


vector<int> getRandom (int n);
vector<int> generateMapping(vector<int> pin, vector<int> random);
bool authenticate(string input, vector<int> mappedPin);

int main() {

    std::cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << std::endl;

    vector<int> rand = getRandom (10);
    std::cout << "NUM: ";
    for (int i = 0; i < rand.size(); i++) {
        cout << rand[i] << " ";
    }
    cout << endl;

    string input;
    cin >> input;

    vector<int> mapped = generateMapping(pin, rand);

    if(authenticate(input, mapped)) {
        cout << "Access granted" << endl;
    }
    else {
        cout << "Your pin is not correct" << endl;
    }


    return 0;
}

vector<int> getRandom (int n) {

    srand(time(0));

    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(rand() % 3 + 1);

    return v;
}

vector<int> generateMapping(vector<int> pin, vector<int> random) {

    vector<int> m;
    for (int i = 0; i < pin.size(); i++) {

        m.push_back(random[pin[i]]);
    }

    return m;
}

bool authenticate(string input, vector<int> mappedPin) {

    if (input.length() != mappedPin.size())
        return false;

    else  {
        for (int i = 0; i < mappedPin.size(); i++) {
            if (input[i] - '0' != mappedPin[i]) {
                return false;
            }
        }

        return true;
    }
}