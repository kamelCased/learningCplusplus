#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SalariedEmployee {
public:
    SalariedEmployee(): salary(0), name(""), ssn(-1) {}
    SalariedEmployee (string the_name, int the_ssn, double the_weekly_salary): name(the_name), ssn(the_ssn), salary(the_weekly_salary){}
    double get_salary() const {return salary;};
    string get_name() const {return name;}
    int get_ssn() const {return ssn;}
    void set_salary(double new_salary) {salary = new_salary;}
    void set_ssn(int new_ssn) {ssn = new_ssn;}
    void set_name(string new_name) {name = new_name;}
private:
    double salary;//weekly
    string name;
    int ssn;
};
class Doctor: public SalariedEmployee {

    string specialty;
    double fee;

public:

    // Constructors
    Doctor(): SalariedEmployee(), specialty(""), fee(0) {}
    Doctor(string specialty, double fee): fee(fee), specialty(specialty) {}
    Doctor(string name, string specialty, int ssn, double salary, double fee): SalariedEmployee(name, ssn, salary), specialty(specialty), fee(fee) {}
    Doctor(const Doctor& doc): SalariedEmployee(doc.get_name(), doc.get_ssn(), doc.get_salary()), specialty(doc.specialty), fee(doc.fee) {}

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
        set_name(rhs.get_name());
        set_salary(rhs.get_salary());
        set_ssn(rhs.get_ssn());
        setSpecialty(rhs.specialty);
        setFee(rhs.fee);
    }
    return *this;
}
ostream& operator<<(ostream& o, const Doctor& dr) {
    cout << "Physician: Dr. " << dr.get_name() << endl;
    cout << "Specialty: " << dr.getSpecialty() << endl;
    cout << setprecision(2) << fixed;
    cout << "Office visit fee: $" << dr.getFee() << endl;

    return o;
}

int main() {
    char choice;
    cout << "Hello, welcome to the clinic, would you like to become a doctor? (y/n)" << endl;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {

        string name, trash;
        getline(cin, trash);
        cout << "What is your first and last name?" << endl;
        getline(cin,name);

        string specialty;
        cout << "What is your medical specialty?" << endl;
        cin >> specialty;

        double fee;
        cout << "How much do you charge for a clinic visit?" << endl;
        cin >> fee;

        int social;
        cout << "What is your social?" << endl;
        cin >> social;

        double salary;
        cout << "What is your weekly salary?" << endl;
        cin >> salary;

        Doctor dr(name, specialty, social, salary, fee);

        cout << dr;
    }

    cout << "Thank you for visiting the NYU Tandon clinic. Have a great day." << endl;

    return 0;
}
