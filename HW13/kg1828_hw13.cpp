// Assignment: NYU Tandon Bridge Homework 13
// Author: Kamel Gazzaz
// Due date: 04/16/2021
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// --------- Useful constants ------------

// Directions
const int UP = 0;
const int DOWN = 1;
const int RIGHT = 2;
const int LEFT = 3;
const int DIRECTION_OPTIONS = 4;
const int INVALID_POSITION = -1;

// Symbols
const char EMPTY = '-';
const char ANT = 'o';
const char DOODLEBUG = 'X';

// Survival and Reproduction cycle
const int ANT_BREEDING_CYCLE = 3;
const int DOODLEBUG_BREEDING_CYCLE = 8;
const int DOODLEBUG_STARVING_CYCLE = 3;

// World Initial Parameters
const int GRID_SIZE = 20;
const int DOODLE_COUNT = 5;
const int ANT_COUNT = 100;
const int FIRST_SLOT = 0;
const int LAST_SLOT = GRID_SIZE - 1;

// Miscellaneous
const int PERCENT = 100;
const int NONE = 0;

// Pre-declaration
class World;

// -------- ORGANISM CLASS ---------------

class Organism {

private:

    // Type
    char symbol;

    // Age
    int breedingCount;

    // Habitat
    int x_coord;
    int y_coord;

    // Behavior
    bool alreadyMoved;

public:

    // Constructors
    Organism(int x, int y, char s): x_coord(x), y_coord(y), breedingCount(NONE), symbol(s), alreadyMoved(false) {};

    // Accessors
    int getXCoordinate() const {return x_coord;}
    int getYCoordinate() const {return y_coord;}
    int getBreedingCount() const {return breedingCount;}
    char getSymbol() const {return symbol;}
    bool getMoved() const {return alreadyMoved;}

    // Mutators
    void setXCoordinate(int coord) {x_coord = coord;}
    void setYCoordinate(int coord) {y_coord = coord;}
    void setBreedingCount(int time) {breedingCount = time;}
    void setMoved(bool moveStatus) {alreadyMoved = moveStatus;}

    // Organism actions
    virtual void move (World& world) = 0;
    virtual void breed (World& world) = 0;
    virtual void starve(World& world) = 0;
};

// -------------- ANT CLASS -----------------

class Ant: public Organism {

public:

    // Ant birth instructions
    Ant(int x, int y): Organism(x,y, ANT) {};

    // Ant Actions
    virtual void move (World& world);
    virtual void breed(World& world);
    virtual void starve(World& world){}; // Doesn't do anything just makes doodles easier to manipulate with Organism pointers
};

// -------------- DOODLEBUG CLASS -----------------

class DoodleBug: public Organism {

private:

    int hungerCount;

public:

    // DoodleBug birth instructions
    DoodleBug(int x, int y): Organism(x,y, DOODLEBUG), hungerCount(NONE) {};

    // DoodleBug Actions
    virtual void move (World& world);
    virtual void breed(World& world);
    virtual void starve(World& world);

    // Homeostatic mechanisms
    int getHungerCount() const {return hungerCount;}
    void incrementHungerCount() {++hungerCount;}
    void resetHungerCount() {hungerCount = NONE;}
};

// ------------- WORLD CLASS -----------------
class World {

private:

    // Closed world configuration
    vector<vector<Organism*>> grid;

public:

    // Create world
    World(int gridSize, int doodles, int ants);

    // Get habitat status
    Organism* getPositionOccupancy(int x, int y) const {return grid[x][y];}

    // Update habitat status
    void setPositionOccupancy(int x, int y, Organism* organism);

    // Find an ant in adjacent slot
    void findAnt(int curr_x, int curr_y, int& next_x, int& next_y) const;

    // Find an open adjacent slot
    void findOpenSlot(int curr_x, int curr_y, int& open_x, int& open_y) const;

    // Update world
    void nextTimeStep();

    // Show world
    void display();

    // Destroy world
    ~World();
};

// ---------------- MAIN -------------------

