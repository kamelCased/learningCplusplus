#include <iostream>
#include <string>
using namespace std;

void countLetters(string text, char*& outChars, int*& outCharCount, int& size);
bool checkAnagrams (char* chars1, int* charsCount1, int size1, char* chars2, int* charsCount2, int size2);

int main() {

    string first, second;
    cout << "Please enter first line of text:" << endl;
    getline(cin, first);
    cout << "Please enter first line of text:" << endl;
    getline(cin, second);

    int size1;
    char* chars1;
    int* charsCount1;
    countLetters(first, chars1, charsCount1, size1);
    int size2;
    char* chars2;
    int* charsCount2;
    countLetters(second, chars2, charsCount2, size2);

    if (checkAnagrams(chars1, charsCount1, size1, chars2, charsCount2, size2)) {
        cout << "Anagrams!" <<endl;
    }
    else {
        cout << "Not anagrams" <<endl;
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

bool checkAnagrams (char* chars1, int* charsCount1, int size1, char* chars2, int* charsCount2, int size2) {

    if (size1 != size2) {
        return false;
    }
    else {
        for (int i = 0 ; (i < size1); i++) {
            if ((chars1[i] != chars2[i]) || (charsCount1[i] != charsCount2[i])) {
                return false;
            }
        }
    }
    return true;
}