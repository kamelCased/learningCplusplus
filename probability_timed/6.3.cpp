/*

 6.3.1

 a. P(A) = P(2 evens) + P (2 odds) = 3*3/6^2 + 3*3/6^2 = 1/4 + 1/4 = 1/2
  . P(B) = {55, 46, 64, 56, 65, 66} = 1/6
  . P(C) = 1/6

 b. P(A|C) = P(AnC) / P(C) = |{51,53,55}|/36 / 1/6 = 3/6 = 1/2

 c. P(B|C) = P(BnC) / P(C) = {55, 56} = 2/36 / 1/6 = 12/36 = 1/3

 d. P(A|B) = P(AnB) / P(B) = |{66}|/36 / 6/36 = 1/6

 e. P(A|B) != P(A) so A and B are not independent
    P(A|C) = P(A) so A and C are independent
    P(B|C) = P(B) so B and C are independent

 6.3.2
 a. p(A) = 6!/7! = 1/7
  . p(B) = 1/2
  . p(C) = 5!/7! = 1/42

 b. P(A|C) = P(AnC) / P(C) = 3!*2 / 5! = 2/4*5 = 1/10

 d. P(A|B) = P(AnB) / P(B) = 6!/(2*7!) / 1/2 = 6!/7! = 1/7

 c. P(B|C) = P(BnC) / P(C) = 5!/2/5! = 1/2

 e. P(A|C) != P(A) so not independent
  . P(A|B) = P(A) so independent
  . P(B|C) = P(B) so independent

 6.3.3
 a. 2*7!/8! = 2/8 = 1/4
 b. 7!/8! = 1/8
 c. P(AnB) = 2*6!/8! = 2/56 = 1/28  !=  P(A).P(B) = 1/4 * 1/8 = 1/32 not independent

 6.3.4
 a. P(JnC) = 2 * C(7,2) / C(10,5)
    P(J) = 2 * C(8,3) / C(10,5)
    P(J|C) = C(7,2) / C(10,5)
    Not independent

 6.3.5
 a. P(A) = C(13,1) * C(4,4) * C(12,1) * C(4,1) / C(52/5)
    P(A) = 13*48 / C(52,5)

    P(B) = 1 - P(~B) = 1 - C(39,5) / C(52,5)

    P(AnB) = C(12,1) * C(4,3) * C(1,1) * C(4,1) * C(2,1) / C(52,5)
    P(AnB) = 12*16*2 / C(52,5)

    P(A).P(B) = (13*48*C(52,5) - C(39,5)) / C(52,5)

    If equal, independent. Else, not independent.

 6.3.6
 a. (1/3)^10
 b. (1/3)^5*(2/3)^5
 c. 1/3*(2/3)^10

 */