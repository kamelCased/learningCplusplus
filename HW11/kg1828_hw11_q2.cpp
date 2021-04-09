// Assignment: NYU Tandon Bridge Homework 11 Question 2
// Author: Kamel Gazzaz
// Due date: 03/26/2021
#include <iostream>

int sumOfSquares(int arr[], int arrSize);
// sumOfSquares - returns the sum of the squares of the elements in the array arr
// input: 1. arr - the array of integers whose squares we will sum
//        2. arrSize - the number of elements in arr
// Output: int (return value) - the value of the sum of the squares of all elements in the array
// Assumptions: arrSize is a nonnegative integer

void getArrayFromUser(int*& outArr, int& outArrSize);
// getArrayFromUser -
// input: ~
// output: 1. outArr - the array of integers inputted by the user
//         2. outArrSize - the size of outArr
// Assumptions: user enters a nonnegative array size

bool isSorted(int arr[], int arrSize);
// isSorted: determines if the integer elements in the array are sorted in ascending order or not
// input: 1. arr - the array containing sorted or unsorted elements
//        2. arrSize - the size of arr
// output: bool (return value): true if integers are sorted in ascending order, false otherwise
// assumptions: arrSize is a nonnegative integer

int main() {

    // Get array of integers from user
    int* intArr, intArrSize;
    getArrayFromUser(intArr, intArrSize);

    // -------------- Part A ----------------

    // Calculate sum of squares
    int sumSquares = sumOfSquares(intArr, intArrSize);

    // Output result
    std::cout << "A. The sum of the squares of the elements is " << sumSquares << std::endl;

    // -------------- Part B ----------------

    // Determine if sorted
    if (isSorted(intArr, intArrSize)) {
        std::cout << "B. The elements of the array are sorted in ascending order!" << std::endl;
    }
    else {
        std::cout << "B. The elements of the array are not sorted in ascending order." << std::endl;
    }

    // (Free memory)
    delete[] intArr;
    intArr = nullptr;

    return 0;
}

int sumOfSquares(int arr[], int arrSize) {

    // Base case: One element in array
    if(arrSize == 1) {

        // Sum of squares is the element squared
        return arr[0] * arr[0];
    }

    // Recursive step: More than one element in the array
    else {

        // Get the sum of squares for k elements recursively and add the square of the (k+1)th element
        return sumOfSquares(arr, arrSize - 1) + arr[arrSize - 1] * arr[arrSize - 1];
    }
}

void getArrayFromUser(int*& outArr, int& outArrSize) {

    // Get array size
    int arrSize;
    std::cout << "Hello, how many elements in your array?" << std::endl;
    std::cin >> arrSize;

    // Create array
    int* arr = new int [arrSize];

    // Fill array
    std::cout << "Thank you, please enter the " << arrSize << " elements in your array (one per line):" << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }

    // Update output parameter values
    outArrSize = arrSize;
    outArr = arr;
    arr = nullptr;
}

bool isSorted(int arr[], int arrSize) {

    // Base case: One element in array
    if (arrSize == 1) {
        // One element must be in ascending order
        return true;
    }

    // Recursive step: More than one element in array
    else {

        // Recursive call: Check if first k elements are sorted
        if (isSorted(arr, arrSize - 1)) {

            // (k+1)th element is sorted
            if (arr[arrSize - 1] >= arr[arrSize - 2]) {
                return true;
            }

            // (k+1)th element is not sorted
            else {
                return false;
            }
        }

        // first k elements not sorted
        else {
            return false;
        }
    }
}