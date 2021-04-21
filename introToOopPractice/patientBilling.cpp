#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

class Person {

    string name;

public:

    // Contructor (person is born)
    Person(string newName) : name(newName) {}

    // Accessors
    string getName() const { return name; }

    // Mutators
    void changeName(string newname) { name = newname; }
};

class SalariedEmployee: public Person {

    double salary;
    int ssn;

public:

    // Constructors
    SalariedEmployee():  Person(""), salary(0), ssn(-1) {}
    SalariedEmployee (string the_name, int the_ssn, double the_weekly_salary): Person(the_name), ssn(the_ssn), salary(the_weekly_salary){}

    // Accessors
    double getSalary() const {return salary;};
    int getSsn() const {return ssn;}

    // Mutators
    void setSalary(double new_salary) {salary = new_salary;}
    void setSsn(int new_ssn) {ssn = new_ssn;}
};

class Doctor: public SalariedEmployee {

    string specialty;
    double fee;

public:

    // Constructors
    Doctor(): SalariedEmployee(), specialty(""), fee(0) {}
    Doctor(string specialty, double fee): fee(fee), specialty(specialty) {}
    Doctor(string name, string specialty, double fee = 100.00, int ssn = 00, double salary = 0.0): SalariedEmployee(name, ssn, salary), specialty(specialty), fee(fee) {}
    Doctor(const Doctor& doc): SalariedEmployee(doc.getName(), doc.getSsn(), doc.getSalary()), specialty(doc.specialty), fee(doc.fee) {}

    // Accessors
    string getSpecialty() const {return specialty;}
    double getFee() const {return fee;}

    // Mutators
    void setSpecialty(string s) {specialty = s;}
    void setFee(double f) {fee = f;}

    // Overloaded Operator
    Doctor& operator=(const Doctor& rhs);

};
Doctor& Doctor::operator=(const Doctor& rhs) {
    if (this != &rhs) {
        changeName(rhs.getName());
        setSalary(rhs.getSalary());
        setSsn(rhs.getSsn());
        setSpecialty(rhs.specialty);
        setFee(rhs.fee);
    }
    return *this;
}
ostream& operator<<(ostream& o, const Doctor& dr) {
    cout << "Physician: Dr. " << dr.getName() << endl;
    cout << "Specialty: " << dr.getSpecialty() << endl;
    cout << setprecision(2) << fixed;
    cout << "Office visit fee: $" << dr.getFee() << endl;

    return o;
}

class Patient: public Person {

    Doctor primaryPhysician;

public:

    // Constructors
    Patient(): Person(""), primaryPhysician(Doctor()) {}
    Patient(const string& name): Person(name), primaryPhysician(Doctor()) {}
    Patient(const string& name, Doctor dr): Person(name), primaryPhysician(dr) {}

    // Accessors
    Doctor getDoctor() {return primaryPhysician;}

    // Mutators
    void changeDoctors(Doctor newDoc) {primaryPhysician = newDoc;}
};

int main() {

    string name;
    cout << "Hello, welcome to the Reem Gazzaz clinic for underserved populations!" << endl;
    cout << "What is your name?" << endl;
    getline(cin, name);

    char choice;
    cout << "Thank you, " << name << "." << endl;
    cout << "Do you already have a doctor at the clinic? (y/n)" << endl;
    cin >> choice;
    cin.ignore(1);

    string doctorName, doctorSpecialty;
    if (choice == 'y' | choice == 'Y') {
        cout << "What is your doctor's name?" << endl;
        getline(cin, doctorName);
        cout << "What specialty is Dr. " << doctorName << "?" << endl;
        getline(cin, doctorSpecialty);
    }
    else {
        doctorName = "Generic";
        cout << "What specialty doctor are you looking for?" << endl;
        getline(cin, doctorSpecialty);
        cout << "Great. I have Dr. " << doctorName << ", who is a great " << doctorSpecialty << endl;
    }

    Doctor doctor(doctorName, doctorSpecialty);

    string lowerDoc = "";
    for (char ch: doctorSpecialty) {
        lowerDoc += tolower(ch);
    }
    if (lowerDoc == "generalist" || lowerDoc == "general praticioner" || lowerDoc == "gp" || lowerDoc == "family doctor") {
    }
    else {
        double fee = 250.00;
        doctor.setFee(fee);
    }

    Patient patient(name, doctor);
    cout << "Thank you " << patient.getName() << "! You're all set with Dr. " << patient.getDoctor().getName() << " (" << patient.getDoctor().getSpecialty() << ")."<< endl;
    cout << fixed << setprecision(2) << "Your appointment will cost $" << patient.getDoctor().getFee() << endl;

    return 0;
}
