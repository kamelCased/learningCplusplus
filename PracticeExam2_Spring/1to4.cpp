/*

 Question 1:

 Theorem: For n>= 1, n^2+n is divisible by 2

 Proof by induction on the value of n

 I) Base case (n=1):
 = n^2+n
 = 1^2+1
 = 2
 = 2 * 1. If we set m=1, we get:
 = 2m
 Since is can be expressed as 2 times an integer, n^2+n is divisible by 2.
 So the theorem is true for the base case.

 II) Inductive step:

 Inductive hypothesis: For any k>= 1, k^2+k is divisible by 2.
 Show that (k+1)^2+(k+1) is divisible by 2

 = (k+1)^2+(k+1)
 = k^2 +2k + 1 + k + 1      Distribute square
 = (k^2+k) + 2k+2           Group k^2+k together
 = 2m + 2k+2                by inductive hypothesis, (k^2+k) is divisible by 2 so we can express it as 2m for some integer m.
 = 2(m+k+1)                 factor out 2
 Since m and k are integers, m+k+1 is also an integer.
 So (k+1)^2+(k+1) can be written as 2 timed an integer, so it is divisible by 2.
 The theorem holds true for the inductive step and is proven by induction. q.e.d.

 Question 2:

 "At least one girl" is the complement of "no girls"
 #(at least one girl) = #(total n selections) - #(no girls)

 "No girls" is synonymous with "all boys"
 #(at least one girl) = #(total n selections) - #(n selections from boys)

 total selections: there are 3n + 7n students in total so 10n.
 So there are 10n options to choose n students from.
 So #(total n selections) = C(10n,n)

 boy selections: there are 3n boys
 So there are 3n options to choose n students from.
 So #(n selections from boys) = C(3n,n)

 We get:
 #(at least one girl) = #(total n selections) - #(n selections from boys)
 #(at least one girl) = C(10n,n) - C(3n,n)
 #(at least one girl) = 10n!/2n!8n! - 3n!/n!2n!
  #(at least one girl) = 10n*9n/2n! - 3n*2n/2n!
  #(at least one girl) = (10n*9n-3n*2n)/2n!
    #(at least one girl) = (90n-6n)/2n!
    #(at least one girl) = 84n/2n*1n
    #(at least one girl) = 84n/2n
    #(at least one girl) = 37n

  Question 3:

  a.

  range: {1,2,3} since the maximum value must be one of the spinners value. Let's find the ditrisbution:
  P(X=1) = |{(1,1)}| / 3^2 = 1/9
  P(X=2) = |{(2,1),(2,2),(1,2)}| / 3^2 = 3/9
  P(X=3) = |{(1,3),(2,3),(3,3),(3,2),(3,1)}| / 3^2 = 5/9

  So the distribution is (1, 1/9), (2, 3/9), (3, 5/9)

 b.

 The expected value is the weighted average of each value of the random variable in the distribution multiplied by its probability.
 We get:

 E[X] = 1.P(X=1) + 2.P(X=2) + 3.P(X=3)
 E[X] = 1 * 1/9 + 2 * 3/9 + 3 * 5/9
 E[X] = 1/9 + 6/9 + 15/9
 E[X] = 22/9

 Question 4:

 a. func1

 Outside the for loops, the function does constant work:
 - memory allocation
 - assignment to arr
 - assignment to sum
 - delete
 - return
 We can model this as 5. (Note: since it is theta(1), we will most likely drop this term)

 The first for loop:
 - Each iteration does constant work (adds 1 to i and assigns that value to arr[i]). So theta(1)
 - The for loop iterates n times from 0 to n-1.
 So, by the product rule, the runtime complexity of this for loop is theta (n * 1) = theta(n)

 The second set of for loops. Let's work from the inside out:
 - Each iteration of the inner for loop does constant work (sums i and j and adds the result to sum)
 - The inner for loop runs from 0 to arr[i]. When we assigned values to arr[i] in the first for loop,
   we assigned values from 1 to n+1 in incrementing order. So the inner for loop runs (i+1) times and does constant work each iteration.
 - The outer for loop runs n times from from 0 to n. Each iteration of the outer for loop will do (i+1) times work.
   So in total, by the product rule, we get: n * (i+1)
   We know that we can approximate this progression as n(n+1)/2. So the runtime complexity of this for loop is n(n+1)/2

 To get the total runtime complexity we sum all the terms and get:
 T(n) = n(n+1)/2 + n + 5
 T(n) = 1/2n^2 + 1/2n + n + 5
 T(n) = 1/2n^2 + 3/2n + 5

 Since we're looking for asymptotic runtime complexity, we can drop the leading constants and lower order terms.
 This gives us T(n) = theta(n^2).

 Therefore, the asymptotic runtime complexity of func1 is theta(n^2)

 b. func2

 Outside the for loops, the function does constant work:
 - memory allocation
 - assignment to arr
 - assignment to sum
 - delete
 - return
 We can model this as 5. (Note: since it is theta(1), we will most likely drop this term)

 The first for loop:
 - Each iteration does constant work (assigns j to arr[i], and increments i and doubles j). So theta(1)
 - The for loop iterates n times from 0 to n-1.
 So, by the product rule, the runtime complexity of this for loop is theta (n * 1) = theta(n)

 The second set of for loops: Let's work from the inside out.
 - Each iteration of the inner for loop does constant work (sums i and j and adds it to sum). So theta(1)
 - The inner for loop iterates from j = 1 to j= arr[i]. We saw in the previous for loop, that the value of arr[i] doubles every time
   for n iterations. So in n iterations arr[i] reaches the value 2^n. So the inner for loop needs to iterate 2^n times and does constant work each iteration. theta(2^n).
 - The outer for loop iterates n times from 0 to n-1. It does theta(2^n) work each iteration because of its nested loop.
 So by the product rule, the runtime complexity is n * 2^n * 1 = theta(n*2^n)

 To get the overall runtime complexity we sum all sequential terms up:
 T(n) = n*2^n + n + 5
 Since we're looking for asymptotic runtime complexity, we can drop the lower order terms.
 This gives us T(n) = theta(n*2^n).

 Therefore, the asymptotic runtime complexity of func2 is theta(n*2^n)

 */