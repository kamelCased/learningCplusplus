#include <iostream>
#include <string>
using namespace std;

const string NINETY = "Ninety";
const string EIGHTY = "Eighty";
const string SEVENTY = "Seventy";
const string SIXTY = "Sixty";
const string FIFTY = "Fifty";
const string FORTY = "Forty";
const string THIRTY = "Thirty";
const string TWENTY = "Twenty";

const string NINETEEN = "Nineteen";
const string EIGHTEEN = "Eighteen";
const string SEVENTEEN = "Seventeen";
const string SIXTEEN = "Sixteen";
const string FIFTEEN = "Fifteen";
const string FOURTEEN = "Fourteen";
const string THIRTEEN = "Thirteen";
const string TWELVE = "Twelve";
const string ELEVEN = "Eleven";

const string TEN = "ten";
const string NINE = "nine";
const string EIGHT = "eight";
const string SEVEN = "seven";
const string SIX = "six";
const string FIVE = "five";
const string FOUR = "four";
const string THREE = "three";
const string TWO = "two";
const string ONE = "one";
const string ZERO = "zero";


void sing (int bottles);
string getNumberString(int bottles, string &tensString, string &onesString);

int main() {

    int bottlesOnWall;
    cout << "Please enter a positive integer less than 100:" << endl;
    cin >> bottlesOnWall;

    sing(bottlesOnWall);

    return 0;
}

void sing(int bottles) {

    while (bottles > 0) {

        // Get the number of bottles
        string tensString, onesString;
        string numBottlesString = getNumberString(bottles, tensString, onesString);

        // Sing the song
        if (bottles > 20 || bottles < 10) {

            cout << numBottlesString << " bottles of milk on the wall," << endl;
            cout << numBottlesString << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            numBottlesString = getNumberString(bottles - 1, tensString, onesString);
            cout << numBottlesString << " bottles of milk on the wall." << endl;
        }

        // Edge cases
        else if (bottles == 20) {
            cout << numBottlesString << " bottles of milk on the wall," << endl;
            cout << numBottlesString << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << EIGHTEEN << " bottles of milk on the wall." << endl;
        }
        else if (bottles == 19) {
            cout << NINETEEN << " bottles of milk on the wall," << endl;
            cout << NINETEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << EIGHTEEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 18) {
            cout << EIGHTEEN << " bottles of milk on the wall," << endl;
            cout << EIGHTEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << SEVENTEEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 17) {
            cout << SEVENTEEN << " bottles of milk on the wall," << endl;
            cout << SEVENTEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << SIXTEEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 16) {
            cout << SIXTEEN << " bottles of milk on the wall," << endl;
            cout << SIXTEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << FIFTEEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 15) {
            cout << FIFTEEN << " bottles of milk on the wall," << endl;
            cout << FIFTEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << FOURTEEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 14) {
            cout << FOURTEEN << " bottles of milk on the wall," << endl;
            cout << FOURTEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << THIRTEEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 13) {
            cout << THIRTEEN << " bottles of milk on the wall," << endl;
            cout << THIRTEEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << TWELVE << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 12) {
            cout << TWELVE << " bottles of milk on the wall," << endl;
            cout << TWELVE << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << ELEVEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 11) {
            cout << ELEVEN << " bottles of milk on the wall," << endl;
            cout << ELEVEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << TEN << " bottles of milk on the wall." << endl;
        }

        else if (bottles == 10) {
            cout << TEN << " bottles of milk on the wall," << endl;
            cout << TEN << " bottles of milk," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << NINE << " bottles of milk on the wall." << endl;
        }

        // bottle of milk done
        cout << endl;
        bottles--;
    }
}


string getNumberString(int bottles, string &tensString, string &onesString) {

    int tens = bottles / 10;
    int ones = bottles % 10;

    // Get the string corresponding to the number of bottles
    switch(tens) {
        case 9:
            tensString = NINETY;
            break;
        case 8:
            tensString = EIGHTY;
            break;
        case 7:
            tensString = SEVENTY;
            break;
        case 6:
            tensString = SIXTY;
            break;
        case 5:
            tensString = FIFTY;
            break;
        case 4:
            tensString = FORTY;
            break;
        case 3:
            tensString = THIRTY;
            break;
        case 2:
            tensString = TWENTY;
            break;
    }

    switch(ones) {
        case 9:
            onesString = NINE;
            break;
        case 8:
            onesString = EIGHT;
            break;
        case 7:
            onesString = SEVEN;
            break;
        case 6:
            onesString = SIX;
            break;
        case 5:
            onesString = FIVE;
            break;
        case 4:
            onesString = FOUR;
            break;
        case 3:
            onesString = THREE;
            break;
        case 2:
            onesString = TWO;
            break;
        case 1:
            onesString = ONE;
            break;
        case 0:
            onesString = ZERO;
            break;
    }

    string numBottlesString = "";
    if (bottles >= 20) {

        if (ones == 0) {
            return tensString;
        }
        else {
            return (tensString + "-" + onesString);
        }
    }

    else if (bottles < 10) {
        return onesString;
    }
    else {
        return "";
    }
}
