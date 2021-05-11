// Assignment: NYU Tandon Bridge Homework 15
// Author: Kamel Gazzaz
// Due date: 04/30/2021
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// ----------- Useful constants ---------------

const string EMPTY_STRING = "";
const double ZERO = 0.0;
const int INVALID = -1;
const string IN_OUR_HEARTS = "Vincent Nikolayev";

// ------------- Pre declarations ---------------

class Employee;
typedef Employee* EmployeePtr;
typedef EmployeePtr* EmployeePtrPtr;

class Workforce;
typedef Workforce* WorkforcePtr;

// --------------- Employee Class ---------------

class Employee {

    string name;
    int id;
    double hoursWorked;
    double hourlyPay;
    double totalPay;
    EmployeePtr manager;
    EmployeePtr trainee;

public:

    // Constructors
    Employee(): name(EMPTY_STRING), id(INVALID), hoursWorked(ZERO), hourlyPay(ZERO), totalPay(ZERO), manager(nullptr), trainee(nullptr) {}
    Employee(string empName, int idNum, double pay): name(empName), id(idNum), hoursWorked(ZERO), hourlyPay(pay), totalPay(ZERO), manager(nullptr), trainee(nullptr) {}
    Employee(string empName, int idNum, double hours, double pay): name(empName), id(idNum), hoursWorked(hours), hourlyPay(pay), totalPay(ZERO), manager(nullptr), trainee(nullptr) {}
    Employee(const Employee& employee): name(employee.name), id(employee.id), hoursWorked(employee.hoursWorked), hourlyPay(employee.hourlyPay), totalPay(employee.totalPay), manager(
            nullptr), trainee(nullptr) {}

    // Accessors
    string getName() const {return name;}
    int getId() const {return id;}
    double getHoursWorked() const {return hoursWorked;}
    double getHourlyPay() const {return hourlyPay;}
    double getTotalPay() const {return totalPay;}
    EmployeePtr getManager() const  {return manager;}
    EmployeePtr getTrainee() const {return trainee;}

    // Mutators
    void setName(string newName) {name = newName;}
    void setId(int newId) {id = newId;}
    void addHours(int newHours) {hoursWorked += newHours; adjustTotalPay();}
    void setHourlyPay(int newPay) {hourlyPay = newPay;}
    void adjustTotalPay() {totalPay = hourlyPay * hoursWorked;}
    void setManager(EmployeePtr newManager) {manager = newManager;}
    void setTrainee(EmployeePtr newTrainee) {trainee = newTrainee;}
};

// --------------- Workforce Class ---------------

class Workforce {

    // Head employee
    EmployeePtr founder;

    // Mailroom employee
    EmployeePtr newestHire;

public:

    // Startup
    Workforce(): founder(nullptr), newestHire(nullptr) {}
    Workforce(EmployeePtr firstEmployee);

    // Liquidity event
    ~Workforce(){clear();}
    void clear();

    // M&A activity
    Workforce(const Workforce& parentOrganization): Workforce() {operator=(parentOrganization);}
    Workforce& operator=(const Workforce& parentOrganization);

    // Human Resources
    void hireNewEmployee(EmployeePtr& newEmployee);
    int findEmployeeID (string name);
    void dismissEmployee(int employeeID);
    void logHours(const vector<int>& tempIDs, const vector<double>& tempHours);

    // Executive leadership
    EmployeePtr getFounder() const {return founder;}
    void setFounder(EmployeePtr coFounder) {founder = coFounder;}

    // Run payroll
    friend ostream& operator<<(ostream& o, WorkforcePtr w);
};

// ----------- Program Function Declarations -------------

WorkforcePtr getPayroll();
// Wrapper for getting company employee information from a file

void getTimeSheet(vector<int>& empIDs, vector<double>& empHours);
// Wrapper for getting company employee hours worked from a file

template <class T>
void openFile(T& fileStream, string reason = EMPTY_STRING);
// Opens an input or output file stream

WorkforcePtr readEmployeeData(ifstream& inFile);
// Reads in employee data from file and creates the company

