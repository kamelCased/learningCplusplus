#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string* getBinaryStrings(int n, int& arrSize);

int main() {

    // Get string size from user
    int n;
    cout << "Please enter a positive integer:" << endl;
    cin >> n;

    // Get binary strings
    int binariesCount;
    string* binariesOfLengthN = getBinaryStrings(n, binariesCount);

    // Output results
    cout << "There are " << binariesCount << " binary strings of length " << n << endl;
    cout << "They are:" << endl;
    for (int i = 0; i < binariesCount; i++) {
        cout << binariesOfLengthN[i] << endl;
    }

    // free memory
    delete[] binariesOfLengthN;
    binariesOfLengthN = nullptr;

    return 0;
}

string* getBinaryStrings(int n, int& arrSize) {

    int cardinality = pow(2, n);

    if (n == 1) {
        auto* arr = new string[cardinality];
        arr[0] = "0";
        arr[1] = "1";
        arrSize = cardinality;
        return arr;
    }

    else {

        string* arr = getBinaryStrings(n-1, cardinality);

        cardinality *= 2;

        for (int i = 0; i < cardinality / 2; i++) {
            arr[cardinality - i - 1] = arr[i] + "1";
            arr[i] += "0";
        }

        arrSize = cardinality;
        return arr;
    }
}
