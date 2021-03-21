#include <iostream>

int countHandshakes (int people);

int main() {

    int people;
    std::cout << "Please enter the number of people at the party: ";
    std::cin >> people;

    // count number of handshakes
    int shakes = countHandshakes (people);

    // output result
    std::cout << "If each of the " << people << " people shake each other's hands once, there are a total of ";
    std::cout << shakes << " handshakes." << std::endl;

    return 0;
}

int countHandshakes (int people) {

    if (people == 1) {
        return 0;
    }
    
    if (people == 2) {
        return 1;
    }

    else {
        return countHandshakes (people - 1) + (people - 1);
    }
}

