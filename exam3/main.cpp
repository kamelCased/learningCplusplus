/*
 Problem 1.

 Answer is c.

 int DLL::getFirstValue() const;


 Problem 2.

 Answer is b. An abstract class (though getBetterVal() should be marked as const)

 Problem 3.

 Stack stages:
 *
 ( *
 + ( *
 *
 /

 Output during stages:
 3
 3 4
 3 4 5
 3 4 5 +
 3 4 5 + *
 3 4 5 + * 2 /

 Final Output in postfix form:
 3 4 5 + * 2 /

 Problem 4.

 a. Constructor (that takes an int or equivalent)
 b. Copy constructor
 c. Destructor

 Problem 5.

 2, 5, 4, 3, 8, 9, 7

 Problem 6.

#include <vector>
using namespace std;

void quicksort(vector<double>& busLocs, int start, int end) {

    if(end - start < 10) {
        insertionSort(busLocs, start, end);
        return;
    }

    int mid = (start + end) / 2;
    if (busLocs[start] > busLocs[mid]) {
        double temp = busLocs[start];
        busLocs[start] = busLocs[mid];
        busLocs[mid] = temp;
    }
    if (busLocs[mid] > busLocs[end]) {
        double temp = busLocs[mid];
        busLocs[mid] = busLocs[end];
        busLocs[end] = temp;
    }
    if (busLocs[start] > busLocs[end]) {
        double temp = busLocs[start];
        busLocs[start] = busLocs[end];
        busLocs[end] = temp;
    }
    double pivot = busLocs[mid];
    busLocs[mid] = busLocs[end-1];
    busLocs[end-1] = pivot;

    int iLeft = start;
    int iRight = end-1;
    for (;;) {
        while (busLocs[++iLeft] < pivot) {}
        while (busLocs[--iRight] < pivot) {}
        if (iLeft < iRight){
            double temp = busLocs[iLeft];
            busLocs[iLeft] = busLocs[iRight];
            busLocs[iRight] = temp;
        }
        else {
            break;
        }
    }
    double temp = busLocs[iLeft];
    busLocs[iLeft] = busLocs[end - 1];
    busLocs[end - 1] = temp;

    quicksort(busLocs, start, iLeft - 1);
    quicksort(busLocs, iLeft+1, end);
}

void quicksort(vector<double>& busLocs) {
    quicksort(busLocs, 0, busLocs.size() -1);
}

bool busesTooClose(string busLine) {

    vector<double> busLocs = getBusLineInfo(busLine);
    quicksort(busLocs);

    for (int i = 0; i < busLocs.size() - 1; i++) {
        if (busLocs[i+1] - busLocs[i] <= 1)
            return true;
    }

    return false;
}

 void insertionSort(vector<double>& busLocs, int start, int end) {

    for (int i = start + 1; i <= end; i++) {
        double value = busLocs[i];
        int j = i;
        while(j > start && busLocs[j] > busLocs[i]) {
                busLocs[j] = busLocs[j-1];
                j--;
        }
        busLocs[j] = value;
    }
}

 Problem 7.

     template <class T>
     void fixList(LListNode<T>* node) {

        if (node == nullptr || node == tail)
            return;

        else if (node->prev == head) {
            fix(node->next);
        }

        else {
            LListNode<T>* temp = node->prev;
            node->prev = node->next;
            node->next = temp;
            if (node->next != nullptr && node->next != tail)
                fix(node->next->next);
        }
    }



 Problem 8.
#include <iostream>
#include <vector>
using namespace std;

class Discount {
public:
    virtual double calculateFinalDiscount(double price) const = 0;
};

class SingleValueDiscount: public Discount {
    double value;
public:
    SingleValueDiscount(double newVal = 0.0): value(newVal){}
    virtual double calculateFinalDiscount(double price) const {return value;}
};

class SinglePercentDiscount: public Discount {
    double percent;
public:
    SinglePercentDiscount(double newPct = 0.0): percent(newPct) {}
    virtual double calculateFinalDiscount(double price) const;
};
double SinglePercentDiscount::calculateFinalDiscount(double price) const {
    return price - (price * (1 - percent));
}

class MultiDiscount: public Discount {
    double value, percent;
public:
    MultiDiscount(double newPct = 0.0, double newVal = 0.0): value(newVal), percent(newPct) {}
    virtual double calculateFinalDiscount(double price) const;
};
double MultiDiscount::calculateFinalDiscount(double price) const {
    return price - ((price - value) * (1 - percent));
}

class Order {
    vector<double> prices;
    vector<Discount*> discounts;
public:
    double addItem(double price, Discount* discount = nullptr);
    double totalCost();
};
double Order::addItem(double price, Discount* discount) {
    prices.push_back(price);
    discounts.push_back(discount);
}
double Order::totalCost() {
    double totalCost = 0.0;
    for (int i = 0; i < prices.size(); i++) {
        if (discounts[i] != nullptr) {
            double appliedDisc  = discounts[i]->calculateFinalDiscount(prices[i]);
            cout << prices[i] << " " << appliedDisc << endl;
            totalCost += prices[i] - appliedDisc;
        }
        else {
            totalCost += prices[i];
        }
    }

    return totalCost;
}


int main () {

    Order firstOrder;
    SingleValueDiscount svd10(10.0);
    SinglePercentDiscount spd5(.5);
    MultiDiscount md(.102, 5.5);
    firstOrder.addItem(20, &svd10);
    firstOrder.addItem(100, &spd5);
    firstOrder.addItem(20, &md);
    firstOrder.addItem(20, nullptr);
    cout << firstOrder.totalCost() << endl;
}
*/