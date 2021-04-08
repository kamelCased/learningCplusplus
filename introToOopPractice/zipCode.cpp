#include <iostream>
#include <string>
using namespace std;

class ZipCode {
    int zip;
public:
    ZipCode(int zip);
    ZipCode(string zip);
    int getZip() {return zip;}
    string getZipBar();
};
ZipCode::ZipCode(int zip) {
    if (zip > 0 && zip < 100000) {
        this->zip = zip;
    }
    else {
        cout << "Invalid zip.";
        exit(1);
    }
}
ZipCode::ZipCode(string zip) {

    if (zip.length() == 27) {
        int finalZip = 0;
        int weight = 10000;
        for (int i = 1; i < zip.length() - 1; i+=5) {
                int digit;
                if (zip[i] + zip[i+1] + zip[i+2] + zip[i+3] + zip[i+4] != 2) {
                    cout << "Invalid zip.";
                    exit(1);
                }
                else {
                    if (zip[i]) digit += 7;
                    if (zip[i+1]) digit += 4;
                    if (zip[i+2]) digit += 2;
                    if (zip[i+3])  digit += 1;
                    finalZip += digit * weight;
                    weight /= 10;
                }
        }
        this->zip = finalZip;
    }
    else {
        cout << "Invalid zip.";
        exit(1);
    }
}
string ZipCode::getZipBar() {
    string bar = "1";
    int weight = 10000;
    int temp = zip;
    while (temp > 0) {
        int count = 0;
        int digit = temp / weight;
        if (digit == 0) {
            bar += "11000";
        }
        else {
            if (digit >= 7) {
                bar += "1";
                digit -= 7;
                count++;
            }
            else {
                bar += "0";
            }
            if (digit >= 4) {
                bar += "1";
                digit -= 4;
                count++;
            }
            else {
                bar += "0";
            }
            if (digit >= 2) {
                bar += "1";
                digit -= 2;
                count++;
            }
            else {
                bar += "0";
            }
            if (digit >= 1) {
                bar += "1";
                digit -= 1;
                count++;
            }
            else {
                bar += "0";
            }
            if (count < 2) {
                bar += "1";
                count++;
            }
            else {
                bar += "0";
            }
        }
        temp %= weight;
        weight /= 10;
    }
    bar += "1";
    return bar;
}

int main() {

    int input;
    std::cout << "Hello, please enter your zip code: ";
    cin >> input;

    ZipCode zip(input);

    cout << "Your USPS barcode is: " << zip.getZipBar() << endl;

    return 0;
}
