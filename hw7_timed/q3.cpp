/*

 8.2.2 b

 f(n) = n^3 + 3n^2 + 4

 Show big O:

 For n >= 1
     3n^3 >= 3n^2
     4n^3 >= 4

     So n^3 + 3n^3 + 4n^3 >= n^3 + 3n^2 + 4
                     8n^3 >= n^3 + 3n^2 + 4
                     8n^3 >= f(n)

 Show omega:

  For n >= 1
     3n^2 >= 0
     4 >= 0
     3n^2 + 4 >= 0

    So n^3 + 0 <= n^3 + 3n^2 + 4
        n^3 <= n^3 + 3n^2 + 4
        1.n^3 <= f(n)

    By definition, f(n) is theta(g(n)) if c1.g(n) >= f(n) >= c2.g(n) for n >= n0 for positive real numbers c1 and c2 and positive integer n
    If we take c1 = 8, c2 = 1 and n0 = 1, we get:
    8n^3 >= f(n) >= n^3

    Therefore, f(n) = theta(n^3)


    8.3.4

    a. The input that would cause the inner for loop to execute the most number of times is an input where no product ai * aj == prod.

    b. The inner for loop does constant work and iterates (n-1)/2 times the outer for loop iterates n times, so the wort case lower bound would be Omega(n^2)

    c. Yes, it is important to consider the worst case input when finding the asymptotic lower bound.
       If the same length input had a0 * a1 == prod for example, the loops would execute once, then return true.
       So the asymptotic time complexity would not be the same, it would be O(1).

    d. The inner for loop does constant work and at maximum will iteration (n-1)/2 times, the outer for loop iterates at maximum n times.
       So the overall time complexity will have an upper bound O(n^2)

    8.3.1

    a.
    Outside the loop, the function does constant work O(1)

    The loop also does constant work each iteration (boolean check and potential increment)
    and iterates n times.

    Therefore, the asymptotic time complexity is theta(n).

    8.3.2

    a.

    Outside the loops, the function does constant work O(1)

    The inner loop also does constant work per iteration (addition, boolean checkm, and if true assignment).
    The inner loop iterates n/2 times.
    The outer loop iterates n times.

    By the product rule, the worst-case asymptotic time complexity is theta (n^2)

    8.3.3

    Outside the loops, the function does constant work O(1)

    The innermost loop also does constant work per iteration (addition, boolean checkm, and if true assignment).
    The innermost for loop iterates n times (from 1 to n)
    The middle for loop does linear work per iteration and iterates n times. So it's time complexity is theta(n^2)
    The outer for loop does quadratic work per iteration and iterates n times.
    So it's runtime complexity is theta(n^3).

    We can disregard lower order terms outside the loop.
    We get an overall worst case time complexity of theta(n^3)

 */