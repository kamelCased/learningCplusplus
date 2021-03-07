// Assignment: NYU Tandon Bridge Homework 8 Question 3
// Author: Kamel Gazzaz
// Due date: 03/05/21
#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);

void reverseArray(int arr[], int arrSize);
// reverseArray: reverses the order of the array arr
// input: 1. arr[] - the array whose elements are to be reversed
//        2. arrSize - the size of the array arr
// output: arr[] - same array updated to have the elements in reverse order
// assumptions: arrSize is a non-negative integer

void removeOdd(int arr[], int& arrSize);
// removeOdd: removes the odd integer elements initially present in the array arr
// input: 1. arr[] - the array containing the even and odd integer elements
//        2. arrSize - the size of the array arr
// output: 1. arr[] - same array updated to not have any odd elements
//         2. arrSize - the logical size of the array arr updated to account for removing all odd elements
// assumptions: arrSize is a non-negative integer

void splitParity(int arr[], int arrSize);
// removeOdd: rearranges the elements of an array such that all odd numbers precede even numbers.
// input: 1. arr[] - the array containing the even and odd integer elements
//        2. arrSize - the size of the array arr
// output: 1. arr[] - same array updated to have all odd numbers come before all even numbers.
// assumptions: arrSize is a non-negative integer

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
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

void removeOdd(int arr[], int& arrSize) {

    int oddCount = 0;

    // Loop through array
    for (int i = 0, j = 0; i < arrSize; i++) {

        // if even
        if (arr[i] % 2 == 0) {

            // move it up earlier
            arr[j] = arr[i];
            j++;
        }

        // if odd
        else {

            // add it to the odd tally
            oddCount++;
        }
    }

    // adjust the array size
    arrSize -= oddCount;
}

// Other implementation:
//void removeOdd(int arr[], int& arrSize) {
//
//    // Loop through array
//    for (int i = 0; i < arrSize; i++) {
//
//        bool foundOdd = false;
//        int numOdds = 0;
//
//        // Skip over evens
//        while (!foundOdd && (i < arrSize)) {
//
//            // found odd value
//            if (arr[i] % 2) {
//                foundOdd = true;
//                numOdds++;
//            }
//
//            // not odd, go to next value
//            else {
//                i++;
//            }
//        }
//
//        // Look for next even value
//        bool foundEven = false;
//
//        while (!foundEven && (i + numOdds < arrSize)) {
//
//            // found even value
//            if (arr[i + numOdds] % 2 == 0) {
//
//                // swap even value with odd value
//                int temp1 = arr[i];
//                int temp2 = arr[i + numOdds];
//                arr[i + numOdds] = temp1;
//                arr[i] = temp2;
//
//                // break out of loop
//                foundEven = true;
//            }
//
//            // skip over sequential odd values
//            else {
//                numOdds++;
//            }
//        }
//    }
//
//    // Update array size
//    int tempArrSize = arrSize;
//    for (int i = 0; i < tempArrSize; i++) {
//
//        // For each odd value
//        if(arr[i] % 2 != 0) {
//
//            // decrement the array
//            arrSize--;
//        }
//    }
//}

void splitParity(int arr[], int arrSize) {

    // Indices start at both ends of the array
    int i = 0;
    int j = arrSize - 1;

    // loop through array
    while (i < j) {

        // odd numbers on the left side
        while ((i < j) && (arr[i] % 2 != 0)) {
            ++i;
        }

        // even numbers on the right side
        while ((i < j) && (arr[j] % 2 == 0)) {
            --j;
        }

        // swap even and odd values that are on wrong side
        if (i < j) {
            int temp1 = arr[i];
            int temp2 = arr[j];
            arr[i] = temp2;
            arr[j] = temp1;
        }
    }
}
