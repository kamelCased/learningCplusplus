#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void splitParity(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);

int main() {

    int arr[4] = {1,2,3,4}, arrSize = 4;

    reverseArray(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " " << std::endl;
    }
    cout << endl;

    splitParity(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " " << std::endl;
    }
    cout << endl;

    removeOdd(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " " << std::endl;
    }

    return 0;
}

void reverseArray(int arr[], int arrSize) {

    int temp;
    for (int i = 0; i < arrSize/2; i++) {
        temp  = arr[i];
        arr[i] = arr[arrSize - i - 1];
        arr[arrSize - i - 1] = temp;
    }
}

void removeOdd(int arr[], int& arrSize) {

    int oddCount = 0;
    int oddIndex = 0;
    bool otherOdd = false;
    for (int i = 0; i < arrSize; i++) {
        while(arr[i] % 2 == 0) {
            i++;
        }
        if (arr[i] % 2) {
            oddCount++;
            if (!otherOdd) {
                oddIndex = i;
            }
            i++;
        }
        while((arr[i] % 2 != 0) && i < arrSize) {
            otherOdd = true;
            oddCount++;
            i++;
        }
        if ((i < arrSize - 1) && (arr[i] % 2 == 0)){
            int temp = arr[i];
            arr[i] = arr[oddIndex];
            arr[oddIndex] = temp;
            oddIndex++;
        }
    }

    arrSize -= oddCount - 1;
}

void splitParity(int arr[], int arrSize) {

    for (int i = 0, j = arrSize - 1; i < j; i++) {

        while (i % 2) {
            i++;
        }

        while(j % 2 == 0) {
            j--;
        }

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}