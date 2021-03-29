// Practice ex 2
// 03/24/21
#include <iostream>
using namespace std;

bool isPalindrome(int seq[], int seqSize);
void getArrayFromUser(int*& outArr, int& outArrSize);

int main() {

    int* seq = nullptr, seqSize;
    getArrayFromUser(seq, seqSize);

    if(isPalindrome(seq, seqSize)) {
        cout << "seq is a palindrome" << endl;
    }
    else {
        cout << "seq is not a palindrome" << endl;
    }

    return 0;
}

bool isPalindrome(int seq[], int seqSize) {

    // Base cases: One element
    if (seqSize==1) {
        // Must be true
        return true;
    }
    // Two elements
    if(seqSize == 2) {
        // Palindrome if same number
        if (seq[0] == seq[1])
            return true;
        // Not palindrome if not same
        else
            return false;
    }

    // Recursive step
    else  {
        // Call isPalindrome on smaller sequence and check outermost mirror images
        return (isPalindrome(seq+1, seqSize-2) && (seq[0] == seq[seqSize-1]));
    }
}

void getArrayFromUser(int*& outArr, int& outArrSize) {

    int arrSize;
    cout << "What is the size of your array:" << endl;
    cin >> arrSize;

    int* arr = new int[arrSize];
    cout << "Please enter the " << arrSize << " elements (separated by a space):" << endl;
    for(int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    outArrSize = arrSize;
    outArr = arr;
    arr = nullptr;
}