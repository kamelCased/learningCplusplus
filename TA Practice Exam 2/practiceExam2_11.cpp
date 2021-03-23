#include <iostream>

void moveZeroes(int nums[], int numsSize);

int main() {

    int arr[5] = {0,2,0,1,0}, arrSize = 5;

    moveZeroes(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " " << std::endl;
    }

    return 0;
}

void moveZeroes(int nums[], int numsSize) {

    for (int i = 0, j = 0; (i < numsSize - 1) && (j < numsSize - 1); i++) {

        while (nums[i] != 0) {
            i++;
        }

        int temp = nums[i];
        j = i;

        while (nums[j] == 0 && j < numsSize - 1) {
            j++;
        }

        nums[i] = nums[j];
        nums[j] = temp;
    }
}
