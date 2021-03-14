#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string INTERCEPTED_MSG = ":mmZ\\dZm]Zpg";

char getDecryptedChar(char encryptedChar, int key);
vector<string> getAllPossibleMessages(string unencrypted);
void printVec(vector<string> hiddenMessages);
vector<string> narrowMessages (vector<string> v); // assumes true messages contain all letters

int main() {

    // Decrypt the intercepted message
    vector<string> hiddenMessages = getAllPossibleMessages(INTERCEPTED_MSG);

    // Output all possible messages
    cout << "All possible messages:" << endl;
    printVec(hiddenMessages);

    // Restrict to letter messages
    hiddenMessages = narrowMessages(hiddenMessages);

    // Output letter messages
    cout << "\nWhat we think are the most likely encrypted messages:" << endl;
    printVec(hiddenMessages);

    return 0;
}

vector<string> getAllPossibleMessages(string unencrypted) {

    int MAX_KEY = 100;

    vector<string> messagesVec;
    string decryptedMessage;

    for (int key = 0 ; key < MAX_KEY; key++) {

       decryptedMessage = "";

       for (int i = 0; i < unencrypted.length(); i++) {
           decryptedMessage += getDecryptedChar(unencrypted[i], key);
       }
       messagesVec.push_back(decryptedMessage);
    }

    return messagesVec;
}

void printVec(vector<string> v) {

    for (string element: v) {
        cout << element << endl;
    }
}


char getDecryptedChar(char encryptedChar, int key) {

    const int MIN = 126;
    const int START = 32;

    char decryptedChar;

    if (encryptedChar > MIN - key){
        decryptedChar = char(((encryptedChar - key) + MIN + 1) - START);
    }
    else {
        decryptedChar = char(encryptedChar - key);
    }

    return decryptedChar;
}

vector<string> narrowMessages (vector<string> v) {

    vector<string> potentialMessages;

    for (string element: v) {

        bool potentialMessage = true;

        for (int j = 0; j < element.length(); j++) {

            if ((element[j] < 'A')  || (element[j] < 'a' && element[j] > 'Z') || (element[j] > 'z')) {
                potentialMessage = false;
            }
        }

        if (potentialMessage) {
            potentialMessages.push_back(element);
        }
    }

    return potentialMessages;
}