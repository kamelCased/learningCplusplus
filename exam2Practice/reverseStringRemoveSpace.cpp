#include <iostream>
#include <string>
using namespace std;

string reverseStringRemoveSpaces(string s);

int main() {

    //Get a sentence
    string inputStr;
    cout << "Please enter a sentence:" << endl;
    getline(cin, inputStr);

    // Reverse the sentence and remove spaces
    string reverseNoSpace = reverseStringRemoveSpaces(inputStr);

    //Output result
    cout << "The reverse string with no spaces is:" << endl;
    cout << reverseNoSpace << endl;

    return 0;
}


string reverseStringRemoveSpaces(string s) {

    if(s.length() == 0) {
        return "";
    }

    else if (s.length() == 1) {
        return s;
    }

    else {

        char first = s[s.length() - 1];
        bool firstIsSpace = false;
        if (first == ' ') {
            firstIsSpace = true;
        }

        char last = s[0];
        bool lastIsSpace = false;
        if (last == ' ') {
            lastIsSpace = true;
        }

        if (firstIsSpace && lastIsSpace) {
            return reverseStringRemoveSpaces(s.substr(1, s.length() - 2));
        }
        else if (firstIsSpace) {
            return reverseStringRemoveSpaces(s.substr(1, s.length() - 2)) + last;
        }
        else if (lastIsSpace) {
            return first + reverseStringRemoveSpaces(s.substr(1, s.length() - 2));
        }
        else {
            return first + reverseStringRemoveSpaces(s.substr(1, s.length() - 2)) + last;
        }
    }
}