/*
// Question 1
#include <iostream>
using namespace std;

int main() {
    double item1, item2;
    cout << "Enter price of first item: ";
    cin >> item1;
    cout << "Enter price of second item: ";
    cin >> item2;

    char clubCard;
    cout << "Does customer have a club card (Y/N): ";
    cin >> clubCard;

    double taxRate;
    cout << "Enter tax rate: ";
    cin >> taxRate;

    double basePrice = item1 + item2;
    cout << "Base price: " << basePrice << endl;

    if (item1 > item2) {
        item2 /= 2;
    }
    else {
        item1 /= 2;
    }

    double discountPrice = item2 + item1;
    if ((clubCard == 'Y') || (clubCard == 'y')) {
        discountPrice = 0.9 * discountPrice;
    }
    cout << "Price after discounts: " << discountPrice << endl;

    discountPrice *= (1 + taxRate/100);
    cout << "Total price: " << discountPrice << endl;

    return 0;
}
*/
/*
// Question 2
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    int gradYear;
    cout << "Please enter your grad year: ";
    cin >> gradYear;
    int currYear;
    cout << "Please enter the current year: ";
    cin >> currYear;

    if (gradYear <= currYear) {
        cout << name << ", you graduated";
    }
    else if (gradYear - currYear == 1) {
        cout << name << ", you are a senior";
    }
    else if (gradYear - currYear == 2) {
        cout << name << ", you are a junior";
    }
    else if (gradYear - currYear == 3) {
        cout << name << ", you are a sophomore";
    }
    else if (gradYear - currYear == 4) {
        cout << name << ", you are a freshman";
    }
    else {
        cout << name << ", you are not in college yet";
    }

    return 0;
}
*/
/*
//Question 3:
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double a, b, c;
    cout << "Please enter the value of a: ";
    cin >> a;
    cout << "Please enter the value of b: ";
    cin >> b;
    cout << "Please enter the value of c: ";
    cin >> c;

    double discriminant = b*b - 4*a*c;
    double root1, root2;

    if ((a==0) && (b==0) && (c==0)) {
        cout << "infinite solutions" << endl;
    }
    else if ((a==0) && (b==0)) {
        cout << "no solutions" << endl;
    }
    else if (discriminant < 0) {
        cout << "no real solutions" << endl;
    }
    else if (discriminant == 0){
        root1 = (-b)/(2*a);
        cout << "one real solution x=" << root1 << endl;
    }
    else if ((a==0) && (b!=0)) {
        root1 = -b/c;
        cout << "one real solution: " <<root1 <<endl;
    }
    else {
        root1 = (-b - pow(discriminant, 0.5)) / (2*a);
        root2 = (-b + pow(discriminant, 0.5)) / (2*a);
        cout << "two real solutions x1=" << root1 << " and x2=" << root2 << endl;
    }

    return 0;
}
 */
