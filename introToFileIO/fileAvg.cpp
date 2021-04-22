#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void openInputFile(ifstream& ifs);
void openOutputFile(ofstream& ofs, bool append);

vector<double> getNums(ifstream& ifs);
double getAverage (const vector<double>& vec);

int main() {

    ifstream inFile;
    openInputFile(inFile);

    vector<double> nums = getNums(inFile);
    cout << "Successfully got the numbers from the file." << endl;

    inFile.close();

    double avg = getAverage(nums);
    cout << "Successfully calculated the average." << endl;

    ofstream outFile;
    openOutputFile(outFile, true);

    outFile << endl << "Average: " << avg << endl;
    cout << "Successfully outputted average to the file." << endl;

    outFile.close();

    return 0;
}


vector<double> getNums(ifstream& ifs) {

    vector<double> vec;
    double num;

    while(ifs >> num) {
        vec.push_back(num);
    }

    return vec;
}

void openInputFile(ifstream& ifs)  {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifs.open(filename);

    while(!ifs) {

        cout << "File failed to open.\n";
        cout << "Enter file name: ";
        cin >> filename;

        ifs.clear();
        ifs.open(filename);
    }
}

void openOutputFile(ofstream& ofs, bool append)  {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    if (append) {

        ofs.open(filename, ios::app);

        while(!ofs) {

            cout << "File failed to open.\n";
            cout << "Enter file name: ";
            cin >> filename;

            ofs.clear();
            ofs.open(filename, ios::app);
        }
    }

    else {

        ofs.open(filename);

        while(!ofs) {

            cout << "File failed to open.\n";
            cout << "Enter file name: ";
            cin >> filename;

            ofs.clear();
            ofs.open(filename);
        }
    }
}

double getAverage (const vector<double>& vec) {

    double sum = 0.0;

    for (auto num: vec) {
        sum += num;
    }

    return sum / vec.size();
}
