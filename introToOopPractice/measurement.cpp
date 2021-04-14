class Measurement {
    // Private variables
    int feet;
    int inches;

    // Private helper function
    void normalize();

public:
    // Constructor
    Measurement(int newInches = 0, int newFeet = 0) :feet(newFeet), inches(newInches) { normalize(); }

    // Accessors
    int getFeet() const { return feet; }
    int getInches() const { return inches; }
    int getTotalInches()const { return 12 * feet + inches; }

    // Mutators
    void setFeet(int newFeet) { feet = newFeet; }
    void setInches(int newInches);

    // Overloaded operators
    Measurement operator+(const Measurement& rhs)const;
    Measurement& operator-=(const Measurement& rhs);
    Measurement operator++(int); //PostIncrement
    Measurement& operator++();   //PreIncrement
};
// post-increment denoted by int param
Measurement Measurement::operator++(int) {

    // Create an object storing current values
    Measurement temp = *this;

    // Modify values
    inches++;
    normalize();

    // Return object with original values
    return temp;
}
Measurement& Measurement::operator++() {

    // Modify the values
    inches++;
    normalize();

    // Return the same object with modified values
    return *this;
}
Measurement& Measurement::operator-=(const Measurement& rhs) {

    // Subtract rhs's measurement values from the measurement values
    feet -= rhs.feet;
    inches -= rhs.feet;
    normalize();

    // Return object
    return *this;
}

//Not a member or friend so this function doesn't have access to private!!!!
Measurement operator-(const Measurement& lhs, const Measurement& rhs) {

    // Create an object with measuring the difference of the two objects
    Measurement temp(lhs.getTotalInches() - rhs.getTotalInches());

    // return the difference object
    return temp;
}
Measurement Measurement::operator+(const Measurement& rhs) const {

    // Create a new object
    Measurement temp;

    // Set its values to be the sum of the two
    temp.feet = feet + rhs.feet;
    temp.inches = inches + rhs.inches;
    temp.normalize();

    // return the sum object
    return temp;
}
void Measurement::normalize() {

    // Convert overflow of inches to feet
    if (inches >= 12) {
        feet += inches / 12;
        inches = inches % 12;
    }
    // Convert feet to inches to cover shortage of inches
    else if (inches < 0) {
        feet += inches / 12 - 1;
        inches = 12 + (inches % 12);
    }
}
void Measurement::setInches(int newInches) {

    // Modify inches value
    inches = newInches;
    normalize();
}
