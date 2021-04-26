#include <iostream>
using namespace std;

class LLNode {

    int data;
    LLNode* next;
    LLNode* prev;

public:

    LLNode(int d): data(d), next(nullptr), prev(nullptr) {}

    int getData() {return data;}
    LLNode* getNext() {return next;}
    LLNode* getPrev() {return prev;}

    void setData(int d) {data = d;}
    void setNext(LLNode* n) {next = n;}
    void setPrev(LLNode* p) {prev = p;}

    friend class LList;
};

class LList {

    LLNode* head;
    LLNode* tail;

public:

    LList(): head(nullptr), tail(nullptr) {}
    LList(LLNode* h, LLNode* t): head(h), tail(t) {}
    LList(LLNode* h): head(h), tail(h) {}

    void setHead(LLNode* l) {head = l;}

    void reverseOrder();

    void addNode(int data);

    void clear();

    friend ostream& operator<<(ostream& o, LList l);
};

void LList::reverseOrder() {

    LLNode* temp = head;

    while (temp != nullptr) {

        LLNode* temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;

        temp = temp->prev;
    }

    temp = tail;
    tail = head;
    head = temp;
}

void LList::addNode(int data) {

    LLNode* node = new LLNode(data);

    node->setPrev(tail);
    tail->setNext(node);
    tail = node;
}

void LList::clear() {

    LLNode* temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
        delete temp->prev;
    }
}

ostream& operator<<(ostream& o, LList l) {

    LLNode* temp = l.head;

    while (temp != nullptr) {
        o << temp->getData() << endl;
        temp = temp->getNext();
    }

    temp = nullptr;

    return o;
}


int main() {

    LLNode* headPtr = new LLNode(1);
    LList list(headPtr);

    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    cout << list << endl;

    list.reverseOrder();

    cout << list << endl;

    list.clear();

    return 0;
}