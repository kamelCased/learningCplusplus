#include <iostream>
using namespace std;

void makeDifferenceArray(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN);
void printArray(int arr[], int arrSize);

int main() {

    // Create arrays
    int srtArr1[6] = {1,2,3,5,7,8};
    int srtArr2[4] = {2,5,6,9};
    int  differenceArrSize;
    int* differenceArr;

    // Get the elements in srtArr1 but not in srtArr2
    makeDifferenceArray(srtArr1, 6, srtArr2, 4, differenceArr, differenceArrSize);

    // Output the first array
    cout << "srtArr1: ";
    printArray(srtArr1, 6);

    // Output the second array
    cout << "srtArr2: ";
    printArray(srtArr2, 4);

    // Output the results
    cout << "differenceArr: ";
    printArray(differenceArr, differenceArrSize);

    // Free memory
    delete[] differenceArr;
    differenceArr = nullptr;

    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void makeDifferenceArray(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN){

    // Get max value: Since sorted will be last element
    int max = srtArr1[n1-1];
    if(srtArr2[n2 - 1] > max) {
        max = srtArr2[n2 - 1];
    }

    // Get min value: Since sorted will be first element
    int min = srtArr1[0];
    if(srtArr2[0] < min) {
        min = srtArr2[0];
    }

    // Declare an array to count the instances of each value within range
    int range = max - min;
    int* countArr = new int[range]{0};

    // Account for the values in srtArr1
    for(int i = 0; i < n1; i++) {
        countArr[srtArr1[i]-1]++;
    }

    // Remove the values that are in srtArr2
    for(int i = 0; i < n2; i++) {
        countArr[srtArr2[i]-1] = 0;
    }

    // Count number of values to create the difference array
    int valuesArrSize = 0;
    for(int i = 0; i < range; i++) {
        if(countArr[i] > 0) {
            valuesArrSize++;
        }
    }

    // Create the difference array
    int* valuesArr = new int[valuesArrSize];

    // Populate the difference array
    for(int i = 0, j = 0; i < range; i++) {
        if(countArr[i] > 0) {
            valuesArr[j] = i + min;
            j++;
        }
    }

    // Free memory
    delete[] countArr;
    countArr = nullptr;

    // Send difference array back to calling function
    outN = valuesArrSize;
    outDifferenceArr = valuesArr;
}