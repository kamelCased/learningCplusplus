// Assignment: NYU Tandon Bridge Homework 10 Question 3
// Author: Kamel Gazzaz
// Due date: 03/19/2021
#include <iostream>
#include <vector>
using namespace std;

void getArrayFromUser(int*& arr, int& arrSize);
// getArrayFromUser: gets an input array arr of integers from the user and determines its size
// output: 1. arr - pointer to the array with elements inputted from the user (call-by-reference)
//         2. arrSize - the size of arr (call-by-reference)

vector<int> getVectorFromUser();
// getVectorFromUser: gets an input vector of integers from the user
// output: vector<int> - vector with integer elements inputted from the user (return value)

int getNumFromUser();
// getNumFromUser: gets an integer from the user
// output: int - the integer inputted by the user (return value)

void findInArray(int* arr, int arrSize, int num, int*& outFoundLineNumbers, int& outFoundLineNumberSize);
// findInArray: determines the line number (actual index + 1) at which the integer num is found in the array arr
// input: 1. arr - pointer to the array potentially containing num;
//        2. arrSize - the size of arr
//        3. num - the number to be searched for in arr
// output: 1. outFoundIndices - pointer to the array containing the indices at which num is found in arr
//         2. outFoundIndicesSize - the size of the outFoundIndices array (also the number of times num is found in arr)
// assumptions: arrSize is a non-negative integer

vector<int> findInVec(vector<int> vec, int num);
// findInVec: determines the line numbers (actual index + 1) at which the integer num is found in the vector vec
// input: 1. vec - the vector potentially containing num;
//        2. num - the number to be searched for in vec
// output: vector<int> - vector containing the line numbers (actual index + 1) at which num is found in vec (return value)

void printArray(int* arr, int arrSize);
// printArray: prints the elements of an array arr to the console in order
// input: 1. arr - pointer to the array to be printed
//        2. arrSize - the size of arr
// output: The elements of the array in order (console output)
// assumptions: arrSize is a non-negative integer

void printVec(vector<int> vec);
// printVec: prints the elements of a vector vec to the console in order
// input: 1. vec - the vector whose elements are to be printed
// output: The elements of the vector in order (console output)

int main1();
// main1: main function for executing the array program

int main2();
// main2: main function for executing the vector program

int main() {

    const int ARRAY_CHOICE = 1;
    const int VECTOR_CHOICE = 2;

    int choice;
    cout << "Do you wish to run the array or vector version? (Select 1 for array, 2 for vector):" << endl;
    cin >> choice;

    switch (choice) {
        case ARRAY_CHOICE:
            main1();
            break;
        case VECTOR_CHOICE:
            main2();
            break;
    }

    return 0;
}

int main1() {

    // Get input array
    int* inputArr;
    int inputArrSize;
    getArrayFromUser(inputArr, inputArrSize);

    // Get the search number
    int searchNum = getNumFromUser();

    // Search for number in input array
    int* indicesFound;
    int indicesFoundSize;
    findInArray(inputArr, inputArrSize, searchNum, indicesFound, indicesFoundSize);

    // Output results
    if (indicesFoundSize > 0) {
        cout << searchNum << " shows in lines ";
        printArray(indicesFound, indicesFoundSize);
    }
    else {
        cout << searchNum << " does not show in your array of integers.";
    }

    // (free memory)
    delete[] inputArr, indicesFound;
    inputArr = indicesFound = nullptr;

    return 0;
}

int main2() {

    // Get input vector
    vector<int> numVec = getVectorFromUser();

    // Get the search number
    int searchNum = getNumFromUser();

    // Search for number in input vector
    vector<int> foundIndices = findInVec(numVec, searchNum);

    // Output the results
    if (foundIndices.size() > 0) {
        cout << searchNum << " shows in lines ";
        printVec(foundIndices);
    }
    else {
        cout << searchNum << " does not show in your array of integers.";
    }

    return 0;
}

void getArrayFromUser(int*& arr, int& arrSize) {

    const int SENTINEL = -1;
    const int START_SIZE = 10;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1." << endl;

    bool seenEndOfInput = false;
    int num;

    // create a new array with a physical size for 10 integers
    arr = new int[START_SIZE];
    int capacity = START_SIZE;
    int arrIndex = 0;

    while (!seenEndOfInput) {

        cin >> num;

        // User entered -1
        if (num == SENTINEL) {

            // End input
            seenEndOfInput = true;
        }

        // Not -1
        else {

            // Resize if needed
            if (arrIndex == capacity) {

                // double the size
                capacity *= 2;
                int* temp = new int[capacity];

                // move values over to larger array
                for (int i = 0; i < arrIndex; i++) {
                    temp[i] = arr[i];
                }

                // free dynamic memory
                delete []arr;
                arr = temp;
                temp = nullptr;
            }

            // Add the number to the array of numbers
            arr[arrIndex] = num;
            ++arrIndex;
        }
    }

    // Update the array's logical size
    arrSize = arrIndex;
}

vector<int> getVectorFromUser() {

    const int SENTINEL = -1;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1." << endl;

    bool seenEndOfInput = false;
    int nextNum;
    vector<int> inputNums;

    // while not -1
    while (!seenEndOfInput) {

        // get user input
        cin >> nextNum;

        // if -1
        if (nextNum == SENTINEL) {

            // end of input
            seenEndOfInput = true;
        }

        // Not -1
        else {

            // Add nextNum to the input vector
            inputNums.push_back(nextNum);
        }
    }

    return inputNums;
}

int getNumFromUser() {

    int searchNum;
    cout << "Please enter a number you want to search." << endl;
    cin >> searchNum;

    return searchNum;
}

void findInArray(int* arr, int arrSize, int num, int*& outFoundLineNumbers, int& outFoundLineNumberSize) {

    int* lineNumbersArr = new int[arrSize];
    int lineNumberArrSize = 0;

    // Loop through array
    for (int i = 0; i < arrSize; i++) {

        // Number found
        if (arr[i] == num) {

            // Add line number to the array of matches
            lineNumbersArr[lineNumberArrSize] = i + 1; // line number starts at 1 whereas index starts at 0

            // Increment the matches array index
            lineNumberArrSize++;
        }
    }

    // Update the pointer output parameter
    outFoundLineNumbers = lineNumbersArr;
    lineNumbersArr = nullptr;

    // Update the size output parameter
    outFoundLineNumberSize = lineNumberArrSize;
}

vector<int> findInVec(vector<int> numVec, int num) {

    // to hold line numbers at which num is found
    vector<int> foundAtLines;

    // Loop through vector elements
    for (int i = 0; i < numVec.size(); i++) {

        // Found num
        if (numVec[i] == num) {

            // Add line number to the matches vector
            foundAtLines.push_back(i + 1); // line number starts at 1 whereas index starts at 0
        }
    }

    return foundAtLines;
}


void printArray(int* arr, int arrSize) {

    // Loop through elements and print them
    for (int i = 0; i < arrSize; i++) {

        // Not last element
        if (i != arrSize - 1) {
            cout << arr[i] << ", ";
        }

        // Last element
        else {
            cout << arr[i] << "." << endl;
        }
    }
}

void printVec(vector<int> vec) {

    // Loop through elements and print them
    for (int i = 0; i < vec.size(); i++) {

        // Not last element
        if (i < vec.size() - 1) {
            cout << vec[i] << ", ";
        }

        // Last element
        else {
            cout << vec[i] << "." << endl;
        }
    }
}