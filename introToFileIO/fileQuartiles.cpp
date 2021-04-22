#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void openInputFile(ifstream& i);
void addNums(ifstream& ifs, vector<int>& sortedNums);
vector<double> getQuartiles (vector<int> list);

int main() {

    ifstream ifs;
    openInputFile(ifs);

    vector<int> sortedNums;
    addNums(ifs, sortedNums);

    ifs.close();

    vector<double> quarts = getQuartiles(sortedNums);

    cout << "First quartile: " << quarts[0] << endl;
    cout << "Median: " << quarts[1] << endl;
    cout << "Third quartile: " << quarts[2] << endl;

    return 0;
}

void addNums(ifstream& ifs, vector<int>& sortedNums) {
    int num;
    while(ifs >> num) {
        sortedNums.push_back(num);
    }
}

void openInputFile(ifstream& i) {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    i.open(filename);
    while(!i) {
        cout << "Failed to open file.\n";
        cout << "Enter file name: ";
        cin >> filename;
        i.clear();
        i.open(filename);
    }
}

vector<double> getQuartiles (vector<int> list) {

    vector<double> quartiles;

    if (list.size() % 2) {

        int halfIndex = list.size() / 2;

        double q1 = list[halfIndex / 2];
        double med = list[halfIndex];
        double q3 = list[(list.size() - halfIndex) / 2 + halfIndex];

        quartiles.push_back(q1);
        quartiles.push_back(med);
        quartiles.push_back(q3);

        return quartiles;
    }

    else {

        int firstHalfIndex = list.size() / 2 - 1;

        double q1 = (list[firstHalfIndex / 2] + list[firstHalfIndex / 2 + 1]) / 2.0;
        double med = (list[firstHalfIndex] + list[firstHalfIndex + 1]) / 2.0;
        double q3 = (list[(list.size() - firstHalfIndex) / 2 + firstHalfIndex] + list[(list.size() - firstHalfIndex) / 2 + 1 + firstHalfIndex]) / 2.0;

        quartiles.push_back(q1);
        quartiles.push_back(med);
        quartiles.push_back(q3);

        return quartiles;
    }
}