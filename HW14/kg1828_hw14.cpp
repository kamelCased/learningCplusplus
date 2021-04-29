// Assignment: NYU Tandon Bridge Homework 14
// Author: Kamel Gazzaz
// Due date: 04/24/2021
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<double> minMax(vector<double> vec);
// Driver for MinMax

vector<double> minMax(const vector<double>& vec, int left, int right);
// minMax: returns the minimum and maximum values in a sequence vec
// input: 1. vec - the sequence containing the numbers from which we'll find the min and max
//        2. left - the first index of vec for the numbers being considered
//        3. right - the last index of vec for the numbers being considered
// output: vector<double> containing the minimum and maximum numbers in the sequence (return value)
// Assumptions: vec is not empty

void printVec(vector<double> vec);
// printVec: outputs the elements of the vector vec to the console
// input: vec - the vector whose numbers we will output
// output: the elements of vec (console output)
// assumptions: vec is not empty

const int MIN_POS = 0;
const int MAX_POS = 1;
const int RES_VEC_SIZE = 2;
constexpr int MIN_RAND_VAL = 10;
constexpr int MAX_RAND_VAL = 100;

int main() {

    // I - Create a vector of random numbers

    srand(NULL);

    vector<double> test(10);

    for (int i = 0; i < test.size(); ++i){
        test[i] = MIN_RAND_VAL + (double)(rand()) / ((double)(RAND_MAX/(MAX_RAND_VAL - MIN_RAND_VAL)));
    }
    printVec(test);

    // II - Get the min and max values

    vector<double> res = minMax(test);

    // III - Output the results to the user

    std::cout << "Min: " << res[MIN_POS] << std::endl;
    std::cout << "Max: " << res[MAX_POS] << std::endl;

    return 0;
}


vector<double> minMax(vector<double> vec) {

    // Vec has elements to be min and max
    if (vec.size() > 0) {

        // Find min and max
        return minMax(vec, 0, vec.size() - 1);
    }

    // Vec does not have elements
    else {

        // No min and max possible
        cout << "Invalid, input vector is empty." << endl;
        exit(1);
    }
}

vector<double> minMax(const vector<double>& vec, int left, int right) {

    vector<double> res(RES_VEC_SIZE);
    double min, max;

    // Base case: One element
    if (left == right) {

        // Only element is both min and max
        min = vec[left];
        max = vec[left];
    }

    // Base case: two elements
    else if (right - left == 1) {

        // Smaller of the two becomes min, larger becomes max
        if (vec[left] < vec[right]) {
            min = vec[left];
            max = vec[right];
        }

        else {
            min = vec[right];
            max = vec[left];
        }
    }

    // Recursive step: More than two elements
    else {

        // Take the midpoint
        int mid = (left + right) / 2;

        // Find the min and max in the left half
        vector<double> minMax1 = minMax(vec, left, mid);

        // Find the min and max in the right half
        vector<double> minMax2 = minMax(vec, mid + 1, right);

        // Smaller of the two half minima becomes overall minimum
        if (minMax1[MIN_POS] < minMax2[MIN_POS]) {
            min = minMax1[MIN_POS];
        }
        else {
            min = minMax2[MIN_POS];
        }

        // Larger of the two half maxima becomes the overall maximum
        if (minMax1[MAX_POS] > minMax2[MAX_POS]) {
            max = minMax1[MAX_POS];
        }
        else {
            max = minMax2[MAX_POS];
        }
    }

    // Return the resulting min and max
    res[MIN_POS] = min;
    res[MAX_POS] = max;
    return res;
}

void printVec(vector<double> vec) {

    // Print vector elements
    for (auto el: vec){

        cout << el << " ";
    }

    cout << endl;
}

