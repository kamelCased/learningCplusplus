// Assignment: NYU Tandon Bridge Homework 8 Question 2
// Author: Kamel Gazzaz
// Due date: 03/05/2021
#include <iostream>
using  namespace std;

int minInArray(const int arr[], int arrSize);
// minInArray: determines the minimum integer value in an array of integers
// input: 1. arr[] - the array of integers whose minimum we determine
//        2. arrSize - the logical size of arr
// output: int min - lowest value integer in the array (return value)
// assumptions: arr[] is an array whose size is at least 1

int getIndices(int value, const int integerArray[], int integerArraySize, int outIndicesArray[]);
// getIndices: determines the indices at which a target value is found in an array
// input: 1. value - the target integer whose indices we're looking for
//        2. integerArray[] - the array of integers we're looking for the target in
//        3. integerArraySize - the logical size of the integer array
//        4. outIndicesArray - array to store the indices at which the target is found
// output:  1. outIndicesArray - (array)
//          2. int minArrIndex - the logical size of the indices array (return value)
// assumptions: value is an integer in the integerArray

const int MAX_ARRAY_SIZE = 20;

int main() {

    // Get the values in the array from the user
    int numberArray[MAX_ARRAY_SIZE];

    cout << "Please enter " << MAX_ARRAY_SIZE << " integers separated by a space:" << endl;

    for (int index = 0; index < MAX_ARRAY_SIZE; index++) {
        cin >> numberArray[index];
    }


    // Get the minimum value in the array
    int minimum = minInArray(numberArray, MAX_ARRAY_SIZE);


    // Get the index or indices of the minimum value
    int minIndices[MAX_ARRAY_SIZE];
    int logicalSize = getIndices(minimum, numberArray, MAX_ARRAY_SIZE, minIndices);


    // Output the minimum and its indices to the user
    cout << "The minimum value is " << minimum << ", and it is located in the following indices: ";

    for (int index = 0; index < logicalSize; index++) {

        cout << minIndices[index] << " ";
    }
    cout << endl;

    return 0;
}

int minInArray(const int arr[], int arrSize) {

    // initialize minimum to first integer in array
    int min = arr[0];

    // loop through integers
    for (int index = 1; index < arrSize; index++) {

        // new minimum value
        if (arr[index] < min) {

            // update the minimum value
            min = arr[index];
        }
    }

    // return the minimum value
    return min;
}

int getIndices(int value, const int integerArray[], int arraySize, int indicesArray []) {

    // initialize an index for the indices array
    int minArrIndex = 0;

    // loop through integer values in the array
    for (int index = 0; index < arraySize; index++) {

        // if the value we want
        if (integerArray[index] == value) {

            // add the index to our indices array
            indicesArray[minArrIndex] = index;

            // increment the minimum indices array
            minArrIndex++;
        }

    }

    // holds the logical size of the array of minimum indices (already takes care of +1 since we increment after assignment)
    return minArrIndex;
}