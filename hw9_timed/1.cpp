#include <iostream>
#include <string>
using namespace std;

int countWords (string text);
void countLetters(string text, char*& outChars, int*& outCharCount, int& size);

int main() {

    string text;
    cout << "Please enter a line of text:" << endl;
    getline(cin, text);

    cout << countWords(text) << "\twords" << endl;

    char* chars;
    int* charCount;
    int charArrSize;
    countLetters(text, chars, charCount, charArrSize);

    for(int i = 0; i < charArrSize; i++) {
        cout << charCount[i]  << "\t" << chars[i] << endl;
    }

    return 0;
}

void countLetters(string text, char*& outChars, int*& outCharCount, int& size) {

    const char FIRST_LOWER ='a';
    const char LAST_LOWER = 'z';
    const char FIRST_UPPER = 'A';
    const char LAST_UPPER = 'Z';
    const int ALPHABET_LENGTH = 26;

    // chars
    int charCount[ALPHABET_LENGTH] = {0};

    // Count letters
    for(int i = 0; i < text.length(); i++) {
        if (text[i] >= FIRST_UPPER && text[i] <= LAST_UPPER) {
            charCount[text[i] - FIRST_UPPER]++;
        }
        if (text[i] >= FIRST_LOWER && text[i] <= LAST_LOWER) {
            charCount[text[i] - FIRST_LOWER]++;
        }
    }

    // Count unique letters
    int uniqueCount = 0;
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        if (charCount[i] > 0) {
            uniqueCount++;
        }
    }

    // Create arrays
    int* uniqueCharCount = new int[uniqueCount];
    char* uniqueChar = new char[uniqueCount];

    // Populate arrays
    for (int i = 0, j = 0; i < ALPHABET_LENGTH; i++) {
        if (charCount[i] > 0) {
            uniqueChar[j] = i + 'a';
            j++;
        }
    }
    for (int i = 0, j = 0; i < ALPHABET_LENGTH; i++) {
        if (charCount[i] > 0) {
            uniqueCharCount[j] = charCount[i];
            j++;
        }
    }

    outCharCount = uniqueCharCount;
    outChars = uniqueChar;
    size = uniqueCount;
}

int countWords (string text) {

    if (text.length() == 0) {
        return 0;
    }
    else {
        const char DELIM = ' ';
        int wordCount = 0;
        for(int i = 0; i < text.length(); i++) {
            while(text.find(DELIM, i) != string::npos) {
                wordCount++;
                int index = text.find(DELIM, i);
                i = index + 1;
            }
        }
        return wordCount+1;
    }
}