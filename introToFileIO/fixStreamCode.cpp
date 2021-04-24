#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void openFile(T& file);

vector<string> readLines(ifstream& i);

void fixCode(vector<string>& lines);

void writeFile(ofstream& o, vector<string> lines);

int main() {

    ifstream inFile;
    openFile(inFile);

    vector<string> code = readLines(inFile);

    inFile.close();

    fixCode(code);

    ofstream outFile;
    openFile(outFile);

    writeFile(outFile, code);

    outFile.close();

    return 0;
}

template <class T>
void openFile(T& file) {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    file.open(filename);

    while(!file) {

        cout << "File failed to open" << endl;
        cout << "Enter file name: ";
        cin >> filename;

        file.open(filename);
    }

    cout << "Successfully opened file" << endl;
}

vector<string> readLines(ifstream& i) {

    vector<string> program;
    string line;
    while(getline(i, line)) {
        program.push_back(line);
    }

    cout << "Successfully read lines" << endl;
    return program;
}

void fixCode(vector<string>& lines) {

    for (auto& line: lines) {

        if (line.find("    cout ") != -1) {

            int idx = line.find(">>");
            while (idx != -1) {
                string before = line.substr(0, idx);
                string after = line.substr(idx + 2, line.size() - (idx + 2));
                line = before + "<<" + after;
                idx = line.find(">>", idx + 1);
            }
        }

        else if (line.find("    cin ") != -1) {

            int idx = line.find("<<");
            while (idx != -1) {
                string before = line.substr(0, idx);
                string after = line.substr(idx + 2, line.size() - (idx + 2));
                line = before + ">>" + after;
                idx = line.find("<<", idx + 1);
            }
        }
    }

    cout << "Successfully fixed code" << endl;
}

void writeFile(ofstream& o, vector<string> lines) {

    for (auto& line: lines) {
        o << line << endl;
    }

    cout << "Successfully wrote to file" << endl;
}