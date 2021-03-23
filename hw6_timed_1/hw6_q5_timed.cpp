/*

 Question 5:

 a.

 Show big O:

 for   n >= 1
    3n^3 >= 3n

 for  n >= 1
   2n^3 >= 2n^2

 So: 5n^3 + 2n^3 + 3n^3 >= 5n^3 + 2n^2 + 3n
                  10n^3 >= 5n^3 + 2n^2 + 3n
                  10n^3 >= f(n)
 Show Omega:

 for   n >= 1
    3n   >= 0

 for  n >= 1
   2n^2 >= 0

 So: 5n^3 + 2n^2 + 3n   >= 5n^3 + 0 + 0
                 f(n)   >= 5n^3

 By definition, f(n) = Theta(g(n)) if c1.g(n) >= f(n) >= c2.g(n) for some n0.
 So if we take n0 = 1, c1 = 10, c2 = 5 we get:
 10n^3 >= f(n) >= 5n^3

 Therefore, f(n) is theta(n^3).

 b.

 Show big O:

 For n >= 1
   2n^2 >= 2n

 For n >= 1
     0 >= -8

 So sqrt(n^2+2n^2 + 0) >= sqrt(n^2+2n-8)
    sqrt(3n^2) >= sqrt(n^2+2n-8)
    3n >= sqrt(n^2+2n-8)
    3n >= f(n)

 Show Omega:

 2n - 8 >= 0
 2n >= 8
 n >= 4

 So for n >= 4:

 sqrt(n^2+ 2n^2-8) >= sqrt(n^2 + 0)
 sqrt(n^2+ 2n^2-8) >= n

 By definition, f(n) = Theta(g(n)) if c1.g(n) >= f(n) >= c2.g(n) for some n0.
 So if we take n0 = 4, c1 = 3, c2 = 1 we get:
 3n >= f(n) >= n

 Therefore, f(n) is theta(n).

 */