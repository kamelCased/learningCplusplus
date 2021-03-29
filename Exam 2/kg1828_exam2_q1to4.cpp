/*
 Question 1:

 Theorem: For n>=1, An >= (sqrt(2))^n   (where An is the nth fibonacci number as defined in the problem)

 Proof by mathematical induction on the value of n.

 I) Base case (n=1):
 - A1 = 1
 - (sqrt(2))^1 = sqrt(2) = 1.4
 A1 < (sqrt(2))^1
 So the theorem fails the base case.
 The theorem must be false.

 I suspect the question meant to ask about:

  Theorem: For n >= 6, An >= (sqrt(2))^n. So I will answer that using strong induction:

 I) Base case (n=6):
 - A6 = 8
 - (sqrt(2))^6 = 8
 A6 >= (sqrt(2))^6
 Therefore, the theorem holds true for the base case.

 II) Inductive step

 Inductive hypothesis: For any j in the range 3 through k, Aj <= (sqrt(2))^j
 Show that A(k+1) <= (sqrt(2))^(k+1)

 A(k+1) = Ak + Ak-1
 A(k+1) >= (sqrt(2))^(k) + Ak-1                             By inductive hypothesis, k is in the range so Ak <= (sqrt(2))^(k)
 A(k+1) >= (sqrt(2))^(k) + (sqrt(2))^(k-1)                  By inductive hypothesis, k-1 is in the range so A(k-1) <= (sqrt(2))^(k-1)
 A(k+1) >= (sqrt(2))(sqrt(2))^(k-1) + (sqrt(2))^(k-1)
 A(k+1) >= (2 + sqrt(2))(sqrt(2))^(k-1)                     x + x = 2x
 A(k+1) >=  (sqrt(2)^2)(sqrt(2))^(k)                                2 > sqrt(2) so we can replace 2 by sqrt(2) and it will make the inequality greater
 A(k+1) >= (sqrt(2))^(k+1)
 Therefore, the theorem holds true for the inductive step.

 Question 2:

 a.
 There are 10 decimal digits (0-9)
 The first digit in the pin code can be any of these 10
 The second digit in the pin code can be any of the remaining 9
 The third digit in the pin code can be any of the remaining 8
 The fourth digit in the pin code can be any of the remaining 7
 So by the product rule the total number is:
 P(10,4) = 10*9*8*7 = 5040 pin codes

 b.
 There are 10 decimal digits (0-9)
 The first digit in the pin code can be any digit up to 6 (since the following digits must be higher than it)
 The second digit in the pin code can be any digit between the first digit and 7
 The third digit in the pin code can be any digit between the second digit and 8
 The fourth digit in the pin code can be any digit between the third digit and 9 (the highest digit)

 C(6,1) * C(10-first,1) * C(10-second,1) * C(10-third,1)

 If first is 0:
 1 * 2 * 3 * C(10-3,1) = 1*2*3*7
 1 * 2 * 4 * C(6,1) = 1*2*3*6
 1 * 2 * 5 * C(5,1) = 1*2*3*5
 1 * 2 * 6 * C(4,1) = 1*2*3*4
 1 * 2 * 7 * C(3,1) = 1*2*3*3
 1 * 2 * 8 * C(2,1) = 1*2*3*2
 1 * 2 * 8 * C(2,1) = 1*2*3*1


 Question 3:

 a.

 For the record, I am assuming both dice are tossed in the same time during a single trial.
 So I am considering one toss to be we hold both dice in our hand and toss them together.

 Let's first find the range:

 If we get two even numbers on the first try. X=1.
 If we don't get two even numbers on the first try, but get them on the second try. X=2.
 If we don't get two even numbers on the first or second try, but get them on the third try. X=3.
 If we don't get two even numbers on the first, second or third try, we are done regardless of whether we get two evens on the fourth try or not. X=4

 We know that two dice thrown are independent. So P(red even and blue even) = P(red even) * P(blue even)
 P(even) = |{2,4,6}|/|{1,2,3,4,5,6}| = 3/6 = 1/2

 Let's find the probabilities:
 P(X=1) = P(red even) * P(blue even)
 P(X=1) = 1/2 * 1/2
 P(X=1) = 1/4

 P(X=2) = (1 - P(red even and blue even on 1st try)) * (P(red even) * P(blue even))
 P(X=2) = (1 - 1/4) * (1/4)
 P(X=2) = 3/4 * 1/4
 P(X=2) = 3/16

 P(X=3) = P(not double even on 1st) * P(not double even on 2nd) * P(double even on third)
 P(X=3) = (1 - P(red even and blue even)) * (1 - P(red even and blue even)) * (P(red even) * P(blue even))
 P(X=3) = (1 - 1/4) * (1 - 1/4) * (1/4)
 P(X=3) = (3/4) * (3/4) * (1/4)
 P(X=3) = (9/16) * 1/4
 P(X=3) = 9/64

 P(X=4) = P(not double even on 1st) * P(not double even on 2nd) * P(not double even on third) * (1)
 P(X=4) = (3/4) * (3/4) * (3/4) * 1
 P(X=4) = 27/64

 So the distribution is (1, 1/4), (2, 3/16), (3, 9/64), (4, 27/64)

 b.

 The expected value is the weighted average of the values of the random variable multiplied by their respective probabilities.
 We get these from the distribution.

 E[X] = 1.P(X=1) + 2.P(X=2) + 3.P(X=3) + 4.P(X=4)
 E[X] = 1 * (1/4) + 2 * (3/16) + 3 * (9/64) + 4 * (27/64)
 E[X] = 16/64 + 24/64 + 27/64 + 108/64
 E[X] = 175/64
 E[X] = 2.73

 Question 4:

 a.

 Outside of the for loops, the function does constant work (assignment to count, return).
 So theta(1)

 The for loops. Let's work form the inside out.
 - Each iteration of the inner for loop does constant work (increments count). So theta(1).
 - The inner for loop iterates from 0 to i and does constant work each iteration.
 We know that i doubles its value with each iteration and goes up to log(n). So the inner for
 loop has exponential theta(2^(log(n))) runtime.
 - The outer for loop runs from 1 to log(n), doubling the value of i each iteration.
 The outer for loop does 2^(log(n)) work each iteration.
 Therefore, the asymptotic runtime is log(2^(log(n)). Let's simplify this:
 = log(2^(log(n))        Since by log rules, we know that log(a^b) = b log(a)
 = log(n) * log(2)       Log rule: log_a(a) = 1
 = log(n)
 Therefore, the loops have a log(n) runtime

 Since it's the most significant runtime, we can drop lower order runtimes outside the loop.

 Therefore, the asymptotic runtime complexity of func is log(n).

 b.

 1.
 Inside the first10Squares function, Ben-El initialized a static array arr to hold the values of the first 10 squares.
 We know that static arrays are stored on the runtime stack for that function.
 We know that when a function ends, the runtime stack pops out and all local variables in it are lost.
 Therefore, when first10Squares ends its runtime stack pops out and the static array is lost.
 So when he calls printArray with arr in the main, arr points to garbage values and it will print out whatever garbage values are there.

 2.
 On line 8, instead of declaring a static array. Ben-El can declare a pointer to a dynamic array that holds the values of the squares.
 The code is:
 int* arr = new int [10];

 */