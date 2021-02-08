/*
Question 22
c. ExAy (B(x)^(S(x)-->P(x, y)))
d. Ax(S(x)-->Ay(B(y)-->P(x, y)))

Question 1:
(326)10
326 / 2 = 163 R 0
163 / 2 = 81 R 1
81 / 2 = 40 R 1
40 / 2 = 20 R 0
20 / 2 = 10 R 0
10 / 2 = 5 R 0
5 / 2 = 2 R 1
2 / 2 = 1 R 0
1 / 2 = 0 R 1
(326)10 = (101000110)2

(132)5 to octal
1 * 5^2 + 3 * 5^1 + 2 * 5^0 = (42)10
42(10)
42 / 8 = 5 R 2
5 / 8 = 0 R 5
(132)5 = (52)8

(10101001) to hex
(1010 1001) = (A9)16

Question 2:
(-71)10
71 / 2 = 35 R 1
35 / 2 = 17 R 1
17 / 2 = 8 R 1
8 / 2 = 4 R 0
4 / 2 = 2 R 0
2 / 2 = 1 R 0
1 / 2 = 0 R 1
  0100 0111
  +1011 1001
  ---------
1 0000 0000

(-71)10 = 1011 1001

Question 3
b.
(p ^ q ^ ~r) v (p ^ ~q ^ ~r)
p ^ ((q ^ ~r) v (~q ^ ~r))      distribution law on 1
p ^ ((~r ^ q) v (~q ^ ~r))      commutative law on 2
p ^ ((~r ^ q) v (~r ^ ~q))      commutative law on 3
p ^ (~r ^ (q v ~q))             distributive law on 4
p ^ (~r ^ T)                    complement law on 5
p ^ ~r                          Identity law on 6

Question 4
h. Ax (M(x)-->(S(x) v V(x)))

Question 20
d.
Ex (P(x) ^ C(x))
~Ex (P(x) ^ C(x))
Ax ~(P(x) ^ C(x))
Ax (~P(x) v ~C(x))
All students showed up without a calculator or without a calculator or both.

Question 21
g.
False, if x=-1
h.
True

Question 5
b.
Predicates:
- f: it was foggy
- r: it rained
- h: race was held
- t: trophy ceremony

Form:
(~f v ~r) --> (h ^ t)
~t
---------------------
r

Proof:
1. ~t                           hypothesis
2. ~t v ~h                       Addition on 1
3. ~(t ^ h)                      De Morgan's on 2
4. ~(h ^ t)                     Commutative on 3
5. (~f v ~r) --> (h ^ t)        Hypothesis
6. ~(~f v ~r)                   modus tollens on 4, 5
7. ~~f ^ ~~r                    De Morgan's on 6
8. f ^ ~~r                      Double negation on 7
9. f ^ r                        Double negation on 8
10. r ^ f                       Commutative on 9
11. r                           Simplification on 10

Question 23
1. c is an arbitrary element        element definition
2. Ax (~Q(x))                       hypothesis
3. ~Q(c)                            universal instantiation on 1,2
4. Ax (Q(x) v P(x))                 hypothesis
5. Q(c) v P(c)                      universal instantiatopm  on 1, 4
6. P(c)                             disjunctive syllogism on 5,3
7. Ax P(x)                          universal generalization on 6, 1

Question 6
c. x=1

Question 24
b.
x > 0
y > 0
x^2 >  0
y^2 > 0
xy > 0
x^2 + y^2 + xy > 0
x^2 + y^2 + 2xy > xy
(x + y)^2 > xy
x+y > sqrt(xy)

e.
r = a/b and s = c/d where a,b,c,d are integers and b and d are not zero
rs = a/b * c/d
rs = ac/bd
Since a,b,c,d are integers and b and d are not zero. ac is an integer and bd is a non-zero integer.
Since rs can be expresssed as a ratio of an integer and a non-zero integer it is rational.

Question 7
j.
Contrapositive: If x and y are odd, then xy is odd
Proof:
1. x = 2k+1 and y = 2c+1 for some integers k and c
2. xy = (2k+1)*(2c+1)
3. xy = 4kc + 2k + 2c + 1
4. xy = 2(2kc + k + c) + 1
Since k and c are integers, (2kc + k + c) is also an integer.
2g + 1 is an odd integer for any integer g.
Therefore, xy is odd.

l.
Contrpositive: if 4x^2+3x is rational than x is rational
Proof:
1. 4x^2+3x = a/b for some integers a and b where a and b are not zero
2. x(4x+3) = a/b

Question 8:
b.
Assume cuberoot 2 is rational
1. cuberoot(2) = a/b for some integers a and b where b is not zero.
2. 2 = (a/b)^3 cubing both sides
3. 2 = a^3/b^3
Since a and b are integers and b is not zero. a^3 is an integer and b^3 is a non-zero integer.
Since it can be expressed as a ratio of an integer and a non-zero integer, 2 must be rational.
This is a contradiction since 2 is irrational.


d.
Assume there is a largest rational negative number x.
1. x = a/b for some integers a and b where a is negative and b is not zero
2. Since x > 0, x/2 > x
3. x/2 = (a/b) / 2
4. x/2 = a/2b
Since a and b are integers and b is not zero. a is  a negative integer and 2b is a non-zero integer.
Therefore, x/2 can be expressed as a ratio of a negative integer ver a non-zero integer, so it is a negative rational number
Since, x/2 > x this contradicts the fact that x is the largest rational negative number

Question 9:

Case 1: x and y are both negative
x < 0 and y < 0
So x*y > 0
So |x*y| = x*y

Since x < 0, |x| = -x
Since y < 0, |y| = -y
|x|.|y| = -x.-y = x.y

So |x*y| = |x|*|y|

Case 2: x is negative and y is positive (or vice versa)

x < 0 and y >= 0
x*y < 0
So |x*y| = -(x*y) = -xy

Since x < 0, |x| = -x
Since y >= 0, |y| = y
|x|*|y| = -x*y = -xy

So |x*y| = |x|*|y|

Case 3: x and y are both positive
x >= 0 and y >= 0
x*y > 0
|x*y| = xy

x >= 0, |x|=x
y >= 0, |y|=y
|x|.|y| = xy

So |x*y| = |x|*|y|

Since the theorem is true in all cases, it's valid.

Question 10:
d. True, {2,4,6,8} subset of {2,4,6,8,10}
e. False, 10 is not an element in B


Question 11:
c. True, P(X) always has at least one element
d. More info needed, true if P(X) has more elements than the empty set, false otherwise


Question 12:
b. A2 = {1,2,4}
A3 = {1,3,9}
A4={1,4,16}
A5={1,5,25}
So Ai = {1,2,3,4,5,9,16,25};

d.
The lower bound of Bi decreases as i increases. The upper bound of Bi also decreasses as i increases.
Since we're looking for the union, we take the widest bounds.
So Bi: {x in R: -100 <= x <= 1};

Question 25:
f. False, not in B
g. False, c has numbers not sets as elements
h. True, 0 is in C so {0} is in P(C).

Question 26:
c. {l, 0, 1, 00, 01, 10, 11}
d. {01, 001, 011, 0011};

Question 28:
c. {ac, aa, ab, ad}
d. {ab}
e. {bb}

Question 13:
d.
1. A n (A u B)
2. A n B  Absorption law

e.
1. A n (B n B)
2. A n Ø       complement law
3. Ø            domination law

b.
1. A - (B n A)
2. A n (B n A)` Subtraction law
3. A n (B` u A`) De Morgan's law
4. A n (A` u B`) commutative law
5. (A n A`) u (A n B') Distributive law
6. Ø u (A n B`)  Complement law
7. A n B` Identity law

Question 29:
c.
1. A u (B - A)
2. A u (B n A`) set subtraction
3. (A u B) n (A u A`) distributive law
4. (A u B) n U          complement law
5. A u B                identity law

*/

