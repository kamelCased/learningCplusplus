// Practice Exam 2 Question 5
// 3/24/2021
#include <iostream>
#include <vector>
using namespace std;

void intToBitsArr(int num, int** outBitsArr, int& outBitsArrSize);
// converts to integer to array of bits

void printArray(int arr[], int arrSize);
// Prints array to the console

int main() {

    // Convert to bits
    int* bitsArr, bitsArrSize;
    intToBitsArr(38, &bitsArr, bitsArrSize);

    // Output result
    cout << "bitsArr: ";
    printArray(bitsArr, bitsArrSize);

    // Free memory
    delete[] bitsArr;
    bitsArr = nullptr;

    return 0;
}

void printArray(int arr[], int arrSize) {

    // Print array elements
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void intToBitsArr(int num, int** outBitsArr, int& outBitsArrSize) {

    vector<int> temp;

    // Convert to binary digits (reverse order)
    while (num > 0) {
        int digit = num % 2;
        temp.push_back(digit);
        num /= 2;
    }

    // Create an array to hold binary number
    int* arr = new int[temp.size()];

    // Populate array with binary digits in correct order
    for (int i = temp.size()-1, j = 0; i >= 0; i--, j++) {
        arr[j] = temp[i];
    }

    // Update output params
    *outBitsArr = arr;
    outBitsArrSize = temp.size();
    arr = nullptr;
}