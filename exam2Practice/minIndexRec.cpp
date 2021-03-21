#include <iostream>

void getArrFromUser(int*& arr, int& arrSize);
void findIndex(int* arr, int arrSize, int search, int& outIndex);
int getMin(int* arr, int arrSize);

int main() {

    // Get input
    int* arr, arrSize;
    getArrFromUser(arr, arrSize);

    // Find smallest value
    int min = getMin(arr, arrSize);

    // Find first index of smallest value
    int minIndex;
    findIndex(arr, arrSize, min, minIndex);

    // free memory
    delete[] arr;
    arr = nullptr;

    // Output results
    std::cout << "The minimum is " << min << ", it shows up in index " << minIndex << std::endl;

    return 0;
}

void findIndex(int* arr, int arrSize, int search, int& outIndex) {

    if(arrSize == 1) {
        outIndex = 0;
    }

    else {

        findIndex(arr, arrSize - 1, search, outIndex);

        if (arr[arrSize - 1] < arr[outIndex]) {
            outIndex = arrSize - 1;
        }
    }
}

int getMin(int* arr, int arrSize) {

    int min = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void getArrFromUser(int*& outArr, int& outArrSize) {

    int arrSize;
    std::cout << "Please enter the number of elements in your array:" << std::endl;
    std::cin >> arrSize;

    int* arr = new int[arrSize];

    std::cout << "Please enter the elements of your array:" << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }

    outArrSize = arrSize;
    outArr = arr;
}

