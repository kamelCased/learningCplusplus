#include <iostream>
using namespace std;

void squareSortedArray(int arr[], int arrSize);

int main() {

    int arr[10] = {-3,-2,-1,0,1,3,5,6,7,8};
    squareSortedArray(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

void squareSortedArray(int arr[], int arrSize) {

    // Find where positives and negatives split
    int posIndex = 0;
    bool foundPos = false;
    for (int i = 0; i < arrSize && !foundPos; i++) {
        if(arr[i] >= 0){
            posIndex = i;
            foundPos = true;
        }
    }
    int negIndex = posIndex - 1;
    int i = 0;
    int* tempArray = new int [arrSize];

    // Fill in negatives and positives (until one runs out)
    while (negIndex >= 0 && posIndex < arrSize) {

        if(arr[negIndex] * arr[negIndex] <= arr[posIndex] * arr[posIndex]){
            tempArray[i] = arr[negIndex] * arr[negIndex];
            negIndex--;
        }

        else {
            tempArray[i] = arr[posIndex] * arr[posIndex];
            posIndex++;
        }

        i++;
    }

    // Fill in any remaining negatives
    while (negIndex >= 0) {
        tempArray[i] = arr[negIndex] * arr[negIndex];
        negIndex--;
        i++;
    }

    // OR Fill in any remaining positives
    while (posIndex < arrSize) {
        tempArray[i] = arr[posIndex] * arr[posIndex];
        posIndex++;
        i++;
    }

    // Copy tempArray elements back into original array
    for (int j = 0; j < arrSize; j++) {
        arr[j] = tempArray[j];
    }
}