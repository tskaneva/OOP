#include <iostream>
#include <string>
using namespace std;

// Основен клас Employee
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}

    void displayInfo() {
        cout << "Employee Name: " << name << ", ID: " << id << endl;
    }
};

// Клас Programmer, наследяващ виртуално от Employee
class Programmer : virtual public Employee {
public:
    Programmer(string n, int i) : Employee(n, i) {}

    void writeCode() {
        cout << name << " is writing code..." << endl;
    }
};

// Клас Manager, наследяващ виртуално от Employee
class Manager : virtual public Employee {
public:
    Manager(string n, int i) : Employee(n, i) {}

    void holdMeeting() {
        cout << name << " is holding a meeting..." << endl;
    }
};

// Клас TechLead, наследяващ от Programmer и Manager
class TechLead : public Programmer, public Manager {
public:
    TechLead(string n, int i)
        : Employee(n, i), Programmer(n, i), Manager(n, i) {
    }

    void leadTeam() {
        cout << name << " is leading the team..." << endl;
    }
};

int main() {
    TechLead lead("John Doe", 101);

    // Използване на методи от Employee
    lead.displayInfo();

    // Използване на методи от Programmer
    lead.writeCode();

    // Използване на методи от Manager
    lead.holdMeeting();

    // Собствен метод на TechLead
    lead.leadTeam();

    return 0;
}
