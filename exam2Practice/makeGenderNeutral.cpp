#include <iostream>
#include <string>
using namespace std;

const string HIS = "his";
const string HIM = "him";
const string HE = "he";

const string THEIR = "their";
const string THEM = "them";
const string THEY = "they";

void getText(string& text);
void makeGenderNeutral(string& text); // doesn't change the verbs
void makeLower (string& str);
void fixCapitalization(string& text);


int main() {

    // Get text
    string text;
    getText(text);

    // Make lowercase
    makeLower(text);

    // Replace pronouns
    makeGenderNeutral(text);

    // Recapitalize properly
    fixCapitalization(text);

    // Output results
    std::cout << text << std::endl;

    return 0;
}

void getText(string& text) {
    cout << "Please enter a line of text:" << endl;
    getline(cin, text);
}

void makeGenderNeutral(string& text) {
    int start = 0;
    while(text.find(HIS, start) != string::npos) {
        int index = text.find(HIS, start);
        if ((index == 0 && text[index+3] == ' ') || (index > 0 && text[index-1] == ' ' && text[index+3] == ' ') || index == text.length() - 3) {
            text += "  ";
            for (int i = text.length(); i > index + 2; i--) {
                text[i] = text[i-2];
            }
            text[index + 3] = ' ';
            text[index + 4] = ' ';
            text.replace(index, THEIR.length(), THEIR);
        }
        else {
            start++;
        }
    }

    start = 0;
    while(text.find(HIM, start) != string::npos) {
        int index = text.find(HIM, start);
        if ((index == 0 && text[index+3] == ' ') || (index > 0 && text[index-1] == ' ' && text[index+3] == ' ') || index == text.length() - 3)  {
            text += " ";
            for (int i = text.length(); i > index + 2; i--) {
                text[i] = text[i - 1];
            }
            text[index + 3] = ' ';
            text[index + 4] = ' ';
            text.replace(index, THEM.length(), THEM);
        }
        else {
            start++;
        }
    }

    start = 0;
    while(text.find(HE, start) != string::npos) {
        int index = text.find(HE, start);
        if ((index == 0 && text[index+2] == ' ') || (index > 0 && text[index-1] == ' ' && text[index+2] == ' ') || index == text.length() - 2) {
            text += "  ";
            for (int i = text.length(); i > index + 2; i--) {
                text[i] = text[i - 2];
            }
            text[index + 2] = ' ';
            text[index + 3] = ' ';
            text.replace(index, THEY.length(), THEY);
        }
        else {
            start++;
        }
    }
}

void makeLower(string& str) {

    const char FIRST_LOWER_LETTER = 'a';
    const char FIRST_UPPER_LETTER = 'A';
    const char LAST_UPPER_LETTER = 'Z';

    // Loop through string
    for (int i = 0; i < str.length(); i++) {

        // Capital letter
        if ((str[i] >= FIRST_UPPER_LETTER) && (str[i] <= LAST_UPPER_LETTER)) {

            // Make it lowercase
            str[i] += (FIRST_LOWER_LETTER - FIRST_UPPER_LETTER);
        }
    }
}

void fixCapitalization(string& text) {

    const int CASE_DIFF = 'a' - 'A';

    for (int i = 0; i < text.length(); i++) {

        if (i < 2) {

            // ignore leading whitespaces
            while (text[0] < '!') {
                for (int j = i; j < text.length(); j++) {
                    text[j] = text[j+1];
                }
                text = text.substr(0,text.length()-1);
            }

            // Capitalize first letter
            if (text[0] >= 'a' && text[0] <= 'z') {
                text[0] -= CASE_DIFF;
            }

            if (text[1] >= 'A' && text[1] <= 'Z') {
                text[1] += CASE_DIFF;
            }
        }

        if (i >= 2) {

            char twoBefore = text[i-2];
            char previous = text[i-1];

            // no double spaces
            while (text[i] == ' ' and previous == ' ') {
                for (int j = i; j < text.length(); j++) {
                    text[j] = text[j+1];
                }
                text = text.substr(0,text.length()-1);
            }

            // remove spaces before punctuation
            if ((text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ';' || text[i] == ':') && (previous == ' ')) {

                for (int j = i - 1; j < text.length(); j++) {
                    text[j] = text[j+1];
                }
                text = text.substr(0,text.length()-1);
            }


            // No space between ...
            if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.') {
            }
            else {
                // add space after punctuation
                if ((previous == ',' || previous == '.' || previous == '?' || previous == '!' || previous == ';' || previous == ':') && (text[i] != ' ')) {
                    text += ' ';
                    for (int j = text.length() - 1; j >= i; j--) {
                        text[j+1] = text[j];
                    }
                    text[i] = ' ';
                }
            }

            // Capitalize first letter in sentence
            if ((twoBefore == '.' || twoBefore == '?' || twoBefore == '!') && previous == ' ') {
                if (text[i] >= 'a' && text[i] <= 'z') {
                    text[i] -= CASE_DIFF;
                }
            }

                // All other letters lower case
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] += CASE_DIFF;
            }

            else if (previous == 'i' && twoBefore == ' ' && text[i] == ' ') {
                text[i-1] -= CASE_DIFF;
            }
        }
    }
}
