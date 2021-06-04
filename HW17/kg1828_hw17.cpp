#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
            : data(data),
              color(RED),
              parent(nullptr),
              left(nullptr),
              right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {

    RBTNode<T>* greatgrandparent = point->parent;
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->left;

    if (greatgrandparent == nullptr) {
        root = parent;
    }
    else if (greatgrandparent->left == grandparent) {
        greatgrandparent->left = parent;
    }
    else if (greatgrandparent->right == grandparent) {
        greatgrandparent->right = parent;
    }
    parent->parent = greatgrandparent;

    RBTNode<T>* oldRightChild = parent->right;
    parent->right = grandparent;
    grandparent->parent = parent;
    grandparent->left = oldRightChild;
    if (oldRightChild != nullptr)
        oldRightChild->parent = grandparent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T>* greatgrandparent = point->parent;
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->right;

    if (greatgrandparent == nullptr) {
        root = parent;
    }
    else if (greatgrandparent->left == grandparent) {
        greatgrandparent->left = parent;
    }
    else if (greatgrandparent->right == grandparent) {
        greatgrandparent->right = parent;
    }
    parent->parent = greatgrandparent;

    RBTNode<T>* oldLeftChild = parent->left;
    parent->left = grandparent;
    grandparent->parent = parent;
    grandparent->right = oldLeftChild;
    if (oldLeftChild != nullptr)
        oldLeftChild->parent = grandparent;
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {

    RBTNode<T>* curr_node = point;
    if (curr_node != nullptr && curr_node->color == BLACK && curr_node->left != nullptr && curr_node->left->color == RED && curr_node->right != nullptr && curr_node->right->color == RED) {

        // Make grandparent red and parent/uncle black
        curr_node->color = RED;
        curr_node->right->color = BLACK;
        curr_node->left->color = BLACK;

        if (curr_node->parent != nullptr && curr_node->parent->color == RED) {

            if (curr_node->parent->left == curr_node) {

                if (curr_node->parent->parent != nullptr && curr_node->parent->parent->left == curr_node->parent)
                    singleCR(curr_node->parent->parent);
                else
                    doubleCCR(curr_node->parent->parent);
            }
            else {
                if (curr_node->parent->parent != nullptr && curr_node->parent->parent->right == curr_node->parent)
                    singleCCR(curr_node->parent->parent);
                else
                    doubleCR(curr_node->parent->parent);
            }
            curr_node->parent->color = BLACK;
        }
    }

    // leaf location is found so insert node
    if (point == nullptr) {

        // Create the new node and modify the pointer
        point = new RBTNode<T>(toInsert);
        point->parent = parent;

        // Modify the parent's pointer if appropriate
        if (parent == nullptr) {
            root = point;
        }
        else if (point->data < parent->data) {
            parent->left = point;
        }
        else {
            parent->right = point;
        }

        // Traverse up the tree and ensure Red-Black properties are met
        RBTNode<T>* curr_node = point;

        // Red parent
        if (curr_node->parent != nullptr && curr_node->parent->color == RED)  {

            // Go to grandparent
            curr_node = curr_node->parent->parent;

            // Parent is grandparent's left child
            if (curr_node != nullptr && curr_node->left == parent) {

                //  if uncle is black
                if (curr_node->right == nullptr || curr_node->right->color == BLACK) {

                    // If inserted child is outside, single rotation
                    if (parent->left == point) {
                        singleCR(curr_node);
                    }

                    // If inserted child is inside, double rotation
                    else {
                        doubleCR(curr_node);
                    }
                }

                // Uncle is red
                else {

                    // Make grandparent red and parent/uncle black
                    curr_node->color = RED;
                    curr_node->right->color = BLACK;
                    curr_node->left->color = BLACK;
                }
            }

            // Parent is grandparent's right child
            else if (curr_node != nullptr && curr_node->right == parent) {

                // Uncle is black
                if (curr_node->left == nullptr || curr_node->left->color == BLACK) {

                    // If inserted child is outside, single rotation
                    if (parent->right == point) {
                        singleCCR(curr_node);
                    }
                    // If inserted child is inside, double rotation
                    else {
                        doubleCCR(curr_node);
                    }
                }

                // Uncle is red
                else {

                    // Make grandparent red and parent/uncle black
                    curr_node->color = RED;
                    curr_node->right->color = BLACK;
                    curr_node->left->color = BLACK;
                }
            }
        }

        // Always check if red root and change it to black
        if (root->color == RED) {
            root->color = BLACK;
        }
    }

    else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    }

    else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}
