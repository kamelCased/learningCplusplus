/*

 Question 1:
 Theorem: For n>= 1, 2^(2n+1)+1 is divisible by 3

 Proof by induction on the value of n

 I) Base case (n=1):

 = 2^(2n+1)+1
 = 2^(2*1+1)+1
 = 2^3+1
 = 8+1
 = 9
 = 3 * 3 If we set m=3, we get:
 = 3m
 Since it can be written as 3 times an integer, 2^(2*1+1)+1 is divisible by 3.
 So the theorem is true for the base case.

 II) Inductive step:

 Inductive hypothesis: For any k>=1, 2^(2k+1)+1 is divisible by 3
 Show that 2^(2(k+1)+1)+1 is divisible by 3

 = 2^(2(k+1)+1)+1
 = 2^(2k+1+2)+1                     Multiply out the 2
 = 2^2 * 2^(2k+1) + 1               Exponent rule
 = 2^2 * (3m - 1) + 1               By inductive hypothesis, since 2^(2k+1)+1 is divisible by 3. We can write it as 3m for some integer m. So 2^(2k+1) = 3m-1
 = 4*3m - 4 + 1                     Multiply out the 2^2
 = 4*3m - 3                         Subtract 1 from 3
 = 3(4m - 1)                        Factor out a 3
 Since m is an integer, 4m - 1 is also an integer.
 Since it can be written as 3 times an integer, 2^(2(k+1)+1)+1 is divisible by 3.
 Therefore, the theorem is proven true by induction.

 Question 2:

 Peter needs to choose k red balls from the 30 red balls: C(30,k)
 Peter needs to choose the remaining balls from the 70 green balls.
 Since we already chose k balls and we need to choose 20 balls total,
 the remaining number of balls to be chosen is 20-k.
 We get:
 #choices = C(30,k)C(70,20-k) = 30!/(k!(30-k)!) * 70!/((20-k)!k!)

 Question 3:

 I am not perfectly fluent in English, so I am taking net winnings to mean profit
 (to get amount earned just don't subtract the initial 1000)

 a.

 Get the range:
 First place: 4500 - 1000 = 3500
 Second place: 3500 - 1000 = 2500
 Third place: 1500 - 1000 = 500
 Fourth or worse: Lose -1000. So -1000

 We know that:
 P(1st) = P(X=3500) = 1/20
 P(2nd) = P(X=2500) = 1/10
 P(3rd) = P(X=500) = 1/4
 P(4th+) = P(X=-1000) = 1 - P(1st) - P(2nd) - P(3rd) = 1 - 1/20 - 1/10 - 1/4 = 20/20 - 1/20 - 2/20 - 5/20 = 12/20 = 3/5

 So the distribution is (-1000, 3/5), (500, 1/4), (2500, 1/10), (3500, 1/20)

 b.

 The expected value is the weighted average of the value of the random variable multiplied by the probability for that value
 E[X] = -1000.P(X=-1000) + 500.P(X=500) + 2500.P(X=2500) + 3500.P(X=3500)
 E[X] = -1000.3/5 + 500.1/4 + 2500.1/10 + 3500.1/20
 E[X] = -1000.12/20 + 500.5/20 + 2500.2/20 + 3500.1/20
 E[X] = (-12000+2500+5000+3500)/20
 E[X] = -6000/20
 E[X] = -300

 Question 4:

 a. func1

 Outside the for loops func1 does constant work (memory allocation, assignment to arr, assignment to count, delete, return)
 So theta(1)

 The first for loop:
 - Each iteration does constant work (checks boolean, mods i by 2, adds 1, assigns to arr[i], and increments i). So theta (1)
 - The loop iterates n times (from 0 to n-1, incrementing by 1).
 So, since it does constant operations n times,
 by the product rule, this loop has a runtime complexity of theta(n).

 The second set of for loops. From the inside out:
 - Each iteration of the inner for loop does constant work (boolean check, increments count, increments j), so theta(1)
 - The inner for loop runs from 1 to arr[i]. Above we saw that the value placed in arr[i] was i%2+1.
 So, since i%2 = 0 or 1, arr[i] will always have a value of 1 or 2. So the inner for loop iterates a constant number of times and
 does constant work each time. Thus it is theta(1).
 - The outer for loop iterates n times (from 0 to n-1, incrementing by 1) and does constant operations n times (since the nested loop has constant runtime).
 So, by the product rule, this set of loops has a runtime complexity of theta(n).

 In total, summing up all the components we get:
 T(n) = theta(n + n + 1)
 T(n) = theta(2n+1)
 Dropping leading constants and lower order terms, we get
 T(n) = theta(n)

 Therefore, func1 has an asymptotic runtime complexity of theta(n).

 b.

 Outside the for loops func1 does constant work (memory allocation, assignment to arr, assignment to count, delete, return)
 So these operations are theta(1)

 The first for loop:
 - Each iteration does constant work (checks boolean, adds i to n, assigns to arr[i], and increments i). So theta (1)
 - The loop iterates n times (from 0 to n-1, incrementing by 1).
 So, since it does constant operations n times,
 by the product rule, this loop has a runtime complexity of theta(n).

 The second set of for loops. From the inside out:
 - Each iteration of the inner for loop does constant work (boolean check, increments count, increments j), so theta(1)
 - The inner for loop runs from 1 to arr[i], incrementing by 1. Above we saw that the value placed in arr[i] was i+n. Since i in that
 context went from 0 to n, we get that n <= arr[i] < 2n (since for i = 0, n+1 = n and for i = n, n+i = n+n = 2n).
 So the inner for loop always iterates a linear number of times (up to 2n-1 times) and
 does constant work each time. Thus its runtime complexity is 2n-1 which is theta(n).
 - The outer for loop iterates n times (from 0 to n-1, incrementing by 1) and does theta(n)
 operations n times (since the nested loop has linear runtime).
 So, by the product rule, this set of loops has a runtime complexity of theta(n^2).

 In total, summing up all the components we get:
 T(n) = theta(n^2 + n + 1)
 Dropping leading constants and lower order terms, we get
 T(n) = theta(n^2)

 Therefore, func2 has an asymptotic runtime complexity of theta(n^2).

 */