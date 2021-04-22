#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openInputFile(ifstream& ifs);
void openOutputFile(ofstream& ofs);

int main() {

    string advice;

    ifstream inFile;
    openInputFile(inFile);
    getline(inFile, advice);

    inFile.close();

    cout << "Here's my advice:" << endl;
    cout << advice << endl;

    cout << "Do you have advice for me?" << endl;
    cin.ignore(9999, '\n');
    getline(cin, advice);
    cout << advice << endl;

    ofstream outFile;
    openOutputFile(outFile);

    outFile << advice << endl;
    cout << "Great, I will take that into account." << endl;

    outFile.close();

    return 0;
}

void openInputFile(ifstream& ifs) {

    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    ifs.open(filename);

    while (!ifs) {
        cout << "Input file failed to open." << endl;
        cout << "Enter input file name: ";
        cin >> filename;
        ifs.clear();
        ifs.open(filename);
    }
}

void openOutputFile(ofstream& ofs) {

    string filename;
    cout << "Enter output file name: ";
    cin >> filename;

    ofs.open(filename);

    while (!ofs) {
        cout << "Output file failed to open." << endl;
        cout << "Enter output file name: ";
        cin >> filename;
        ofs.clear();
        ofs.open(filename);
    }
}