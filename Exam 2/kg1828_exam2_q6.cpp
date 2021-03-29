#include <iostream>
using namespace std;

int palindromeDistance(int* arr, int n);

int main() {

    int arr1[6] = {1,3,6,6,3,1}, arr1Size = 6;
    int arr2[6] = {1,3,6,6,5,2}, arr2Size = 6;

    int firstDist = palindromeDistance(arr1, arr1Size);
    int secondDist = palindromeDistance(arr2, arr2Size);

    cout << "The palindrome distance of the first array: " << firstDist << endl;
    cout <<  "The palindrome distance of the second array: " << secondDist << endl;

    return 0;
}

int palindromeDistance(int* arr, int n) {

    if (n == 0) {
        return 0;
    }

    else {
        int previousDistance = palindromeDistance(arr+1, n-2);
        int currentDistance = 0;
        if(arr[0] != arr[n-1]){
            currentDistance++;
        }
        return previousDistance + currentDistance;
    }
}