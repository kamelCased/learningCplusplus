#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void openFile(T& file);

vector<string> getLetterContent(ifstream& inFile);
void replaceRecipient(vector<string>& text, string recipientName);
void writeLetter (ofstream& o, const vector<string>& letter);

string getRecipient();

int main() {

    ifstream inFile;
    openFile(inFile);

    vector<string> letter = getLetterContent(inFile);

    inFile.close();

    string name = getRecipient();

    replaceRecipient(letter, name);

    ofstream outFile;
    openFile(outFile);

    writeLetter(outFile, letter);

    outFile.close();

    return 0;
}

template <class T>
void openFile(T& file) {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    file.open(filename);

    while (!file) {

        cout <<"File failed to open" <<endl;
        cout << "Enter file name: ";
        cin >> filename;

        file.clear();
        file.open(filename);
    }

    cout << "Successfully opened file." << endl;
}

vector<string> getLetterContent(ifstream& inFile) {

    vector<string> text;
    string lineOfText;
    while (getline(inFile, lineOfText)) {
        text.push_back(lineOfText);
    }

    cout << "Successfully got letter content from file" << endl;
    return text;
}

string getRecipient() {

    cin.ignore(9999, '\n');
    string recipient;
    cout << "What is the recipient's name?" << endl;
    getline(cin, recipient);

    return recipient;
}

void replaceRecipient(vector<string>& text, string recipientName) {

    for (string& line: text) {

        for (int i = 0; i < line.length(); i++) {

            string temp = "";
            temp += line[i];
            temp += line[i + 1];
            temp += line[i + 2];

            if (temp == "#N#") {

                string before = line.substr(0, i);
                string after = line.substr(i+3,line.length() - (i+3));

                line = before + recipientName + after;

                cout << "Successfully replaced recipient name" << endl;
            }
        }
    }

}

void writeLetter (ofstream& o, const vector<string>& letter) {

    for (string line: letter) {
        o << line << endl;
    }

    cout << "Successfully mailed letter to recipient" << endl;
}