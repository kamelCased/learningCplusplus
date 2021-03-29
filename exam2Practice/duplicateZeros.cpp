#include <iostream>
using namespace std;

void duplicateZeros(int arr[], int arrSize);

int main() {
    int arr[7] = {1,0,3,2,0,2,1};

    cout << "Before:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    duplicateZeros(arr, 7);

    cout << "After:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void duplicateZeros(int arr[], int arrSize) {

    int zeroCount = 0;
    for(int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            zeroCount++;
        }
    }

    int leadingPtr = arrSize - 1;
    int trailingPtr = arrSize - 1 + zeroCount;

    while (leadingPtr != trailingPtr) {

        if(trailingPtr < arrSize) {
            arr[trailingPtr] = arr[leadingPtr];
        }
        trailingPtr--;

        if(arr[leadingPtr] == 0) {
            if(trailingPtr < arrSize) {
                arr[trailingPtr] = arr[leadingPtr];
            }
            trailingPtr--;
        }
        leadingPtr--;
    }
}