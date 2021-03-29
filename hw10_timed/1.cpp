#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {

    string text;
    cout << "Please enter a line of text:" << endl;
    getline(cin, text);

    int wordCount;
    string* words = createWordsArray(text, wordCount);

    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << ", ";
    }

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {

    int wordCount = 0;
    for (int i = 0; i < sentence.length(); i++) {
        while (sentence.find(' ', i) != string::npos) {
            wordCount++;
            i = sentence.find(' ', i)+1;
        }
    }

    string* words = new string[wordCount + 1];

    int prevSpace = 0;
    for (int i = 0, j = 0; i < sentence.length(); i++) {

        int nextSpace = sentence.find(' ', i);
        if (nextSpace != string::npos) {
            words[j] = sentence.substr(i, nextSpace-i);
            j++;
            i = sentence.find(' ', i);
        }
        else {
            words[j] = sentence.substr(i, sentence.length()-i);
            j++;
        }
    }

    outWordsArrSize = wordCount + 1;
    return words;
}