/*

Question 10:

np = 100 * 1/100 = 1

 Question 9:
 b.

 Question 8:
 n[i] can be even or odd only not both.
 So either i will increment or j will decrement by 1 on every iteration of the while loop
 Therefore, since the while loop runs about n times and does constant work at every iteration
 The asymptotic runtime complexity is O(n)

 Question 7:
 Each iteration of inner for loop does constant work
 The inner for loop iterates m times from 0 to m-1
 The outer for loop iterates n times from 0 to n-1
 Therefore, by the product rule the asymptotic runtime complexity is
 O(n*m)

 Question 6:

 P:1
 R: 1
 O: 1
 B: 2
 A: 1
 I: 2
 L: 1
 T: 1
 Y: 1

 |PROBABILITY|! / (2!2!) = 11!/(2!2!)

 Question 5:
 address of n passed into function n modified to 10
 local m is 10, main m is 5
 *n + local m = 10 + 10 = 20
 res = 20
 so res + n + m = 20 + 10 + 5 = 35

 Question 4:
 P~(AuB) = 0.42
 P(AuB) = 1 - P~(AuB) = 1 - 0.42 = 0.58
 P(AuB) = P(A) + P(B) - P(AnB)
 P(AnB) = P(A) + P(B) - P(AuB)
 P(AnB) = 0.4 + 0.3 - 0.58 = 0.12
 P(A|B) = P(AnB)/P(B) = 0.12/0.3 = 0.4
 Since P(A|B) = P(A), Independent!

 Question 3:
 c. 7C4 * 6C4 * 4!

 Question 2:
 P(AuB) = 1 - P~(AuB)
        = 1 - 2/3
        = 1/3 c.

 Question 1:
 Theorem: For n >= 4, n! > 2^n
 Proof by induction on the value of n

 I) Base Case: n=4: 4! = 4*3*2*1 = 24 > 16 = 2^4
    Theorem holds true for base case.

 II) Inductive step:
    Inductive hypothesis: For any k>= 4, k! >= 2^k
    Show that (k+1)! > 2^(k+1)

    (k+1)!  = k! * (k+1)
            > 2^k * (k+1) by inductive hypothesis
            > 2^k * k + 2^k
            > 2^k * 2 + 2^k    since k>= 4 we can say k > 2
            > 2^k+1 + 2^k
    (k+1)!  > 2^k+1           since k>=4, 2^k is positive removing it only makes the inqueality greater

    Therefore, since (k+1)!  > 2^k+1, the theorem is proven by induction
*/
