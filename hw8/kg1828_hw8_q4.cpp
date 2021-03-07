// Assignment: NYU Tandon Bridge Homework 8 Question 4
// Author: Kamel Gazzaz
// Due date: 03/05/2021
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string getInput (char randomMap[], int randomMapSize);
// getInput: generates an array of random digits to map to the pin
// input: 1. char randomMap[] - array mapping each digit in pin to a randomly generated digit for protection
//        2. int randomMapSize - the size of the array to generate
// output: string - the user inputted pin code
// assumptions: randomMapSize is a positive integer

void generateRandomMapping (char outRandomMap[], int randomMapSize);
// generateRandomMapping: generates an array of random digits to map to the pin
// input: int randomMapSize - the size of the array to generate
// output: char outRandomMap[] - An array of random digits of size randomMapSize
// assumptions: randomMapSize is a positive integer

bool authenticatePinCode (string inputPin, char map[], const char pinCode[], int pinCodeSize);
// authenticatePassword: Checks that the inputted pin matches the correct pinCode
// input: 1. string inputPin - pin entered by user to be checked
//        2. char map[] - the mapping for the pin code
//        3. char pinCode[] - the correct pin code
//        4. int pinCodeSize - the size of the pin code array
// output: bool - true if inputPin matches pinCode according to the mapping
// assumptions: pinCodeSize is a positive integer

void mapPassword (const char password[], int passwordSize, char map[], char outConvertedPassword[]);
// mapPassword: converts the password to according to a predetermined mapping
// input: 1. char password[] - passcode to be converted
//        2. int passwordSize - the size of the password array
//        3. char map[] - the mapping for the password
// output: char outConvertedPassword[] - the password converted according to the mapping
// assumptions: passwordSize is a positive integer

const char PASSWORD[5] = {'8','7','6','5','4'};
const int PASSWORD_SIZE = 5;

const char PIN[10] = {'0','1','2','3','4','5','6','7','8','9'};
const int PIN_LENGTH = 10;

const int DIGIT_START_ASCII = (int) '0';

const int POSSIBLE_MAP_DIGITS = 3;
const int START_MAP_DIGITS = 1;

int main() {

    // Generate a random pin code mapping
    char randomMap[PIN_LENGTH];
    int randomMapSize = PIN_LENGTH;
    generateRandomMapping(randomMap, randomMapSize);

    // get pin from user
    string input = getInput(randomMap, randomMapSize);

    // Check if correct pin
    bool isValid = authenticatePinCode(input, randomMap, PASSWORD, PASSWORD_SIZE);

    // passes authentication
    if (isValid) {
        cout << "Your PIN is correct" << endl;
    }

    // fails authentication
    else {
        cout << "Your PIN is not correct" << endl;
    }

    return 0;
}


// Gets input from user (Note to TAs: I know we like do user IO in main, but this is cleaner since the code is long)
string getInput (char randomMap[], int randomMapSize) {

    // Prompt user
    cout << "Please enter your PIN according to the following mapping:" << endl;

    // available pin digits
    cout << "PIN:\t";
    for (int i = 0; i < PIN_LENGTH; i++) {
        cout << PIN[i] << " ";
    }
    cout << endl;

    // mapped digits
    cout << "NUM:\t";
    for (int i = 0; i < randomMapSize; i++) {
        cout << randomMap[i] << " ";
    }
    cout << endl;

    // get input from user
    string inputCode;
    getline(cin, inputCode);

    return inputCode;
}


// Generates a random mapping
void generateRandomMapping (char randomMap[], int randomMapSize) {

    srand (time(0));

    // Generate a specified number of integer digits between 0-9
    for (int i = 0; i < randomMapSize; i++) {

        // Add them to the mapping array as characters
        randomMap[i] = char(rand() % POSSIBLE_MAP_DIGITS + DIGIT_START_ASCII + START_MAP_DIGITS);
    }
}


// Converts the password to match the random mapping
void mapPassword (const char password[], int passwordSize, char map[], char convertedPassword[]) {

    // loop through password
    for (int i = 0; i < passwordSize; i++) {

        // get password digit's integer value
        int index = password[i] - DIGIT_START_ASCII;

        // use the integer value to convert to the corresponding mapped character
        convertedPassword[i] = map[index];
    }
}


// Authenticates the input string against the converted passcode
bool authenticatePinCode (string input, char map[], const char password[], int passwordSize) {

    // Convert the password according to the map
    char convertedPassword[passwordSize];
    mapPassword(password, passwordSize, map, convertedPassword);

    // loop through input pin code
    for (int i = 0; (i < input.length()) || (i < passwordSize); i++) {

        // input digit doesn't match
        if (input[i] != convertedPassword[i]) {

            // wrong pin code
            return false;
        }
    }

    // authenticate pin code
    return true;
}