int main() {

    // Info for user
    cout << "Welcome to the NYU Tandon Wildlife Reserve." << endl;
    cout << "Here we have many doodlebugs and ants coexisting." << endl;
    cout << "Doodlebugs are represented by " << DOODLEBUG << endl;
    cout << "Ants are represented by " << ANT << endl;
    cout << "You can see how their respective populations evolve over time by pressing enter." << endl;
    cout << "You can end your visit by entering (the letter) q" << endl;

    bool firstTry = true;
    bool done = false;
    srand(time(0));

    // Create and output initial world
    World tandonWildlifeReserve(GRID_SIZE, DOODLE_COUNT, ANT_COUNT);
    tandonWildlifeReserve.display();

    // World
    while (!done) {

        // No need to reexplain choice
        if (firstTry){
            firstTry = false;
        }

        // Reexplain choice
        else {

            // What next
            string choice;
            cout << "Press enter to go again. Input q to end" << endl;
            getline(cin, choice);

            // End simulation
            if (choice == "q") {
                done = true;
                cout << "Thank you for visiting the NYU Tandon Wildlife Reserve. We hope you learned a lot about natural phenomena." << endl;
            }

            // Run simulation
            else {
                tandonWildlifeReserve.nextTimeStep();
                tandonWildlifeReserve.display();
            }
        }
    }

    return 0;
}

// ----------------- ANT FUNCTION DEFINITIONS --------------------

void Ant::move (World& world) {

    int x = INVALID_POSITION, y = INVALID_POSITION;
    world.findOpenSlot(getXCoordinate(), getYCoordinate(), x, y);

    // Found new territory
    if (x != INVALID_POSITION && y != INVALID_POSITION) {

        // Abandon current territory
        world.setPositionOccupancy(getXCoordinate(), getYCoordinate(), nullptr);

        // Move to new territory
        this->setXCoordinate(x);
        this->setYCoordinate(y);
        world.setPositionOccupancy(x, y, this);
    }
}

void Ant::breed(World& world) {

    // Breeding season is upon us
    if (getBreedingCount() == ANT_BREEDING_CYCLE) {

        // Find a birthplace for the baby ant
        int birthPlaceX = INVALID_POSITION, birthPlaceY = INVALID_POSITION;
        world.findOpenSlot(getXCoordinate(), getYCoordinate(), birthPlaceX, birthPlaceY);

        // Spawn a baby ant
        if (birthPlaceX != INVALID_POSITION && birthPlaceY != INVALID_POSITION) {
            Ant* baby = new Ant(birthPlaceX, birthPlaceY);
            world.setPositionOccupancy(birthPlaceX, birthPlaceY, baby);
        }

        // Mother ant survived to next breeding cycle
        setBreedingCount(NONE);
    }
}

// ---------------- DOODLEBUG FUNCTION DEFINITIONS --------------------

void DoodleBug::starve(World& world) {

    // Doodlebug hasn't eaten in 3 time steps
    if (getHungerCount() == DOODLEBUG_STARVING_CYCLE) {

        // Doodlebug starves and dies
        delete this;
        world.setPositionOccupancy(getXCoordinate(), getYCoordinate(), nullptr);
    }
}

void DoodleBug::breed(World& world) {

    // Doodlebug breeding season is upon us
    if (getBreedingCount() != NONE && getBreedingCount() % DOODLEBUG_BREEDING_CYCLE == NONE) {

        // Find a birthplace for the baby doodlebug
        int birthPlaceX = INVALID_POSITION, birthPlaceY = INVALID_POSITION;
        world.findOpenSlot(getXCoordinate(), getYCoordinate(), birthPlaceX, birthPlaceY);

        // Spawn a baby doodlebug
        if (birthPlaceX != INVALID_POSITION && birthPlaceY != INVALID_POSITION) {
            Organism* baby = new DoodleBug(birthPlaceX, birthPlaceY);
            world.setPositionOccupancy(birthPlaceX, birthPlaceY, baby);
        }
    }
}

