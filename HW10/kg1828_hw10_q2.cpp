// Assignment: NYU Tandon Bridge Homework 10 Question 2
// Author: Kamel Gazzaz
// Due date: 03/19/2021
#include <iostream>

int* findMissing(int arr[], int n, int& resArrSize);
// findMissing: finds the missing values between 0 and n in the array arr
// input: 1. arr - array from which we'll see which elements between 0 and n are missing
//        2. n - the logical size of the array (also the highest value for which we'll search for natural numbers)
// output: 1. int* - (return value)
//         2. resArrSize - the size of the array of missing elements
// assumptions: n is a positive integer

void printArray(int *arr, int arrSize);
// printArray: prints the elements of an array arr to the console in order
// input: 1. arr - pointer to the array to be printed
//        2. arrSize - the size of arr
// output: The elements of the array in order (Console output)
// assumptions: arrSize is a positive integer

void getArrayFromUser(int*& arr, int& arrSize);
// getArrayFromUser: Gets an array arr of a user-determined size arrSize from the user
// output: 1. arr - pointer to the array newly populated by the user (call-by-reference)
//         2. arrSize - the size of arr determined by the user (call-by-reference)
// assumptions: User enters a positive integer for arrSize

int main() {

    // Get an array from the user
    int* arr;
    int arrSize;
    getArrayFromUser(arr, arrSize);

    // Find the missing values
    int missingArraySize;
    int* missingValuesArr = findMissing(arr, arrSize, missingArraySize);

    // Output the result
    printArray(missingValuesArr, missingArraySize);

    // (free memory)
    delete[] missingValuesArr, arr;
    missingValuesArr = nullptr;
    arr = nullptr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {

    // Array to contain the number of times each value appears in arr
    int* numsCountArrPtr = new int[n + 1]{0};

    // Number of missing values
    int missingArrSize = n + 1;

    // Loop through arr
    for (int i = 0; i < n; i++) {

        // new number in arr
        if (numsCountArrPtr[arr[i]] == 0) {

            // decrement missing value count
            missingArrSize--;
        }

        // Increment the count at the index corresponding to the number
        numsCountArrPtr[arr[i]]++;
    }


    int* missingArrPtr = new int[missingArrSize];

    for (int i = 0, j = 0; i <= n; i++) {

        // if num not in arr
        if (numsCountArrPtr[i] == 0) {

            // add num to missingArr
            missingArrPtr[j] = i;

            // increment the missingArr index
            j++;
        }
    }

    // delete the auxiliary array
    delete [] numsCountArrPtr;
    numsCountArrPtr = nullptr;

    // return the missingArrPtr and update its logical size
    resArrSize = missingArrSize;
    return missingArrPtr;
}

void getArrayFromUser (int*& arr, int& arrSize) {

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

void printArray(int *arr, int arrSize){

    std::cout << "The missing elements are:\n" << "[";

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
