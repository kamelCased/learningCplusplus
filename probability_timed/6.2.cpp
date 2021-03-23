/*
 6.2.1

 a. P(0 tails) + P(1 tail) = 1/2^n + n/2^n = (n+1)/2^n
 b. 1 - P(nosameflips) = 1 - 2/2^n
 c. 1 - P(same heads tails) = 1 - n/2/2^n = 1 - n/2^(n+1)

 6.2.2

 a. (Mutually exclusive): P(Celia) + P(Felicity) = 2 * (n-1)! / n!
 b. (Not mutually exclusive): P(Celia first) + P(Felicity last) - P(Celia first n Felicity last) = (n-1)!/n! + (n-1)!/n! - (n-2)!/n!
 c. 1 - P(Celia next to Felicity) = 1 - 2 * (n-1)! / n!
 d. (Not mutually exclusive): P(next to Celia) + P(next to Felicity) - P(next to Celia n Felicity) = 2 * (n-1)! / n! + 2 * (n-1)! - 2 * (n-2)!/n!
 e. P~(next to Celia v Felicity) = 1 - P(next to Celia v Felicity) = 1 - (2 * (n-1)! / n! + 2 * (n-1)! - 2 * (n-2)!/n!)

 6.2.3

 a. 1 - P(no friends) = 1 - 2 * C(1,1) * C(7,4) * C(5,5) / C(10,5)
                      = 1 - 2 * C(7,4) / C(10,5)

 6.2.4

 a. 1 - P(no club) = 1 - C(39,5)/C(52,5)
 b. 1 - P(no same rank) = 1 - C(13,5) * C(4,1)^5 / C(52,5)
 c. P(one club) + P(one spade) - P(one club n one spade) = C(13,1) * C(39,4) / C(52,5) + C(13,1) * C(39,4) / C(52,5) - C(13,1) * C(13,1) * C(26,3) / C(52,1)
 d. 1 - P(no club n no spade) = 1 - C(26,5)/C(52,5)

 6.2.5

 a. P (valid) = C(26,1) * C(26,1) * C(10,1) * 62^7 / 62^10

 */