#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double num;
    std::cout << "Please enter a real number " << std::endl;
    cin >> num;

    int round;
    std::cout << "Please enter your rounding method " << std::endl;
    cout << "1.\tFloor\tround\n"
            "2.\tCeiling\tround\n"
            "3.\tRound\tto\tthe\tnearest\twhole\tnumber\n";
    cin >> round;


    if (num >= 0) {
        switch (round) {

            case 1:
                cout << (int) num << endl;
                break;
            case 2:
                if (num != (int) num) {
                    cout << (int) num + 1 << endl;
                }
                else {
                    cout << (int) num << endl;
                }
                break;
            case 3:
                cout << int (num + 0.5) << endl;
        }
    }
    else {
        switch (round) {
            case 1:
                if (num != (int) num) {
                    cout << (int) num - 1 << endl;
                }
                else {
                    cout << (int) num << endl;
                }
                break;
            case 2:
                cout << (int) num << endl;
                break;
            case 3:
                cout << int (num - 0.5) << endl;
        }
    }

    return 0;
}
