#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {

    int n;
    cout << "Enter the size of your tree:" <<endl;
    cin >> n;

    char s;
    cout << "Enter the character symbol of your tree:" <<endl;
    cin >> s;

    printPineTree(n, s);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {

    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            cout << " ";
        }
        for (int i = 1; i <= n-j; i++) {
            cout << " ";
        }
        for(int i = 1; i <= 2*j+1; i++) {
            cout <<symbol;
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {

    for (int j = 1; j <= n; j++) {
        printShiftedTriangle(j, n-j, symbol);
    }

}