#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void openInputFile(ifstream& ifs);
void openOutputFile(ofstream& ofs);
vector<double> mergeSort(const vector<double>& nums1, const vector<double>& nums2);

int main() {

    ifstream inFile1;
    ifstream inFile2;

    openInputFile(inFile1);
    openInputFile(inFile2);

    vector<double> nums1;
    vector<double> nums2;
    double temp;
    while(inFile1 >> temp) {
        nums1.push_back(temp);
    }
    while (inFile2 >> temp) {
        nums2.push_back(temp);
    }

    inFile1.close();
    inFile2.close();

    vector<double> nums3 = mergeSort(nums1, nums2);

    ofstream outFile;
    openOutputFile(outFile);
    for (auto num: nums3){
        outFile << num << endl;
    }

    cout << "Successfully wrote merged number list to new file" << endl;

    outFile.close();

    ifstream inFile3;

    openInputFile(inFile3);

    cout << "Here's the merged list I wrote out:" << endl;
    while(inFile3 >> temp) {
        cout << temp << " ";
    }

    inFile3.close();

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

    cout << "Successfully opened input file." << endl;
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

    cout << "Successfully opened output file." << endl;
}

vector<double> mergeSort(const vector<double>& nums1, const vector<double>& nums2) {

    vector<double> merged;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i++]);
        }
        else {
            merged.push_back(nums2[j++]);
        }
    }

    while (i < nums1.size()) {
        merged.push_back(nums1[i++]);
    }
    while (j < nums2.size()) {
        merged.push_back(nums2[j++]);
    }

    return merged;
}

