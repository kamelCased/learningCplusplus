// Practice exam 2 Question 6
// 03/24/21
#include <iostream>
#include <cmath>
using namespace std;

int bitsArrToInt(int* bitsArr, int bitsArrSize);
// Converts a bit array into its decimal integer

int main() {

    // Create a bit array
    int bitsArr[6] = {1,0,1,0,1,0};
    int bitsArrSize = 6;

    // Convert to decimal
    int num = bitsArrToInt(bitsArr, bitsArrSize);

    // Output result
    cout << "Decimal: " << num << endl;

    return 0;
}


int bitsArrToInt(int* bitsArr, int bitsArrSize) {

    // Base case, no elements
    if(bitsArrSize == 0) {
        return 0;
    }

    // Recursive step
    else {
        // Add digits with correct power of 2
        return bitsArr[0]* pow(2,bitsArrSize-1) + bitsArrToInt(bitsArr+1, bitsArrSize - 1);
    }
}