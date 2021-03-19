// Assignment: NYU Tandon Bridge Homework 10 Question 1
// Author: Kamel Gazzaz
// Due date: 03/19/2021
#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
// createWordsArray: creates an array containing all the words in a sentence
// input: sentence - the sentence we will parse to get the words
// output: outWordsArrSize - the size of the array of words (i.e. the number of words)
// assumptions: sentence is not an empty string

int countWords(string lineOfText);
// countWords: counts the number of words in a line of text
// input: lineOfText - the string for which we need to count the number of words
// output: int - the number of words in the lineOfText
// assumptions: lineOfText can only contain whitespaces, periods, commas, digits and letters

string getLineOfText();
// getText: gets a line of text from the user
// input: ~
// output: string - the line of text entered by the user (return value)

void printArray(string* arr, int arrSize);
// printArray: outputs the elements of an array to the console
// input: 1. arr - pointer to the array whose elements we will output
//        2. arrSize - the size of arr
// output: The elements of the array in proper format (console output)
// Assumptions: arrSize is a non-negative number

int main() {

    // Get a sentence from the user
    string sentence = getLineOfText();

    // Get words
    int outWordsArrSize;
    string* wordsArr = createWordsArray(sentence, outWordsArrSize);

    // output words
    printArray(wordsArr, outWordsArrSize);

    // (free memory)
    delete []wordsArr;
    wordsArr = nullptr;

    return 0;
}

// Note to TAs: This is much more general than substr and find because it can handle leading spacing, multiple spacing, etc.
// I also added a substr and find implementation below if you want to use that one alternatively (only handles one space between words).
string* createWordsArray(string sentence, int& outWordsArrSize) {

    const char FIRST_LOWER_LETTER = 'a';
    const char LAST_LOWER_LETTER = 'z';
    const char FIRST_UPPER_LETTER = 'A';
    const char LAST_UPPER_LETTER = 'Z';
    const char FIRST_DIGIT = '0';
    const char LAST_DIGIT = '9';

    int wordsArrSize = countWords(sentence);

    string* wordsArr = new string[wordsArrSize];

    // loop through sentence
    for (int i = 0, j = 0; i < sentence.length(); i++) {

        // skip over non alphanumeric characters
        while ((sentence[i] < FIRST_DIGIT) || ((sentence[i] > LAST_DIGIT) && (sentence[i] < FIRST_UPPER_LETTER)) || ((sentence[i] > LAST_UPPER_LETTER) && (sentence[i] < FIRST_LOWER_LETTER)) || (sentence[i] > LAST_LOWER_LETTER)) {
            i++;
        }

        // Get word
        string currentWord = "";
        while (((sentence[i] >= FIRST_UPPER_LETTER) && (sentence[i] <= LAST_UPPER_LETTER)) || ((sentence[i] >= FIRST_LOWER_LETTER) && (sentence[i] <= LAST_LOWER_LETTER)) || ((sentence[i] >= FIRST_DIGIT) && (sentence[i] <= LAST_DIGIT))) {
            currentWord += sentence[i];
            i++;
        }

        // add it to the array
        wordsArr[j] = currentWord;
        j++;
    }

    outWordsArrSize = wordsArrSize;
    return wordsArr;
}

//string* createWordsArray(string sentence, int& outWordsArrSize) {
//
//    const char SPACE_DELIM = ' ';
//
//    // Count words
//    int numWords;
//    numWords = countWords(sentence);
//
//    // Create array to hold words
//    string* wordsArr = new string[numWords];
//
//    // Put words in array
//    bool lastWord = false;
//    for (int i = 0, j = 0; (i < sentence.length()) && (!lastWord); i++, j++) {
//
//        // Find next space
//        int index = sentence.find(SPACE_DELIM, i);
//
//        // End loop if last word
//        if (index == string::npos) {
//            lastWord = true;
//        }
//
//        // Add word to array
//        int wordLength = index - i;
//        wordsArr[j] = sentence.substr(i, wordLength);
//        i = index;
//    }
//
//    // return the words array and update the number of words
//    outWordsArrSize = numWords;
//    return wordsArr;
//}

string getLineOfText() {

    string sentence;
    cout << "Please enter a sentence:" << endl;
    getline (cin, sentence);

    return sentence;
}

int countWords(string lineOfText) {

    const char LOWEST_ALPHANUMERIC_CHAR = '0';

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

void printArray(string* arr, int arrSize) {

    cout << "The words are:" << endl << "[";;

    // output words
    for (int i = 0; i < arrSize; i++) {
        // not last word
        if (i < arrSize - 1) {
            cout << arr[i] << ", ";
        }
        // last word
        else {
            cout << arr[i];
        }
    }
    cout << "]" << endl;
}