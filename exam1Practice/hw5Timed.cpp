/*
// Question 1
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "PLease enter a positive integer:" << endl;
    cin >> n;

    for (int row = 1; row <= n; row++) {

        for (int col = 1; col <=n; col++) {
            cout << row * col << "\t";
        }
        cout << endl;
    }

    return 0;
}
*/
/*
// Question 2
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_GUESSES = 5;

int main() {

    srand(time(0));
    int target = (rand() % 100) + 1;
    cout << target ;
    cout << "I thought of a number between 1 and 100! Try to guess it:" << endl;

    int intervalMin = 1, intervalMax = 100, guess;
    bool guessedRight = false;
    for (int guessCount = 1; (guessCount <= MAX_GUESSES) && (!guessedRight); guessCount++) {
        cout << "Range: [" << intervalMin << ", " << intervalMax << "], number of guesses left: " << MAX_GUESSES - guessCount + 1 << endl;
        cin >> guess;

        // guessed right
        if (guess == target) {
            guessedRight = true;

            if (guessCount == 1) {
                cout << "Congrats! You guessed my number in " << guessCount << " guess" << endl;
            }
            else{
                cout << "Congrats! You guessed my number in " << guessCount << " guesses" << endl;
            }
        }
        //guessed wrong
        else {

            //out of guesses
            if (guessCount == MAX_GUESSES) {
                cout << "Out of guesses! My number is " << target << endl;
            }

            // not out of guesses
            else {
                // guessed too high
                if (guess > target) {
                    cout << "Wrong! my number is smaller" << endl;
                    // in range
                    if ((guess < intervalMax)) {
                        intervalMax = guess - 1;
                    }
                }

                //guessed too low
                else {
                    cout << "Wrong! my number is bigger" << endl;
                    // in range
                    if ((guess > intervalMin)) {
                        intervalMin = guess + 1;
                    }
                }
            }

        }

    }

    return 0;
}
 */
/*
 Question 3:
 a)
 b.
 If x = -2 or x = 2, f(x) = 1/0, which is not a real number.
 Therefore, f is not well defined from R to R.

 c.
 Any real number x squared is a non-negative real number.
 The square root function can take any non-negative real number as input and map it to a non-negative real number.
 Therefore, f is well defined from R to R.

 b)
 b. {4, 9, 16, 25}
 d. {0,1,2,3,4,5}
 h. {(1, 1), (2, 1), (3, 1), (1, 2), (2, 2), (3, 2), (1, 3), (2, 3), (3, 3)}
 i. {(1, 2), (1, 3), (1, 4), (2, 2), (2, 3), (2, 4), (3, 2), (3, 3), (3, 4)}
 l. {Ø, {2}, {3}, {2,3}}

 Question 4:

 PART I:

 a)
 c. one-to-one but not onto. For example, y = 2 cannot be mapped to by any integer x via f(x) = x^3
 g. one-to-one but not onto. For example, (1, 3) cannot be mapped to by any integers (x,y) via f(x) = (x+1, 2y)
 k. not one-to-one or onto. For example, f(1,3) = f(2,1) = 5 and f(x,y) = 1 cannot be mapped to by any positive integers x and y via f(x)

 b)
 b.
 Check if one-to-one:
 f({000}) = 100
 f({100}) = 100
 So, not one-to-one.
 Check if onto:
 y = 000 cannot be mapped to by any integer x via f(x) since the output must always have a 1 as the first bit.
 So, not onto.

 c.
 Check if one-to-one:
 f({000}) = 000
 f({001}) = 100
 f({010}) = 010
 f({011}) = 110
 f({100}) = 001
 f({101}) = 101
 f({110}) = 011
 f({111}) = 111
 Since each value maps to a unique output, f is one-to-one.
 Check if onto:
 The target is {0,1}^3 = {000, 001, 010, 011, 100, 101, 110, 111}
 The range is {000, 001, 010, 011, 100, 101, 110, 111}
 Since the target and the range are the same, f is onto.

 d.
 Check if one-to-one:
 f({000}) = 0000
 f({001}) = 0010
 f({010}) = 0100
 f({011}) = 0110
 f({100}) = 1001
 f({101}) = 1011
 f({110}) = 1101
 f({111}) = 1111
 Since each value maps to a unique output, f is one-to-one.
 Check if onto:
 The target is {0,1}^4. So 0001 is in the target.
 The range is {0000, 0010, 0100, 0110, 1001, 1011, 1101, 1111}
 However, 0001 is not in the range.
 Since some values from the target are not in range, f is not onto.

 g.
 Check if one-to-one:
 f({1}) = Ø
 f(Ø) = Ø
 So, not one-to-one.
 Check if onto:
 The target is P(A).
 {1} is a value in P(A), since 1 is an element in A.
 y = {1} cannot be mapped to by any integer x via f(x).
 So, f is not onto.

 Part II

 a. -2x + 3 if x <= 0, 2x + 2 if x > 0
 b. |x| + 1
 c. -2x + 1 if x <= 0, 2x if x > 0
 d. x^2 + 5

 Question 5:
 a)
 c.
 f^-1: Z --> Z, f^-1 (x)= (x - 3) / 2

 d.
 {2,3} and {1,2} are both in P(A)
 f({2,3}) = 2
 f({1,2}) = 2
 So f is not one-to-one.
 Since f is not a bijection it does not have a well defined inverse.

 g.
 f({110}) = 011
 f(f(110)) = 110
 f is its own inverse.
 Therefore, f^-1: {0, 1}3→{0, 1}3. The output of f^-1 is obtained by taking the input string and reversing the bits.

 i.
 f^-1: ZxZ --> ZxZ, f^-1(x,y) = (x-5, y+2)

 b)
 c. f o h = 2(x^2 + 1) + 3 = 2x^2 + 5
 d. h o f = (2x+3)^2 + 1 = 4x^2 + 12x + 10

 c)
 b.
 f o h (52) = f(ceil(52/5)) = f(11) = 121

 c.
 g o h o f (4) = g(h(f(4))) = g(h(16)) = g(4) = 2^4 = 16

 d.
 h o f = ceil(x^2/5)

 d)
 c.
 h o f (010) = h(f(010)) = h(110) = 111

 d.
 Since f replaces the first bit of a 3 bit string with 1,
 the range of f {100, 101, 110, 111}
 Since h replaces the last bit of the input with a copy of the first,
 the range of h o f is {101, 111}

 e.
 Since f replaces the first bit of a 3 bit string with 1,
 the range of f {100, 101, 110, 111}
 Since g reverses the bits,
 the range of g o f is {001, 101, 011, 111}

 e)
 c.
 If f is not one-to-one, then:
 Ex1,x2 (x1 != x2) ^ (f(x1) = f(x2) = y) for some value int the target y.

 As such, g o f (x1) = g(f(x1)) = g(y)
 And, g o f (x2) = g(f(x2)) = g(y)

 Therefore,  g(f(x1)) = g(f(x2)) = g(y).

 So it is not possible that f is not one-to-one and g ο f is one-to-one.

 d.
 Consider the example:
    f           g
 a. ------> 1 -----> x
 b. ------> 2 -----> y
            3 -------^
 In this example, g is not one-to-one given that g(2) = g(3) = y

 Nonetheless:
     f o g
 a. ------> x
 b. ------> y

 Since each input element in f o g maps to a unique output, f o g is one-to-one.

 Therefore,it is possible that g is not one-to-one and g ο f is one-to-one.
 */
