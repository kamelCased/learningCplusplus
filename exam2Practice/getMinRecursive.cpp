#include <iostream>

void getArrayFromUser(int*& arr, int& arrSize);
int getMin(int* arr, int arrSize);

int main() {

    // Get input
    int* sequenceOfNums;
    int numCount;
    getArrayFromUser(sequenceOfNums, numCount);

    // Find the minimum value
    int min = getMin(sequenceOfNums, numCount);

    // (free memory)
    delete[] sequenceOfNums;
    sequenceOfNums = nullptr;

    // Output result
    std::cout << "The minimum is: " << min << std::endl;

    return 0;
}

int getMin(int* arr, int arrSize) {

    if (arrSize == 1) {
        return arr[0];
    }

    else  {

        int previousMin = getMin(arr, arrSize - 1);

        if (previousMin < arr[arrSize - 1]) {
            return previousMin;
        }

        else {
            return arr[arrSize - 1];
        }
    }
}

void getArrayFromUser(int*& arrPtr, int& arrSize) {

    std::cout << "How many integers in your sequence:" << std::endl;
    std::cin >> arrSize;

    std::cout << "Please enter your sequence of " << arrSize << " integers" << std::endl;
    int* arr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {

        std::cin >> arr[i];
    }

    arrPtr = arr;
}