#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node *link;
};

typedef Node* NodePtr;

void outputValues(NodePtr n);
void deleteValues(NodePtr& n);

int main() {

    NodePtr listPtr, tempPtr;

    listPtr = new Node;
    listPtr->name = "Emily";

    tempPtr = new Node;
    tempPtr->name = "James";

    listPtr->link = tempPtr;
    tempPtr->link = new Node;

    tempPtr = tempPtr->link;
    tempPtr->name = "Joules";
    tempPtr->link = NULL;

    outputValues(listPtr);

    NodePtr thirdPtr = new Node;
    thirdPtr->name = "Joshua";
    thirdPtr->link = tempPtr;
    listPtr->link->link = thirdPtr;

    cout << endl << "After adding:" << endl;
    outputValues(listPtr);

    delete tempPtr;
    thirdPtr->link = nullptr;

    cout << endl << "After deleting:" << endl;
    outputValues(listPtr);

    cout << endl << "After deleting all:" << endl;

    deleteValues(listPtr);

    outputValues(listPtr);

    return 0;
}

void outputValues(NodePtr n) {
    while (n != nullptr) {
        cout << n->name << endl;
        n = n->link;
    }
}

void deleteValues(NodePtr& n) {
    NodePtr temp;
    while (n != nullptr) {
        temp = n->link;
        delete n;
        n = temp;
    }
}
