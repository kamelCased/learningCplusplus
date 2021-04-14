#include <iostream>
#include <string>
using namespace std;

class Person {

    string name;
    Person* spouse; // Can point to another object!

public:
    
    // Contructor (person is born)
    Person(string newName) : name(newName),spouse(nullptr) {}

    // Accessors
    string getName() const { return name; }
    string getSpouseName() const;

    // Mutators
    void changeName(string newname) { name = newname; }
    bool marry(Person& other);
};

bool Person::marry(Person& other) {

    // Already married
    if (spouse != nullptr || other.spouse != nullptr)
        return false;

    // This person marries other
    spouse = &other;

    // Other person marries this person
    other.spouse = this; //this is ok because marry has access to the other object's spouse variable (since it's same class)

    // Holy matrimony
    return true;
}

string Person::getSpouseName() const {

    // Not married
    if (spouse == nullptr)
        return "";

    // Married
    return spouse->name;
}