/*
#include <iostream>
using namespace std;

int main() {
    bool buddy, license, advancedLicense, rescueLicense;
    cout << "Do you have a padi license? (yes=1,no=0) ";
    cin >> license;

    // 1
    if (!license) {
        cout << "Sorry, you can't dive!" << endl;
    }
    else {
        cout << "Do you have a have an advanced padi license? (yes=1,no=0) ";
        cin >> advancedLicense;

        if (advancedLicense) {
            cout << "Do you have a have a padi rescue license? (yes=1,no=0) ";
            cin >> rescueLicense;

            if (rescueLicense) {
                // 4
                cout << "You can dive with any buddy. Enjoy!" << endl;
            }
            else {
                // 3
                cout << "You can dive with another buddy who has an advanced license." << endl;
            }

        }
        //2
        else{
            cout << "You can dive with an instructor" <<endl;
        }

    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the size of your +: ";
    cin >> rows;

    for (int lineCount = 1; lineCount <= rows; lineCount++) {

        if (lineCount == rows / 2) {
            for (int hashCount = 1; hashCount <= rows; hashCount++) {
                cout << "#";
            }
        }
        else {
            for (int spaceCount = 0; spaceCount < rows / 2; spaceCount++) {
                cout << " ";
            }

            cout << "#";
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
    int rows;
    cout << "Enter the size of your F: ";
    cin >> rows;

    for (int lineCount = 1; lineCount <= rows; lineCount++) {

        if ((lineCount == 1)||(lineCount == rows/2+1)) {
            for (int hashCount = 1; hashCount <= rows; hashCount++) {
                cout << "#";
            }
        }
        else {
            cout << "#";
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
    int size;
    cout <<"Enter size of L: "<<endl;
    cin >> size;

    for (int rows = 1; rows <= size; rows++) {
        if (rows == size) {
            for (int cols = 1; cols <= size; cols++) {
                cout << "$";
            }
        }
        else {
            cout << "#";
        }
        cout <<endl;
    }

    return 0;
}
*/
#include <iostream>
using namespace std;

int main() {
    int size;
    cout <<"Enter size of barn door odd number > 3: "<<endl;
    cin >> size;

    int left = 0;
    int middle = size - 2;

    for (int rows = 1; rows <= size; rows++) {
        if (rows == 1 || rows == size) {
            for (int cols = 1; cols <= size; cols++) {
                cout << "#";
            }
        }

        else {
            cout << "#";

            for (int space = 1; space < left; space++) {
                cout << " ";
            }

            cout << "$";

            if (rows != size/2 +1) {
                for (int space = 1; space <= middle; space++) {
                    cout << " ";
                }

                cout << "$";
            }

            for (int space = 1; space < left; space++) {
                cout << " ";
            }

            cout << "#";
        }

        if (rows < size/2+1) {
            left++;
            middle -=2;
        }
        else {
            left--;
            middle +=2;
        }

        cout << endl;
    }

    return 0;
}