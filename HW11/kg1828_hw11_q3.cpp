// Assignment: NYU Tandon Bridge Homework 11 Question 3
// Author: Kamel Gazzaz
// Due date: 03/26/2021
#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
// minInArray1 - returns the minimum value in an array
// input: 1. arr - the array of integers whose minimum we will return
//        2. arrSize - the number of elements in arr
// output: int (return value) - the value of the smallest element in arr
// assumptions: arrSize is a nonnegative integer

int minInArray2(int arr[], int low, int high);
// minInArray2 - returns the minimum value in an array between the indices low and high (inclusive)
// input: 1. arr - the array of integers that we will index
//        2. low - the lowest index in arr to be considered
//        3. high - the highest index in arr to be considered
// output: int (return value) - the value of the smallest element from arr[low] through arr[high]
// assumptions: high is greater than or equal to low

//void getArrayFromUser(int*& outArr, int& outArrSize);
//// getArrayFromUser: gets an array of integers via user I/O
//// output: 1. outArr - the array with integer elements inputted by the user
////         2. outArrSize - the number of elements in outArr
//// assumptions: user enters a nonnegative array size
//
//int main() {
//
//    // Get array of integers
//    int* intArr, intArrSize;
//    getArrayFromUser(intArr, intArrSize);
//
//    // ------------ Part A --------------
//
//    // Get minimum value
//    int min = minInArray1(intArr, intArrSize);
//
//    // Output result
//    std::cout << "A. The minimum is: " << min << std::endl;
//
//    // ------------ Part B --------------
//
//    // Get minimum value between low and high
//    int low = 0, high = intArrSize / 2; // TAs: Adjust as necessary (just make sure it's within bounds)
//    min = minInArray2(intArr, low, high);
//
//    // Output result
//    std::cout << "B. The minimum between index " << low << " and index " << high << " is: " << min << std::endl;
//
//    // Free dynamic memory
//    delete[] intArr;
//    intArr = nullptr;
//
//    return 0;
//}

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl; //should both be -9

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<" "<<res4<<endl; //should both be 3

    return 0;
}

int minInArray1(int arr[], int arrSize) {

    // Base case: One element in array
    if (arrSize == 1) {

        // Only element is the minimum
        return arr[0];
    }

    // Recursive step: More than one element in array
    else {

        // Inductive Hypothesis: A recursive call to minInArray(arr, k) returns the minimum in the first k elements
        int min = minInArray1(arr, arrSize - 1);

        // Previous min is less than (k+1)th element
        if (min < arr[arrSize - 1]) {

            // Previous min is overall min up to k+1
            return min;
        }

        // Previous min is not less than (k+1)th element
        else {

            // (k+1)th element is the min in the range 0 through k+1
            return arr[arrSize - 1];
        }
    }
}

int minInArray2(int arr[], int low, int high) {

    // Base case: One element in the considered array range
    if(high == low) {

        // The only element must be the minimum
        return arr[low];
    }

    // Recursive step: More than one element in array
    else {

        // Inductive Hypothesis: A recursive call to minInArray2(arr, k-1) returns the minimum in the first k-1 elements
        int min = minInArray2(arr, low, high - 1);

        // Min value from first k-1 values is greater than kth element
        if (min > arr[high - 1]) {

            // kth value is new min
            min = arr[high - 1];
        }

        // Min value from first k values is greater than (k+1)th element
        if (min > arr[high]) {

            // (k+1)th value is new min
            min = arr[high];
        }

        // min in low to high (high included)
        return min;
    }
}

//void getArrayFromUser(int*& outArr, int& outArrSize) {
//
//    // Get array size
//    int arrSize;
//    std::cout << "Hey there, how many elements in your array?" << std::endl;
//    std::cin >> arrSize;
//
//    // Create array
//    int* arr = new int[arrSize];
//
//    // Populate array
//    std::cout << "Please enter the " << arrSize << " elements of your array (one per line):" << std::endl;
//    for (int i = 0; i < arrSize; i++) {
//        std::cin >> arr[i];
//    }
//
//    // Update output parameters
//    outArrSize = arrSize;
//    outArr = arr;
//}