/*
Question 1:
 a. True, {2,3} is in the roster notation for A
 b. True, 2 and 3 are both elements in A and 1 is also in A but not in {2,3}
 c. False, {{1,2,3}} is not in the roster notation
 d. True, {1,2,3} is an element in A and 1 is in A but not {{1,2,3}}

 Question 2:
 a.
 (-43)10
 43 / 2 = 21 R 1
 21 / 2 = 10 R 1
 10 / 2 = 5 R 0
 5 / 2 = 2 R 1
 2 / 2 = 1 R 0
 1 / 2 = 0 R 1

   0010 1011
+  1101 0101
------------
 1 0000 0000

 So (-43)10 = 1101 0101

 b.
 110011100 = 0001 1001 1100
 Each 4 bit binary number corresponds to a hex digit:
 1100 = C
 1001 = 9
 0001 = 1

 So (110011100)2 = (19C)16

 Question 3:
 a. f(x) = 4;
 b. f(x) = x^2 + 1 if x <= 0, x^2 if x > 0
 c. f(x) = |x| + 1
 d. f(x) = -2x + 1 if x <= 0, 2x if x > 0

 Question 4:
 a.
 Proof by contradiction:
 1. Assume a is rational and ab is irrational an b is rational
 2. since a and b are rational a = x/y and b = m/n for some integers x,y,m,n where m,n are not zero.
 3. So, we get:
    ab = x/y * m/n
 4. ab = xm/yn
 5. Since x,m,y,n are integers and y and n are not zero, xm is an integer and yn is a non-zero integer.
    So, ab is expressed as a ratio of an integer over a non-zero integer.
    Therefore, ab is rational. This contradicts the assumption that ab is irrational.

 b.
 Contrapositive: For any k in Z, if k is even, 3k+1 is odd
 Proof:
 1. k = 2g for some integer g since k is even
 2. 3k+1 = 3(2g)+1 plugging in the value of a
 3. 3k+1 = 6g+1
 4. 3k+1 = 2(3g)+1
    Since g is an integer, 3g is also an integer.
    2x+1 is an odd integer for any integer x.
    Therefore, 3k+1 is odd.

 c.
 Proof:
 1. x = 2k+1 and y = 2c+1 for some integers k and c, since x and y are odd integers
 2. x+y = (2k+1) + (2c+1) plugging in the values of x and y
 3. x+y = 2k+2c+2 summing all up
 4. x+y = 2(k+c+1) factoring by two
    Since k and c are integers, (k+c+1) is also an integer.
    2g is an even integer for any integer g.
    Therefore, x+y is even.

//Question 5:
#include <iostream>
using namespace std;

int main () {
    int num;
    cout << "Please enter a positive integer: ";
    cin >> num;

    int iterable = num, sumDigits = 0;

    while (iterable > 0) {
        int digit = iterable % 10;
        sumDigits += digit;
        iterable /= 10;
    }

    cout << "The sum of the digits of " << num << " is " << sumDigits << endl;

    return 0;
}
 */
/*
// Question 6
#include <iostream>
using namespace std;

int main () {
    int size;
    cout << "Please enter the max number of stars: ";
    cin >> size;

    for (int row = 1; row <= size; row++) {

        for (int space = 1; space <= size - row; space++) {
            cout << " ";
        }

        for (int star = 1; star <= row; star++) {
            cout << "* ";
        }

        cout << endl;
    }

    for (int row = 1; row < size; row++) {

        for (int space = 1; space <= row; space++) {
            cout << " ";
        }

        for (int star = 1; star <= size - row; star++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
*/