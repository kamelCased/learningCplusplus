#include <iostream>
#include <string>
using namespace std;

bool isPalindromeRec (string s);

int main() {

    // get input
    string word;
    cout << "Please enter a word:" << endl;
    cin >> word;

    // Determine if palindrome
    if (isPalindromeRec(word)) {
        cout << word << " is a palindrome!" << endl;
    }
    else {
        cout << word << " is not a palindrome." << endl;
    }

    return 0;
}

bool isPalindromeRec (string s) {

    if(s.length() == 0)
        return true;

    if(s.length() == 1)
        return true;

    else {
        if (s[0] == s[s.length() - 1]) {
            return isPalindromeRec (s.substr(1,s.length() - 2));
        }
        else {
            return false;
        }
    }
}
