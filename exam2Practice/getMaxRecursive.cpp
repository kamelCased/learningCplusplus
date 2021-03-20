#include <iostream>

int getMax(int* arr, int arrSize);
void getArrayFromUser(int*& outArrPtr, int& outArrSize);

int main() {

    // Get array from user
    int* numSequence;
    int numCount;
    getArrayFromUser(numSequence, numCount);

    // Find the max value
    int max = getMax(numSequence, numCount);

    // Free dynamic memory
    delete[] numSequence;
    numSequence = nullptr;

    // Output the result
    std::cout << "The maximum is: " << max << std::endl;

    return 0;
}

int getMax(int* arr, int arrSize) {

    if (arrSize == 1) {
        return arr[0];
    }

    else {

        int previousMax = getMax(arr, arrSize - 1);

        if (previousMax > arr[arrSize - 1]) {
            return previousMax;
        }
        else {
            return arr[arrSize - 1];
        }
    }
}

void getArrayFromUser(int*& outArrPtr, int& outArrSize) {

    int arrSize;
    std::cout << "How many integers in your sequence?" << std::endl;
    std::cin >> arrSize;

    std::cout << "Got it, please enter the elements:" << std::endl;
    int* arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }

    outArrSize = arrSize;
    outArrPtr = arr;
}