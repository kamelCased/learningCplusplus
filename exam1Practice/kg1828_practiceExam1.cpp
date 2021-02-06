// Author: Kamel Gazzaz
// Assignment: Practice Exam 1
// Date: 02/04/2021

/*
1.
0011 0111 1100

2. (45) base 10

3.
(p --> q) ^ (p --> r)
(~p v q) ^ (p --> r)     conditional identity
(~p v q) ^ (~p v r)      conditional identity
~p v (q ^ r)             distributive law
p --> (q ^ r)

4.
Ax (~W(x) --> (S(x) v V(x)))
Ex (~W(x) ^ ~(S(x) v V(x)))

20.
Ax (P(x) v C(x))

21.
d. False, regardless of choice of y. Once a y is chosen, it cannot satisfy equality for all possible values of z.
f. True, example: x=3 y=4 z=5

22.
a. Ax (~B(x))
b. Ex (S(x) ^ B(x))

5.
d: drive on freeway
f: see fire
s: drive on surface street

Form :
d --> f
d v s
~s
---------
f

Proof:
d v s
s v d   commutative law
~s      hypothesis
d       disjunctive syllogism on 2, 3
d --> f hypothesis
f       modus ponens on 4,5

23.

1. Ex P(x)
2. c is a particular element ^ P(c)    Existential instantiation
3. c is a particular element           Simplification on 2
4. Ax Q(x)                              hypothesis
5. Q(c)                                 Universal instantiation on 4,3
6. P(c)                                 Simplification on 2
7. P(c) ^ Q(c)                          Conjunction on 6,5
8. Ex(P(x) ^ Q(x))                      Existential generalization on 7,3

d.
P(x): x has a permission slip
F(x): x can go on the field trip

Form:
Ax (P(x)-->F(x))
Ax(P(x))
----------------
Ax(F(x))

Proof:
1. Ax(P(x)-->F(x))                      hypothesis
2. c is an arbitrary element            element definition
3. P(c)-->F(c)                          universal instantiation on 1,2
4. AxP(x)                               hypothesis
5. P(c)                                 universal instantiation on 4, 2
6. F(c)                                 modus ponens on 5, 3
7. AxF(x)                               universal generalization on 6, 2

6.
a. Proof by exhaustion
n=0: 1 > 0
n=1: 4 > 1
n=2: 9 > 8
Therefore, the statement is valid for all 0 <= x < 3.

24.
a.
Proof by contradiction:
1. Assume x/y + y/x < 2
2. (x^2y + y^2x)/xy < 2   Express in common denominator
3. x^2y + y^2x < 2xy      Multiply both sides by xy, since x and y positive xy is positive
4. x^2y - 2xy + y^2x < 0  Subtract 2xy from both sides
5.




7.
Contraspositive: For every integer n, if n is even then n^2 is divisible by 4.
Proof:
1. n = 2k for some integer k, since n is even
2. n^2 = (2k)^2  taking the square of both sides
3. n^2 = 4k^2
4. Since k is an integer, k^2 is also an integer.
4g is a multiple of 4 for any integer g.
Therefore, n^2 is a multiple of 4.auto

8.
Proof by contradiction:
1. Assume sqrt(a) + sqrt(b) = sqrt(a+b)
2. (sqrt(a) + sqrt(b))^2 = (sqrt(a+b))^2        taking the square
3. a + 2sqrt(ab) + b = a + b                    distribute the square
4. 2sqrt(ab) = 0                                subtract both sides by (a+b)
5. sqrt(ab) = 0                                 Divide by 2
6. ab = 0                                       Square both sides
7. This statement contradicts the fact that a and b are both positive integers.
If a>0 and b>0 then ab>0.
Therefore, the original theorem must be true.


9.
Case 1: x > y
1. Since, x > y                 max(x, y) = x
2. Add x to both sides         2x > y + x
3. Divide both sides by 2       x > (y + x) / 2
4. Replace x with max           max(x, y) > (y + x)/2
3. Since greater, greater or equal must be true max(x, y) >= (y + x)/2

Case 2: y >= x
1. Since, y >= x                max(x, y) = y
2. Add y to both sides         2y >= x + y
3. Divide both sides by 2       y >= (x + y) / 2
4. Replace y with max           max(x, y) >= (y + x)/2

Since it holds for all cases, the theorem is valid.

10.
a. True, all elements in A also in B.
b. False, no element in b that is not in A.


11.
a. True, Ø is an element of all power sets.
b. True, Ø is a subset of all sets.

12.
a. {1,2,4} n {1,3,9} n {1,4,16} n {1,5,25} = {1}
c. -i decreases as i increases. 1/i decreases as i increases.
Therefore, the intersection is -1 <= x <= 1/100

25.
a. False, no elements in common so 0
b. False, elements in P(A) are sets.
c. True, both sets are equal
d. False, 0 and -1 are not in F so cardinality is 2.

26.
a. {000, 001, 010, 011}
b. {l, 0, 1, 00, 01, 10, 11}

28.
a. {aa, ab, ac, ad}
b. {ab}

13.
a.
1. (A n C) u (A` n C)
2. (C n A) u (A` n C)   Commutative law on 1
3. (C n A) u (C n A`)   Commutative law on 2
4. C n (A u A`)         Distributive law on 3
5. C n Universe         Complement law on 4
6. C                    Identity law on 5

c.
1. (AnB`)`
2. A` u B``           De Morgan's law on 1
3. A' u B             Double complement law on 2

29.
a.
1. A - (B n A)
2. A n (B n A)`         Set subtraction law on 1
3. A n (B` u A`)        De Morgan's law on 2
4. (A n B`) u (A n A`)  Distributive law on 3
5. (A n B`) u Ø         Complement law on 4
6. (A n B`)             identity law on 5
7. A - B                set subtraction law on 6

b.
1. A n (B - A)
2. A n (B n A`)         set subtraction law on 1
3. (B n A`) n A         commutative law on 2
4. B n (A` n A)         associative law on 3
5. B n (A n A`)         commutative law on 4
6. B n Ø                complement law on 5
7. Ø                    domination law on 6

 14.
 */
#include <iostream>
using namespace std;

int main() {
    double startTemp;
    cout << "Please enter the starting temperature: ";
    cin >> startTemp;

    double endTemp;
    cout << "Please enter the ending temperature: ";
    cin >> endTemp;

    double stepSize;
    cout << "Please enter the step size (not zero): ";
    cin >> stepSize;

    double currentTemp = startTemp;

    if (startTemp <= endTemp) {
        while (currentTemp <= endTemp) {
            cout << currentTemp << endl;
            currentTemp += stepSize;
        }
    }
    else {
        while (currentTemp >= endTemp) {
            cout << currentTemp << endl;
            currentTemp -= stepSize;
        }
    }

    int rows;
    cout << endl << "Please enter the size of your Z:" << endl;
    cin >> rows;

    // Top horizontal bar
    for (int lineCount = 1; lineCount <= rows; lineCount++) {
        cout << "#";
    }
    cout << endl;

    // Middle Diagonal
    for (int lineCount = 1; lineCount <= rows - 2; lineCount++) {

        for (int spaceCount = 1; spaceCount <= (rows - lineCount - 1); spaceCount++) {
            cout << " ";
        }

        cout << "#";

        cout << endl;
    }

    //Bottom horizontal bar
    for (int lineCount = 1; lineCount <= rows; lineCount++) {
        cout << "#";
    }
    cout << endl;

    return 0;
}

