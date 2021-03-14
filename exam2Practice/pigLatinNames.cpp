#include <iostream>
#include <string>
using namespace std;

void getName(string& first, string& last);
void toPigLatin(string& word);

int main() {

    // Get user input
    string first, last;
    getName(first, last);

    // Make pig latin
    toPigLatin(first);
    toPigLatin(last);

    // Output result
    cout << first << " " << last << endl;

    return 0;
}

void getName(string& first, string& last) {
    cout << "Please enter your first and last name separated by a space" << endl;
    cin >> first >> last;
}

void toPigLatin(string& word) {

    const char VOWELS[5] = {'a','e','i','o','u'};
    const char CASE_DIFF = 'a' - 'A';

    // Check if starts with vowel or consonant
    bool startsWithVowel = false;
    for (int i = 0; i < 5; i++) {
        if ((word[0] == VOWELS[i])||(word[0] == VOWELS[i] - CASE_DIFF)) {
            startsWithVowel = true;
        }
    }

    // Vowel: add "way"
    if (startsWithVowel) {
        word += "way";
    }
    // Consonant: Move first letter to end and add "ay"
    else  {

        // Shuffle letters
        char toBeLast = word[0];
        for (int i = 0; i < word.length(); i++) {
            word[i] = word[i+1];
            if (i == 0){
                word[i] -= CASE_DIFF;
            }
            if (i == word.length() - 1) {
                word[i] = toBeLast + CASE_DIFF;
            }
        }
        // Add suffix
        word += "ay";
    }
}