void checkAlreadyUsed(const vector<int>& usedIds, int id);
// Check if an employee id was already used

void readLogSheet(ifstream& logSheet, vector<int>& employeeIDs, vector<double>& employeeHours);
// Reads in employee time sheet

void rankEmployees(EmployeePtrPtr highestEarner);
// Sorts employees from highest to lowest earner

void segmentToTeams(EmployeePtr boss, EmployeePtrPtr teamAStart, EmployeePtrPtr teamBStart);
// Splits the company into two roughly equal sized teams

EmployeePtr evaluateTeamPerformance(EmployeePtr teamAMember, EmployeePtr teamBMember);
// Merges two sorted teams

// ------------------- MAIN -----------------------

int main() {

    // Step 1: Read in employee data

    WorkforcePtr payroll = getPayroll();

    // Step 2: Read in log sheet

    vector<int> loggedIDs;
    vector<double> loggedHours;
    getTimeSheet(loggedIDs, loggedHours);

    // Step 3: Update employee data

    payroll->logHours(loggedIDs, loggedHours);

    // Step 4: End someone's employment (just to check if function works)

    int vincentID = payroll->findEmployeeID(IN_OUR_HEARTS);
    payroll->dismissEmployee(vincentID);

    // Step 5: Run payroll

    cout << payroll << endl;

    return 0;
}


// ----------- Program Function Definitions --------------

WorkforcePtr getPayroll() {

    // Go to HR
    ifstream employeeDataFile;
    string reason = "employee data";
    openFile(employeeDataFile, reason);

    // Read employee data
    WorkforcePtr payroll = readEmployeeData(employeeDataFile);

    // Leave HR
    employeeDataFile.close();

    // Bring data to CFO
    return payroll;
}

void getTimeSheet(vector<int>& empIDs, vector<double>& empHours) {

    // Go to field sites
    ifstream logSheet;
    string reason = "log sheet";
    openFile(logSheet, reason);

    // Get hours logged
    readLogSheet(logSheet, empIDs, empHours);

    // Bring data to CHRO
    logSheet.close();
}

template <class T>
void openFile(T& fileStream, string reason) {

    string filename;

    // Input File
    if (typeid(T) == typeid(ifstream)) {

        // Get file name from user
        cout << "Enter input file name (" << reason << "): ";
        cin >> filename;

        // Open file
        fileStream.open(filename);

        // If fails. Keep trying until successful
        while(!fileStream) {

            cout << "Input file failed to open. Please try again." << endl;
            cout << "Enter input file name: ";
            cin >> filename;

            fileStream.clear();
            fileStream.open(filename);
        }
    }

    // Output File
    else if (typeid(T) == typeid(ofstream)) {

        // Get file name from user
        cout << "Enter output file name: ";
        cin >> filename;

        // Open file
        fileStream.open(filename);

        // If fails. Keep trying until successful
        while(!fileStream) {

            cout << "Output file failed to open. Please try again." << endl;
            cout << "Enter output file name: ";
            cin >> filename;

            fileStream.clear();
            fileStream.open(filename);
        }
    }
}

WorkforcePtr readEmployeeData(ifstream& inFile) {

    WorkforcePtr employees = new Workforce;
    int id;
    double pay;
    string name;
    vector<int> usedIds;

    // Read employee ID
    while (inFile >> id) {

        // No two employees should share same ID number
        checkAlreadyUsed(usedIds, id);

        // Read employee hourly wage
        inFile >> pay;

        // Read employee Name
        inFile.ignore(1, ' ');
        getline(inFile, name);

        // Create employee credentials
        EmployeePtr newestHire = new Employee(name, id, pay);

        // Add employee to company
        employees->hireNewEmployee(newestHire);
    }

    return employees;
}

void checkAlreadyUsed(const vector<int>& usedIds, int id) {

    // Loop through ID numbers
    for (int used: usedIds) {

        // ID numbers already used
        if (used == id) {

            // Report to security team
            cout << "Duplicate user ID detected. Company security breach." << endl;

            // Eliminate the threat
            exit(1);
        }
    }
}

