// Practice Exam 2
// 3/23/21
#include <iostream>
using namespace std;

void makeXorArr (int* srtArr1, int n1, int* srtArr2, int n2, int** outXorArr, int* outN);

int main() {


    // Create test arrays and pointers
    int arr1[8] = {1,2,3,5,7,8,10,11};
    int n1 = 8, n2 = 4;
    int arr2[4] = {2,5,6,9};
    int* srtArr1 = arr1;
    int* srtArr2 = arr2;


    // Get xor values
    int** outXorArr = new int*;
    int outN;
    makeXorArr (srtArr1, n1, srtArr2, n2, outXorArr, &outN);


    // Output results
    for (int i = 0; i < outN; i++) {
        cout << (*outXorArr)[i] << endl;
    }

    // Free dynamic memory
    delete[] *outXorArr;
    delete outXorArr;
    outXorArr = nullptr;

    return 0;
}

void makeXorArr (int* srtArr1, int n1, int* srtArr2, int n2, int** outXorArr, int* outN) {

    // Get range of values
    int max1 = srtArr1[n1-1];
    int min1 = srtArr1[0];
    int max2 = srtArr2[n2-1];
    int min2 = srtArr2[0];

    int max, min;
    if (max1 > max2) {
        max = max1;
    }
    else {
        max = max2;
    }
    if (min1 < min2) {
        min = min1;
    }
    else {
        min = min2;
    }

    // Create an array whose indices hold the count of that value
    int arrSize = max + min;
    int* arr = new int[arrSize]{0};

    // Count all numbers in first array
    for (int i = 0; i < n1; i++) {
        arr[srtArr1[i]]++;
    }

    // Count all numbers in second array
    for (int i = 0; i < n2; i++) {
        arr[srtArr2[i]]++;
    }

    // Create a new array to hold the values only in one array

    // Get array size
    int* xorArrSize = new int;
    *xorArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 1) {
            (*xorArrSize)++;
        }
    }

    // Populate array
    int* xorArr = new int [*xorArrSize];
    for (int i = 0, j = 0; i < arrSize; ++i) {
        if(arr[i] == 1) {
            xorArr[j] = i - min + 1;
            j++;
        }
    }

    // Free dynamic memory
    delete[] arr;
    arr = nullptr;

    // Update output params
    *outN = *xorArrSize;
    *outXorArr = xorArr;
}