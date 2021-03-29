#include <iostream>

void removeElement(int arr[], int& arrSize, int val);

int main() {

    int arr[10] = {1,3,8,6,2,4,5,9,3}, arrSize = 10, val = 3;

    removeElement(arr, arrSize, val);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}


void removeElement(int arr[], int& arrSize, int val) {

    int j = 0;
    for (int i = 0; i < arrSize; i++) {
        if(arr[i] != val) {
            arr[j++] = arr[i];
        }
    }

    arrSize = j - 1;
}