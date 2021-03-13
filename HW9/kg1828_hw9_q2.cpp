// Assignment: NYU Tandon Bridge Homework 9 Question 2
// Author: Kamel Gazzaz
// Due date: 03/12/21
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

bool areAnagrams(vector<char> &uniqueChars1, vector<int> &countChars1, vector<char> &uniqueChars2, vector<int> &countChars2);
// areAnagrams: determines if two sentences are anagrams
// input: 1. uniqueChars1: vector containing the unique letters in the first sentence
//        2. countChars1: Vector containing the frequency of each unique letter in the first sentence
//        3. uniqueChars2: vector containing the unique letters in the second sentence
//        4. countChars2: Vector containing the frequency of each unique letter in the second sentence

const char FIRST_LOWER_LETTER = 'a';
const char LAST_LOWER_LETTER = 'z';
const char FIRST_UPPER_LETTER = 'A';
const char LAST_UPPER_LETTER = 'Z';
const int ALPHABET_LENGTH = 26;

int main() {

    // Get first sentence from user
    string sentence1;
    cout << "Lovely TA, please enter your first sentence:" << endl;
    getline(cin,sentence1);

    // Get second sentence from user
    string sentence2;
    cout << "Lovely TA, please enter your second sentence:" << endl;
    getline(cin,sentence2);

    // Make sentences lowercase
    string lowerSentence1 = makeLower(sentence1);
    string lowerSentence2 = makeLower(sentence2);

    // Get the unique characters in both sentences and their frequency
    vector<char> uniqueVec1, uniqueVec2;
    vector<int> countVec1, countVec2;
    getUniqueChars(lowerSentence1, uniqueVec1, countVec1);
    getUniqueChars(lowerSentence2, uniqueVec2, countVec2);

    // Check if anagrams and output the result
    if (areAnagrams(uniqueVec1, countVec1, uniqueVec2, countVec2)) {
        cout << sentence1 << " and " << sentence2 << " are anagrams!" << endl;
    }
    else {
        cout << sentence1 << " and " << sentence2 << " are not anagrams." << endl;
    }

    return 0;
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
    delete[] tempCount;
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

bool areAnagrams(vector<char> &uniqueChars1, vector<int> &countChars1, vector<char> &uniqueChars2, vector<int> &countChars2) {

    // Loop through vectors
    for (int i = 0; (i < countChars1.size()) || (i < countChars2.size()); i++) {

        // Letters don't match
        if ((uniqueChars1[i] != uniqueChars2[i]) || (countChars1[i] != countChars2[i])) {

            // not anagrams
            return false;
        }
    }

    // anagrams
    return true;
}
