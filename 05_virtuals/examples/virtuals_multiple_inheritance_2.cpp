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
        : Employee(n, i), Programmer(n, i), Manager(n, i) {}

    void leadTeam() {
        cout << name << " is leading the team..." << endl;
    }
};

// Нов клас CTO, наследяващ от TechLead
class CTO : public TechLead {
public:
    CTO(string n, int i)
        : Employee(n, i), TechLead(n, i) {} // Инициализираме само базовия клас Employee и прекия родител - TechLead

    void defineStrategy() {
        cout << name << " is defining the company's technology strategy..." << endl;
    }

    void overseeProjects() {
        cout << name << " is overseeing all technology projects..." << endl;
    }
};

int main() {
    CTO cto("Alice Smith", 1001);

    // Използване на методи от Employee
    cto.displayInfo();

    // Използване на методи от Programmer
    cto.writeCode();

    // Използване на методи от Manager
    cto.holdMeeting();

    // Използване на методи от TechLead
    cto.leadTeam();

    // Собствени методи на CTO
    cto.defineStrategy();
    cto.overseeProjects();

    return 0;
}
