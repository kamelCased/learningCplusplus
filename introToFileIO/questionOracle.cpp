#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
void openFile(T& file);

void askQuestions(ifstream& inFile);
string getAnswer(ifstream& inFile, int& chap);

const int NUM_CHAPTERS = 18;

int main() {

    ifstream inFile;
    openFile(inFile);

    askQuestions(inFile);

    inFile.close();

    cout << "Thank you for visiting the Oracle." << endl;

    return 0;
}

template <class T>
void openFile(T& file) {

    string filename = "answers.txt";

    file.open(filename);

    while (!file) {
        cout << "File failed to open." << endl;
        cout << "Enter input file name: ";
        cin >> filename;
        file.clear();
        file.open(filename);
    }
}

void askQuestions(ifstream& inFile) {

    bool done = false;
    int chap = 0;

    while (!done) {

        char choice;
        cout << "Do you want to ask the Oracle another question? (y/n)" << endl;
        cin >> choice;
        cin.ignore(999, '\n');

        if (choice == 'N' || choice == 'n') {
            done = true;
        }

        else {

            string question;
            cout << "What is your question?" << endl;
            getline(cin, question);

            cout << getAnswer(inFile, chap) << endl;
        }
    }
}

string getAnswer(ifstream& inFile, int& chap) {

    string answer;

    if (getline(inFile, answer)) {}
    else {
        inFile.close();
        openFile(inFile);
        getline(inFile, answer);
    }

    if (answer.find("#N") != -1) {

        int index = answer.find("#N");
        string num = to_string(NUM_CHAPTERS - chap);

        answer.replace(index + 1, 1, num);

        if (++chap >= 18)
            chap = 0;
    }

    return answer;
}


