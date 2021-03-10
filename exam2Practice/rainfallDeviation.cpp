#include <iostream>
#include <string>
#include <vector>

const std::string MONTHS[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

std::vector<double> getRainfall();
void printTable(std::vector<double> rainfall);

int main() {

    // Get rainfall values
    std::vector<double> rainfall;
    rainfall = getRainfall();

    // Output results
    printTable(rainfall);

    return 0;
}

std::vector<double> getRainfall() {

    std::vector<double> averageRainfall;
    std::vector<double> rainfallThisYear;

    for (std::string month: MONTHS) {
        double rain;
        std::cout << "Please enter the average rainfall for the month " << month << "." << std::endl;
        std::cin >> rain;
        averageRainfall.push_back(rain);
    }

    for (std::string month: MONTHS) {
        double rain;
        std::cout << "Please enter the actual rainfall in " << month << " of this year." << std::endl;
        std::cin >> rain;
        rainfallThisYear.push_back(rain);
    }

    std::vector<double> rainfallDiff;
    for (int i = 0; i < averageRainfall.size(); i++) {
        double diff = averageRainfall[i] - rainfallThisYear[i];
        rainfallDiff.push_back(diff);
    }

    return rainfallDiff;
}

void printTable(std::vector<double> rainfall) {

    std::cout << "Month: " << "\t\t|\t" << "Deviation from Average:"<< std::endl;

    for (int i = 0; i < rainfall.size(); i++) {
        if (MONTHS[i].length() < 4) {
            std::cout << MONTHS[i] << "\t\t\t|\t" << rainfall[i]<< std::endl;
        }
        else if (MONTHS[i].length() < 8) {
            std::cout << MONTHS[i] << "\t\t|\t" << rainfall[i]<< std::endl;
        }
        else {
            std::cout << MONTHS[i] << "\t|\t" << rainfall[i]<< std::endl;
        }

    }
}
