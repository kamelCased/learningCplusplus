#include <iostream>
#include <vector>
using namespace std;

int* getArrayFromUser(int& outArrSize);
void searchArray(int arr[], int arrSize, int n, int*& outArr, int& outArrSize);
void printArray (int arr[], int arrSize);
vector<int> getVectorFromUser();
vector<int> searchVec(vector<int> vec, int n);
void printVec(vector<int> v);
int mainVec();
int mainArr();

int main() {
    int choice;
    cout << "Please enter 1 for array, 2 for vector.\n";
    cin >> choice;

    switch (choice){
        case 1:
            mainArr();
            break;
        case 2:
            mainVec();
            break;
    }
}

int mainVec() {

    vector<int> inputVec = getVectorFromUser();

    int n;
    cout << "Please enter a number you want to search.\n";
    cin >> n;

    vector<int> foundLines = searchVec(inputVec, n);

    if (foundLines.size() == 0) {
        cout << n << " is not in the sequence" << endl;
    }
    else {
        cout << n << " shows in lines ";
        printVec(foundLines);
    }

    return 0;
}


int mainArr() {

    int arrSize;
    int* arr = getArrayFromUser(arrSize);

    int n;
    cout << "Please enter a number you want to search.\n";
    cin >> n;

    int* indices, indicesSize;
    searchArray(arr, arrSize, n, indices, indicesSize);

    if (indicesSize == 0) {
        cout << n << " is not in the sequence" << endl;
    }
    else {
        cout << n << " shows in lines ";
        printArray(indices, indicesSize);
    }

    delete[] arr;
    arr = nullptr;
    delete[] indices;
    indices = nullptr;

    return 0;
}


void printArray (int arr[], int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        if (i < arrSize - 1) {
            cout << arr[i] << ", ";
        }
        else {
            cout << arr[i] << ".\n";
        }
    }
}

int* getArrayFromUser(int& outArrSize) {

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    int* inputArr = new int[10];
    bool seenEndOfInput = false;
    int i = 0, value, inputArrSize = 10;
    while (!seenEndOfInput) {
        cin >> value;
        if (value == -1) {
            seenEndOfInput = true;
        }
        else  {

            if (i == inputArrSize) {

                int* tempArr = new int[2 * inputArrSize];
                for(int i = 0; i < inputArrSize; i++) {
                    tempArr[i] = inputArr[i];
                }
                inputArrSize *= 2;
                delete[] inputArr;
                inputArr = tempArr;
                tempArr = nullptr;
            }

            inputArr[i] = value;
            i++;
        }

    }

    outArrSize = inputArrSize;
    return inputArr;
}

void searchArray(int arr[], int arrSize, int n, int*& outArr, int& outArrSize) {

    int foundCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == n) {
            foundCount++;
        }
    }

    int* found = new int[foundCount];
    for (int i = 0, j =0; i < arrSize; i++) {
        if (arr[i] == n) {
            found[j] = i+1;
            j++;
        }
    }

    outArrSize = foundCount;
    outArr = found;
    found = nullptr;
}


vector<int> getVectorFromUser() {

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    vector<int> inputVec;
    bool seenEndOfInput = false;
    int value;
    while (!seenEndOfInput) {
        cin >> value;
        if (value == -1) {
            seenEndOfInput = true;
        }
        else  {
            inputVec.push_back(value);
        }

    }

    return inputVec;
}

vector<int> searchVec(vector<int> vec, int n) {

    vector<int> results;
    for (int i = 0; i < vec.size(); i++) {
        if(vec[i] == n) {
            results.push_back(i+1);
        }
    }

    return results;
}

void printVec(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i < v.size()-1){
            cout << ", ";
        }
        else {
            cout << ".\n";
        }
    }
}
