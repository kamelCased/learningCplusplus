// Assignment: NYU Tandon Bridge Homework 8 Question 6
// Author: Kamel Gazzaz
// Due date: 03/05/21
#include <iostream>
#include <string>
using namespace std;

string hideNumbers(string str);
// hideNumbers: replaces all unattached numbers in a line of text with x
// input: str - The string whose numbers we must hide
// output: string - str with all unattached numbers replaced with x

const char FIRST_DIGIT = '0';
const char LAST_DIGIT = '9';
const char FIRST_LOWER_LETTER = 'a';
const char LAST_LOWER_LETTER = 'z';
const char FIRST_UPPER_LETTER = 'A';
const char LAST_UPPER_LETTER = 'Z';
const char NUMBER_REPLACEMENT = 'x';
const char TOKEN_DELIMITER = ' ';

int main() {

    // Get a line of text from the user
    string inputText;
    cout << "Please enter a line of text:" << endl;
    getline(cin, inputText);

    // Hide all numbers from the line
    string secureText = hideNumbers(inputText);

    // Output the line without the numbers
    cout << secureText << endl;

    return 0;
}

string hideNumbers(string str) {

    int tokenLength;

    // iterate over line of text
    for (int i = 0; i < str.length(); i += tokenLength + 1) {

        // get next word
        int nextSpace = str.find(TOKEN_DELIMITER, i);
        string token = str.substr(i, nextSpace - i);
        tokenLength = token.length(); // update token length to increment to next word

        // iterate over characters in word
        bool hasLetters = false;
        for (int tokenIndex = 0; (tokenIndex < token.length()) && (!hasLetters); tokenIndex++) {

            // contains lowercase letter(s)
            if ((token[tokenIndex] >= FIRST_LOWER_LETTER) && (token[tokenIndex] <= LAST_LOWER_LETTER)) {
                hasLetters = true;
            }
            // contains uppercase letter(s)
            if ((token[tokenIndex] >= FIRST_UPPER_LETTER) && (token[tokenIndex] <= LAST_UPPER_LETTER)) {
                hasLetters = true;
            }
        }

        // characters not attached to a word
        if (!hasLetters) {

            // loop through digits
            for (int tokenIndex = 0; tokenIndex < token.length(); tokenIndex++) {

                // if character is a digit (note this is optional since we're assuming only letters, digits, and spaces)
                if ((token[tokenIndex] >= FIRST_DIGIT) && (token[tokenIndex] <= LAST_DIGIT)) {

                    // Replace the digit by x
                    str[i + tokenIndex] = NUMBER_REPLACEMENT;
                }
            }
        }
    }

    // string with no unattached digits
    return str;
}

