// Assignment: NYU Tandon Bridge Homework 9 Question 3
// Author: Kamel Gazzaz
// Due date: 03/12/21
#include <iostream>

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
// getPosNums1: returns an array mde up of only the positive numbers in the input array and its new logical size
// input: 1. arr - pointer to the array containing the pool of integers we'll retrieve the positives from
//        2. arrSize - the size of the array arr
// Output: 1. int* - the base address of an array containing only the positive numbers in arr (return value)
//         2. outPosArrSize - the returned array’s logical size (call-by-reference)
// assumptions: arrSize is at least the number of elements in arr

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
// getPosNums2: returns an array made up of only the positive numbers in the input array and its new logical size
// input: 1. arr - pointer to the array containing the pool of integers we'll retrieve the positives from
//        2. arrSize - the size of the array  arr
// Output: 1. int* - the base address of an array containing only the positive numbers in arr (return value)
//         2. outPosArrSizePtr - pointer to the returned array’s logical size
// assumptions: arrSize is at least the number of elements in arr

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
// getPosNums3: Fills in outPosArr with the positive numbers in arr and determines its size
// input: 1. arr - pointer to the array containing the pool of integers we'll retrieve the positives from
//        2. arrSize - the size of the array arr
// Output: 1. outPosArr - the base address of an array containing only the positive numbers in arr
//         2. outPosArrSize - the positive array outPosArr's logical size (call-by-reference)
// assumptions: arrSize is at least the number of elements in arr

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
// getPosNums4: Fills in an array pointed to by outPosArrPtr with the positive numbers in arr
//             and updates the value of the variable pointed to by outPosArrSizePtr to the size of the positive array
// input: 1. arr - pointer to the array containing the pool of integers we'll retrieve the positives from
//        2. arrSize - pointer to the size of the array arr
// Output: 1. outPosArr - the base address of an array containing only the positive numbers in arr
//         2. outPosArrSize - the positive array outPosArr's logical size (call-by-reference)
// assumptions: arrSize is at least the number of elements in arr

int getPosNumCount(int* arr, int arrSize);
// getPosNumCount: gets the number of positive elements in the array
// input: 1. arr - pointer to the array containing the pool of integers we'll count the positives in
//        2. arrSize - size of the array arr
// output: int - the number of positive elements in arr (return value)
// assumptions: arrSize is a non-negative integer

void printArray(int *arr, int arrSize);
// printArray: prints the elements of an array arr to the console in order
// input: 1. arr - pointer to the array to be printed
//        2. arrSize - the size of arr
// output: The elements of the array in order (Console output)
// assumptions: arrSize is a non-negative integer

void getArrayFromUser(int*& arr, int& arrSize);
// getArrayFromUser: Gets an array arr of a user-determined size arrSize from the user
// output: 1. arr - pointer to the array newly populated by the user (call-by-reference)
//         2. arrSize - the size of arr determined by the user (call-by-reference)
// assumptions: User enters a non-negative integer for arrSize

int main() {

    // Get an input array from the user
    int arrSize;
    int* arr;
    getArrayFromUser (arr, arrSize);

    /*------------------ TESTING FIRST FUNCTION ------------------------------*/

    // Get the positive values in the array
    int positiveArr1Size;
    int *positiveArr1 = getPosNums1(arr, arrSize, positiveArr1Size);

    // output the positives array to the console
    printArray(positiveArr1, positiveArr1Size);

    // delete the pointer
    delete [] positiveArr1;
    positiveArr1 = nullptr;

    /*------------------ TESTING SECOND FUNCTION ------------------------------*/

    // Create an array from the positive values in arr
    int *positiveArr2SizePtr = new int;
    int *positiveArr2 = getPosNums2(arr, arrSize, positiveArr2SizePtr);

    // output the positives array to the console
    printArray(positiveArr2, *positiveArr2SizePtr);

    // delete the pointers
    delete [] positiveArr2, positiveArr2SizePtr;
    positiveArr2 = nullptr;
    positiveArr2SizePtr = nullptr;

    /*------------------ TESTING THIRD FUNCTION ------------------------------*/

    // Create an array from the positive values in arr
    int *positiveArr3;
    int positiveArr3Size;
    getPosNums3(arr, arrSize, positiveArr3, positiveArr3Size);

    // output the positives array to the console
    printArray(positiveArr3, positiveArr3Size);

    // delete the pointer
    delete [] positiveArr3;
    positiveArr3 = nullptr;

    /*------------------ TESTING FOURTH FUNCTION ------------------------------*/

    // Create an array from the positive values in arr
    int *positiveArr4Ptr = nullptr;
    int *positiveArr4SizePtr;
    int **positiveArr4DblPtr = &positiveArr4Ptr;
    getPosNums4(arr, arrSize, positiveArr4DblPtr, positiveArr4SizePtr);

    // output the positives array to the console
    printArray(positiveArr4Ptr, *positiveArr4SizePtr);

    // delete the pointers
    delete [] positiveArr4Ptr, positiveArr4DblPtr, positiveArr4SizePtr;
    positiveArr4Ptr = nullptr;
    positiveArr4DblPtr = nullptr;
    positiveArr4SizePtr = nullptr;

    // Delete pointer to input array
    delete arr;
    arr = nullptr;

    return 0;
}

