// Assignment: NYU Tandon Bridge Homework 7 Question 2
// Author: Kamel Gazzaz
// Due date: 02/26/2021
#include <iostream>
#include <cmath>

void analyzeDivisors (int num, int& outCountDivs, int& outSumDivs);
// analyzeDivisors: determines the count and sum of the proper divisors of a number num
// input: num: the number whose divisors we are counting and summing
// output: 1. outCountDivs: The number of proper divisors that num has (reference variable)
//         2. outSumDivs: The sum of the proper divisors of num (reference variable)
// Assumptions: num is a positive integer >= 2

bool isPerfect(int num);
// isPerfect: determines if a number is perfect (equal to the sum of its divisors)
//            or if it has an amicable number (equal to the sum of each other's divisors) within range.
// input: num: the number to be checked
// output: 1. bool -- true if num is perfect, false if not (return value)
//         2. pairs of amicable numbers (console output)
// assumptions: num is a positive integer >= 2

int main() {

    // Get the range from the user
    int m;
    std::cout << "Please enter a positive integer >= 2:" << std::endl;
    std::cin >> m;

    // Determine all perfect numbers in the range
    for (int i = 2; i <= m; i++) {

        bool perfect = isPerfect(i);

        if (perfect) {
            std::cout << i << " is perfect" << std::endl;
        }
    }
    
    // Determine all amicable number pairs in the range
    for (int i = 2; i <= m; i++) {

        bool perfect = isPerfect(i);

        if (!perfect) {
            
            // Analyze the divisors of the number
            int firstCountDivs, firstSumDivs;
            analyzeDivisors(i, firstCountDivs, firstSumDivs);
            
            // If the sum is within range
            if ((firstSumDivs >= 2) && (firstSumDivs <= i)) {
             
                // check amicable number
                int secondSumDivs, secondCountDivs;
                analyzeDivisors(firstSumDivs, secondCountDivs, secondSumDivs);

                // print amicable number
                if (secondSumDivs == i) {
                    std::cout << "(" << firstSumDivs << ", " << i << ") are amicable numbers" << std::endl;
                }
            }
        }
    }

    return 0;
}

void analyzeDivisors (int num, int& outCountDivs, int& outSumDivs) {

    int countDivs = 0, sumDivs = 0;

    // Get divisors smaller than sqrt(num)
    for (int divisor = 1; divisor < sqrt(num); divisor++) {

        if (num % divisor == 0) {

            // increment sum and count
            countDivs++;
            sumDivs += divisor;
        }
    }

    for (int divisor = sqrt(num); divisor >= 2; divisor--) {

        // For each divisor smaller than sqrt(num)
        if (num % divisor == 0) {

            // Get complementary divisor
            int complementaryDivisor = num / divisor;

            // increment sum and count
            countDivs++;
            sumDivs += complementaryDivisor;
        }
    }

    outCountDivs = countDivs;
    outSumDivs = sumDivs;
}

bool isPerfect(int num) {

    // Get sum of divisors
    int count, sum;
    analyzeDivisors(num, count, sum);

    // Perfect number
    if (sum == num) {
        return true;
    }

    // Not perfect number
    else {
        return false;
    }
}
