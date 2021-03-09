#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int FOURTH_PLACE_BALLS = 20;
const int THIRD_PLACE_BALLS = 10;
const int SECOND_PLACE_BALLS = 6;
const int FIRST_PLACE_BALLS = 4;

const int FOURTH_PLACE_TEAM = 4;
const int THIRD_PLACE_TEAM = 3;
const int SECOND_PLACE_TEAM = 2;
const int FIRST_PLACE_TEAM = 1;

const int NUM_OF_TEAMS = 4;

void simulateDraft(int numTeams);
void getTeam(std::vector<int>& chosenTeamsVector);

int main() {

    simulateDraft(NUM_OF_TEAMS);

    return 0;
}

void simulateDraft(int numTeams) {

    std::vector<int> chosenTeamsVector;

    for (int i = 0; i < numTeams; i++) {
        getTeam(chosenTeamsVector);
    }

    std::cout << "The order of the draft is:" << std::endl;

    for (int team: chosenTeamsVector) {
        switch (team) {
            case FIRST_PLACE_TEAM:
                std::cout << "First place team" << std::endl;
                break;
            case SECOND_PLACE_TEAM:
                std::cout << "Second place team" << std::endl;
                break;
            case THIRD_PLACE_TEAM:
                std::cout << "Third place team" << std::endl;
                break;
            case FOURTH_PLACE_TEAM:
                std::cout << "Fourth place team" << std::endl;
                break;
        }
    }
}

void getTeam(std::vector<int>& chosenTeamsVector) {

    int totalBalls = FOURTH_PLACE_BALLS + THIRD_PLACE_BALLS + SECOND_PLACE_BALLS + FIRST_PLACE_BALLS;

    bool alreadyPicked = true;
    int chosenTeam;

    while (alreadyPicked) {

        srand(time(0));
        int pick = rand() % totalBalls;

        if (pick < FIRST_PLACE_BALLS) {
            chosenTeam = 1;
        }
        else if (pick < FIRST_PLACE_BALLS + SECOND_PLACE_BALLS) {
            chosenTeam = 2;
        }
        else if (pick < FIRST_PLACE_BALLS + SECOND_PLACE_BALLS + THIRD_PLACE_BALLS) {
            chosenTeam = 3;
        }
        else {
            chosenTeam = 4;
        }

        bool inVector = false;
        for (int team: chosenTeamsVector) {
            if (team == chosenTeam) {
                 inVector = true;
            }
        }

        if (!inVector) {
            chosenTeamsVector.push_back(chosenTeam);
            alreadyPicked = false;
        }
    }
}