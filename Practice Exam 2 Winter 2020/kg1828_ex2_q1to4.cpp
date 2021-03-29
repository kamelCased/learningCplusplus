/*
 Question 1:

 Theorem: For n>= 2, An < (7/4)^n-1

 Proof by induction on the value of n.

 I) Base case (n = 2):
 - The second Fibonacci number A_2 = 1
 - (7/4)^(2-1) = (7/4)^1 = 7/4
 Since  1 < 7/4
       A_n < (7/4)^(n-1)
 So the theorem holds true for the base case.

 II) Inductive step:

 Inductive Hypothesis: For any k>= 2, A_k < (7/4)^(k-1)
 Show that for k+1, A_(k+1) < (7/4)^(k+1-1)

 A_(k+1) = A_k + A_(k-1)                            according to Fibonacci definition
 A_(k+1) < (7/4)^(k-1) + A_(k-1)                    by inductive hypothesis
 A_(k+1) < (7/4)^(k-1) + A_(k) - A_(k-2)            Since A_k = A_(k-1) +  A_(k-2) --> A_(k-1) = A_k - A_(k-2)
 A_(k+1) < (7/4)^(k-1) + (7/4)^(k-1) - A_(k-2)      by inductive hypothesis
 A_(k+1) < 2*(7/4)^(k-1)
 A_(k+1) < (7/4)(7/4)^(k-1)                         since A_(k-2) > 1 (all Fibonacci numbers are greater than 1)  if we replace 2 by 7/4 we make the inequality greater
 A_(k+1) < (7/4)^((k+1)-1)     q.e.d

 Therefore, theorem proven by induction.

 Question 2:

 At least 4 zeroes is the complement of 0,1,2,or 3 zeros
 #strings with 0 zeros: C(n,0) for the zeros, and 2^n since the other two can be anything else (1 or 2)
 #strings with 1 zeros: C(n,1) for the zeros, and 2^n-1 since the other two can be anything else (1 or 2)
 #strings with 2 zeros: C(n,2) for the zeros, and 2^n-2 since the other slot can be anything else (1,2)
 #strings with 3 zeros: C(n,3) for the zeros, and 2^n-3 since the other slot can be anything else (1,2)

 #(4+) = #(ternary strings) - #(0) - #(1) - #(2) - #(3)
        = 3^n - C(n,0)*2^n - C(n,1)*2^(n-1) + C(n,2)*2^(n-2) + C(n,3)*2^n-3
        = 3^n - 2^n - 2n^(n-1) + C(n,2)*2^(n-2) + C(n,3)*2^n-3

 
 Question 3:

 a.
 P(X=1): 1/2 = 1/2                   Probability of getting heads is 1/2 and the game stops
 P(X=2): 1/2 * 1/2 = 1/4             Probability of getting tails is 1/2 then heads 1/2 and the game stops
 P(X=3): 1/2 * 1/2 * 1/2 = 1/8       Probability of getting tails is 1/2, tails 1/2, then heads 1/2 and the game stops
 P(X=4): 1/2 * 1/2 * 1/2 * 1 = 1/8   Probability of getting tails is 1/2, tails 1/2, heads 1/2 and on the fourth throw if you get a heads the game stops if you get a tails the game also stops so 1/2+1/2 = 1.

 b.

 E(X)   = 1.P(X=1) + 2.P(X=2) + 3.P(X=3) + 4.P(X=4)
        = 1 * 1/2 + 2 * 1/4 + 3 * 1/8 + 4 * 1/8
        = 4/8 + 4/8 + 3/8 + 4/8
        = 15/8


 Question 4:

 a. func1

 Aside from the for loops, the function does constant work:
 - assignment to arr
 - memory allocation
 - set count to 0
 - delete
 - return
 We can model this runtime as 5.

 The first for loop:
 - Each iteration does constant work (indexes arr[i] and sets arr[i] to 7), we can model this as 2.
 - The for loop runs from 0 to n-1. Thereby iterating n times.
 Combining by the product rule, we can model this runtime as 2n.

 The second set of for loops:
 - Each iteration of the second for loop does constant work (increments count)
 - The inner for loop runs a constant number of times (always runs 7 times, since we set arr[i]=7 for all i).
 - The outer for loop runs from 0 to n-1. Thereby iterating n times.
 Combining by the product rule, we can model this runtime as 7n.

 In total, we get: T(n) = 7n + 2n + 5 = 9n + 5
 To get the asymptotic runtime, we can ignore leading constants and drop lower order terms.

 Therefore, func1 has an asymptotic time complexity of theta(n).

 b. func2

 Aside from the for loop in func2, thee declaration is negligible. So we'll focus on the for loop.

 The for loop runs from n to 1, thereby running n times. Each iteration of the for loop makes a call to reverseArray.
 So to determine the work done at each iteration let's analyze reverseArray

 from the inside out:
 - Each iteration of reverseArray does constant work (swaps mirror image elements in the array)
 - Since left increments and right decrements every iteration, reverseArray runs i/2 times.
 Therefore, the runtime of the loop is i/2
 - reverseArray has no significant cost otherwise, so the total cost of a call to reverseArray is i/2

 Since i goes from n to 1, i = n(n+1)/2
 So i/2 = n(n+1)/4

 So the runtime can be modeled as 1/4n^2 + 1/4n.

 To get the asymptotic runtime, we can ignore leading constants and drop lower order terms.

 Therefore, func1 has an asymptotic time complexity of theta(n^2).

 */
