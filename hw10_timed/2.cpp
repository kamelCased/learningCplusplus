#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {

    int arr[7] = {0,3,2,5,4,2,5};

    int missCount;
    int* miss = findMissing(arr, 7, missCount);

    for (int i = 0; i < missCount; i++) {
        cout << miss[i] << " " << endl;
    }

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {

    int* nums = new int[n+1]{0};

    for (int i = 0; i < n; i++) {
        nums[arr[i]]++;
    }

    int missingCount = 0;
    for (int i = 0; i <= n; i++) {
        if (nums[i] == 0) {
            missingCount++;
        }
    }

    int* missingNums = new int[missingCount];
    for (int i = 0, j = 0; i <= n; i++) {
        if (nums[i] == 0) {
            missingNums[j] = i;
            j++;
        }
    }

    delete[] nums;
    nums = nullptr;

    resArrSize = missingCount;
    return missingNums;
}