void printArray(int *arr, int arrSize){

    std::cout << "[";

    // Loop through array
    for (int i = 0; i < arrSize; i++) {

        // Print elements
        std::cout << arr[i];

        // separate by comma if not last element
        if (i < arrSize - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {

    // Count positive elements
    int posArr1Size = getPosNumCount(arr, arrSize);

    // declare a new array to hold positive values
    int *posArr = new int [posArr1Size];

    // Loop through array
    for (int i = 0, j = 0; i < arrSize; i++) {

        // Element is positive
        if (arr[i] > 0) {

            // Add it the positive array
            posArr[j] = arr[i];

            // Increment the positive array index
            j++;
        }
    }

    // Update the size of the positive array
    outPosArrSize = posArr1Size;

    // Return the positive array
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {

    // Count positive elements
    int posArr2Size = getPosNumCount(arr, arrSize);

    // declare a new array to hold positive values
    int *posArr2 = new int [posArr2Size];

    // Loop through array
    for (int i = 0, j = 0; i < arrSize; i++) {

        // Element is positive
        if (arr[i] > 0) {

            // Add it the positive array
            posArr2[j] = arr[i];

            // Increment the positive array index
            j++;
        }
    }

    // Update the size of the positive array
    *outPosArrSizePtr = posArr2Size;

    // Return the positive array
    return posArr2;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {

    // Count positive elements
    int posArr3Size = getPosNumCount(arr, arrSize);

    // initialize pointer to the array
    outPosArr = new int[posArr3Size];

    // Loop through array
    for (int i = 0, j = 0; i < arrSize; i++) {

        // Element is positive
        if (arr[i] > 0) {

            // Add it the positive array
            outPosArr[j] = arr[i];

            // Increment the index of the positive array
            j++;
        }
    }

    // Update the size of the positive array
    outPosArrSize = posArr3Size;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {

    // Count positive elements
    int posArr4Size = getPosNumCount(arr, arrSize);

    // declare a new array to hold positive values
    int *posArr4 = new int [posArr4Size];

    // Loop through array
    for (int i = 0, j = 0; i < arrSize; i++) {

        // Element is positive
        if (arr[i] > 0) {

            // Add it the positive array
            posArr4[j] = arr[i];

            // Increment the positive array index
            j++;
        }
    }

    // Set the value in the array pointer to the address of the positive array
    *outPosArrPtr = posArr4;

    // Update the size of the positive array
    *outPosArrSizePtr = posArr4Size;
}

void getArrayFromUser (int*& arr, int& arrSize) {

    std::cout << "Added helper function for Ian!" << std::endl;

    // Get array size
    std::cout << "Please enter the size of your array: " << std::endl;
    std::cin >> arrSize;

    // initialize arr with the correct size
    arr = new int[arrSize];

    // Get the array elements
    std::cout << "Thanks, please enter the " << arrSize << " elements of your array separated by a space: " << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }
}

int getPosNumCount(int* arr, int arrSize) {

    int posArrSize = 0;

    // Loop through array
    for (int i = 0; i < arrSize; i++) {

        // Element is positive
        if (arr[i] > 0) {

            //increment the positive array size
            posArrSize++;
        }
    }

    return posArrSize;
}
