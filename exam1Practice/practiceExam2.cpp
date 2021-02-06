//Author: Kamel Gazzaz
//Practice Exam 2
/*
1.
a. True, the set {2,3} is in the roster notation
b. True, 2 and 3 are elements in A and 1 is not in {2,3}
c. True, the set {1,2,3} is an element of A
d. True, {1,2,3} is an element in A and {2,3} is in A but not {{1,2,3}}

2.
(-43)10
Step 1. Find (43)10 in 8 bit 2's complement:
43 / 2 = 21 R 1
21 / 2 = 10 R 1
10 / 2 = 5 R 0
5 / 2 = 2 R 1
2 / 2 = 1 R 0
1 / 2 = 0 R 1
(00101011)8 bit 2
Step 2. Find the complement
  0010 1011
  1101 0101
  --------
1 0000 0000
Therefore, (43)10 = (1101 0101)8 bit 2's complement

b.
1 1001 1100
- 1100 = C
- 1001 = 9
- 0001 = 1

Therefore (1 1001 1100)2 = (19C)16

3.
a. cos(x) + 100
b. e(x)
c. x^2
d. if x < 0: -2x-1, if x >= 0: x = 2x

4.
a. Proof by contradiction
Step 1: Assume if a rational and ab is irrational then b is irrational.
Step 2: Since a and b are rational. a = x/y and b=m/n for some integers, x,y,m,n where y and n are not zero.
Step 3: ab = (x/y) * (m/n)
Step 4: ab = xm / yn
Step 5: Since x, y, m, and n are integers, xm and yn are also integers.
Since y and n are not zero, yn is not zero.
So ab is expressed as an integer over a non-zero integer, so ab is rational.
This contradicts the assumption that ab is irrational.

b.
Contrapositive: For any integer k, if k is even, then 3k+1 is odd.
Proof:
Step 1: Since k is even, k = 2c for some integer c.
Step 2: Replace k by its value. 3k+1 = 3(2c)+1
Step 3: 3k+1 = 6c+1
Step 4: 3k+1 = 2(3c)+1. Since c is an integer, 3c is also an integer.
Let's set g=3c.
2g+1 is an odd integer for any integer g.
Therefore, 3k+1 is odd.

c.
Proof:
1. Since x and y are odd, x=2k+1 and y=2c+1 for some integers k and c.
2. x+y = (2k+1)+(2c+1)
3. x+y = 2k+2c+2
4. x+y = 2(k+c+1)
Since k and c are both integers, k+c+1 is also an integer.
Let's set g=k+c+1.
2g is an even integer for any integer g.
Therefore, x+y is even.

*/
#include <iostream>
using namespace std;

int main() {

    // Exercise 5
    int n;
    cout <<"Please enter a positive integer n: " << endl;
    cin >> n;

    int sum = 0;
    int iterableNum = n;
    for (int i = 0; i < n; i++) {
        int digit = iterableNum % 10;
        sum += digit;
        iterableNum /= 10;
    }

    cout << sum << endl;

    // Exercise 6
    int maxStars;
    cout << "Please enter the max number of stars in a row of your diamond: " << endl;
    cin >> maxStars;

    if (maxStars % 2 == 0) {
        maxStars = maxStars - 1;
    }

    for(int lineCount = 1; lineCount <= maxStars; lineCount++) {

        if ((maxStars - lineCount) % 2) {
            for (int spaceCount = 1; spaceCount <= (maxStars - lineCount)/2; spaceCount++) {
                cout << " ";
            }
        }
        else {
            for (int spaceCount = 1; spaceCount <= (maxStars - lineCount + 1)/2; spaceCount++) {
                cout << " ";
            }
        }

        for (int starCount = 1; starCount <= lineCount; starCount+=2) {
            cout << "*";
        }

        cout << endl;
    }

    for(int lineCount = 1; lineCount <= maxStars; lineCount++) {

        for (int spaceCount = 1; spaceCount <= lineCount/2; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <= (maxStars - lineCount); starCount++) {
            cout << "*";
        }

        cout << endl;
    }


    return 0;
}


