#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openInputFile(ifstream& inFile);

int main() {

    ifstream inFile;
    openInputFile(inFile);

    int num;
    inFile >> num;
    int max = num, min = num;

    while(inFile >> num) {
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }

    cout << "Max in file: " << max << endl;
    cout << "Min in file: " << min << endl;

    return 0;
}

void openInputFile(ifstream& inFile) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "File failed to open" << endl;
        cout << "Enter filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}