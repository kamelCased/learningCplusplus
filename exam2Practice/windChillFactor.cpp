#include <iostream>

bool getWindchillIndex(double windSpeed, double tempCelsius, double& windchillIndex);
double convertMilesPerHourToMetersPerSecond(double mph);

int main() {

    double windSpeed;
    std::cout << "Hello, what is the current wind speed in mph?" << std::endl;
    std::cin >> windSpeed;

    windSpeed = convertMilesPerHourToMetersPerSecond(windSpeed);

    double tempCelsius;
    std::cout << "And what is the current temperature in celsius?" << std::endl;
    std::cin >> tempCelsius;

    double windChillIndex;

    if (getWindchillIndex(windSpeed, tempCelsius, windChillIndex)) {
        std::cout << "The windchill index is " << windChillIndex << " degrees celsius." << std::endl;
    }
    else {
        std::cout << "The temperature is too high, there is no windchill index." << std::endl;
    }

    return 0;
}

bool getWindchillIndex(double windSpeed, double tempCelsius, double& windchillIndex){

    const double MAX_TEMP_FOR_WINDCHILL = 10.0;

    if (tempCelsius <= MAX_TEMP_FOR_WINDCHILL) {
        windchillIndex = 13.12 + 0.6215 * tempCelsius - 11.37 * pow(windSpeed, 0.16) + 0.3965 * tempCelsius * pow(windSpeed,0.016);
        return true;
    }

    return false;
}

double convertMilesPerHourToMetersPerSecond(double mph) {
    double SECONDS_IN_HOUR = 3600.0;
    double METERS_IN_MILE = 1609.34;
    return (METERS_IN_MILE * mph / SECONDS_IN_HOUR);
}