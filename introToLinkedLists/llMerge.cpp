#include <iostream>
using namespace std;

class LList;

class LLNode {

    int data;
    LLNode* next;

public:

    LLNode(int d): data(d) {}

    friend class LList;
    friend LList& mergeLists(LList& l1, LList& l2);
    friend ostream& operator<<(ostream& o, LList l);
};

class LList {

    LLNode* head;

public:

    LList(): head(nullptr) {}
    LList(int d): head(new LLNode(d)) {}

    LLNode* getHead() const {return head;}

    void addNode(int n);

    void setHead(LLNode* h) {head = h;}

    void clear();

    friend ostream& operator<<(ostream& o, LList l);
};
void LList::addNode(int n) {

    LLNode* temp = head;

    if (temp == nullptr) {
        temp = new LLNode(n);
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new LLNode(n);
}
void LList::clear() {

    LLNode* curr = head;
    while (curr != nullptr) {
        LLNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

LList& mergeLists(LList& l1, LList& l2) {

    LLNode* l1Ptr = l1.getHead();
    LLNode* l2Ptr = l2.getHead();

    LLNode* curr;
    bool firstOrSecond;
    if (l1Ptr->data < l2Ptr->data){
        curr = l1Ptr;
        l1Ptr = l1Ptr->next;
        firstOrSecond = true;
    }
    else {
        curr = l2Ptr;
        l2Ptr = l2Ptr->next;
        firstOrSecond = false;
    }

    while (l1Ptr != nullptr && l2Ptr != nullptr) {

        if (l1Ptr->data < l2Ptr->data) {
            curr->next = l1Ptr;
            l1Ptr = l1Ptr->next;
        }

        else {
            curr->next = l2Ptr;
            l2Ptr = l2Ptr->next;
        }

        curr = curr->next;
    }

    while (l1Ptr != nullptr) {
        curr->next = l1Ptr;
        l1Ptr = l1Ptr->next;
        curr = curr->next;
    }

    while (l2Ptr != nullptr) {
        curr->next = l2Ptr;
        l2Ptr = l2Ptr->next;
        curr = curr->next;
    }

    if (firstOrSecond)
        return l1;

    return l2;
}

ostream& operator<<(ostream& o, LList l) {

    LLNode* temp = l.head;
    while (temp != nullptr) {
        o << temp->data << endl;
        temp = temp->next;
    }

    return o;
}

int main() {
    LList l1(1);
    l1.addNode(3);
    l1.addNode(5);
    l1.addNode(7);

    cout << l1 << endl;

    LList l2(2);
    l2.addNode(4);
    l2.addNode(6);
    l2.addNode(8);

    cout << l2 << endl;

    LList final = mergeLists(l1, l2);

    cout << final << endl;

    final.clear();

    return 0;
}