void readLogSheet(ifstream& logSheet, vector<int>& employeeIDs, vector<double>& employeeHours) {

    int id;
    double hours;

    // ID logged in time sheet
    while (logSheet >> id) {

        // Hour logged in time sheet
        logSheet >> hours;

        // Report id and hours to HR database
        employeeIDs.push_back(id);
        employeeHours.push_back(hours);
    }
}


ostream& operator<<(ostream& os, WorkforcePtr company) {

    EmployeePtr currentEmployee = company->founder;
    EmployeePtrPtr officeOfCurrentEmployee = &currentEmployee;

    // Rank employees by performance
    rankEmployees(officeOfCurrentEmployee);
    company->setFounder(currentEmployee);

    // Process payroll
    os << "*********Payroll Information********" << endl;

    while(currentEmployee != nullptr) {

        // Compensate employee
        os << currentEmployee->getName() << ", $" << setprecision(2) << fixed << currentEmployee->getTotalPay() << endl;

        // Go to next employee
        currentEmployee = currentEmployee->getTrainee();
    }

    os << "*********End payroll**************" << endl;

    return os;
}

void rankEmployees(EmployeePtrPtr highestEarner) {

    EmployeePtr boss = *highestEarner;
    EmployeePtr teamALeader;
    EmployeePtr teamBLeader;

    // Base Case: Company defaulted or Company only has one employee
    if ((boss == nullptr) || (boss->getTrainee() == nullptr)) {

        // No earners to sort
        return;
    }

    // Split company into two teams
    segmentToTeams(boss, &teamALeader, &teamBLeader);

    // Recursively rank members of the two teams
    rankEmployees(&teamALeader);
    rankEmployees(&teamBLeader);

    // Merge teams to get overall company performance
    *highestEarner = evaluateTeamPerformance(teamALeader, teamBLeader);
}

EmployeePtr evaluateTeamPerformance(EmployeePtr teamAMember, EmployeePtr teamBMember) {

    // Base Cases: One of the two teams is empty

    // Team A (and perhaps team B) is empty
    if (teamAMember == nullptr) {
        return teamBMember;
    }

    // Team B is empty
    else if (teamBMember == nullptr) {
        return teamAMember;
    }

    // Recursive Step: compare employees from both teams to get their overall rank
    EmployeePtr higherEarner = nullptr;

    // Team A member earned more than team B member
    if (teamAMember->getTotalPay() >= teamBMember->getTotalPay()) {

        // Team A member is the higher earner
        higherEarner = teamAMember;

        // Find next highest earner in the two teams
        EmployeePtr nextEarner = evaluateTeamPerformance(teamAMember->getTrainee(), teamBMember);
        higherEarner->setTrainee(nextEarner);
        nextEarner->setManager(higherEarner);
    }

    // Team B member earned more than team A member
    else {

        // Team B member is the higher earner
        higherEarner = teamBMember;

        // Find next highest earner in the two teams
        EmployeePtr nextEarner = evaluateTeamPerformance(teamAMember, teamBMember->getTrainee());
        higherEarner->setTrainee(nextEarner);
        nextEarner->setManager(higherEarner);
    }

    return higherEarner;
}

void segmentToTeams(EmployeePtr boss, EmployeePtrPtr teamAStart, EmployeePtrPtr teamBStart) {

    EmployeePtr middleManager = boss;
    EmployeePtr newestHire = boss->getTrainee();

    // Go down the corporate ladder to determine middle manager and last employee
    while (newestHire != nullptr) {

        // Next employee
        newestHire = newestHire->getTrainee();

        if (newestHire != nullptr) {

            // Middle manager is midway between chairman and last employee
            middleManager = middleManager->getTrainee();
            newestHire = newestHire->getTrainee();
        }
    }

    // Split into teams A and B
    *teamAStart = boss;
    *teamBStart = middleManager->getTrainee();

    // Break link between team A and team B
    middleManager->getTrainee()->setManager(nullptr);
    middleManager->setTrainee(nullptr);
}