void DoodleBug::move (World& world) {

    // Seek nearby prey
    int x = INVALID_POSITION, y = INVALID_POSITION;
    world.findAnt(getXCoordinate(), getYCoordinate(), x, y);

    // Found an ant
    if (x != INVALID_POSITION, y != INVALID_POSITION) {

        // Leave habitat
        world.setPositionOccupancy(getXCoordinate(), getYCoordinate(), nullptr);

        // Hunt down ant
        this->setXCoordinate(x);
        this->setYCoordinate(y);

        // Eat ant
        delete world.getPositionOccupancy(x, y);
        world.setPositionOccupancy(x, y, this);

        // Hunger satisfied
        resetHungerCount();
    }

    else  {

        // Doodlebug doesn't eat
        incrementHungerCount();

        // Decide on where to forage
        world.findOpenSlot(getXCoordinate(), getYCoordinate(), x, y);

        // Found possible terrain to explore
        if (x != INVALID_POSITION, y != INVALID_POSITION) {

            // Abandon old habitat
            world.setPositionOccupancy(getXCoordinate(), getYCoordinate(), nullptr);

            // Forage in new habitat
            world.setPositionOccupancy(x, y, this);
            this->setXCoordinate(x);
            this->setYCoordinate(y);
        }
    }
}

// ---------------- WORLD FUNCTION DEFINITIONS ---------------------

World::World(int gridSize, int doodles, int ants) {

    // Create random world with 5 doodlebugs and 100 ants
    int doodleBugsRemaining = doodles;
    int antsRemaining = ants;
    int emptyCellsRemaining = gridSize * gridSize - doodles - ants;
    double doodleBugPercentage = doodleBugsRemaining / double(doodleBugsRemaining + antsRemaining + emptyCellsRemaining) * PERCENT;
    double antPercentage = antsRemaining / double(doodleBugsRemaining + antsRemaining + emptyCellsRemaining) * PERCENT;

    // Loop through grid positions
    for (int rows = 0; rows < gridSize; rows++) {

        vector<Organism*> row;

        for (int cols = 0; cols < gridSize; cols++) {

            // Establish a doodlebug, ant, or neither as position inhabitant
            int critter = rand() % PERCENT;

            // Doodlebug
            if (critter < doodleBugPercentage  && doodleBugsRemaining > NONE) {
                Organism* occ = new DoodleBug(rows, cols);
                row.push_back(occ);
                doodleBugsRemaining--;
            }

            // Ant
            else if (critter < doodleBugPercentage + antPercentage && antsRemaining > NONE) {
                Organism* occ = new Ant(rows, cols);
                row.push_back(occ);
                antsRemaining--;
            }

            // Empty cell
            else if (emptyCellsRemaining) {
                row.push_back(nullptr);
                emptyCellsRemaining--;
            }

            // Fill leftovers from remaining ants
            else if (antsRemaining > NONE) {
                Organism* occ = new Ant(rows, cols);
                row.push_back(occ);
                antsRemaining--;
            }

            // Fill leftovers from remaining doodlebugs
            else if (doodleBugsRemaining > NONE) {
                Organism* occ = new DoodleBug(rows, cols);
                row.push_back(occ);
                doodleBugsRemaining--;
            }
        }

        grid.push_back(row);
    }
}

void World::findAnt(int curr_x, int curr_y, int& next_x, int& next_y) const {

    // Check up
    if (curr_y > FIRST_SLOT && getPositionOccupancy(curr_x, curr_y - 1) != nullptr && getPositionOccupancy(curr_x, curr_y - 1)->getSymbol() == ANT) {
        next_x = curr_x;
        next_y = curr_y - 1;

    }

    // Check down
    else if (curr_y < LAST_SLOT && getPositionOccupancy(curr_x, curr_y + 1) != nullptr && getPositionOccupancy(curr_x, curr_y + 1)->getSymbol() == ANT) {
        next_x = curr_x;
        next_y = curr_y + 1;
    }

    // Check left
    else if (curr_x > FIRST_SLOT && getPositionOccupancy(curr_x - 1, curr_y) != nullptr && getPositionOccupancy(curr_x - 1, curr_y)->getSymbol() == ANT) {
        next_x = curr_x - 1;
        next_y = curr_y;
    }

    // Check right
    else if (curr_x < LAST_SLOT && getPositionOccupancy(curr_x + 1, curr_y) != nullptr && getPositionOccupancy(curr_x + 1, curr_y)->getSymbol() == ANT) {
        next_x = curr_x + 1;
        next_y = curr_y;
    }
}

