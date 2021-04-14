#include <iostream>
using namespace std;

class Thing {

	int item;

public:

    // Constructor
	Thing() { cout << "Thank you for using my class!" << endl; }

	// Mutator
	void setItem(int newItem) { item = newItem; }

	// Accessor
	int getItem() const { return item; }

	// Gets a pointer to the item
	int* getPointer() { return &item; }
};

// const reference parameter cannot be modified in function
void func1(const Thing& t) {
	cout << t.getItem() << endl;
}

// Non-const reference parameter can be modified in function
void func2(Thing& t) {
	cout << t.getItem() << endl;
	t.setItem(100);
}

// non-const value parameter can be modified in function but doesn't affect main object outside
void func3(Thing t) {
	cout << t.getItem() << endl;
    t.setItem(100);
}

// A function can have default parameter values
void func4(int x = 100) {
	cout << x << endl;
}

int main() {

    // Uses default parameter
	func4();
	// Uses programmer-defined parameter value
	func4(20);

	// Create two Things and set their values
	Thing one;
	one.setItem(100);
	Thing two;
	two.setItem(500);

	// Get the values of the items of the Things
	cout << one.getItem() << endl; //100
	cout << two.getItem() << endl; //500

	// Initialize a pointer to a thing object
	Thing* tptr = &one;

	// Get the value
	cout << (*tptr).getItem() << endl;
	cout << tptr->getItem() << endl; //Equivalent to line above
    //cout << *tptr.getItem() << endl; //Doesn't work because of precedence

	return 0;
}