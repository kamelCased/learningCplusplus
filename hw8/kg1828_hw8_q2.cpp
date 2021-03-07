// Assignment: NYU Tandon Bridge Homework 8 Question 2
// Author: Kamel Gazzaz
// Due date: 03/05/2021
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
// isPalidrome: determines if a word is a palindrome
// input: string str - the word to be analyzed
// output: bool true/false - true if word reads the same forward and backward, false otherwise;
// assumptions: str is a non-empty string

int main() {

    // Get word from user
    string word;
    cout << "Please enter a word: ";
    cin >> word;

    // word is a palindrome
    if (isPalindrome(word)) {
        cout << word << " is a palindrome" << endl;
    }

    // word is not a palindrome
    else {
       cout << word << " is not a palindrome" << endl;
    }

    return 0;
}

bool isPalindrome(string str) {

    int wordLength = str.length();

    // iterate through word
    for (int letterIndex = 0; letterIndex < wordLength / 2; letterIndex++) {

        // mirror image letters don't match
        if (str[letterIndex] != str[wordLength - letterIndex - 1]) {

            // not palindrome
            return false;
        }
    }

    // If all mirror image letters match (includes middle letter with itself for odd word length), palindrome
    return true;
}