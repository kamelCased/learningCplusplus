#include <iostream>
#include <vector>
using namespace std;

int* getArrayFromUser (int& outArrSize);
vector<int> makeSetFromArray(int* arr, int arrSize);
vector<vector<int>> getPowerSet(vector<int> set);
vector<vector<int>> trimEqualElements(vector<vector<int>> powerSet);
void printVec(vector<vector<int>> v);

int main() {

    // Get array from user
    int userArrSize;
    int* userArr = getArrayFromUser (userArrSize);

    // Make set from array
    vector<int> set = makeSetFromArray(userArr, userArrSize);

    // free memory
    delete[] userArr;
    userArr = nullptr;

    // Get all subsets
    vector<vector<int>> powerSet = getPowerSet(set);

    // trim same subsets
    powerSet = trimEqualElements(powerSet);

    // Print the power set
    cout << "The cardinality of the power set is " << powerSet.size() << " and the elements are:\n";
    printVec(powerSet);

    return 0;
}

int* getArrayFromUser (int& outArrSize) {

    int arrSize;
    cout << "Please enter the size of your array:" << endl;
    cin >> arrSize;

    int* arr = new int[arrSize];

    cout << "Please enter the elements of your array, each on a separate line." << endl;
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    outArrSize = arrSize;
    return arr;
}

vector<int> makeSetFromArray(int* arr, int arrSize) {

    vector<int> set;

    for (int i = 0; i < arrSize; i++) {

        bool alreadyInSet = false;

        for (int j = 0; j < set.size(); j++) {
            if (set[j] == arr[i]) {
                alreadyInSet = true;
            }
        }

        if (!alreadyInSet) {
            set.push_back(arr[i]);
        }
    }

    return set;
}

vector<vector<int>> getPowerSet(vector<int> set) {

    if (set.empty()) {
        vector<vector<int>> subset;
        return subset;
    }
    else {

        vector<vector<int>> power;

        for (int i = 0; i < set.size(); i++) {

            vector<int> tempSet = set;
            tempSet.erase(tempSet.begin() + i);

            vector<vector<int>> powerSubset = getPowerSet(tempSet);

            powerSubset.push_back(tempSet);

            for (vector<int> el: powerSubset) {
                power.push_back(el);
            }
        }

        power.push_back(set);

        return power;
    }
}

vector<vector<int>> trimEqualElements(vector<vector<int>> powerSet) {

    vector<vector<int>> unique;

    for (int i = 0; i < powerSet.size(); i++) {

        vector<vector<int>>::iterator it = find(unique.begin(), unique.end(), powerSet[i]);

        if (it == unique.end()) {
            unique.push_back(powerSet[i]);
        }
    }

    return unique;
}

void printVec(vector<vector<int>> v) {

    cout << "{";

    for (int i = 0; i < v.size(); i++) {

        cout << "{";

        for (int j = 0; j < v[i].size(); j++) {

            cout << v[i][j];

            if (j < v[i].size() - 1) {
                cout << ", ";
            }
        }

        if (i < v.size() - 1) {
            cout << "},\n";
        }

        else {
            cout << "}}" << endl;
        }
    }
}