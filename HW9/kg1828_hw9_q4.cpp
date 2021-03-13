// Assignment: NYU Tandon Bridge Homework 9 Question 4
// Author: Kamel Gazzaz
// Due date: 03/12/2021
#include <iostream>

void printArray(int arr[], int arrSize);
// printArray: prints the elements of an array arr to the console in order
// input: 1. arr - the array to be printed
//        2. arrSize - the size of arr
// output: The elements of the array in order (Console output)
// assumptions: arrSize is a non-negative integer

void reverseArray(int arr[], int arrSize);
// reverseArray: reverses the order of the array arr
// input: 1. arr[] - the array whose elements are to be reversed
//        2. arrSize - the size of the array arr
// output: arr[] - same array updated to have the elements in reverse order
// assumptions: arrSize is a non-negative integer

void oddsKeepEvensFlip(int arr[], int arrSize);
// oddsKeepEvensFlip: rearranges the elements of an array such that all odd numbers precede even numbers
//                    and odd numbers remain in their original order but even numbers are in reverse order.
// input: 1. arr[] - the array containing the even and odd integer elements
//        2. arrSize - the size of the array arr
// output: 1. arr[] - same array updated to have all odd numbers in their original order
//                    come before all even numbers in reverse order.
// assumptions: arrSize is a non-negative integer

void getArrayFromUser (int*& arr, int& arrSize);
// getArrayFromUser: Gets an array arr of a user-determined size arrSize from the user
// output: 1. arr - pointer to the array newly populated by the user (call-by-reference)
//         2. arrSize - the size of arr determined by the user (call-by-reference)
// assumptions: User enters a non-negative integer for arrSize

int main() {

    // Get an array from the user
    int arrSize;
    int* arr;
    getArrayFromUser(arr, arrSize);

    // Manipulate the array
    oddsKeepEvensFlip(arr, arrSize);

    // Output the result
    printArray(arr, arrSize);

    // free dynamic memory
    delete arr;
    arr = nullptr;

    return 0;
}

void printArray(int arr[], int arrSize){

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

void reverseArray(int arr[], int arrSize) {

    // loop through the first half of the array
    for (int i = 0; i < arrSize / 2; i++) {

        // swap the mirror image elements
        int temp = arr[i];
        arr[i] = arr[(arrSize - 1) - i];
        arr[(arrSize - 1) - i] = temp;
    }
}

void oddsKeepEvensFlip(int arr[], int arrSize) {

    int evensArr[arrSize];
    int evensArrSize = 0;

    int oddsArr[arrSize];
    int oddsArrSize = 0;

    // Loop through array
    for (int i = 0; i < arrSize; i++) {

        // Add even numbers to evens array
        if (arr[i] % 2 == 0) {
            evensArr[evensArrSize] = arr[i];
            evensArrSize++;
        }

        // Add odd numbers to odds array
        else {
            oddsArr[oddsArrSize] = arr[i];
            oddsArrSize++;
        }
    }

    // Add the odd numbers in their original order to the beginning of the array
    for (int i = 0; i < oddsArrSize; i++) {
        arr[i] = oddsArr[i];
    }

    // Reverse the order of the even elements
    reverseArray(evensArr, evensArrSize);

    // Add them to the original array
    for (int i = oddsArrSize; i < arrSize; i++) {
        arr[i] = evensArr[i - oddsArrSize];
    }
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