/*
//Question 4
#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double num;
    cout <<"Please enter a real number: " <<endl;
    cin >> num;

    int round;
    cout << "Choose your rounding method:" << endl;
    cout << "1.	Floor	round" <<endl;
    cout << "2.	Ceiling	round" << endl;
    cout << "3.	Round to the nearest whole number" << endl;
    cin >> round;

    int roundedNumber;

    if (num >= 0) {
        switch (round) {
            case 1:
                roundedNumber = (int) num;
                break;
            case 2:
                if ((int)num == num) {
                    roundedNumber = (int) num;
                }
                else {
                    roundedNumber = int (num + 1);
                }
                break;
            case 3:
                roundedNumber = int (num + 0.5);
                break;
        }
    }
    else {
        switch (round) {
            case 1:
                if ((int)num == num) {
                    roundedNumber = (int) num;
                }
                else {
                    roundedNumber = int (num - 1);
                }
                break;
            case 2:
                roundedNumber = (int) num;
                break;
            case 3:
                roundedNumber = int (num - 0.5);
                break;
        }
    }
    cout << roundedNumber << endl;

    return 0;
}
*/
/*
//Question 5
#include <iostream>
using namespace std;

int main (){
    double height, weight;
    cout << "Enter your height in inches: ";
    cin >> height;
    cout << "Enter your weight in lbs: ";
    cin >> weight;

    weight *= 0.453592;
    height *= 0.0254;
    double bmi = (weight) / (height * height);

    string weightStatus;
    if (bmi >= 30) {
        weightStatus = "Obese";
    }
    else if (bmi >= 25) {
        weightStatus = "Overweight";
    }
    else if (bmi >= 18.5) {
        weightStatus = "Normal";
    }
    else {
        weightStatus = "Underweight";
    }

    cout << "The weight status is: " << weightStatus << endl;

    return 0;
}
*/
/*
//Question 6
#include <iostream>
#include <string>
using namespace std;

int main () {
    string day;
    cout << "Enter the day of your call: ";
    cin >> day;

    int hour, minute;
    char colon;
    cout << "Please enter the call start time in 24h notation: ";
    cin >> hour >> colon >> minute;

    int duration;
    cout << "Please enter the call duration in minutes: ";
    cin >> duration;

    double callPrice;
    if ((day == "Sa") ||(day == "Su" )) {
        callPrice = 0.15 * duration;
    }
    else {
        if ((hour < 8)||(hour > 18)||((hour == 18) && (minute != 0)))  {
            callPrice = 0.25 * duration;
        }
        else {
            callPrice = 0.4 * duration;
        }
    }

    cout << "Price of call: $" << callPrice << endl;

    return 0;
}
*/
/*
Question 7:
a)
 a. True
 b. False
 c. True
 d. False
 e. True
 f. False
 g. False

b)
 a. False
 b. True
 c. True
 d. True
 e. False

c)
 b. {3x: x in Z+}
 d. {10x: x in N and x < 100}

d)
 a. True
 b. True
 c. False
 d. False
 e. True
 f. True
 g. True
 h. False
 i. False
 j. False
 k. False

 Question 8:
 b. P(A) = {Ø, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}}
 The set is all elements in P(A) with cardinality of 2.
 {{1,2}, {1,3}, {2,3}}

 Question 9:
 a)
 c. {-3, 1, 17}
 d. {-5, -3, 0, 1, 4, 17}
 e. {1}

 b)
 a. {1}
 b. {1, 2, 3, 4, 5, 9, 16, 25}
 e. {x in R: -1/100 <= x <= 1/100}
 f. {x in R: -1 <= x <= 1}

 c)
 b. P({a,b,c}) = {Ø, {a}, {b}, {c}, {a,b}, {a,c}, {b,c}, {a,b,c}}
 d. {Ø, {a}, {b}, {c}, {a,b} {b,c}}

 Question 10:
 a)
 b. {foam, tall, non-fat}
 c. {{foam, non-fat}, {foam, whole}, {no-foam, non-fat}, {no-foam, whole}}

 b)
 b. True
 c. True
 e. True

 c)
 d. {01,011,001,0011}
 e. {aaa, aaaa, aba, abaa}

 d)
 c. {aa, ab, ac, ad}
 f. P({ab,ac}) = {Ø, {ab}, {ac}, {ab,ac}}
 g. {Ø, {a}} {Ø, {b}, {c}, {b,c}} {(Ø,Ø), (Ø,{b}), (Ø,{c}), (Ø,{b,c}), ({a},Ø), ({a},{b}), ({a},{c}), ({a},{b,c})}

 Question 11:
 a)
 b.
 1. (B u A) n (B` u A)
 2. (A u B) n (B` u A)      commutative law on 1
 3. (A u B) n (A u B`)      commutative law on 2
 4. A u (B n B`)            distributive law on 3
 5. A u Ø                   complement law on 4
 6. A                       identity law on 5

 c.
 1. (A n B`)`
 2. A` u B``              De Morgan's law on 1
 3. A` u B                Double complement law on 2

 b)
 b.
 A = {a,b,c}
 B = {c,d,e}
 A - (B n A)  = {a,b}
 A - (B n A) != A

 d.
 A = {a,b,c}
 B = {c,d,e}
 (B - A) u A = {a,b,c,d,e}
 (B - A) u A != A

 c)
 b.
 1. A n (B - A)
 2. A n (B n A`)        Set subtraction law on 1
 3. (A n B) n A`        Associative law on 2
 4. (B n A) n A`        Commutative law on 3
 5. B n (A n A`)        Associative law on 4
 6. B n Ø               Complement law on 5
 7. Ø                   Domination law on 6

 c.
 1. A u (B - A)
 2. A u (B n A`)            set subtraction law on 1
 3. (A u B) n (A u A`)      distributive law on 2
 4. (A u B) n Universe      complement law on 3
 5. A u B                   identity law on 4
*/




