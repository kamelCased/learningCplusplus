#include <iostream>
#include <string>
using namespace std;

class DynArray {

    // Private member variables
	int* data;
	int size;
	int capacity;
    // Private member functions
	void resize(int newsize);

public:
    // Constructors
	DynArray() :size(0), capacity(5) { data = new int[capacity]; }
	DynArray(const DynArray& rhs) : size(0), capacity(5), data(new int[capacity]) { *this = rhs; } //Copy constructor calls assignment operator

	// Destructor
    ~DynArray() { delete[] data; }

    // Assigment Operator
    DynArray& operator=(const DynArray& rhs);

    // Mutators
	void push_back(int newval);
	void clear() { size = 0; }
	int pop_back();
};
void DynArray::resize(int newsize) {

    // Create a temporary array with the desired size
    int* temp = new int[newsize];

    // Copy over elements
    for (int i = 0; i < min(size, newsize); i++)
        temp[i] = data[i];

    // Delete the original array and make it point to the new one
    delete[] data;
    data = temp;

    // array increased in size
    if (size < newsize)
        capacity = newsize;

    // the array was shrunk and now has less items in it
    else
        size = capacity = newsize;
}
int DynArray::pop_back() {

    // remove last value and return it
    if (size >= 1)
        return data[--size];

    // can't pop back from empty or negative sized array
    else
        exit(1);
}
void DynArray::push_back(int newval) {

    // resize if necessary
    if (size == capacity)
        resize(size * 2+1);

    // Add the value and increment the size
    data[size++] = newval;
}
DynArray& DynArray::operator=(const DynArray& rhs) {
    //Test for self-assignment
    if (this == &rhs)
        return *this;

    // Clear initial values
    delete[] data;

    // Update to new values
    size = rhs.size;
    capacity = rhs.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
        data[i] = rhs.data[size];

    // Return the object
    return *this;
}