// ----------- Workforce Function Definitions -------------

Workforce::Workforce(EmployeePtr firstEmployee): founder(firstEmployee) {  // First employee is head

    // Go to last employee in chain
    while (firstEmployee->getTrainee() != nullptr) {
        firstEmployee = firstEmployee->getTrainee();
    }

    // Last employee is tail
    newestHire = firstEmployee;
}

void Workforce::clear() {

    EmployeePtr currentEmployee = founder;

    // Fire all employees from the top down
    while(currentEmployee != nullptr) {

        // Choose who to fire
        EmployeePtr toBeFired = currentEmployee;

        // Promote their trainee (to be fired next quarter)
        currentEmployee = currentEmployee->getTrainee();

        // Fire employee
        delete toBeFired;
        toBeFired = nullptr;
    }
}

void Workforce::logHours(const vector<int>& tempIDs, const vector<double>& tempHours) {

    // Loop through hours logged
    for (int i = 0; i < tempIDs.size(); i++) {

        EmployeePtr currentEmployee = founder;

        bool employeeCompensated = false;

        // Find employee in HR records
        while(currentEmployee != nullptr && !employeeCompensated) {

            // Assign hours to the right employee
            if(currentEmployee->getId() == tempIDs[i]) {
                currentEmployee->addHours(tempHours[i]);
                employeeCompensated = true;
            }

            // Not right employee
            else {
                currentEmployee = currentEmployee->getTrainee();
            }
        }
    }
}

void Workforce::hireNewEmployee(EmployeePtr& newEmployee) {

    // New company
    if (founder == nullptr) {

        // First employee becomes founder
        founder = newEmployee;

        while (newEmployee->getTrainee() != nullptr) {
            newEmployee = newEmployee->getTrainee();
        }

        // Last employee becomes newest hire
        newestHire = newEmployee;

        return;
    }

    // Not new company

    // New employee reports to previous newest hire
    newestHire->setTrainee(newEmployee);
    newEmployee->setManager(newestHire);

    // New employee becomes newest hire
    newestHire = newEmployee;
}

Workforce& Workforce::operator=(const Workforce& parentOrganization) {

    // Remove old employees
    clear();

    // Employees of holding organization are now employees of acquired organization
    EmployeePtr secondPosition = parentOrganization.founder;

    // Hire first employee
    founder = new Employee(*secondPosition);

    // Hire other employees of the parent organization
    while (secondPosition->getTrainee() != nullptr) {

        // Hire next employee
        secondPosition = secondPosition->getTrainee();
        EmployeePtr next = new Employee(*secondPosition);
        this->hireNewEmployee(next);
    }

    return *this;
}

void Workforce::dismissEmployee(int employeeID) {

    EmployeePtr currentEmployee = founder;
    bool employeeFoundInCompany = false;

    // Lookup id in employee directory
    while ((currentEmployee != nullptr) && (!employeeFoundInCompany)) {

        if (currentEmployee->getId() == employeeID) {
            employeeFoundInCompany = true;
        }

        else {
            currentEmployee = currentEmployee->getTrainee();
        }
    }

    // ID found
    if (employeeFoundInCompany) {

        // Call in the employee's direct coworkers
        EmployeePtr trainee = currentEmployee->getTrainee();
        EmployeePtr manager = currentEmployee->getManager();

        // Handle the change of roles
        if (trainee != nullptr) {
            trainee->setManager(manager);
        }
        else {
            newestHire = manager;
        }
        if (manager != nullptr) {
            manager->setTrainee(trainee);
        }

        // Dismiss the employee
        delete currentEmployee;
    }
}

int Workforce::findEmployeeID (string name) {

    EmployeePtr currentEmployee = founder;

    // Loop through payroll
    while (currentEmployee != nullptr) {

        // Employee found
        if (currentEmployee->getName() == name) {
            return currentEmployee->getId();
        }

        // Check next employee
        currentEmployee = currentEmployee->getTrainee();
    }

    // Employee not found
    return INVALID;
}