#include <iostream>
#include <string>
using namespace std;

string* readText1(int& numStrings);
string* readText2(int& numStrings);

int main() {

    // --------- First version ----------

    int textSize;
    string* text = readText1(textSize);

    for (int i = 0; i < textSize; i++) {
        std::cout << i+1 << ". " << text[i] << std::endl;
    }

    delete[] text;
    text = nullptr;

    // --------- Second version ----------

    text = readText2(textSize);

    for (int i = 0; i < textSize; i++) {
        std::cout << i+1 << ". " << text[i] << std::endl;
    }

    delete[] text;
    text = nullptr;

    return 0;
}

string* readText1(int& numStrings) {

    int num;
    cout << "How many lines?" << endl;
    cin >> num;

    string temp;
    getline(cin,temp);

    string* lines = new string[num];
    cout << "Please enter " << num << " lines:" <<endl;
    for(int i = 0; i < num; ++i) {
        getline(cin, lines[i]);
    }

    numStrings = num;
    return lines;
}

string* readText2(int& numStrings) {

    int size = 10;
    string* lines = new string[size];

    cout << "Please enter your text, end input with an empty line:" << endl;

    bool endOfInput = false;
    int index = 0;
    while (!endOfInput) {

        string input;
        getline(cin, input);

        if (input == ""){
            endOfInput = true;
        }
        else {
            if (index == size) {
                // double size
                size *= 2;
                string* temp = new string[size];
                for (int i = 0; i < size / 2; i++) {
                    temp[i] = lines[i];
                }
                delete[] lines;
                lines = temp;
                temp = nullptr;
            }

            lines[index] = input;
            index++;
        }
    }

    numStrings = index;
    return lines;
}