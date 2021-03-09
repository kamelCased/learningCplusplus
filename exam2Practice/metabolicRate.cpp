#include <iostream>
#include <cmath>

const int RUNNING_10_MPH_INTENSITY = 17;
const int RUNNING_6_MPH_INTENSITY = 10;
const int BASKETBALL_INTENSITY = 8;
const int WALKING_INTENSITY = 1;

int getWeight();
int getFoodServingCalories();
double getBasalMetabolicRateCalories(int weightInPounds);
double getPhysicalActivityCalories(int weightInPounds);
double getFoodDigestionCalories(int caloriesConsumed);
double calculateServings(double totalCalories, double favoriteFoodCalories);

int main() {

    // Get weight and calories per serving
    int weightInPounds = getWeight();
    int favoriteFoodCalories = getFoodServingCalories();

    // calculate the calories burned by metabolism
    double basalMetabolicRateCalories = getBasalMetabolicRateCalories(weightInPounds);

    // calculate the calories burned by sports
    double physicalActivityCalories = getPhysicalActivityCalories(weightInPounds);

    // sum up the metabolic and exercise calories burned
    double totalCalories = basalMetabolicRateCalories + physicalActivityCalories;

    // calculate the calories burned by digestion
    double foodDigestionCalories = getFoodDigestionCalories(totalCalories);

    // sum up all calories
    totalCalories += foodDigestionCalories;

    // determine the number of servings
    double servings = calculateServings(totalCalories, favoriteFoodCalories);

    // output to result to the user
    std::cout << "You need to eat " << servings << " servings of your favorite food to stay at your current weight!" << std::endl;

    return 0;
}

int getWeight() {

    int weight;

    std::cout << "Dear user, please enter your weight in pounds:" << std::endl;
    std::cin >> weight;

    return weight;
}

int getFoodServingCalories() {

    int caloriesPerServing;

    std::cout << "Dear user, please enter the number of calories in your favorite food:" << std::endl;
    std::cin >> caloriesPerServing;

    return caloriesPerServing;
}

double getBasalMetabolicRateCalories(int weightInPounds) {
    return 70 * pow(weightInPounds / 2.2, 0.756);
}

double getPhysicalActivityCalories(int weight) {

    int minutes;

    std::cout << "How many minutes do you run at 10 mph daily?" << std::endl;
    std::cin >> minutes;
    double running10Calories = 0.0385 * RUNNING_10_MPH_INTENSITY * weight * minutes;

    std::cout << "How many minutes do you run at 6 mph daily?" << std::endl;
    std::cin >> minutes;
    double running6Calories = 0.0385 * RUNNING_6_MPH_INTENSITY * weight * minutes;

    std::cout << "How many minutes do you play basketball daily?" << std::endl;
    std::cin >> minutes;
    double basketballCalories = 0.0385 * BASKETBALL_INTENSITY * weight * minutes;

    std::cout << "How many minutes do you walk daily?" << std::endl;
    std::cin >> minutes;
    double walkingCalories = 0.0385 * WALKING_INTENSITY * weight * minutes;

    return running10Calories + running6Calories + basketballCalories + walkingCalories;
}

double getFoodDigestionCalories (int caloriesConsumed) {
    return (caloriesConsumed / 0.90) * 0.10;
}

double calculateServings(double totalCalories, double favoriteFoodCalories) {
    return totalCalories / favoriteFoodCalories;
}

