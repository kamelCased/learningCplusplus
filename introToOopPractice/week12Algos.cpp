#include <iostream>
using namespace std;

// ----------------- EXAMPLE 1 ----------------------------


class B; //pre-definition

class A {
    int x;
public:
    A(int newx = 0): x(newx) {}
    friend class B; // Gives B direct access to A's private members
};

class B {
    A amember;
public:
    int getX() const { return amember.x; }
};

// ----------------- EXAMPLE 2 ----------------------------

// Needs big 3 to handle the dynamic array arr
class Elephants {
    int* arr;
    int count;
    int capacity;
public:
    // Constructors
    Elephants() : arr(new int[200]),count(0), capacity(200) {}
    Elephants(const Elephants& rhs) : arr(new int[200]), count(0), capacity(200) {*this = rhs;}
    //Destructor
    ~Elephants() {delete [] arr;}
    // Assignment Operator (must be a member)
    Elephants& operator=(const Elephants& rhs);
};
Elephants& Elephants::operator=(const Elephants& rhs) {
    // Check for self-assignment
    if (this == &rhs)
        return *this;
    // Copy all the values over
    for (int i = 0; i < count; i++)
        arr[i] = rhs.arr[i];
    // Return the copy elephant object
    return *this;
}

void func2(const Elephants& e) {
    cout << "Bring in da noise, bring in da Func2!" << endl;
}

int main1() {
    cout << "Creating an elephant!" << endl;
    Elephants e1;
    cout << "Now calling the func" << endl;
    func2(e1);
    cout << "Done!" << endl;
    return 0;
}

// ----------------- EXAMPLE 3 ----------------------------

class Thing {
    int *val;
public:
    // Constructors
    Thing(int newval = 0) : val(new int(newval)) {}
    Thing(const Thing& rhs) : val(new int(*rhs.val)) {}

    // Destructor
    ~Thing() { delete val; }

    // Assignment operator
    Thing& operator=(const Thing& rhs);

    // Overloaded operators
    Thing operator+(const Thing& rhs) const; // Member
    friend Thing operator-(const Thing& lhs, const Thing& rhs); // Friend

    // Accessors
    int getVal() const {return *val;} //const-ify the calling object
    const int getVal2() {return *val;} //const-ify the return value!

    //Mutator
    void setVal(int newval) { *val = newval; }

};
Thing& Thing::operator=(const Thing& rhs) {

    //test for self-assignment!
    if (this == &rhs)
        return *this;

    // Change value
    *val = *rhs.val;

    // Return modified object
    return *this;
}
Thing operator-(const Thing& lhs, const Thing& rhs) {

    // Create an object with the difference of the vals of the objects
    Thing temp(lhs.getVal() - rhs.getVal());

    // Return the difference object
    return temp;
}
Thing Thing::operator+ (const Thing& rhs)const {

    // Use copy constructor to instantiate a new object with val
    Thing temp = *this;

    // Add the other object's val to our val
    temp.val += *rhs.val;

    // Return the sum object
    return temp;
}
ostream& operator<<(ostream& outs, const Thing& rhs) {
    // output the object's value
    outs << rhs.getVal();
    // return the same stream by reference for chaining
    return outs;
}
// Acts like an accessor
void func(const Thing& one) {
    // Get the value of the Thing
    one.getVal();
}

int main2() {


    // Initialize a pointer to a Thing
    Thing* tptr = new Thing(100);

    // Output the value of the Thing pointed to
    cout << *tptr << endl;

    // Output the value of the Thing pointed to
    cout << tptr->getVal() << endl; // same as (*tptr).getVal()

    // free dynamic memory
    delete tptr;
    tptr = nullptr;

    // Initialize 3 Things
    Thing t1(5);
    Thing t2(10);
    Thing t3;

    // Do some operations with the Things
    t3 = t1 + t2; // t3.operator=(t1.operator+(t2));        creates a sum object of t1 and t2 using operator+, then assigns the value of t3 to equal that object's value using operator=
    t3 = t1 - t2; // t3.operator=(operator-(t1,t2));        creates a difference object of t1 and t2 using operator-, then assigns the value of t3 to equal that object's value using operator=
    t2 = t3; // t2.operator=(t3);                           Uses assignment operator= to change the value of t2 to equal the value of t3
    t1 = t2 = t3;
    cout  << t1 << " " << t2 << " " << t3  << endl; // (operator<<(operator<<(operator<<(operator<<(operator<<(cout, t1), " "), t2), " "), t3) endl);

    return 0;
}