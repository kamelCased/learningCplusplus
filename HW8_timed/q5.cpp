#include <iostream>
#include <string>
using namespace std;

int main() {

    string first, middle, last;
    std::cout << "Please enter your first middle and last name:" << std::endl;
    cin >> first >> middle >> last;

    cout << last << ", " << first << " " << middle[0] <<". " << endl;

    return 0;
}


