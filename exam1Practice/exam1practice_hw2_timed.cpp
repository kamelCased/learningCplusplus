/*
// Question 1
#include <iostream>
using namespace std;

int main() {

    int quarters, dimes, nickels, pennies;
    cout << "# quarters: ";
    cin >> quarters;
    cout << "# dimes: ";
    cin >> dimes;
    cout << "# nickels: ";
    cin >> nickels;
    cout << "# pennies: ";
    cin >> pennies;

    int totalInPennies = quarters * 25 + dimes * 10 + nickels * 5 + pennies;

    int dollars = totalInPennies / 100;
    int cents = totalInPennies % 100;

    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;

    return 0;
}
*/
/*
// Question 2
#include <iostream>
using namespace std;

int main() {

    int dollars, cents;
    cout << "Please\tenter\tyour\tamount\tin\tthe\tformat\tof\tdollars\tand\tcents\tseparated\tby\ta\tspace:\n";
    cin >> dollars >> cents;

    cents = dollars * 100 + cents;

    int quarters = cents / 25;
    cents -= quarters * 25;

    int dimes = cents / 10;
    cents -= dimes * 10;

    int nickels = cents / 5;
    cents -= nickels * 5;

    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << cents << " pennies."
         << endl;

    return 0;
}
*/
/*
//Question 3
#include <iostream>
using namespace std;

int main() {

    int jDays, jHours, jMins;
    cout << "John # days: ";
    cin >> jDays;
    cout << "John # hours: ";
    cin >> jHours;
    cout << "John # minutes: ";
    cin >> jMins;

    cout << endl;

    int bDays, bHours, bMins;
    cout << "Bill # days: ";
    cin >> bDays;
    cout << "Bill # hours: ";
    cin >> bHours;
    cout << "Bill # minutes: ";
    cin >> bMins;

    int combinedMins = bMins + bHours * 60 + bDays * 1440 + jMins + jHours * 60 + jDays * 1440;

    int combinedDays = combinedMins / 1440;
    combinedMins -= combinedDays * 1440;

    int combinedHours = combinedMins / 60;
    combinedMins -= combinedHours * 60;

    cout << endl << "The total work time is " << combinedDays << " days, " << combinedHours << " hours, and " << combinedMins << " minutes." <<endl;

    return 0;
}
*/
/*
// Question 4
#include <iostream>
using namespace std;

int main() {

    int num1, num2;
    cout << "Please enter two positive integers separated by a space:" << endl;
    cin >> num1 >> num2;

    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " / " << num2 << " = " << double(num1) / num2 << endl;
    cout << num1 << " div " << num2 << " = " << num1 / num2 << endl;
    cout << num1 << " mod " << num2 << " = " << num1 % num2 << endl;

    return 0;
}
*/
/*
Question 5:
a.
1)
b)
1. ~q                   hypothesis
2. ~q v ~r              addition on 1
3. ~(q ^ r)             De Morgan's law on 2
4. p --> (q ^ r)        Hypothesis
5. ~p                   modus tollens on 3, 4

e)
 1. p v q           hypothesis
 2. q v p           commutative law on 1
 3. ~q              hypothesis
 4. p               disjunctive syllogism on 2,3
 5. ~~p             double negation on 4
 6. ~p v r          hypothesis
 7. r               disjunctive syllogism on 6,5

2)
1. p v q            hypothesis
2. ~~p v q          double negation on 1
3. ~p-->q           conditional identity on 2
4. ~p               hypothesis
5. q                modus ponens on 4,3

3)
Propositions:
- c: i will buy a car
- h: i will buy a house
- j: I will get a job

c)
Form:
 (c ^ h) --> j
 ~j
 -------------
 ~c

Counterexample: c = True, h = false, j = false.
Therefore, the argument is invalid.

d)
 (c ^ h) --> j
 ~j
 h
 -------------
 ~c
Proof:
1. ~j                   hypothesis
2. (c ^ h) --> j        hypothesis
3. ~(c ^ h)             modus tollens on 1, 2
4. ~c v ~h              de morgan's on 3
5. ~h v ~c              commutative law on 4
6. h                    hypothesis
7. ~~h                  double negation on 6
8. ~c                   disjunctive syllogism on 5,7

b)
1)
Counterexample: Domain = {c}, P(c) = False, Q(c) = True

2)
d)
Predicates:
 M(x): x missed class
 D(x): x got detention

 Form:
 Ax M(x)-->D(x)
 Penelope in U
 ~M(Penelope)
 -------------
 ~D(Penelope)

 Counterexample: domain = {Penelope}, M(Penelope) = False, D(Penelope) = True
 Since there is a counterexample for which all hypotheses are true and the conclusion is false, the argument is invalid.

e)
 Predicates:
 M(x): x missed class
 D(x): x got detention
 A(x): x got an A

 Form:
 Ax (M(x) v D(x))-->~A(x)
 Penelope in U
 A(Penelope)
 ------------------------
 ~D(Penelope)

 Proof:
 1. Penelope in U                                   hypothesis
 2. Ax (M(x) v D(x)) --> ~A(x)                      hypothesis
 3. (M(Penelope) v D(Penelope)) --> ~A(Penelope)    universal instantiation on 1, 2
 4. A(Penelope)                                     hypothesis
 5. ~~A(Penelope)                                   double negation on 4
 6. ~(M(Penelope) v D(Penelope))                    modus tollens on 3,5
 7. ~M(Penelope) ^ ~D(Penelope)                     de morgan's law on 6
 8. ~D(Penelope) ^ ~M(Penelope)                     commutative law on 7
 9. ~D(Penelope)                                    simplification on 8

Question 6:
d.
 Let x and y be odd integers.
 x = 2k+1 and y = 2c+1 for some integers k and c, since x and y are odd
 xy = (2k+1)(2c+1)
 xy = 4kc + 2c + 2k + 1
 xy = 2(2kc + c + k) + 1
 since k and c are both integers, (2kc + c + k) is also an integer.
 Let's set g = (2kc + c + k)
 xy = 2g + 1
 2g+1 is an odd integer for any integer g.
 Therefore, xy is odd.

 c.
 x <= 3
 0 <= 3 - x
 0 <= 4 - x
 the product of two non-negative integers is also non-negative
 0 <= (3 - x)(4 - x)
 0 <= 12 - 3x - 4x + x^2
 0 <= 12 - 7x + x^2

 Question 7:
 d)
 Contrapositive: if n is even, then n^2-2n+7 is odd
 Proof:
 1. n = 2k for some integer k since n is even
 2. n^2-2n+7 = (2k)^2 - 2(2k) + 7 plugging n's value in
 3. n^2-2n+7 = 4k^2 - 4k + 7
 4. n^2-2n+7 = 2(2k^2 - 2k + 3) + 1
 Since k is an integer, (2k^2 - 2k +3) is also an integer.
 Let's set g = (2k^2 - 2k +3)
 5. n^2-2n+7 = 2g + 1
 2g+1 is an odd integer for any integer g.
 Therefore, n^2-2n+7 is odd.

 f)
 Contrapositive: For any non-zero real number, if 1/x is rational, then x is rational.
 Proof:
 1. 1/x = a/b for some non-zero integers a and b since 1/x is rational and x is not zero.
 2. 1 = ax/b mutliply both sides by x
 3. 1/a = x/b divide both sides by a
 4. b/a = x  mutliply both sides by b.
 Since b and a are non-zero integers, x is expressed as a ratio of an integer over a non-zero integer.
 Therefore, x is rational.

 g)
 Contrapositive: If x > y, then x^3 + xy^2 > x^2y + y^3
 Proof:
 1. x > y
 2. x^3 > yx^2                      multiply both sides of step 1 by x^2 (since x^2 is non-negative for any real number)
 3. xy^2 > y^3                      multiply both sides of step 1 by y^2 (since y^2 is non-negative for any real number)
 4. x^3 + xy^2 > yx^2 + y^3         combine both inequalities.

 l)
 Contrapositive: For every pair of real number x and y, if x <= 10 and y <= 10, then x+y <= 20
 Proof:
 1. (x <= 10) ^ (y <= 10)
 2. x <= 10 simplification on line 1
 3. (y <= 10) ^ (x <= 10) commutative on line 1
 4. y <= 10 simplification on line 3
 5. x + y <= 10 + 10 combining inequalities 2 and 4
 6. x + y <= 20

 Question 8:
 c)
 Proof by contradiction:
 1. Assume the average of three real numbers is less than all three numbers.
 2. ((a+b+c) / 2 < a)^((a+b+c)/2 < b)^((a+b+c)/2 < c)
 3. (a+b+c) / 2 < a) simplification (twice) on line 2
 4. (a+b+c) / 2 < b) simplification (twice) on line 2
 5. (a+b+c) / 2 < c) simplification (twice) on line 2
 6. (a+b+c)/2 + (a+b+c)/2 + (a+b+c)/2 < a + b + c
 7. a + b + c < a + b + c, which is an obvious contradiction.

 e)
 Proof by contradiction:
 1. Assume there is a smallest integer x.
 2. x - 1 < x
 3. Since x is an integer, x-1 is also an integer.
 4. So we have an integer that is smaller than x, this contradicts the assumption that x is the smallest integer.

 Question 9:
 c)
 Case 1: x and y are even
 1. x = 2k and y = 2c for some integers k and c since x and y are even
 2. x + y = 2k + 2c plugging in the values of x and y
 3. x + y = 2(k+c) factoring by 2
    Since k and c are integers, (k+c) is also an integer.
    Let's set g = k+c
 4. x + y = 2g
    By definition, 2g is an even integer for any integer g.
    Therefore, x + y is even.

 Case 2: x and y are odd
 1. x = 2k+1 and y = 2c+1 for some integers k and c since x and y are odd
 2. x + y = 2k+1 + 2c+1 plugging in the values of x and y
 3. x + y = 2k + 2c + 2 summing everything up
 4. x + y = 2(k+c+2) factoring by 2
    Since k and c are integers, (k+c+2) is also an integer.
    Let's set g = k+c+2
 4. x + y = 2g
    By definition, 2g is an even integer for any integer g.
    Therefore, x + y is even.
*/

