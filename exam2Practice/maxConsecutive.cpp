#include <iostream>
using namespace std;

int getMaxConsecutive(int arr[], int arrSize, int val);

int main() {

    int arr[10] = {0,0,0,1,0,1,0,0,1,1};
    int max = getMaxConsecutive(arr, 10, 1);

    std::cout << "Max number of consecutive ones: " << max << std::endl;

    return 0;
}

int getMaxConsecutive(int arr[], int arrSize, int val) {

    int currentMax = 0;
    int totalMax = 0;

    for (int i = 0; i < arrSize; i++) {

        if (arr[i] != val) {
            currentMax = 0;
        }

        else {
            currentMax++;
            if(currentMax > totalMax){
                totalMax = currentMax;
            }
        }
    }

    return totalMax;
}
