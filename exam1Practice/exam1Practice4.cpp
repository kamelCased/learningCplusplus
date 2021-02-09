/*
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter max number of stars:" << endl;
    cin >> size;

    if (size % 2 == 0) {
        size--;
    }

    int maxRows = (size + 1)/2;
    int spaces = maxRows - 1;

    for (int rows = 1, stars = rows; rows <= maxRows; rows++, stars++, spaces--) {

        for (int spaceCount = 0; spaceCount < spaces; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <= (2 * stars - 1); starCount++) {
            cout << "*";
        }

        cout << endl;
    }

    for (int rows = 1, stars = maxRows - rows; rows <= maxRows; rows++, stars--,
    spaces++) {

        for (int spaceCount = 0; spaceCount <= spaces+1; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <= (2 * stars - 1); starCount++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter positive integer: ";
    cin >> num;

    int iterable = num;
    int total = 0;

    while (iterable > 0) {
        int digit = iterable % 10;
        total += digit;
        iterable /= 10;
    }

    cout << "For n = " << num << ", the sum of the digits is: " << total << endl;

    return 0;
}
*/
/*
 Question 1:
 a. True, the set {2,3} is in the roster notation of A
 b. True, the elements 2 and 3 are in A and 1 is in A but not in {2,3}
 c. False, there is no element {{1,2,3}} in A
 d. True, the set {1,2,3} is an element in A and A contains other elements not in {{1,2,3}}.

 Question 2:
 a.
 (-43)10

 By successive division:
 43 / 2 = 21 R 1
 21 / 2 = 10 R 1
 10 / 2 = 5 R 0
 5 / 2 = 2 R 1
 2 / 2 = 1 R 0
 1 / 2 = 0 R 1

 Find the complement:
   0010 1011
 + 1101 0101
 ----------
 1 0000 0000

 Therefore, (-43)10 = (1101 0101) 8 bit two's complement

b.
110011100 = 0001 1001 1100
Each 4 bit binary digit maps to a unique hex:
1100: C
1001: 9
0001: 1
So (110011100)2 = (19C)16

Question 3:
 a. x^2 + 3
 b. x^2 + 2 if x <= 0 and x^2 if x > 0
 c. |x| + 1
 d. -2x + 1 if x <= 0 and 2x if x > 0

 Question 4:
 a.
 Assume a is rational, ab is irrational and b is rational
 Since a and b are rational, a = m/n and b = x/y where m,n,x,y are integers and n and y are not zero.
 ab = m/n * x/y
 ab = mx/ny
 Since m,n,x,y are integers, mx and ny are integers.
 Since n and y are not zero, ny is not zero.
 So ab is expressed as a ratio of an integer over a non-zero integer.
 So ab is rational.
This contradicts the assumption that ab is irrational.

 b.
 Contrapositive: if k is even, 3k+1 is odd
 Proof:
 1. k = 2c for some integer c, since k is an even integer
 2. 3k+1 = 3(2c)+1 plugging k's value in
 3. 3k+1 = 6c+1 distributing
 4. 3k+1 = 2(3c)+1 factoring out a two
    Since c is an integer, 3c is also an integer.
    Let's set g = 3c.
 5. 3k+1 = 2g+1  replacing 3c by g
    2g+1 is an odd integer for any integer g.
    Therefore, 3k+1 is odd.

 c.
 Proof:
 1. x = 2k+1 and y = 2c+1 for some integers k and c since x and y are odd
 2. x + y = 2k+1 + 2c+1 plugging in the values of x and y
 3. x + y = 2k + 2c + 2 summing everything up
 4. x + y = 2(k+c+1)    factoring by 2
    Since k and c are integers, (k+c+1) is also an integer.
    Let's set g = (k+c+1). We get:
 5. x + y = 2g replacing (k+c+1) by g
    2g is an even integer for any integer g.
    Therefore, x+y is even.
 */

