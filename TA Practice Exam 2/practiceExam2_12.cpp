#include <iostream>
using namespace std;

int maxZeroLength(int nums[], int len, int startIdx);

int main() {

    int nums[7] = {0,0,1,0,0,0};
    int len = 7;
    const int startIdx = 0;

    int maxZeroes = maxZeroLength(nums, len, startIdx);

    cout << maxZeroes << endl;

    return 0;
}

int maxZeroLength(int nums[], int len, int startIdx) {

    if(startIdx == len) {
        return 0;
    }
    if(startIdx == len - 1) {
        if (nums[startIdx] == 0)
            return 1;
        return 0;
    }

    else {

        while(nums[startIdx] != 0){
            startIdx++;
        }
        while(nums[len - 1] != 0) {
            len--;
        }
        return std::max(maxZeroLength(nums, len, startIdx + 1) + (nums[startIdx] == 0), maxZeroLength(nums, len-1, startIdx+1) + (nums[startIdx] == 0));
    }
}