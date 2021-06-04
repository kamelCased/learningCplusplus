// Assignment: NYU Tandon Bridge Homework 16 Question 1
// Author: Kamel Gazzaz
// Due date: 05/07/2021
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// ----------- Pre declarations --------------

template <class T>
class LList;

template <class T>
class LLItr;

template <class T>
class KatzStack;

// ----------------- Node --------------------

template <class T>
class LLNode {

    T data;
    LLNode<T>* prev;
    LLNode<T>* next;

public:

    // Constructor
    LLNode(T newData, LLNode<T>* newNext = nullptr, LLNode<T>* newPrev = nullptr): data(newData), next(newNext), prev(newPrev) {}

    // Friend classes
    friend class LList<T>;
    friend class LLItr<T>;
    friend class KatzStack<T>;
};

// ------------- Iterator ------------------

template <class T>
class LLItr {

    LLNode<T>* current;

public:

    // Constructor
    LLItr(LLNode<T>* ptr): current(ptr) {}

    // Increment/decrement overloaded operators
    LLItr<T> operator++(int);
    LLItr<T>& operator++();
    LLItr<T> operator--(int);
    LLItr<T>& operator--();

    // Boolean overloaded operators
    bool operator==(const LLItr<T>& rhs) {return (current == rhs.current);}
    bool operator!=(const LLItr<T>& rhs) {return (current != rhs.current);}

    // Friend class
    friend class LList<T>;
};

// ----------------- List -------------------

template <class T>
class LList {

    LLNode<T>* head;
    LLNode<T>* tail;
    int numElements;

public:

    // default constructor
    LList();

    // Big 3
    LList(const LList<T>& rhs): LList() {*this = rhs;}
    LList<T>& operator=(const LList<T>& rhs);
    virtual ~LList();

    // Helper functions
    void clear();
    int size() const {return numElements;}
    bool isEmpty() const {return numElements == 0;}

    // Add elements
    void push_back(T newData) {insertAfter(newData, tail->prev);}
    void push_front(T newData) {insertAfter(newData, head);}
    void insertAfter(T newData, LLItr<T> itr);

    // Remove elements
    T pop_back();
    T pop_front();
    T removeNode(LLItr<T> node);

    // Create iterator
    LLItr<T> begin() {return LLItr<T>(head);}
    LLItr<T> end() {return LLItr<T>(tail->prev);}

    // friend class
    friend class KatzStack<T>;
};

// --------------- Stack ------------------

template <class T>
class KatzStack { // phonetic palindrome

    LList<T> data;

public:

    // Constructors
    KatzStack() {data = LList<T>();} // might not be needed
    KatzStack(LList<T>& data): data(data) {}

    // Stack functions
    void push(T newData) {data.push_front(newData);}
    T pop() {return data.pop_front();}
    T top() {return data.head->next->data;}

    // Helper functions
    void clear() {data.clear();}
    int size() const {return data.size();}
    bool isEmpty() const {return data.isEmpty();}
};

// -------- Program Function declarations ---------

void openInputFile(ifstream& inFile);
// Opens an input file stream for reading

vector<string> readPascalProgram(ifstream& inFile);
// reads Pascal programs from a file

bool checkSymbolBalance(vector<string> programs);
// checks if braces, parentheses, and bracket symbols are balanced for a list of pascal programs

// ------------- MAIN (driver) --------------------

int main() {

    // I - Open the file stream
    ifstream pascalFile;
    openInputFile(pascalFile);

    // II - Read in the pascal programs from the file
    vector<string> pascalPrograms = readPascalProgram(pascalFile);
    pascalFile.close();

    // III - Evaluate symbol balance and output result
    if (checkSymbolBalance(pascalPrograms)) {
        cout << "All programs in this file are balanced!\n";
    }
    else {
        cout << "Some symbols in the programs in this file are not balanced.\n";
    }

    return 0;
}

// ------ LLItr Function implementations ----------

template <class T>
LLItr<T> LLItr<T>::operator++(int) {

    // Save iterator before incrementing
    LLItr<T> temp = *this;

    // Increment iterator
    if (current != nullptr) {
        current = current->next;
    }

    // Return initial iterator
    return temp;
}

template <class T>
LLItr<T>& LLItr<T>::operator++() {

    // Increment iterator
    if (current != nullptr) {
        current = current->next;
    }

    // Return incremented iterator
    return *this;
}

template <class T>
LLItr<T> LLItr<T>::operator--(int) {

    // Save iterator before decrementing
    LLItr<T> temp = *this;

    // Decrement iterator
    if (current != nullptr) {
        current = current->prev;
    }

    // Return initial iterator
    return temp;
}

template <class T>
LLItr<T>& LLItr<T>::operator--() {

    // Decrement iterator
    if (current != nullptr) {
        current = current->prev;
    }

    // Return decremented iterator
    return *this;
}

// ------- LList Function implementations -----------

