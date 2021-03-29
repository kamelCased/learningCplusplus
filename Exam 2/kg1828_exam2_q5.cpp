#include <iostream>
#include <vector>
using namespace std;

void getVecFromUser(vector<int>& outGrades, vector<int>& outUserID);
int findMax(vector<int> v);
vector<int> findIndices(vector<int> allGrades, int val);
vector<int> getValues (vector<int> allIDs, vector<int> indices);
void printVec(vector<int> v);

int main() {

    vector<int>outGrades, outUserID;
    getVecFromUser(outGrades, outUserID);

    int max = findMax(outGrades);
    cout << "The highest grade is " << max << "." << endl;

    vector<int> maxIndices = findIndices(outGrades, max);
    vector<int> maxIDs = getValues (outUserID, maxIndices);

    cout << "The students with the highest grade " << max << " are: ";
    printVec(maxIDs);

    return 0;
}

void getVecFromUser(vector<int>& outGrades, vector<int>& outUserID) {

    cout << "Please enter a non-empty sequence of lines."<< endl;
    cout << "Each line should have a student ID and their grade (0-100)," << endl;
    cout <<"separated by a space." << endl;
    cout <<"To indicate the end of the input, enter -1 as a student ID:" << endl;

    vector<int> grades;
    vector<int> userID;
    int grade, id;
    bool seenEndOfInput = false;

    while (!seenEndOfInput) {
        cin >> id;
        if(id == -1) {
            seenEndOfInput = true;
        }
        else {
            cin >> grade;
            grades.push_back(grade);
            userID.push_back(id);
        }
    }

    outGrades = grades;
    outUserID = userID;
}

int findMax(vector<int> v) {

    int max = v[0];
    for (int el: v) {
        if(el > max){
            max = el;
        }
    }

    return max;
}

vector<int> findIndices(vector<int> allGrades, int val) {

    vector<int> indices;

    for (int i = 0; i < allGrades.size(); i++) {
        if (allGrades[i] == val) {
            indices.push_back(i);
        }
    }

    return indices;
}

vector<int> getValues (vector<int> allIDs, vector<int> indices) {

    vector<int> maxIDs;

    for (int i = 0; i < indices.size(); i++) {
        maxIDs.push_back(allIDs[indices[i]]);
    }

    return maxIDs;
}

void printVec(vector<int> v) {

    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - 1) {
            cout << v[i] << " ";
        }
        else {
            cout << v[i] << ".\n";
        }
    }
}