/*
 a Racer class to
store information about each race participant. The class should store the
racer’s name, bib number, finishing position, and all of his or her split
times as recorded by the RFID sensors. You can choose appropriate structures
to store this information. Include appropriate functions to access or
change the racer’s information, along with a constructor. Make an array or
vector of Racer objects to store the entire race results.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Racer {
    string name;
    int bibNumber;
    int finishPos;
    vector<int> splitTimes;

public:
    Racer(): name(""), bibNumber(-1), finishPos(-1) {};
    Racer(string n, int b): name(n), bibNumber(b), finishPos(-1) {};

    void add_lap(int lapTime) {if (lapTime > 0) splitTimes.push_back(lapTime);}
    double get_lapTime(int lapNumber) {if (lapNumber > 0 && lapNumber < splitTimes.size()) return splitTimes[lapNumber]; else {cout << "Invalid lap"; exit(1);}}
    int get_lapNumber() {return splitTimes.size();}

    int get_bibNumber() const {return bibNumber;}
    void set_bibNumber(int newNum) {bibNumber = newNum;}

    string get_name() {return name;}

    int get_position() const {return finishPos;}
    void set_position(int pos) {if (pos > 0) finishPos = pos;}

    friend ostream& operator<< (ostream& o, const Racer& r);
    friend istream& operator>> (istream& i, Racer& r);
};

ostream& operator<< (ostream& o, const Racer& r) {
    o << "P" << r.finishPos << ".  #" << r.bibNumber << " " << r.name << endl;
    return o;
}

istream& operator>> (istream& i, Racer& r) {
    char hash;
    int b;
    string n;
    i >> hash >> b >> n;

    r.bibNumber = b;
    r.name = n;

    return i;
}

void simulateRace(vector<Racer>& racers, int laps);

int main() {

    int racerCount;
    cout << "Hello, please enter the number of racers:" << endl;
    cin >> racerCount;

    vector<Racer> racers;

    for (int i = 1; i <= racerCount; i++) {
        Racer nextRacer;
        cout << "Please enter racer " << i << " in the format #XX RACER_NAME:" << endl;
        cin >> nextRacer;

        racers.push_back(nextRacer);
    }

    simulateRace(racers, 10);

    cout << "Finished positions: " << endl;
    for (auto racer : racers) {
        cout << racer;
    }

    return 0;
}

void simulateRace(vector<Racer>& racers, int laps) {

    vector <int> positionsTaken;

    for (auto& r: racers) {
        for (int i = 0; i < laps; i++) {
            r.add_lap(rand() % 100);
        }
        bool done = false;
        while (!done) {
            int position = rand() % racers.size() + 1;
            bool finished = true;
            for (int j = 0; j < positionsTaken.size(); j++) {
                if (positionsTaken[j] == position)
                    finished = false;
            }
            if (finished) {
                r.set_position(position);
                positionsTaken.push_back(position);
                done = true;
            }
        }
    }
}