void World::findOpenSlot(int curr_x, int curr_y, int& open_x, int& open_y) const {

    bool finished = false;
    bool checkedRight = false;
    bool checkedLeft = false;
    bool checkedUp = false;
    bool checkedDown = false;

    // Look for open slots
    while (!finished) {

        // No more options
        if (checkedUp && checkedDown && checkedRight && checkedLeft) {
            finished = true;
        }

        // More options
        else {

            // Choose direction at random
            int direction = rand() % DIRECTION_OPTIONS;

            switch (direction) {

                case UP:

                    // Up available
                    if (curr_y > FIRST_SLOT && getPositionOccupancy(curr_x, curr_y - 1) == nullptr) {
                        open_x = curr_x;
                        open_y = curr_y - 1;
                        finished = true;
                    }

                    // Up unavailable
                    else {
                        checkedUp = true;
                    }
                    break;

                case DOWN:

                    // Down available
                    if (curr_y < LAST_SLOT && getPositionOccupancy(curr_x, curr_y + 1) == nullptr) {
                        open_x = curr_x;
                        open_y = curr_y + 1;
                        finished = true;
                    }

                    // Down unavailable
                    else {
                        checkedDown = true;
                    }
                    break;

                case LEFT:

                    // Left available
                    if (curr_x > FIRST_SLOT && getPositionOccupancy(curr_x - 1, curr_y) == nullptr) {
                        open_x = curr_x - 1;
                        open_y = curr_y;
                        finished = true;
                    }

                    // Left unavailable
                    else {
                        checkedLeft = true;
                    }
                    break;

                case RIGHT:

                    // Right available
                    if (curr_x < LAST_SLOT && getPositionOccupancy(curr_x + 1, curr_y) == nullptr) {
                        open_x = curr_x + 1;
                        open_y = curr_y;
                        finished = true;
                    }

                    // Right unavailable
                    else {
                        checkedRight = true;
                    }
                    break;
            }
        }
    }
}

void World::setPositionOccupancy(int x, int y, Organism* organism) {
    grid[x][y] = organism;
}

void World::display() {

    // Rows
    for (const auto& vec: grid) {

        // Cols
        for (auto loc: vec) {

            // Populated
            if (loc != nullptr) {
                cout << loc->getSymbol() << "\t";
            }

            // Deserted
            else {
                cout << EMPTY << "\t";
            }
        }

        // New row
        cout << endl;
    }
}

void World::nextTimeStep() {

    // Doodlebugs make their move
    for (auto& vec: grid) {

        for (auto& doodle: vec) {

            if (doodle != nullptr && doodle->getSymbol() == DOODLEBUG && !doodle->getMoved()) {
                doodle->setBreedingCount(doodle->getBreedingCount() + 1);
                doodle->setMoved(true);
                doodle->move(*this);
            }
        }
    }

    // Ants make their move
    for (auto& vec: grid) {

        for (auto& ant: vec) {

            if (ant != nullptr && ant->getSymbol() == ANT && ant->getMoved() == false) {
                ant->setBreedingCount(ant->getBreedingCount() + 1);
                ant->setMoved(true);
                ant->move(*this);
            }
        }
    }

    // Doodlebugs breed or starve
    for (auto& vec: grid) {

        for (auto& doodle: vec) {

            if (doodle != nullptr && doodle->getSymbol() == DOODLEBUG) {
                doodle->breed(*this);
                doodle->starve(*this);
            }
        }
    }

    // Ants breed
    for (auto& vec: grid) {

        for (auto& ant: vec) {

            if (ant != nullptr && ant->getSymbol() == ANT) {
                ant->breed(*this);
            }
        }
    }

    // Remaining doodlebugs and ants successfully relocated
    for (auto& vec: grid) {

        for (auto& org: vec) {

            if (org != nullptr) {
                org->setMoved(false);
            }
        }
    }
}

World::~World() {

    // Natural disaster sweeps through all lands
    for (auto row: grid) {

        // From the north to the south
        for (auto organism: row) {

            // All organisms go extinct during the apocalypse
            delete organism;
            organism = nullptr;
        }
    }
}