template <class T>
LList<T>::LList() {

    // Create two dummy nodes
    head = new LLNode<T>(T());
    tail = new LLNode<T>(T());

    // Connect dummy nodes to each other
    head->next = tail;
    tail->prev = head;

    // Set initial number of real nodes
    numElements = 0;
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {

    // Remove any existing values if any
    clear();

    // Add all elements
    LLNode<T>* temp = rhs.head->next;
    while (temp != rhs.tail) {
        insertAfter(temp->data, tail->prev);
        temp = temp->next;
    }

    // Return the copied list
    return *this;
}

template <class T>
LList<T>::~LList() {

    // Remove all real nodes
    clear();

    // Remove dummy nodes
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
}

template <class T>
void LList<T>::clear() {

    // Remove all real nodes
    while (!isEmpty()) {
        pop_back();
    }
}

template <class T>
T LList<T>::pop_back() {

    // Remove last node
    if (!isEmpty()) {
        return removeNode(tail->prev);
    }

    // List is empty
    return T();
}

template <class T>
T LList<T>::pop_front() {

    // Remove first node
    if (!isEmpty()) {
        return removeNode(head->next);
    }

    // List is empty
    return T();
}

template <class T>
T LList<T>::removeNode(LLItr<T> node) {

    if (!isEmpty()) {

        // Get node and data
        LLNode<T> *toDelete = node.current;
        T deletedData = toDelete->data;

        // Rewire surrounding pointers
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;

        // Delete node
        delete toDelete;
        numElements--;

        // Return data
        return deletedData;
    }

    // List is empty
    return T();
}

template <class T>
void LList<T>::insertAfter(T newData, LLItr<T> itr) {

    // Point to the three elements involved
    LLNode<T>* afterMe = itr.current;
    LLNode<T>* beforeMe = afterMe->next;
    LLNode<T>* toInsert = new LLNode<T>(newData, beforeMe, afterMe);

    // Rewire surrounding pointers
    afterMe->next = toInsert;
    beforeMe->prev = toInsert;

    // Increment the list size
    numElements++;
}

// ------- Program Function implementations -----------

void openInputFile(ifstream& inFile) {

    // Get file name from user
    string filename;
    cout << "Please enter file name: ";
    cin >> filename;

    // Attempt to open file
    inFile.open(filename);

    // If fails, keep trying until succeeds
    while (!inFile) {

        cout << "File failed to open.\n";
        cout << "Please enter file name: ";
        cin >> filename;

        inFile.clear();
        inFile.open(filename);
    }
}

vector<string> readPascalProgram(ifstream& inFile) {

    // Useful constants
    const string startMarker = "begin";
    const string endMarker = "end";
    // Common variants in Pascal
    const string endMarkerV2 = "end;"; // end of block
    const string endMarkerV3 = "end."; // end of main program

    vector<string> pascalBlocks;
    string wordInFile;

    KatzStack<string> beginEnd;
    KatzStack<string> unfinishedBlocks;
    bool newBlock = true;

    // Read file
    while (inFile >> wordInFile) {

        // Begin marker is found
        if (wordInFile == startMarker) {
            beginEnd.push(wordInFile);
        }

        // Inside a Pascal block
        else if (!beginEnd.isEmpty()) {

            // Read Pascal program contents
            string programWord, block;

            // Recall contents from engulfing block (for nested blocks)
            if (!unfinishedBlocks.isEmpty() && !newBlock) {
                block = unfinishedBlocks.pop();
            }

            // Not end marker
            if (wordInFile != endMarker && wordInFile != endMarkerV2 && wordInFile != endMarkerV3) {

                // Add word to block
                block += wordInFile;

                // Read rest of block content
                while (inFile >> programWord && programWord != endMarker && programWord != endMarkerV2 &&
                       programWord != endMarkerV3 && programWord != startMarker) {
                    block += programWord;
                }

                // Found another begin --- New nested block
                if (programWord == startMarker) {

                    // Add previous contents to a stack to be later remembered
                    unfinishedBlocks.push(block);

                    // Start a new block
                    beginEnd.push(programWord);
                    newBlock = true;
                }

                // Found an End --- Finish current block
                else {

                    // Add the block to the list
                    pascalBlocks.push_back(block);

                    // Not a new block
                    newBlock = false;

                    // Pop current block
                    beginEnd.pop();
                }
            }

            // Next word was an end --- Finish current block
            else {

                // Add the block to the list
                pascalBlocks.push_back(block);

                // Not a new block
                newBlock = false;

                // Pop current block
                beginEnd.pop();
            }
        }
    }

    // Return the list of pascal programs in the file
    return pascalBlocks;
}


bool checkSymbolBalance(vector<string> programs) {

    // Useful symbol constants
    const char opening_curly_brace = '{';
    const char closing_curly_brace = '}';
    const char opening_parenthesis = '(';
    const char closing_parenthesis = ')';
    const char opening_square_bracket = '[';
    const char closing_square_bracket = ']';

    // For each begin-end program in the file
    for (auto program: programs) {

        // Create a stack to hold the symbols and a stack to find the end marker
        KatzStack<char> symbolStack;

        // Go through each letter of the Pascal program until the end marker is found
        for (int i = 0; i < program.length(); i++) {

            char character = program[i];

            // Opening brace, parenthesis or bracket
            if (character == opening_curly_brace || character == opening_parenthesis ||
                character == opening_square_bracket) {
                symbolStack.push(character);
            }

            // Closing brace
            else if (character == closing_curly_brace) {

                // Matching opening brace
                if (!symbolStack.isEmpty() && symbolStack.top() == opening_curly_brace) {
                    symbolStack.pop();
                }

                // No matching opening brace
                else {
                    return false;
                }
            }

            // Closing parenthesis
            else if (character == closing_parenthesis) {

                // Matching opening parenthesis
                if (!symbolStack.isEmpty() && symbolStack.top() == opening_parenthesis) {
                    symbolStack.pop();
                }

                // No matching opening parenthesis
                else {
                    return false;
                }
            }

            // Closing bracket
            else if (character == closing_square_bracket) {

                // Matching opening bracket
                if (!symbolStack.isEmpty() && symbolStack.top() == opening_square_bracket) {
                    symbolStack.pop();
                }

                // No matching opening bracket
                else {
                    return false;
                }
            }
        }

        // Remaining unmatched braces, parentheses, or brackets
        if (!symbolStack.isEmpty()) {
            return false;
        }
    }

    // All braces, parentheses, or brackets appropriately matched
    return true;
}