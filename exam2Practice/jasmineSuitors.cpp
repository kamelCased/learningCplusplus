#include <iostream>
#include <vector>
using namespace std;

int getNumberOfSuitors();
int* lineUpSuitors(int suitors);
void findLove(int* suitorsArr, int suitors, int& loveOfHerLife);

int main() {

    // Get number of suitors
    int suitors = getNumberOfSuitors();

    // Line the suitors up
    int* suitorsArr = lineUpSuitors(suitors);

    // Determine who she'll marry
    int loveOfHerLife;
    findLove(suitorsArr, suitors, loveOfHerLife);

    // Get married
    std::cout << "My heart belongs to suitor #" << loveOfHerLife << "!" << std::endl;

    // Ghost all other suitors
    delete[] suitorsArr;
    suitorsArr = nullptr;

    return 0;
}

int getNumberOfSuitors() {

    int suitors;
    std::cout << "How many suitors does Jasmine have?" << std::endl;
    std::cin >> suitors;

    return suitors;
}

int* lineUpSuitors(int suitors) {

    int* suitorsArr = new int[suitors];

    for (int i = 1; i <= suitors; i++) {
        suitorsArr[i - 1] = i;
    }

    return suitorsArr;
}

void findLove(int* suitorsArr, int suitors, int& loveOfHerLife) {

    std::vector<int> suitorOptions;

    for (int i = 0; i < suitors; i++) {
       suitorOptions.push_back(suitorsArr[i]);
    }

    int count = 1;
    while (suitorOptions.size() > 1) {

        while (count % 7 != 0) {
            count++;
        }

        suitorOptions.erase(suitorOptions.begin() + count % suitorOptions.size());

        count++;
    }

    loveOfHerLife = suitorOptions[0];
}