// Assignment: NYU Tandon Bridge Homework 9 Question 1
// Author: Kamel Gazzaz
// Due date: 03/12/21
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countWords(string lineOfText);
// countWords: counts the number of words in a line of text
// input: lineOfText - the string for which we need to count the number of words
// output: int - the number of words in the lineOfText
// assumptions: lineOfText can only contain whitespaces, periods, commas, digits and letters

string makeLower (string str);
// makeLower: converts all uppercase letters in a string to lowercase letters
// input: str - string that may contain uppercase letters
// output: string - str with all lower case letters (return value)

void getUniqueChars(string str, vector<char> &uniqueChars, vector<int> &countChars);
// getUniqueChars: makes a list of all the unique characters in a string in alphabetical order
//                 and the number of times they each appear.
// input: str - the string whose characters are to be counted.
// output: 1. uniqueChars: vector containing the unique characters in alphabetical order (call-by-reference)
//         2. countChars: vector containing the number of times each character in uniqueChars appears in str

const char LOWEST_ALPHANUMERIC_CHAR = '0';
const char FIRST_LOWER_LETTER = 'a';
const char LAST_LOWER_LETTER = 'z';
const char FIRST_UPPER_LETTER = 'A';
const char LAST_UPPER_LETTER = 'Z';
const int ALPHABET_LENGTH = 26;

int main() {

    // Get string from user
    string sentence;
    cout << "Please enter a line of text:" << endl;
    getline(cin,sentence);

    // Output the number of words
    cout << countWords(sentence) << "\t" << "words" << endl;

    // Convert sentence to lowercase
    string lowerSentence = makeLower(sentence);

    // Determine the unique characters in the sentence and their frequency
    vector<char> uniqueVec;
    vector<int> countVec;
    getUniqueChars(lowerSentence, uniqueVec, countVec);

    // Output the characters and count
    for (int i = 0; i < countVec.size(); i++) {
        std::cout << countVec[i] << "\t" << uniqueVec[i] << std::endl;
    }

    return 0;
}

int countWords(string lineOfText) {

    // start with 0 words
    int wordCount = 0;

    // loop through sentence
    for (int i = 0; i < lineOfText.length(); i++) {

        // skip over alphanumeric character
        while (lineOfText[i] >= LOWEST_ALPHANUMERIC_CHAR) {
            i++;
        }

        // no double counting for consecutive spaces/periods/digits
        if (lineOfText[i - 1] >= LOWEST_ALPHANUMERIC_CHAR){

            // increment the number of words
            wordCount++;
        }
    }

    // return the number of words
    return wordCount;
}

string makeLower (string str) {

    // Loop through string
    for (int i = 0; i < str.length(); i++) {

        // Capital letter
        if ((str[i] >= FIRST_UPPER_LETTER) && (str[i] <= LAST_UPPER_LETTER)) {

            // Make it lowercase
            str[i] += (FIRST_LOWER_LETTER - FIRST_UPPER_LETTER);
        }
    }

    // all lowercase
    return str;
}

void getUniqueChars(string str, vector<char> &uniqueChars, vector<int> &countChars) {

    int *tempCount = new int[ALPHABET_LENGTH]{0};

    // Loop through string
    for (int i = 0; i < str.length(); i++) {

        // letter
        if (str[i] >= FIRST_LOWER_LETTER && str[i] <= LAST_LOWER_LETTER) {

            // increment counter for that letter
            tempCount[(str[i] - FIRST_LOWER_LETTER)]++;
        }
    }

    // Loop through letter count
    for (int i = 0; i < ALPHABET_LENGTH; i++) {

        // letter is in string
        if (tempCount[i] > 0) {

            // Add the count
            countChars.push_back(tempCount[i]);

            // Add the letter
            uniqueChars.push_back(i + FIRST_LOWER_LETTER);
        }
    }

    // free dynamic memory
    delete tempCount;
    tempCount = nullptr;
}

//void getUniqueChars(string str, vector<char> &uniqueChars, vector<int> &countChars) {
//
//    // Loop through letters of alphabet (Note to TAs: I know this is slow, but 26n is still theta n)
//    for (char currentLetter = FIRST_LOWER_LETTER; currentLetter <= LAST_LOWER_LETTER; currentLetter++) {
//
//        // Number of times letter appears in string
//        int charCount = 0;
//
//        // Loop through string
//        for (int i = 0; i < str.length(); i++) {
//
//            // character is the current letter
//            if (str[i] == currentLetter) {
//
//                // add it to the count
//                charCount++;
//            }
//        }
//
//        // Letter is in the string at least once
//        if (charCount > 0) {
//
//            // Add the letter to the unique characters vector
//            uniqueChars.push_back(currentLetter);
//
//            // Add its frequency to the count vector
//            countChars.push_back(charCount);
//        }
//    }
//}
