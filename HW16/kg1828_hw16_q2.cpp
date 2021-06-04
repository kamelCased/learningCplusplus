// Assignment: NYU Tandon Bridge Homework 16 Question 2
// Author: Kamel Gazzaz
// Due date: 05/07/2021
#include <iostream>
#include <vector>
using namespace std;

// --------------- Queue class ------------------------

template <class T>
class BBQueue {

    vector<T> data;
    int startPos;

public:

    // Constructor
    BBQueue(): startPos(0) {}

    // Helper functions
    int size() const {return data.size() - startPos;}
    bool isEmpty() const {return size() == 0;}
    void clear();

    // Useful queue mutators
    void enqueue(T newData) {data.push_back(newData);}
    void dequeue();

    // Useful queue accessors
    T front() const;
    T back() const;

    // Helper for output
    template<class S>
    friend ostream& operator<<(ostream& os, BBQueue<S> queue);
};

// --------------- MAIN ------------------
// Note to grader: I took this driver code from a fellow student on Discord (author: Muhammad Asavir) to test my program

int main(int argc, char const *argv[]) {

    // Testing/driver code.
    BBQueue<int> queue;

    // Perform a size check.
    std::cout << "Size: " << queue.size() << std::endl << std::endl;

    // Push some stuff and then check front/back.
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(6);
    queue.enqueue(2);

    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;
    std::cout << "Size: " << queue.size() << std::endl << std::endl;

    // Pop a few things and then see what happens.
    queue.dequeue();
    queue.dequeue();

    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;
    std::cout << "Size: " << queue.size() << std::endl << std::endl;

    // Pop remaining and check if it's empty/size is good.
    queue.dequeue();
    queue.dequeue();

    std::cout << "Size: " << queue.size() << std::endl;
    std::cout << "Empty: " << queue.isEmpty() << std::endl << std::endl;

    // A bit more testing.
    queue.enqueue(3);
    queue.enqueue(6);
    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;
    std::cout << "Empty: " << queue.isEmpty() << std::endl;
    std::cout << "Size: " << queue.size() << std::endl << std::endl;

    // Final set.
    queue.dequeue();
    queue.dequeue();

    std::cout << "Size: " << queue.size() << std::endl;
    std::cout << "Empty: " << queue.isEmpty() << std::endl;

    return 0;
}

// ------------------- Function definitions ------------------------

template <class T>
void BBQueue<T>::clear() {

    // Remove all nodes
    while (!isEmpty()) {
        data.pop_back();
    }
}

template <class T>
void BBQueue<T>::dequeue() {

    // "Remove" the element by updating the start position
    if (!isEmpty()) {
        ++startPos;
    }

    // If empty, reset the queue
    else {
        clear();
    }
}

template <class T>
T BBQueue<T>::front() const {

    // Return first item in the queue
    if (!isEmpty()){
        return data[startPos];
    }

    // queue is empty
    return T();
}

template <class T>
T BBQueue<T>::back() const {

    // Return last item in the queue
    if (!isEmpty()){
        return data[data.size() - 1];
    }

    // queue is empty
    return T();
}

// Not needed here, useful for testing
template <class T>
ostream& operator<<(ostream& os, BBQueue<T> queue) {

    // Output all elements of the queue to the stream
    for (int i = queue.startPos; i < queue.data.size(); ++i) {
        os << queue.data[i] << endl;
    }

    return os;
}