#include <iostream>
#include <vector>
using namespace std;

class Voter {
    int voterID;
    char vote1, vote2, vote3, vote4;

public:
    Voter(int id, string votes): voterID(id), vote1(votes[0]), vote2(votes[1]), vote3(votes[2]), vote4(votes[3]) {}

    int getID() const {return voterID;}
    int getVote1() const {return vote1;}
    int getVote2() const {return vote2;}
    int getVote3() const {return vote3;}
    int getVote4() const {return vote4;}

    bool operator<(const Voter& rhs) const {return voterID < rhs.voterID;}
    friend ostream& operator<<(ostream& o, const Voter& v);
};

ostream& operator<<(ostream& o, const Voter& v) {
    o << v.voterID << "\t\t" << v.vote1 << v.vote2 << v.vote3 << v.vote4 << endl;
    return o;
}

vector<Voter> getInput () {
    cout << "Welcome to the elections office:" << endl;
    cout << "Choices for first vote: A, B, C" << endl;
    cout << "Choices for second vote: D, E" << endl;
    cout << "Choices for third vote: F, G" << endl;
    cout << "Choices for fourth vote: H, I" << endl;

    vector<Voter> voters;
    bool electionsOver = false;
    while (!electionsOver) {
        char choice;
        cout << "Would you like to enter a voter? (y/n)" << endl;
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            electionsOver = true;
        }
        else {
            int id;
            string votes;
            cout << "Enter the voter in the following format" << endl;
            cout << "VoterID Vote1Vote2Vote3Vote4" << endl;
            cin >> id >> votes;
            Voter v(id, votes);
            voters.push_back(v);
        }
    }

    return voters;
}

vector<double> getPercentages(vector<Voter> voters, vector<char> choices, int proposition) {
    vector<double> tally;
    for (auto choice: choices) {
        int votes = 0;
        for (auto voter: voters) {
            if (proposition == 1) {
                if (voter.getVote1() == choice)
                    votes++;
            }
            else if (proposition == 2) {
                if (voter.getVote2() == choice)
                    votes++;
            }
            else if (proposition == 3) {
                if (voter.getVote3() == choice)
                    votes++;
            }
            else if (proposition == 4) {
                if (voter.getVote4() == choice)
                    votes++;
            }
        }
        tally.push_back(votes);
    }

    int sum = 0;
    for (auto el: tally)
        sum += el;

    for (auto& el: tally) {
        el /= double(sum);
        el *= 100;
    }

    return tally;
}

void outputResults (vector<char> choices, vector<double> percentages) {
    cout << "Choice\tPercentage" << endl;
    for (int i = 0; i < choices.size(); i++)
        cout << choices[i] << ":\t\t" << percentages[i] << "%" << endl;
}

int main() {

    vector<Voter> voters = getInput();

    sort(voters.begin(), voters.end());

    cout << "ID\t\tVotes" << endl;
    for (auto voter: voters)
        cout << voter;

    cout << endl << "Summary:" << endl;
    cout << "--------" << endl;

    vector<char> choices1 = {'A', 'B', 'C'};
    vector<double> v1Percentages = getPercentages(voters, choices1, 1);

    cout << "Proposition 1:" << endl;
    outputResults(choices1, v1Percentages);

    vector<char> choices2 = {'D', 'E'};
    vector<double> v2Percentages = getPercentages(voters, choices2, 2);

    cout << "Proposition 2:" << endl;
    outputResults(choices2, v2Percentages);

    vector<char> choices3 = {'F', 'G'};
    vector<double> v3Percentages = getPercentages(voters, choices3, 3);

    cout << "Proposition 3:" << endl;
    outputResults(choices3, v3Percentages);

    vector<char> choices4 = {'H', 'I'};
    vector<double> v4Percentages = getPercentages(voters, choices4, 4);

    cout << "Proposition 4:" << endl;
    outputResults(choices4, v4Percentages);

    return 0;
}

