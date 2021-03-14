#include <iostream>
#include <cmath>

void getInput(double*& arr, int*& arrSize);
double getStdDev(double* arr, int* arrSize);
double getMean(double* arr, int* arrSize);

int main() {

    // Get array from user
    double* arr;
    int* arrSize;
    getInput(arr, arrSize);

    // Calculate standard deviation
    double std = getStdDev(arr, arrSize);

    // Output result
    std::cout << "The standard deviation is " << std << std::endl;

    // free memory
    delete []arr, arrSize;
    arr = nullptr;
    arrSize = nullptr;

    return 0;
}

void getInput(double*& arr, int*& arrSize) {

    arrSize = new int;

    std::cout << "Please enter the number of elements your wish to add:" << std::endl;
    std::cin >> *arrSize;

    arr = new double[*arrSize];

    std::cout << "Please enter the " << *arrSize << " elements you wish to add separated by a space:" << std::endl;
    for (int i = 0; i < *arrSize; i++) {
        std::cin >> arr[i];
    }
}

double getStdDev(double* arr, int* arrSize) {

    double mean = getMean(arr, arrSize);

    double deviationSum = 0;

    for (int i = 0; i < *arrSize; i++) {
        deviationSum += pow(mean - arr[i], 2);
    }

    return (deviationSum / *arrSize);
}

double getMean(double* arr, int* arrSize) {

    double total = 0;

    for (int i = 0; i < *arrSize; i++) {
        total += arr[i];
    }

    return (total / *arrSize);
}
