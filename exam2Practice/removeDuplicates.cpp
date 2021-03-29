#include <iostream>

void removeDuplicates(int arr[], int& arrSize);

int main() {

    int arr[10] = {0,1,2,3,4,4,5,6,6,6};
    int arrSize = 10;
    
    removeDuplicates(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout <<std::endl;

    return 0;
}

void removeDuplicates(int arr[], int& arrSize) {

    int j = 1;

    for (int i = 1; i < arrSize; i++) {
        if(arr[i] != arr[i-1]) {
            arr[j++] = arr[i];
        }
    }

    arrSize = j;
}
