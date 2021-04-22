#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
    int id;
public:
    Player(int i): id(i) {}
    virtual int getGuess() = 0;
};
class HumanPlayer: public Player {
public:
    HumanPlayer(int i): Player(i) {}
    int getGuess() override;
};
int HumanPlayer::getGuess() {

    int guess;
    cout << "The number is between 0-99" << endl;
    cout << "What is your guess?" << endl;
    cin >> guess;

    return guess;
}
class cpuPlayer: public Player {
    int highGuess;
    int lowGuess;
public:
    cpuPlayer(int i): Player(i), highGuess(99), lowGuess(0) {}
    int getGuess() override;
    void setHigh(int high) {highGuess = high;}
    void setLow(int low){lowGuess = low;}
    int getHigh() const {return highGuess;}
    int getLow() const {return lowGuess;}
};
int cpuPlayer::getGuess() {

    if (highGuess == lowGuess) {
        return highGuess;
    }

    int guess = (rand() % (highGuess - lowGuess)) + lowGuess;
    return guess;
}


bool checkForWin(int guess, int answer, int& resp) {
    cout << "You guessed " << guess << ". ";
    if (answer == guess) {
        cout << "You’re right! You win!" << endl;
        resp = 0;
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess is too high." << endl;
        resp = 1;
    }
    else {
        cout << "Your guess is too low." << endl;
        resp = 2;
    }
    return false;
}
void play(Player &player1, cpuPlayer &player2)
{
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        int temp = 0;
        cout<< "Player 1’s turn to guess." <<endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer, temp);
        if (win) return;
        else {
            if (temp == 1 && guess < player2.getHigh()) {
                player2.setHigh(guess - 1);
            }
            if (temp == 2 && guess > player2.getLow()) {
                player2.setLow(guess + 1);
            }
        }
        cout<< "Player 2’s turn to guess." <<endl;
        guess = player2.getGuess();
        win = checkForWin(guess, answer, temp);
        if (temp == 1 && guess < player2.getHigh()) {
            player2.setHigh(guess - 1);
        }
        if (temp == 2 && guess > player2.getLow()) {
            player2.setLow(guess + 1);
        }
    }
}

int main() {

    srand(time(0));

    std::cout << "Hello, World!" << std::endl;

    HumanPlayer human(1);
    cpuPlayer cpu(2);

    play(human, cpu);

    return 0;
}