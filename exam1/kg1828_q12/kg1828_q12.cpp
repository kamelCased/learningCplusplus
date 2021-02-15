// Assignment: NYU Tandon Bridge Exam 1 Question 12
// Author: Kamel Gazzaz
// Date: 02/11/2021
#include <iostream>
using namespace std;

const int INCHES_PER_FOOT = 12;
const int INCHES_PER_YARD = 36;

int main() {

    int dayCounter = 1;
    bool destinationReached = false;
    int totalTraveled = 0;

    // start travel
    while (!destinationReached) {

        // Get the inches traveled from the user
        int dailyInchesTraveled;
        cout << "Enter the number of inches the snail traveled in day #" << dayCounter << "," << endl;
        cout << "or type -1 if they reached their destination:" << endl;
        cin >> dailyInchesTraveled;

        // destination reached
        if (dailyInchesTraveled == -1) {

            // end travel
            destinationReached = true;
        }

        // still traveling
        else {

            // add the daily distance to the total
            totalTraveled += dailyInchesTraveled;

            // increment the number of days
            dayCounter++;
        }
    }

    // Convert total traveled distance to yards, feet, and inches
    int yards = totalTraveled / INCHES_PER_YARD;
    totalTraveled %= INCHES_PER_YARD;

    int feet = totalTraveled / INCHES_PER_FOOT;
    totalTraveled %= INCHES_PER_FOOT;

    int inches = totalTraveled;

    // Output the travel log to the user
    cout << "In " << dayCounter << " days, the snail traveled " << yards << " yards, ";
    cout << feet << " feet and " << inches << " inches." << endl;

    return 0;
}
