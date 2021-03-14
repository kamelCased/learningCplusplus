#include <iostream>

const int MAX_CHARS = 100;

void getInput(char*& arr, const int arrSize, int& outArrSize);
void fixCapitalization(char*& text, int numLetters);
void printArray(char* arr, int numLetters);

int main() {

    // Get text from user
    char* text;
    int numLetters;
    getInput(text, MAX_CHARS, numLetters);

    // Fix capitalization
    fixCapitalization(text, numLetters);

    //Output result
    printArray(text, numLetters);

    // free memory
    delete []text;
    text = nullptr;

    return 0;
}

void getInput(char*& arr, const int arrSize, int& outArrSize){

    using namespace std;

    cout << "Please enter your text (up to 100 characters, press enter when done):" << std::endl;

    arr = new char[arrSize];
    string temp;
    int i;

    getline(cin,temp);

    for (i = 0; i < temp.length(); i++) {

        if (temp[i] != '\n'){
            arr[i] = temp[i];
        }
        else {
            break;
        }
    }

    outArrSize = i + 1;
}

void fixCapitalization(char*& text, int numLetters) {

    const int CASE_DIFF = 'a' - 'A';

    for (int i = 0; i < numLetters; i++) {

        if (i < 2) {

            // ignore leading whitespaces
            while (text[0] < '!') {
                for (int j = i; j < numLetters; j++) {
                    text[j] = text[j+1];
                }
                numLetters--;
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
                for (int j = i; j < numLetters; j++) {
                    text[j] = text[j+1];
                }
                numLetters--;
            }

            // remove spaces before punctuation
            if ((text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ';' || text[i] == ':') && (previous == ' ')) {

                for (int j = i - 1; j < numLetters; j++) {
                    text[j] = text[j+1];
                }
                numLetters--;
            }


            // No space between ...
            if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.') {
            }
            else {
                // add space after punctuation
                if ((previous == ',' || previous == '.' || previous == '?' || previous == '!' || previous == ';' || previous == ':') && (text[i] != ' ')) {
                    numLetters++;
                    for (int j = numLetters - 1; j >= i; j--) {
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

void printArray(char* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}