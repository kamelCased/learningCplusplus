/*
 // Question 1:

 a.
 (178)10
 178 / 2 = 89 R 0
 89 / 2 = 44 R 1
 44 / 2 = 22 R 0
 22 / 2 = 11 R 0
 11 / 2 = 5 R 1
 5 / 2 = 2 R 1
 2 / 2 = 1 R 0
 1 / 2 = 0 R 1
 Therefore, (178)10 = (10110010)2

 b.
 (11101100)8 bit two's complement

  Step 1: Determine if posiitve or negative:
  Since the first bit is one, the number is negative.

  Step 2: Determine the positive complement:

  1 1111 1
    1110 1100
  + 0001 0100
  ------------
  1 0000 0000

  Step 3: Convert the positive complement to decimal
  0001 0100 = 1 * 2^2 + 1 * 2^4 = 4 + 16 = (20)10

  Step 4: Add the negative sign to get the negative complement's decimal value
  Therefore, (11101100)8 bit two's complement = (-20)10

  // Question 2
  Step 1: Define propositions
  - b: patient has high blood pressure
  - i: patient has influenza

  Step 2: Express the sentence in mathematical form:
  ~(~b ^ ~i)

  Step 3: Apply laws
  1. ~(~b ^ ~i)
  2. ~~b v ~~i      De Morgan's
  3. b v ~~i        Double negation
  4. b v i          Double negation

  Step 4: Translate back to English
  Therefore, the answer is d. The patient has high blood pressure or has influenza.

  //Question 3
  1. Anne is in the domain  Given in description
  2. P(Anne) --> Q(Anne)    Given in table, since ~P(Anne), the implication P(Anne) --> Q(Anne) is true
  3. Ex (P(x)-->Q(x))       existential generalization on 1,2

  Therefore, the answer is c.

  //Question 4
  The sentence is:
  Everyone who earns more than Miguel is a manager
  -------  --    ----------               ------
  Ax       ->       M(x, Miguel)            V(x)

  We get: Ax (M(x, Miguel), V(x))

  Answer is a.

  //Question 5
  The sentence is:
  Someone who did not study for the test received an A on the test.
  ------- --     ----------                     ------
  Ex       ^         ~S(x)                         A(x)

  We get: Ex (~S(x) ^ A(x))

  Answer is c.

  // Question 6
  1. ~Ax Ey (P(x)^Q(x,y))
  2. Ex ~Ey (P(x)^Q(x,y))       De Morgan's law
  3. Ex Ay ~(P(x)^Q(x,y))       De Morgan's law
  4. Ex Ay (~P(x) v ~Q(x,y))    De Morgan's law

  Answer is c.

  //Question 7
  P(A) contains sets as its elements.
  Therefore, any subset of P(A) must also contain sets as elements.
  The set {2,3} contains numbers as elements and not sets.
  Therefore, the set {2,3} cannot be a subset of P(A)

  Answer is d.

  //Question 8
  a. True, 1 is in the roster notation
  b. False, 1 is not a set so it can't be a subset
  c. True, {2} is in the roster notation
  d. False, there is no element 2 in A
  e. False, {3,4} is not in the roster notation
  f. False, 3 and 4 are not elements in A
  g. True, {{3,4}} is in the roster notation
  h. False, {3,4} is not an element in A
  i. False, Ø is not in the roster notation
  j. True, Ø is a subset of all sets

  //Question 9

  Check if one-to-one:
  f(0000) = 000
  f(1000) = 000
  So not one-to-one.

  Check if onto:
  f(0000) = 000
  f(0001) = 001
  f(0010) = 010
  f(0011) = 011
  f(0100) = 100
  f(0101) = 101
  f(0110) = 110
  f(0111) = 111
  The first half of the domain covers all the values in the target.
  So f is onto.

  Therefore, the answer is c.

  //Question 10
  Step 1: Determine P(A)
  P(A) = {Ø, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}}

  Step 2: Determine the range
  f(Ø) = Ø
  f({1}) = Ø
  f({2}) = {2}
  f({3}) = {3}
  f({1,2}) = {2}
  f({1,3}) = {3}
  f({2,3}) = {2,3}
  f({1,2,3}) = {2,3}

  Therefore, the range of f is {Ø, {2}, {3}, {2,3}}.

  */