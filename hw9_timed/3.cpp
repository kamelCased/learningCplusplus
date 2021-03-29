#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {

    int arr[5] = {-3,-1,0,6,4};
    int posArrSize;
    int* posArr = getPosNums1(arr, 5, posArrSize);

    cout <<"PosArr1:" << endl;
    for (int i = 0; i < posArrSize; i++) {
        cout << posArr[i] << " ";
    }
    cout << endl;

    delete[] posArr;
    posArr = nullptr;

    posArr = getPosNums2(arr, 5, &posArrSize);

    cout <<"PosArr2:" << endl;
    for (int i = 0; i < posArrSize; i++) {
        cout << posArr[i] << " ";
    }
    cout << endl;

    delete[] posArr;
    posArr = nullptr;

    getPosNums3(arr, 5, posArr,posArrSize);

    cout <<"PosArr3:" << endl;
    for (int i = 0; i < posArrSize; i++) {
        cout << posArr[i] << " ";
    }
    cout << endl;

    delete[] posArr;
    posArr = nullptr;

    getPosNums4(arr, 5, &posArr, &posArrSize);

    cout <<"PosArr4:" << endl;
    for (int i = 0; i < posArrSize; i++) {
        cout << posArr[i] << " ";
    }
    cout << endl;

    delete[] posArr;
    posArr = nullptr;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {

    int posArrSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArrSize++;
        }
    }

    int* posArr = new int[posArrSize];

    for(int i = 0, j = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[j] = arr[i];
            j++;
        }
    }

    outPosArrSize = posArrSize;
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {

    int posArrSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArrSize++;
        }
    }

    int* posArr = new int[posArrSize];

    for(int i = 0, j = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[j] = arr[i];
            j++;
        }
    }

    *outPosArrSizePtr = posArrSize;
    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {

    int posArrSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArrSize++;
        }
    }

    int* posArr = new int[posArrSize];

    for(int i = 0, j = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[j] = arr[i];
            j++;
        }
    }

    outPosArrSize = posArrSize;
    outPosArr = posArr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int posArrSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArrSize++;
        }
    }

    int* posArr = new int[posArrSize];

    for(int i = 0, j = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[j] = arr[i];
            j++;
        }
    }

    *outPosArrSizePtr = posArrSize;
    *outPosArrPtr = posArr;
}