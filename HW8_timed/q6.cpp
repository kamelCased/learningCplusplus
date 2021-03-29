#include <iostream>
#include <string>
using namespace std;

string encrypt(string s);

int main() {

    string text;
    std::cout << "Please enter a line of text:" << std::endl;
    getline(cin, text);

    string s = encrypt(text);
    cout << s << endl;

    return 0;
}

string encrypt(string s) {

    int prevSpace = 0;
    for (int i = 0; i < s.length(); i++) {

        while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            i++;
        }

        int nextSpace = s.find(' ', i);

        bool hasLetters = false;
        for (int j = prevSpace; j < nextSpace; j++) {
            if ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')) {
                hasLetters = true;
            }
        }

        if (!hasLetters) {
            for (int j = prevSpace; j < nextSpace; j++) {
                if (s[j] >= '0' && s[j] <= '9') {
                    s[j] = 'x';
                }
            }
        }
        prevSpace = nextSpace;
    }

    return s;
}
