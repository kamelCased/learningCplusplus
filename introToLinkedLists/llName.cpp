#include <iostream>
#include <string>
using namespace std;

class Node {

    string name;
    Node *link;

public:
    Node(string n): name(n), link(nullptr) {}

    void setName(const string& n) {name = n;}
    void setLink(Node* l) {link = l;}

    string getName() const {return name;}
    Node* getLink() const {return link;}
};

typedef Node* NodePtr;

class List {

    NodePtr head;

public:

    List(): head(nullptr) {}
    ~List() {clear();}

    NodePtr getHead() const {return head;}
    void insertAtHead(string s);
    void insert(string insert, string after);
    void insertAtEnd(string insert);

    void deleteNode(NodePtr prevNodeLocation);
    void pop_back();
    void clear();
};

void List::insertAtHead(string s) {

    if (head == nullptr) {
        head = new Node(s);
        return;
    }

    NodePtr temp = head->getLink();
    NodePtr temp2 = new Node(s);
    head->setLink(temp2);
    temp2->setLink(temp);
}

void List::insert(string insert, string after) {

    if (head == nullptr) {
        insertAtHead(insert);
        return;
    }

    else if (head->getLink() == nullptr) {
        insertAtEnd(insert);
        return;
    }

    NodePtr temp = head;
    while (temp->getName() != after) {
        temp = temp->getLink();
    }
    NodePtr temp2 = new Node(insert);
    NodePtr temp3 = temp->getLink();
    temp->setLink(temp2);
    temp2->setLink(temp3);
}

void List::insertAtEnd(string insert) {

    NodePtr temp = head;
    NodePtr newNode = new Node(insert);

    if (temp == nullptr) {
        temp = newNode;
        return;
    }

    else {

        while (temp->getLink() != nullptr) {
            temp = temp->getLink();
        }

        temp->setLink(newNode);
        return;
    }
}

void List::deleteNode(NodePtr prevNodeLocation) {

    NodePtr temp = prevNodeLocation->getLink();
    prevNodeLocation->setLink(temp->getLink());
    delete temp;
}

void List::clear() {

    while(head != nullptr)  {
        NodePtr temp = head->getLink();
        delete head;
        head = temp;
    }
}

void List::pop_back() {

    NodePtr temp = head;

    if (temp == nullptr)
        return;

    if (temp->getLink() == nullptr) {
        delete temp;
        head = nullptr;
        return;
    }

    while(temp->getLink()->getLink() != nullptr) {
        temp = temp->getLink();
    }

    NodePtr temp2 = temp->getLink();
    delete temp2;
    temp->setLink(nullptr);
}


void outputList(const List& l);

int main() {

    List names;
    names.insertAtHead("Nehal");
    names.insertAtEnd("Wasfy");
    names.insertAtEnd("Amr");

    outputList(names);

    cout << endl << "After input:" << endl;
    names.insert("Momo", "Wasfy");
    outputList(names);

    cout << endl << "After delete:" << endl;
    names.pop_back();
    outputList(names);

    cout << endl << "After delete all:" << endl;
    names.clear();
    outputList(names);

    return 0;
}

void outputList(const List& l) {

    NodePtr np = l.getHead();

    while (np != nullptr) {
        cout << np->getName() << endl;
        np = np->getLink();
    }
}


