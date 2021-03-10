#include <iostream>
#include <cstdlib>
#include <ctime>

void shoot(bool& targetAlive, double accuracy);
int whoToShoot (int target1, bool target1Alive, int target2, bool target2Alive);
void tallyUpVictories (int winner, int &player1Victories, int &player2Victories, int &player3Victories);
void printDuelWinner (int player1Victories, int player2Victories, int player3Victories);
int startDuel(int strategy);

int main() {

    int duels;
    std::cout << "How many duels do you wish to have?" << std::endl;
    std::cin >> duels;

    srand(time(NULL));

    int strategy;
    std::cout << "Do you want Aaron to use strategy 1 or 2?" << std::endl;
    std::cin >> strategy;

    int charlieVictories = 0;
    int aaronVictories = 0;
    int bobVictories = 0;

    for (int i = 0; i < duels; i++) {
        std::cout << "Start duel " << i << std::endl;
        int winner = startDuel(strategy);
        tallyUpVictories (winner, aaronVictories, bobVictories, charlieVictories);
    }

    // Output summary result of 100 duels
    printDuelWinner(charlieVictories, aaronVictories, bobVictories);

    return 0;
}

int startDuel(int strategy) {

    const int charlie = 3;
    const int bob = 2;
    const int aaron = 1;

    const double AARON_HIT_PROBABILITY = 1.0/3.0;
    const double BOB_HIT_PROBABILITY = 1.0/2.0;
    const double CHARLIE_HIT_PROBABILITY = 1.0;

    const int INTENTIONAL_MISS_STRATEGY = 2;

    bool aaronAlive = true;
    bool bobAlive = true;
    bool charlieAlive = true;
    int roundNumber = 1;

    while ((aaronAlive && bobAlive) || (charlieAlive && bobAlive) || (aaronAlive && charlieAlive)) {

        std::cout << "Round " << roundNumber << std::endl;

        // All 3 shooters take turns
        for (int turn = 1; turn <= 3; turn++) {

            switch(turn) {

                // Aaron's turn
                case aaron:

                    if (!aaronAlive) {
                        turn++;
                    }

                    else {
                        std::cout << "Aaron's turn:" << std::endl;
                        int target = whoToShoot(bob, bobAlive, charlie, charlieAlive);

                        if ((roundNumber == 1) && (strategy == INTENTIONAL_MISS_STRATEGY)) {
                            if (target == bob) {
                                std::cout << "Aaron shoots at Bob" << std::endl;
                                if (!bobAlive) {
                                    std::cout << "Bob is hit" << std::endl;
                                }
                                else {
                                    std::cout << "Bob is not hit" << std::endl;
                                }
                            }
                            else if (target == charlie) {
                                std::cout << "Aaron shoots at Charlie" << std::endl;
                                if (!charlieAlive) {
                                    std::cout << "Charlie is hit" << std::endl;
                                }
                                else {
                                    std::cout << "Charlie is not hit" << std::endl;
                                }
                            }
                        }
                        else {
                            if (target == bob) {
                                std::cout << "Aaron shoots at Bob" << std::endl;
                                shoot(bobAlive, AARON_HIT_PROBABILITY);
                                if (!bobAlive) {
                                    std::cout << "Bob is hit" << std::endl;
                                }
                                else {
                                    std::cout << "Bob is not hit" << std::endl;
                                }
                            }
                            else if (target == charlie) {
                                std::cout << "Aaron shoots at Charlie" << std::endl;
                                shoot(charlieAlive, AARON_HIT_PROBABILITY);
                                if (!charlieAlive) {
                                    std::cout << "Charlie is hit" << std::endl;
                                }
                                else {
                                    std::cout << "Charlie is not hit" << std::endl;
                                }
                            }
                        }
                    }
                    break;

                // Bob's turn
                case bob:

                    if (!bobAlive) {
                        turn++;
                    }

                    else {

                        std::cout << "Bob's turn:" << std::endl;
                        int target = whoToShoot(aaron, aaronAlive, charlie, charlieAlive);

                        if (target == aaron) {
                            std::cout << "Bob shoots at Aaron" << std::endl;
                            shoot(aaronAlive, BOB_HIT_PROBABILITY);
                            if (!aaronAlive) {
                                std::cout << "Aaron is hit" << std::endl;
                            }
                            else {
                                std::cout << "Aaron is not hit" << std::endl;
                            }
                        }

                        else if (target == charlie) {
                            shoot(charlieAlive, BOB_HIT_PROBABILITY);
                            std::cout << "Bob shoots at Charlie" << std::endl;
                            if (!charlieAlive) {
                                std::cout << "Charlie is hit" << std::endl;
                            }
                            else {
                                std::cout << "Charlie is not hit" << std::endl;
                            }
                        }
                    }
                    break;

                // charlie's turn
                case charlie:
                    if (!charlieAlive) {
                        turn++;
                    }

                    else {
                        std::cout << "Charlie's turn:" << std::endl;
                        int target = whoToShoot(bob, bobAlive, aaron, aaronAlive);

                        if (target == bob) {
                            std::cout << "Charlie shoots at Bob" << std::endl;
                            shoot(bobAlive, CHARLIE_HIT_PROBABILITY);

                            if (!bobAlive) {
                                std::cout << "Bob is hit" << std::endl;
                            }
                            else {
                                std::cout << "Bob is not hit" << std::endl;
                            }
                        }

                        else if (target == aaron) {
                            std::cout << "Charlie shoots at Aaron" << std::endl;
                            shoot(aaronAlive, CHARLIE_HIT_PROBABILITY);

                            if (!aaronAlive) {
                                std::cout << "Aaron is hit" << std::endl;
                            }
                            else {
                                std::cout << "Aaron is not hit" << std::endl;
                            }
                        }
                    }

                    break;
            }
            std::cout << std::endl;
        }
        roundNumber++;
    }

    if (aaronAlive) {
        std::cout << "Aaron wins the duel!" << std::endl << std::endl;
        return aaron;
    }
    else if (bobAlive) {
        std::cout << "Bob wins the duel!" << std::endl << std::endl;
        return bob;
    }
    else {
        std::cout << "Charlie wins the duel!" << std::endl << std::endl;

        return charlie;
    }
}


