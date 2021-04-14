#include <iostream>
using namespace std;

class VectorDouble {

    double* dblVecPtr;
    int max_count;
    int count;

public:

    // Constructors
    VectorDouble(): dblVecPtr(new double[50]), max_count(50), count(0) {};
    VectorDouble(int max): dblVecPtr(new double[max]), max_count(max), count(0) {if (max < 0) cout << "Invalid vector capacity" << endl; exit(1);}
    VectorDouble(const VectorDouble& v);

    // Destructor
    ~VectorDouble() {delete[] dblVecPtr; dblVecPtr = nullptr;}

    // Overloaded operators
    VectorDouble& operator=(const VectorDouble& v);
    bool operator==(const VectorDouble& v);

    // Accessors
    int capacity() const {return max_count;}
    int size() const {return count;}
    double value_at(int i) const {if (i >= 0 && i < count) return dblVecPtr[i]; else {cout << "Invalid index" << endl; exit(1);}}

    // Mutators
    void push_back(double el);
    void reserve(int newCapacity);
    void resize(int newSize);
    void change_value_at(double d, int i);
};

VectorDouble& VectorDouble::operator=(const VectorDouble& v) {
    if (&v != this) {
        delete[] dblVecPtr;
        max_count = v.max_count;
        count = v.count;
        dblVecPtr = new double[max_count];
        for (int i = 0; i < count; i++) {
            dblVecPtr[i] = v.dblVecPtr[i];
        }
    }

    return *this;
}

bool VectorDouble::operator==(const VectorDouble& v) {

    if (this->count != v.count)
        return false;

    for (int i = 0; i < count; i++) {
        if (dblVecPtr[i] != v.dblVecPtr[i])
            return false;
    }

    return true;
}

void VectorDouble::push_back(double el) {
    if (count == max_count) {
        reserve(2 * max_count);
        max_count *= 2;
    }
    dblVecPtr[count] = el;
    count++;
}

void VectorDouble::reserve(int newCapacity) {
    if (newCapacity > max_count) {

        double* tempPtr = new double[newCapacity];
        for (int i = 0; i < count; i++) {
            tempPtr[i] = dblVecPtr[i];
        }

        delete[] dblVecPtr;
        dblVecPtr = tempPtr;
        tempPtr = nullptr;

        max_count = newCapacity;
    }
}

void VectorDouble::resize(int newSize) {

    if (newSize > 0) {

        if (newSize > max_count) {
            reserve(newSize);
        }

        if (newSize > count) {
            for (int i = count; i < newSize; i++) {
                dblVecPtr[i] = 0.0;
            }
        }

        count = newSize;
    }
}

void VectorDouble::change_value_at(double d, int i) {
    if (i > 0 && i < count) {
        dblVecPtr[i] = d;
    }
}

VectorDouble::VectorDouble(const VectorDouble& v) {
    max_count = v.max_count;
    count = v.count;
    dblVecPtr = new double[max_count];
    for (int i = 0; i < count; i++) {
        dblVecPtr[i] = v.dblVecPtr[i];
    }
}

int main() {
    cout << "Hello, welcome to the vector maker!" << endl;
    VectorDouble vector;

    bool done = false;
    bool secondVec = false;

    while (!done) {

        int choice;

        cout << "What would you like to do next?" << endl;
        cout << "Here are your choices:" << endl;
        cout << "1. Add an item to the vector" << endl;
        cout << "2. Check out a particular item in the vector" << endl;
        cout << "3. Change an item in the vector" << endl;
        cout << "4. Get the size of the vector" << endl;
        cout << "5. Resize the vector" << endl;
        cout << "6. See how much memory is allocated for the vector" << endl;
        cout << "7. Reserve more memory for the vector" << endl;
        cout << "8. Copy your vector into a second vector" << endl;
        cout << "-1. Exit the vector maker" << endl;

        cin >> choice;

        switch (choice) {
            case -1:
                cout << "Thank you. goodbye." << endl;
                done = true;
                break;
            case 1:
                double value;
                cout << "Enter the value of your item" << endl;
                cin >> value;
                vector.push_back(value);
                break;
            case 2:
                int index;
                cout << "Enter the index of your item" << endl;
                cin >> index;
                cout << "The value is: " << vector.value_at(index) << endl;
                break;
            case 3:
                cout << "Enter the index of your item" << endl;
                cin >> index;
                cout << "Enter the value of your item" << endl;
                cin >> value;
                vector.change_value_at(value, index);
                break;
            case 4:
                cout << "The size is " << vector.size() << endl;
                break;
            case 5:
                cout << "Enter the new size of your vector" << endl;
                cin >> index;
                vector.resize(index);
                break;
            case 6:
                cout << "The vector has capacity for " << vector.capacity() << " doubles." << endl;
                break;
            case 7:
                cout << "Enter the new capacity of your vector" << endl;
                cin >> index;
                vector.reserve(index);
                break;
            case 8:
                VectorDouble v2(vector);
                cout << "Successfully copied vector." << endl;
                char choice2;
                cout << "Would you like to make sure your two vectors are equal? (y/n)" << endl;
                cin >> choice2;
                if (choice2 == 'y' || choice2 == 'Y') {
                    if (vector == v2)
                        cout << "Equal!" << endl;
                    else
                        cout << "Not equal" << endl;
                }
        }
    }

    return 0;
}

