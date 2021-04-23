#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void openFile(T& file);

vector<int> readWordsLengths(ifstream& i);

double calculateAverage(vector<int> nums);

int main() {

    ifstream inFile;
    openFile(inFile);

    vector<int> wordLengths = readWordsLengths(inFile);

    inFile.close();

    double avg = calculateAverage(wordLengths);

    cout << "The words in the file have " << avg << " characters on average." << endl;

    return 0;
}


template <class T>
void openFile(T& file) {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    file.open(filename);

    while (!file) {

        cout << "File failed to open." << endl;
        cout << "Enter file name: ";
        cin >> filename;

        file.clear();
        file.open(filename);
    }

    cout << "Successfully opened file." << endl;
}

vector<int> readWordsLengths(ifstream& i) {

    vector<int> words;
    string word;

    while (i >> word) {
        words.push_back(word.length());
    }

    return words;
}

double calculateAverage(vector<int> nums) {

    double sum = 0;
    for (int num: nums) {

        sum += num;
    }

    return sum / nums.size();
}
