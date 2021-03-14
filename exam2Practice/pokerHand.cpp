#include <iostream>
#include <ctime>
#include <cstdlib>

void getHand(char*& rankArr, char*& suitArr);
void printHand(char* rankArr, char* suitArr);
void scoreHand(char* rankArr, char* suitArr);

const int HAND_SIZE = 5;
const int NUM_OF_RANKS = 13;
const int NUM_OF_SUITS = 4;

int main() {

    // Start program
    std::cout << "Welcome to the Luxor, high roller!" << std::endl;

    // Get a five card hand
    char *ranksInHand, *suitsInHand;
    getHand(ranksInHand, suitsInHand);

    // Read the five card hand to the user
    printHand(ranksInHand, suitsInHand);

    // Determine the hand's category
    scoreHand(ranksInHand, suitsInHand);

    // free memory
    delete [] ranksInHand, suitsInHand;
    ranksInHand = suitsInHand = nullptr;

    return 0;
}

void getHand(char*& rankArr, char*& suitArr) {

    const int FIRST_DIGIT = '0';

    rankArr = new char[HAND_SIZE];
    suitArr = new char[HAND_SIZE];
    int* tempSuitArr = new int[HAND_SIZE];

    srand(time(0));

    for (int i = 0 ; i < HAND_SIZE; i++) {
       rankArr[i] = (char) (rand() % NUM_OF_RANKS + 1) + FIRST_DIGIT;
       tempSuitArr[i] = rand() % NUM_OF_SUITS + 1;
    }

    for (int i = 0; i < HAND_SIZE; i++) {
        if (rankArr[i] == '9' + 1) {
            rankArr[i] = 'T';
        }
        else if (rankArr[i] == '9' + 2) {
            rankArr[i] = 'J';
        }
        else if (rankArr[i] == '9' + 3) {
            rankArr[i] = 'Q';
        }
        else if (rankArr[i] == '9' + 4) {
            rankArr[i] = 'K';
        }
    }

    for (int i = 0; i < HAND_SIZE; i++) {
        switch (tempSuitArr[i]) {
            case 1:
                suitArr[i] = 'S';
                break;
            case 2:
                suitArr[i] = 'D';
                break;
            case 3:
                suitArr[i] = 'H';
                break;
            case 4:
                suitArr[i] = 'C';
                break;
        }
    }

    delete [] tempSuitArr;
    tempSuitArr = nullptr;
}

void printHand(char* rankArr, char* suitArr) {

    std:: cout << "Your hand is: ";

    for (int i = 0; i < HAND_SIZE; i++) {
        std::cout << rankArr[i] << suitArr[i] << " ";
    }
    std::cout << std::endl;
}

void scoreHand(char* rankArr, char* suitArr) {

    // Check straight flush
    bool straightFlush = true;
    bool straight = true;
    bool flush = true;
    std::sort(rankArr, rankArr + HAND_SIZE - 1);
    char previous = rankArr[0];
    for (int i = 1; i < HAND_SIZE; i++) {
        if (rankArr[i] != previous + 1) {
            straightFlush = false;
            straight = false;
        }
    }
    char suit = suitArr[0];
    for (int i = 1; i < HAND_SIZE - 1; i++) {
        if (suitArr[i] != suit) {
            straightFlush = false;
            flush = false;
        }
    }
    if (straightFlush) {
        std::cout << straightFlush;
    }

    else {

        // Check four of a kind
        char kind = rankArr[0];
        int count = 1;
        for (int i = 1; i < HAND_SIZE; i++) {
            if (rankArr[i] == kind) {
                count++;
            }
        }
        if (count == 4) {
            std::cout << "Your hand is a four of a kind!" << std::endl;
        }

        else {

            // Check straight
            if (straight) {
                std::cout << "Your hand is a straight!" << std::endl;
            }

            else {

                // Check full house
                char kind1 = rankArr[0], kind2;
                int count1 = 1, count2 = 0;

                for (int i = 1; i < HAND_SIZE; i++) {
                    if (rankArr[i] == kind1) {
                        count1++;
                    }
                    else if (rankArr[i] == kind2) {
                        count2++;
                    }
                    else if (count2 == 0){
                        kind2 = rankArr[i];
                        count2++;
                    }
                }
                if ((count1 == 3 && count2 == 2) || (count1 == 2 && count2 == 3)) {
                    std::cout << "Your hand is a full house!" << std::endl;
                }

                else {

                    // Check flush
                    if (flush) {
                        std::cout << "Your hand is a flush!" << std::endl;
                    }

                    else {

                        // Check three of a kind
                        if (count1 == 3 || count2 == 3) {
                            std::cout << "Your hand is a 3 of a kind!" << std::endl;
                        }

                        else {

                            // Check two pair
                            char kind3;
                            int count3 = 0;
                            count1 = 1, count2 = 0;
                            kind1 = rankArr[0];

                            for (int i = 1; i < HAND_SIZE; i++) {
                                if (rankArr[i] == kind1) {
                                    count1++;
                                }
                                else if (count2 == 0){
                                    kind2 = rankArr[i];
                                    count2++;
                                }
                                else if (rankArr[i] == kind2) {
                                    count2++;
                                }
                                else if (count3 == 0) {
                                    kind3 = rankArr[i];
                                    count3++;
                                }
                                else if (rankArr[i] == kind3){
                                    count3++;
                                }
                            }
                            if ((count1 == 2 && count2 == 2) || (count1 == 2 && count3 == 2) || (count2 == 2 && count3 == 2)) {
                                std::cout << "Your hand is a two pair!" << std::endl;
                            }

                            else {

                                // Check one pair
                                if (count1 == 2 || count2 == 2 || count3 == 2) {
                                    std::cout << "Your hand is a pair!" << std::endl;
                                }

                                else {

                                    // Nothing
                                    std::cout << "Your hand has nothing." << std::endl;
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}

