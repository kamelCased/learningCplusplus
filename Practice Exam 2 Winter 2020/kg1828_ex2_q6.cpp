// Practice Exam 2
// 3/23/21
#include <iostream>
using namespace std;

bool is2DupSequence(int seq[], int seqSize);

int main() {

    // ------- Should return true -------

    // Create an array
    int seqSize = 6;
    int seq[6] = {3,3,14,14,2,2};

    // Check if 2-dup sequence
    if(is2DupSequence(seq, seqSize)) {
        std::cout << "Is a 2-dup sequence" << std::endl;
    }
    else {
        std::cout << "Is not a 2-dup sequence" << std::endl;
    }

    // ------- Should return false -------

    // Create an array
    int seq2Size = 6;
    int seq2[6] = {3,3,11,14,2,2};

    // Check if 2-dup sequence
    if(is2DupSequence(seq2, seq2Size)) {
        std::cout << "Is a 2-dup sequence" << std::endl;
    }
    else {
        std::cout << "Is not a 2-dup sequence" << std::endl;
    }

    return 0;
}

bool is2DupSequence(int seq[], int seqSize) {

    // Base case: only 2 elements
    if (seqSize == 2) {
        // Elements are same
        if (seq[seqSize - 1] == seq[seqSize - 2]) {
            return true;
        }
        //Elements are not
        else {
            return false;
        }
    }

    // Recursive step
    else{
        // Call with smaller input and check last two elements
        return (is2DupSequence(seq, seqSize - 2) && (seq[seqSize - 2] == seq[seqSize - 1]));
    }
}

// Implementation 2 if we assume that 0 is a 2-dup sequence (question ambiguous)
//bool is2DupSequence(int seq[], int seqSize) {
//
//    if (seqSize == 0) {
//        return true;
//    }
//    else{
//        return (is2DupSequence(seq, seqSize - 2) && (seq[seqSize - 2] == seq[seqSize - 1]));
//    }
//}