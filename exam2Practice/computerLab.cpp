#include <iostream>
#include <cstdlib>
using namespace std;

bool* createArray ();
bool checkIfAvailable(bool* occupancy, int labNumber, int computerNumber);
void updateOccupancy(bool*& arr, int labNumber, int computerNumber);
void logOn (bool*& occupancy, int*& seat);
void logOff (bool*& occupancy, int*& seat);
void printOccupancy (bool* occupancy);

int main() {

    // Generate occupancy
    cout << "Hello, welcome to Maslo Research Labs!" << endl;
    bool* occupancy = createArray ();

    // Log user on
    int* station;
    logOn(occupancy, station);

    // Log user off
    logOff(occupancy, station);

    // (free memory)
    delete [] occupancy, station;
    occupancy = nullptr;
    station = nullptr;

    return 0;
}

void logOn (bool*& occupancy, int*& station) {

    cout << "Here's the current occupancy:" << endl;
    printOccupancy (occupancy);

    bool loggedIn = false;
    int labNumber, cpuNumber;

    while (!loggedIn) {

        // Choose site
        cout << "Which lab do you want to enter?" << endl;
        cin >> labNumber;

        // Choose station
        cout << "Which computer in lab #" << labNumber << " do you want to use?" << endl;
        cin >> cpuNumber;

        // Station available
        if (checkIfAvailable(occupancy, labNumber, cpuNumber)) {

            // Log in
            loggedIn = true;
            cout << "Enjoy your session at lab " << labNumber << " station " << cpuNumber << "!" << endl;
            cout << ".\n.\n.\nd\no\ni\nn\ng\n \nw\no\nr\nk\n.\n.\n.\n";
        }

        // Station not available
        else {
            cout << "Not available, try another station." << endl;
            printOccupancy (occupancy);
        }
    }

    // New station occupied
    updateOccupancy(occupancy, labNumber, cpuNumber);

    // Log station
    station = new int[2];
    station[0] = labNumber;
    station[1] = cpuNumber;
}

void printOccupancy (bool* arr) {

    cout << "Lab Number" << "\tComputer Stations" << endl;

    for (int i = 0; i < 4; i++) {

        cout << i + 1 << "\t\t\t";

        for (int j = 0; j < 5; j++) {

            if (arr[i, j] == false) {
                cout << j+1 << ": " << "occupied" << " ";
            }

            else {
                cout << j+1 << ": " << "empty" << " ";
            }
        }
        cout << endl;
    }
}

bool checkIfAvailable(bool* arr, int labNumber, int computerNumber)  {

    if (labNumber > 4 || computerNumber > 5) {
        return false;
    }

    return arr[labNumber - 1, computerNumber - 1];
}

void updateOccupancy(bool*& arr, int labNumber, int computerNumber)  {
    arr[labNumber - 1, computerNumber - 1] = false;
}

bool* createArray () {

    srand(NULL);
    bool* arr = new bool[4,5];

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 5; j++) {

            int random = rand() % 100;

            if (random >= 50) {
                arr[i,j] = true;
            }
            else {
                arr[i,j] = false;
            }
        }
    }

    return arr;
}

void logOff (bool*& occupancy, int*& seat) {

    bool logOffDesired = false;
    char log;

    while (!logOffDesired) {
        cout << "Do you want to log off? (y/n)" << endl;
        cin >> log;
        if (log == 'y' || log == 'Y') {
            logOffDesired = true;
        }
    }

    cout << "You are now logged off from lab " << seat[0] << " station " << seat[1] << endl;
    occupancy[seat[0] - 1, seat[1] - 1] = true;
    cout << "The occupancy is now: " << endl;
    printOccupancy(occupancy);
}