void shoot(bool& targetAlive, double accuracy) {

    targetAlive = true;

    double r = double(rand()) / RAND_MAX;

    if (r < accuracy) {
        targetAlive = false;
    }
}

int whoToShoot (int target1, bool target1Alive, int target2, bool target2Alive) {

    // target 1 already dead
    if (!target1Alive) {
        return target2;
    }

    // target 2 already dead
    else if (!target2Alive) {
        return target1;
    }

    // both alive
    else {
        if (target1 > target2){
            return target1;
        }
        else {
            return target2;
        }
    }
}

void tallyUpVictories (int winner, int &aaronVictories, int &bobVictories, int &charlieVictories) {

    const int charlie = 3;
    const int bob = 2;
    const int aaron = 1;

    switch (winner) {
        case aaron:
            aaronVictories++;
            break;
        case bob:
            bobVictories++;
            break;
        case charlie:
            charlieVictories++;
            break;
    }
}

void printDuelWinner (int charlieVictories, int aaronVictories, int bobVictories) {

    std::cout << "Aaron has " << aaronVictories << " victories." << std::endl;
    std::cout << "Bob has " << bobVictories << " victories." << std::endl;
    std::cout << "Charlie has " << charlieVictories << " victories." << std::endl;

    if ((charlieVictories > aaronVictories) && (charlieVictories > bobVictories)) {
        std::cout << "Charlie wins!" << std::endl;
    }
    else if ((aaronVictories > charlieVictories) && (aaronVictories > bobVictories)) {
        std::cout << "Aaron wins!" << std::endl;
    }
    else if ((bobVictories > aaronVictories) && (bobVictories > charlieVictories)) {
        std::cout << "Bob wins!" << std::endl;
    }
    else {
        std::cout << "It's a draw!" << std::endl;
    }
}