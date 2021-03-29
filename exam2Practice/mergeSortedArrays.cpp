#include <iostream>

void mergeSortedArrays(int arr1[], int arr1Size, int arr2[], int arr2Size, int*& outMergedArr, int& outMergedArrSize);
int main() {

    int arr1[6] = {1,2,3,5,8,9}, arr1Size = 6, arr2[5] = {3,4,7,10,12}, arr2Size = 5;
    
    int* mergedArr, mergedArrSize;
    mergeSortedArrays(arr1, arr1Size, arr2, arr2Size, mergedArr, mergedArrSize);

    for (int i = 0; i < mergedArrSize; i++) {
        std::cout << mergedArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] mergedArr;
    mergedArr = nullptr;

    return 0;
}

void mergeSortedArrays(int arr1[], int arr1Size, int arr2[], int arr2Size, int*& outMergedArr, int& outMergedArrSize) {

    int* mergedArr = new int [arr1Size + arr2Size];

    int arr1Index = 0;
    int arr2Index = 0;
    int mergedArrIndex = 0;

    while (arr1Index < arr1Size && arr2Index < arr2Size) {

        if (arr1[arr1Index] <= arr2[arr2Index]) {
            mergedArr[mergedArrIndex] = arr1[arr1Index];
            arr1Index++;
            mergedArrIndex++;
        }

        else {
            mergedArr[mergedArrIndex] = arr2[arr2Index];
            arr2Index++;
            mergedArrIndex++;
        }
    }

    while (arr1Index < arr1Size) {
        mergedArr[mergedArrIndex] = arr1[arr1Index];
        arr1Index++;
        mergedArrIndex++;
    }

    while (arr2Index < arr2Size) {
        mergedArr[mergedArrIndex] = arr2[arr2Index];
        arr2Index++;
        mergedArrIndex++;
    }

    outMergedArrSize = mergedArrIndex;
    outMergedArr = mergedArr;
}