#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void openInputFile(ifstream& i);

void readNames(ifstream& i, vector<string>& girls, vector<string>& boys);

string getName();

void outputNamePopularity(string name, vector<string> girls, vector<string> boys);

int main() {

    ifstream inFile;
    openInputFile(inFile);

    vector<string> girls, boys;
    readNames(inFile, girls, boys);

    inFile.close();

    bool done = false;
    while (!done) {

        char choice;
        cout << "Do you want to check another name's popularity? (y/n)" << endl;
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            done = true;
        }

        else {
            string name = getName();
            outputNamePopularity(name, girls, boys);
        }
    }

    return 0;
}

void readNames(ifstream& i, vector<string>& girls, vector<string>& boys) {

    int num;
    string b, g;

    while(i >> num) {

        i >> b;
        i >> g;

        boys.push_back(b);
        girls.push_back(g);
    }
}

void openInputFile(ifstream& i) {

    string filename = "names.txt";

    i.open(filename);

    while (!i) {

        cout << "File failed ot open" << endl;
        cout << "Enter file name: ";
        cin >> filename;

        i.clear();
        i.open(filename);
    }
}

string getName() {

    string baby;
    cout << "What is the name?" << endl;
    cin >> baby;

    return baby;
}

void outputNamePopularity(string name, vector<string> girls, vector<string> boys) {

    bool found = false;

    for (int i = 0; i < girls.size(); ++i) {
        if (name == girls[i]) {
            cout << name << " is #" << i + 1 << " among the most popular girls name." << endl;
            found = true;
        }
    }

    for (int i = 0; i < boys.size(); ++i) {
        if (name == boys[i]) {
            cout << name << " is #" << i + 1 << " among the most popular boys name." << endl;
            found = true;
        }
    }

    if (!found) {
        cout << name << " is not among the most popular names in the US. Embrace the uniqueness!" << endl;
    }
}