#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void getArrayFromUser(int*& outArr, int& outArrSize);
void findInArray(int arr[], int arrSize, int val, int*& outArr, int& outArrSize);

int main() {

    int* numArr, numArrSize;
    getArrayFromUser(numArr, numArrSize);

    int min = minInArray(numArr, numArrSize);

    int* indices, indicesSize;
    findInArray(numArr, numArrSize, min, indices, indicesSize);

    cout << "The minimum value is " << min << " and it is located in the following indices: ";
    for (int i = 0; i < indicesSize; i++) {
        std::cout << indices[i] <<  " ";
    }


    delete[] indices;
    delete[] numArr;
    numArr = nullptr;
    indices = nullptr;

    return 0;
}

int minInArray(int arr[], int arrSize){

    int min = arr[0];

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void getArrayFromUser(int*& outArr, int& outArrSize) {

    int arrSize = 20;
    int* arr = new int[arrSize];

    cout << "Please enter 20 integers separated by a space:" << endl;
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    outArrSize = arrSize;
    outArr = arr;
    arr = nullptr;
}

void findInArray(int arr[], int arrSize, int val, int*& outArr, int& outArrSize) {

    int indicesArrSize = 0;
    for (int i = 0; i < arrSize; i++) {

        if (arr[i] == val) {
            indicesArrSize++;
        }
    }

    int* indicesArr = new int [indicesArrSize];

    for (int i = 0, j = 0; i < arrSize; i++) {

        if (arr[i] == val) {
            indicesArr[j] = i;
            j++;
        }
    }

    outArr = indicesArr;
    outArrSize = indicesArrSize;
    indicesArr = nullptr;
}