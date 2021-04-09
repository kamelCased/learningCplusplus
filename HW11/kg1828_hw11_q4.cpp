// Assignment: NYU Tandon Bridge Homework 11 Question 4
// Author: Kamel Gazzaz
// Due date: 03/26/2021
#include <iostream>
#include <cstdlib>
#include <ctime>

void generateBoard(int*& outArr, int& outArrSize);
// getArrayFromUser: gets an array of integers via user I/O
// output: 1. outArr - the array with integer elements inputted by the user
//         2. outArrSize - the number of elements in outArr
// assumptions: user enters a nonnegative array size

void printArray(int* arr, int arrSize);
// printArray: prints the elements of an array arr to the console in order
// input: 1. arr - pointer to the array to be printed
//        2. arrSize - the size of arr
// output: The elements of the array in order (console output)
// assumptions: arrSize is a non-negative integer

int jumpIt(int arr[], int currentIndex, int lastIndex);
// jumpIt: determines the lowest cost to travel from one end of the array to the other end
//         taking only steps of size 1 or 2
// input: 1. arr - the array to travel over
//        2. currentIndex - the current index we are on
//        3. lastIndex - the index of the last element in arr
// output: int (return value) - the sum of the values (cost) at the array indices traveled
// assumptions: 1. lastIndex is a non-negative integer
//              2. currentIndex should be initialized to 0

int main() {

    // Get the board
    int* board, boardSize;
    generateBoard(board, boardSize);

    //Print the board for the user
    printArray(board, boardSize);

    // Calculate cost
    const int START_INDEX = 0;
    int lastElementIndex = boardSize - 1;
    int cost = jumpIt(board, START_INDEX, lastElementIndex);

    // output result
    std::cout << "The lowest cost is: " << cost << std::endl;

    return 0;
}


int jumpIt(int arr[], int currentIndex, int lastIndex) {

    // Base case: last element
    if (currentIndex == lastIndex)
        return arr[lastIndex];

    // Recursive step: More than one element
    else {

        // One element left: Only strategy --> Jump to last since you need to eat that cost anyway
        if (lastIndex - currentIndex == 1) {
            return jumpIt(arr, currentIndex + 1, lastIndex) + arr[currentIndex];

        }

        // Two elements left: Best strategy --> Jump to last since you need to eat that cost anyway
        if (lastIndex - currentIndex == 2) {
            return jumpIt(arr, currentIndex + 2, lastIndex) + arr[currentIndex];
        }

        // Three elements left: Best strategy --> Choose only between next block and the one after (you will eat last index cost anyway)
        if (lastIndex - currentIndex == 3) {

            // Take step size 2
            if (arr[currentIndex + 1] > arr[currentIndex + 2]) {
                return jumpIt(arr, currentIndex + 2, lastIndex) + arr[currentIndex];
            }

            // Take step size 1
            else  {
                return jumpIt(arr, currentIndex + 1, lastIndex) + arr[currentIndex];
            }
        }

        // More than three elements left
        else {

            // Take step size of 1
            if (arr[currentIndex + 2] > arr[currentIndex + 1] + arr[currentIndex + 3]) {
                return jumpIt(arr, currentIndex + 1, lastIndex) + arr[currentIndex];
            }

            // Take step size of 2
            else {
                return jumpIt(arr, currentIndex + 2, lastIndex) + arr[currentIndex];
            }
        }
    }
}


void generateBoard(int*& outArr, int& outArrSize) {

    std::srand(time(0));

    // Get array size
    int arrSize = rand() % 10 + 1;

    // Create array
    int* arr = new int[arrSize];

    // First block always 0;
    arr[0] = 0;

    // Populate array
    for (int i = 1; i < arrSize; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Update output parameters
    outArrSize = arrSize;
    outArr = arr;
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
