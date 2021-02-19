// Assignment: NYU Tandon Bridge Homework 5 Question 2
// Author: Kamel Gazzaz
// Due date: 02/12/2021
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_GUESSES = 5;

int main() {

    // Choose a random time between 0 and 100
    srand(time(0));
    int toBeGuessed = (rand() % 100) + 1;
    int rangeMax = 100;
    int rangeMin = 1;

    // Ask the user to guess the random number
    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    bool guessedRight = false;

    // User gets 5 guesses to get the correct number
    for (int numOfGuesses = 0; (numOfGuesses < MAX_GUESSES) && (!guessedRight); numOfGuesses++) {

        // Give the user the range and remaining guesses
        cout << "Range: [" << rangeMin << ", " << rangeMax << "] Number of guesses left: " << MAX_GUESSES - numOfGuesses << endl;

        // User guesses a number
        cout << "Your guess: ";
        int guess;
        cin >> guess;

        // Correct guess
        if (guess == toBeGuessed) {
            guessedRight = true;

            // First guess (for singular/plural)
            if (numOfGuesses == 0) {
                cout << "Congrats! You guessed my number in " << numOfGuesses + 1 << " guess." << endl;
            }

            // Other guess
            else {
                cout << "Congrats! You guessed my number in " << numOfGuesses + 1 << " guesses." << endl;
            }
        }

        // Wrong guess
        else {

            // No more guesses
            if (MAX_GUESSES - numOfGuesses == 1) {
                cout << "Out of guesses! My number is " << toBeGuessed << endl;
            }

            // Some guess(es) remaining
            else {

                // Guessed too high
                if (guess > toBeGuessed) {

                    cout << "Wrong!	My	number	is	smaller." << endl;

                    // High guess in range
                    if (guess >= rangeMin && guess <= rangeMax) {
                        rangeMax = guess - 1;
                    }
                }

                // Guessed too low
                else {

                    cout << "Wrong!	My	number	is	bigger." << endl;

                    // Low guess in range
                    if (guess >= rangeMin && guess <= rangeMax) {
                        rangeMin = guess + 1;
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;
}
