#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(): name(""){};
    Person(string the_name): name(the_name) {}
    Person(const Person &the_object): Person(the_object.name){}

    string get_name() const {return name;}

    Person &operator=(const Person &rt_side) {name = rt_side.name; return *this;}

    friend istream &operator>>(istream &in_stream, Person &person_object);
    friend ostream& operator <<(ostream& out_stream, const Person& person_object);
private:
    string name;
};
istream &operator>>(istream &i, Person &person_object) {
    string name;
    cout << "Enter the person's name: ";
    getline(i, name);
    person_object.name = name;

    return i;
}
ostream& operator <<(ostream& o, const Person& person_object) {
    o << person_object.name << endl;
    return o;
}

class Vehicle {
    string manufacturer;
    int cylinders;
    Person owner;

public:

    // Constructors
    Vehicle(): manufacturer(""), cylinders(0), owner(Person()) {}
    Vehicle(string company, int engine, Person proprietor): manufacturer(company), cylinders(engine), owner(proprietor) {}
    Vehicle(const Vehicle& v): manufacturer(v.manufacturer), cylinders(v.cylinders), owner(v.owner) {}

    // Accessors
    string getManufacturer() const {return manufacturer;}
    int getCylinders() const {return cylinders;}
    Person getOwner() const {return owner;}

    // Mutators
    void setManufacturer(string m) {manufacturer = m;}
    void setCylinders(int c) {cylinders = c;}
    void setOwner(const Person& o) {owner = o;}

    // Overloaded operator
    Vehicle& operator=(const Vehicle& v) {if (this != & v) { manufacturer = v.manufacturer; owner = v.owner; cylinders = v.cylinders;} return *this;}
};

class Truck: public Vehicle {
    double loadCapacity;
    int towingCapacity;

public:

    // Constructors
    Truck(): Vehicle(), loadCapacity(0), towingCapacity(0) {}
    Truck(double load, int tow): Vehicle(), loadCapacity(load), towingCapacity(tow) {}
    Truck(string manufacturer, int engine, string owner, double load, int tow): Vehicle(manufacturer, engine, owner), loadCapacity(load), towingCapacity(tow) {}
    Truck(const Truck& t): Vehicle(t), loadCapacity(t.loadCapacity), towingCapacity(t.towingCapacity) {}

    // Accessors
    double getLoadCapacity() const {return loadCapacity;}
    int getTowingCapacity() const {return towingCapacity;}

    // Mutators
    void setLoadCapacity(double newLoad) {loadCapacity = newLoad;}
    void setTowingCapacity(int newTow) {towingCapacity = newTow;}

    // Overloaded operator
    Truck& operator=(const Truck& rhs) {if (this != & rhs){Vehicle::operator=(rhs); setLoadCapacity(rhs.loadCapacity); setTowingCapacity(rhs.towingCapacity);} return *this;}
};

class Car: public Vehicle {
    int doors;
    string model;
    string color;
public:

    // constructors
    Car(): Vehicle(), doors(0), model(""), color("") {}
    Car(int d, string m, string c): Vehicle(), doors(d), model(m), color(c) {}
    Car(string man, int cyl, Person own, int dor, string mod, string col): Vehicle(man, cyl, own), doors(dor), model(mod), color(col) {}
    Car(const Car& c): Vehicle(c), doors(c.doors), model(c.model), color(c.model) {}

    // Accessors
    int getDoors() const {return doors;}
    string getModel() const {return model;}
    string getColor() const {return color;}

    // Mutators
    void setDoors(int d) {doors = d;}
    void setModel(string m) {model = m;}
    void setColor(string c) {color = c;}

    // Overloaded operator
    Car& operator=(const Car& c) {if (this != & c){Vehicle::operator=(c); doors = c.doors; model = c.model; color = c.color;} return *this;}
};

class SportsCar: public Car{
    bool convertible;
    bool suicideDoors;
    int hp;
public:

    // Convertible
    SportsCar(): Car(), convertible(false), suicideDoors(false), hp(0) {}
    SportsCar(bool con, bool suicide, int horses): Car(), convertible(con), suicideDoors(suicide), hp(horses) {}
    SportsCar(string man, int cyl, Person own, int dor, string mod, string col, bool con, bool suicide, int horses): Car(man, cyl, own, dor, mod, col), convertible(con), suicideDoors(suicide), hp(horses) {}
    SportsCar(const SportsCar& sc): Car(sc), convertible(sc.convertible), suicideDoors(sc.suicideDoors), hp(sc.hp) {}

    // Accessors
    bool isConvertible() const {return convertible;}
    bool hasSuicideDoors() const {return suicideDoors;}
    int getHP() const {return hp;}

    // Mutators
    void setConvertible(bool c) {convertible = c;}
    void setSuicideDoors(bool s) {suicideDoors = s;}
    void setHP(int h) {hp = h;}

    // Overloaded operator
    SportsCar& operator=(const SportsCar& sc) {if (this != &sc) {Car::operator=(sc); convertible = sc.convertible; suicideDoors = sc.suicideDoors; hp = sc.hp;} return *this;}
};