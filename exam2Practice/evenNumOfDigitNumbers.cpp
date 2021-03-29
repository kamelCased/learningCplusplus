#include <iostream>
using namespace std;

void findEvenDigsNums(int arr[], int arrSize, int** outArrPtr, int& outArrSize);

int main() {

    int arr[8] = {132, 42743432, 17469, 84636, 42,3112,44232,1836};

    int* evensPtr, evensSize;
    findEvenDigsNums(arr, 8, &evensPtr, evensSize);

    for (int i = 0; i < evensSize; i++) {
        cout << evensPtr[i] << " ";
    }
    cout << endl;

    delete evensPtr;
    evensPtr = nullptr;

    return 0;
}

void findEvenDigsNums(int arr[], int arrSize, int** outArrPtr, int& outArrSize) {

    int evenDigsNumsCount = 0;
    for (int i = 0; i < arrSize; i++) {

        int num = arr[i];
        int digitCount = 0;

        while (num > 0) {
            digitCount++;
            num /= 10;
        }

        if (digitCount % 2 == 0) {
            evenDigsNumsCount++;
        }
    }

    int* evenDigsNumsArr = new int[evenDigsNumsCount];

    int j = 0;
    for (int i = 0; i < arrSize; i++) {

        int num = arr[i];
        int digitCount = 0;

        while (num > 0) {
            digitCount++;
            num /= 10;
        }

        if (digitCount % 2 == 0) {
            evenDigsNumsArr[j++] = arr[i];
        }
    }

    outArrSize = j;
    *outArrPtr = evenDigsNumsArr;
}
