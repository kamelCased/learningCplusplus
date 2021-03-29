#include <iostream>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {

    int m;
    std::cout << "Please enter a positive integer:" << std::endl;
    cin >> m;

    for (int i = 2; i <= m; i++) {

        if (isPerfect(i)) {
            cout << i << " is perfect!" << endl;
        }

        else {
            int amCountDivs, amSumDivs, amSum2Divs;
            analyzeDividors(i, amCountDivs, amSumDivs);
            if(amSumDivs > i) {
                if (amSumDivs <= m) {
                    analyzeDividors(amSumDivs, amCountDivs, amSum2Divs);
                    if (amSum2Divs == i) {
                        cout << i << " and " << amSumDivs << " are amicable numbers!" << endl;
                    }
                }
            }
        }

    }
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {

    int sumDivs = 0, countDivs = 0;

    for (int i = 1; i < num; i++) {

        if(num % i == 0) {
            sumDivs += i;
            countDivs++;
        }

    }

    outSumDivs = sumDivs;
    outCountDivs = countDivs;
}

bool isPerfect(int num) {

    int countDivs, sumDivs;
    analyzeDividors(num, countDivs, sumDivs);

    if (sumDivs == num) {
        return true;
    }

    else {
        return false;
    }
}