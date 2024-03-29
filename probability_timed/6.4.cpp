/*
 P(Fair|X) = P(X|F)P(F) / (P(X|F)P(F) + P(X|~F)P(~F))
            = (1/6)(1/2) / ((1/6)(1/2) + (2/7)(1/2))
            = .37


P(F|Y)  = P(Y|F)P(F) / (P(Y|F)P(F) + P(Y|~F)P(~F))
        = (5/36)(1/2) / ((5/36)(1/2)+(10/49)(1/2))

 FN(0.01)
 FP(0.02)
 P(F|D) = P(D|F)P(F) / (P(D|F)P(F) + P(D|~F)P(~F))
        = 0.99 * 0.001 / (0.99*0.001 + 0.02 * 0.999)
        = 0.047

 P(D) = 0.0001
 FN = P(~T|D) =  0.01
 FP = P(T|~D) = 0.005

 6.4.1

 a.
 Result: 7 tails, 3 heads
 P(X|B) = (.75^7)(.25^3)
 P(X|B) = (.5^7)(.5^3)

 P(B|X) = P(X|B)P(B) / (P(X|B)P(B) + P(X|~B)P(~B))
        = (.75^7)(.25^3)(1/2) / ((.75^7)(.25^3)(1/2) + (.5^10)*(1/2))
        = 0.68

 6.4.2

 a.

 P(X|~B) = (1/6)^6
 P(X|B) = (0.15^4)(0.25^2)

 P(~B|X) = P(X|~B)P(~B) / (P(X|B)P(B) + P(X|~B)P(~B))
         = (1/6)^6(1/2) / ((0.15^4)(0.25^2)(1/2) + (1/6)^6(1/2))
         = 0.404

 6.4.3

 a.

 P(D) = 0.03
 FP = P(T|~D) = 0.02
 FN = P(~T|D) = 0.04

  P(D|T) = P(T|D)P(D) / (P(T|D)P(D) + P(T|~D)P(~D))
         = 0.96 * 0.03 / (0.03 * 0.96 + 0.02 * 0.97)
         = 0.597

 6.4.4

 a.

 P(HIV) = 0.0001
 FP = P(T|~HIV) = 0.025
 FN = P(~T|HIV) = 0

 P(HIV|T) = P(T|HIV)P(HIV) / (P(T|HIV)P(HIV) + P(T|~HIV)P(~HIV))
          = 1 * 0.0001 / (1 * 0.0001 + 0.025*0.9999)
          = 0.00398

 */