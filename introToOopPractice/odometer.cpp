#include <iostream>
using namespace std;

class Odometer {
    double milesDriven;
    double fuelEfficiency;
public:
    Odometer(): milesDriven(0.0), fuelEfficiency(0.0) {};
    Odometer(double miles, double efficiency);

    void resetOdometer() {milesDriven = 0.0;}
    void setFuelEfficiency(double eff) {if (eff > 0) fuelEfficiency = eff; else cout << "Invalid" << endl;}
    void addMiles(double newMiles) {if (newMiles > 0) milesDriven += newMiles; else cout << "Invalid" << endl;}
    double gasConsumed() {if (fuelEfficiency != 0) return milesDriven / fuelEfficiency; else return 0;}
};
Odometer::Odometer(double miles, double efficiency) {

    if (miles > 0)
        milesDriven = miles;
    else
        milesDriven = 0.0;

    if (efficiency > 0)
        fuelEfficiency = efficiency;
    else
        fuelEfficiency = 0.0;
}

int main() {

    int choice;
    cout << "Hello, welcome to the car club." << endl;
    cout << "Do you want a new or used car? (Enter 1 for new, 0 for used)" << endl;
    cin >> choice;
    Odometer car;
    if (choice == 0) {
        double mileage, efficiency;
        cout << "Enter the car mileage: ";
        cin >> mileage;
        cout << "Enter the car fuel efficiency: ";
        cin >> efficiency;
        car = Odometer(mileage, efficiency);
    }

    bool done = false;
    while (!done) {
        cout << "What do you want to do?" << endl;
        cout << "1. Drive more" << endl;
        cout << "2. Set car efficiency" << endl;
        cout << "3. See gas consumption" << endl;
        cout << "4. Reset odometer" << endl;
        cout << "-1. End ride" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                double miles;
                cout << "How many miles are you driving?" << endl;
                cin >> miles;
                car.addMiles(miles);
                break;
            case 2:
                double eff;
                cout << "What is the new car efficiency?" << endl;
                cin >> eff;
                car.setFuelEfficiency(eff);
                break;
            case 3:
                cout << "You've consumed " << car.gasConsumed() << " gallons of fuel" << endl;
                break;
            case 4:
                car.resetOdometer();
                cout << "Odometer successfully reset" << endl;
                break;
            case -1:
                cout << "Hope you enjoyed your ride." << endl;
                done = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
