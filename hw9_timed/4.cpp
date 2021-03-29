#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray (int arr[], int arrSize);

int main() {

    int arr[6] = {5,2,11,7,6,4}, arrSize = 6;

    cout << "Original:" << endl;
    printArray(arr, arrSize);

    oddsKeepEvensFlip(arr, arrSize);

    cout << "After mods:" << endl;
    printArray(arr, arrSize);

    return 0;
}

void printArray (int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {

    int oddsCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0){
            oddsCount++;
        }
    }

    int evensCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0){
            evensCount++;
        }
    }

    int* evensArr = new int[evensCount];
    int* oddsArr = new int [oddsCount];

    for (int i = 0, j = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0){
            oddsArr[j] = arr[i];
            j++;
        }
    }

    for (int i = 0, j = evensCount - 1; i < arrSize; i++) {
        if (arr[i] % 2 == 0){
            evensArr[j] = arr[i];
            j--;
        }
    }

    for (int i = 0; i < oddsCount; i++) {
        arr[i] = oddsArr[i];
    }

    for (int i = oddsCount; i < arrSize; i++) {
        arr[i] = evensArr[i-oddsCount];
    }

    delete[] evensArr;
    evensArr = nullptr;
    delete[] oddsArr;
    oddsArr = nullptr;
}