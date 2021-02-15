/*
 // Assignment: NYU Tandon Bridge Exam 1
 // Author: Kamel Gazzaz
 // Date: 02/11/2021

 // Question 1

 a.

 The decimal number in question is (148)10

 Using the successive divisions method:

 148 / 4 = 37 R 0
 37 / 4 = 9 R 1
 9 / 4 = 2 R 1
 2 / 4 = 0 R 2

 Therefore, (148)10 = (2110)4

 b.

 The number in question is (1011 1100)8 bit 2's complement

 Step 1: Determine if positive or negative
 The leftmost bit is 1, as such the number is negative

 Step 2: Calculate the positive complement
 1 1111 1
   1011 1100
 + 0100 0100
 ------------
 1 0000 0000

 Step 3: Convert the positive complement to decimal
 0100 0100 = 1 * 2^2 + 1 * 2^6 = (68)10

 Step 4: Add the negative sign
 Therefore, (1011 1100)8 bit 2's complement = (-68)10

 // Question 2

 1. ~(~p --> q)
 2. ~(~~p v q)  Conditional identity
 3. ~(p v q)    Double negation
 4. ~p ^ ~q     De Morgan's law

 Therefore, the answer is d. ~p ^ ~q

 // Question 3
 a. False
 b. True
 c. True
 d. False

 // Question 4
 Sentence: “There is an employee that is not a manager, which earns more than at least one manager”
            ------                          -------      -----  ________         --------   ------
            Ex                              ~V(x)          ^       M(x,y)           Ey        V(y)

 Therefore, the answer is b. Ex (~V(x) ^ Ey (V(y) ^ (M(x,y)))

 // Question 5

 D - (A u B) = {1,2,3,4,5,6,7,8,9,10} - {x in Z: x is odd or x is a power of 2} = {6, 10}

 Therefore, the answer is c. {6, 10}

 // Question 6
 1. ~P(3)
 2. ~P(3) v Q(3)                Addition
 3. Ex (~P(x) v Q(x))           Existential generalization

 Answer is c.

 // Question 7

 Theorem: The average of any two real numbers is greater than or equal to at least one of the two numbers.

 A proof by contradiction starts by assuming the opposite of the theorem.
 Opposite: The average of any two real numbers is less than both of the two numbers.

 In mathematical terms: For every two real numbers, x and y, ((x+y) / 2 < x) ^ ((x+y) / 2 < y)

 Therefore, the answer is a.

 // Question 8
 a. True
 b. False
 c. True
 d. True
 e. True
 f. False
 g. False
 h. True
 i. True
 j. True

 //Question 9

 Step 1: Check if f is one-to-one

 By definition, the function f takes any input value in the domain and adds 1 to it.

 Each natural number n maps to a unique n + 1.

 So, f is one-to-one.

 Step 2: Check if f is onto.

 We know that:
 - The function f increases as the input value increases.
 - The domain is the set of natural numbers.

 So the smallest output of f is mapped to by the smallest natural number in the domain (i.e. 0)
 f(0) = 0 + 1 = 1

 We cannot get f(x) = 0 for any input value in the domain.

 As such, f is not onto.

 Therefore, the answer is b. one-to-one but not onto

 // Question 10

 Step 1: Find all values in the domain
 {0,1}^2 = {00,01,10,11}

 Step 2: Evaluate the function for all inputs
 f(00) = 0001
 f(01) = 0011
 f(10) = 0101
 f(11) = 0111

 Therefore, the range of f is {0001, 0011, 0101, 0111}.

 */