/*

 6.5.1

 a.

 1*1 = 1
 2*1,1*2 = 2
 3*1,1*3 = 3
 4*1,2*2,1*4 = 4
 5*1,1*5 = 5
 6*1,3*2,2*3,1*6 = 6
 2*4,4*2 = 8
 2*5,5*2 = 10
 3*3 = 9
 3*4,6*2,2*6,4*3 = 12
 3*5,5*3 = 15
 3*6,6*3 = 18
 4*4 = 16
 4*5,5*4 = 20
 4*6,6*4 = 24
 5*5 = 25
 5*6,6*5 = 30
 6*6 = 36

 range: {1,2,3,4,5,6,8,9,10,12,15,16,18,20,24,25,30,36}

 distribution:
 (1, 1/36), (2, 2/36), (3, 2/36),  (4, 3/36),  (5, 2/36),  (6, 4/36)
 (8, 2/36), (9, 1/36), (10, 2/36),  (12, 4/36), (15, 2/36), (16, 1/36),
 (18, 2/36), (20, 2/36), (24, 2/36), (25, 1/36), (30, 2/36), (36, 1/36)

 b.

 P(X=6) = 4/36 = 1/9

 6.5.2

 a.
 range = {0,1,2,3,4}

 b.

 P(0 aces) = C(48,5)/C(52,5)
 P(1 aces) = C(4,1)C(48,4)/C(52,5)
 P(2 aces) = C(4,2)C(48,3)/C(52,5)
 P(3 aces) = C(4,3)C(48,2)/C(52,5)
 P(4 aces) = C(4,4)C(48,1)/C(52,5)

 (0, C(48,5)/C(52,5)), (1, C(4,1)C(48,4)/C(52,5)), (2, (C(4,2)C(48,3)/C(52,5)), (3, C(4,3)C(48,2)/C(52,5), (4, C(4,4)C(48,1)/C(52,5)

 6.5.3

 a.
 range = {0,1,2}

 b.
 P(G=0) = C(3,2)/C(10,2)
 P(G=1) = C(3,1)C(7,1)/C(10,2)
 P(G=2) = C(7,2)/C(10,2)

 (0, C(3,2)/C(10,2)), (1, C(3,1)C(7,1)/C(10,2)), (2, C(7,2)/C(10,2))

 6.5.4

 a.
 range = {0,1,2,3,4,5}

 b.
 P(F=2) = C(5,2)C(35,5)/C(40,7)

 6.5.5

 a.
 HHHHH.HHHHH = 10 - 0
 HHHHH.HHHHT = 9 - 1 = 8
 HHHHH.HHHTT = 8 - 2 = 6
 ...
 Decreases by 2 every time.

 range = {10, 8, 6, 4, 2, 0, -2, -4, -6, -8, -10}

 b.
 P(X=10) = P(10 heads and 0 tails) = C(10,10)/2^10
 P(X=8) = P(9 heads and 1 tails) =  C(10,9)/2^10
 P(X=6) = P(8 heads and 2 tails) = C(10,8)/2^10
 P(X=4) = P(7 heads and 3 tails) = C(10,7)/2^10
 P(X=2) = P(6 heads and 4 tails) = C(10,6)/2^10
 P(X=0) = P(5 heads and 5 tails) = C(10,5)/2^10
 P(X=-2) = P(4 heads and 6 tails) = C(10,4)/2^10
 P(X=-4) = P(3 heads and 7 tails) = C(10,3)/2^10
 P(X=-6) = P(2 heads and 8 tails) = C(10,2)/2^10
 P(X=-8) = P(1 heads and 9 tails) = C(10,1)/2^10
 P(X=-10) = P(10 tails and 0 tails) = C(10,0)/2^10

 distribution:
 (-10, 1/2^10), (-8, 10/2^10), (-6, C(10,8)/2^10), (-4, C(10,7)/2^10), (-2, C(10,6)/2^10)
 (0, C(10,5)/2^10), (2, C(10,4)/2^10), (4, C(10,3)/2^10), (6, C(10,2)/2^10), (8, 10/2^10), (10, 1/2^10)

 */