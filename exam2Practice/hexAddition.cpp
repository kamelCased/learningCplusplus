#include <iostream>
#include <string>
#include <vector>

void stringToIntVec(std::string num1, std::string num2, std::vector<int> &num1Digits, std::vector<int> &num2Digits);
std::vector<int> calculateSum(std::vector<int>num1Digits, std::vector<int>num2Digits);
std::string getHexSum(std::string num1, std::string num2);
std::string intVecToString(std::vector<int> sumDigits);

int main() {

    // Get two hex numbers form user
    std::string num1;
    std::cout << "Please enter the first hexadecimal number:" << std::endl;
    std::cin >> num1;

    std::string num2;
    std::cout << "Please enter the second hexadecimal number:" << std::endl;
    std::cin >> num2;

    // Calculate the sum
    std::string sum = getHexSum(num1, num2);

    // Output the result
    std::cout << num1 << " + " << num2 << " = " << sum << std::endl;

    return 0;
}

std::string getHexSum(std::string num1, std::string num2) {

    std::vector<int> num1Digits;
    std::vector<int> num2Digits;
    stringToIntVec(num1, num2, num1Digits, num2Digits);

    std::vector<int> sumDigits = calculateSum(num1Digits, num2Digits);

    return intVecToString(sumDigits);
}

void stringToIntVec(std::string num1, std::string num2, std::vector<int> &num1Digits, std::vector<int> &num2Digits) {

    int HEX_LETTER_START = 10;

    for (char d1: num1){

        if (d1 >= '0' && d1 <= '9') {
            int digit = d1 - '0';
            num1Digits.push_back(digit);
        }
        else if (d1 >= 'A' && d1 <= 'Z') {
            int digit = d1 - 'A' + HEX_LETTER_START;
            num1Digits.push_back(digit);
        }
    }

    for (char d2: num2){

        if (d2 >= '0' && d2 <= '9') {
            int digit = d2 - '0';
            num2Digits.push_back(digit);
        }
        else if (d2 >= 'A' && d2 <= 'Z') {
            int digit = d2 - 'A' + HEX_LETTER_START;
            num2Digits.push_back(digit);
        }
    }
}

std::vector<int> calculateSum(std::vector<int>num1Digits, std::vector<int>num2Digits) {

    const int HEX_SIZE = 16;

    std::vector<int> sumDigits;
    int overFlow = 0;

    for (int i = num1Digits.size() - 1; i >= 0; i--) {

        int nextDigit = (num1Digits[i] + num2Digits[i] + overFlow) % HEX_SIZE;
        overFlow = (num1Digits[i] + num2Digits[i] + overFlow) / HEX_SIZE;
        sumDigits.push_back(nextDigit);
    }

    for (int i = 0; i < (sumDigits.size() / 2); i++) {
        int temp = sumDigits[i];
        sumDigits[i] = sumDigits[(sumDigits.size() - 1) - i];
        sumDigits[(sumDigits.size() - 1) - i] = temp;
    }

    return sumDigits;
}

std::string intVecToString(std::vector<int> sumDigits) {

    const char HEX_DIGITS[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    std::string sum = "";

    for (int element: sumDigits) {
        sum += HEX_DIGITS[element];
    }

    return sum;
}
