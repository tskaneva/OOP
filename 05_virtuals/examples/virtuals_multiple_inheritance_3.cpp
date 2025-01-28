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

    virtual ~Employee() {}

    virtual void displayInfo() {
        cout << "Employee Name: " << name << ", ID: " << id << endl;
    }
};

// Клас Programmer, наследяващ виртуално от Employee
class Programmer : virtual public Employee {
protected:
    string programmingLanguage;

public:
    Programmer(string n, int i, string lang) : Employee(n, i), programmingLanguage(lang) {}

    void writeCode() {
        cout << name << " is writing code in " << programmingLanguage << "..." << endl;
    }
};

// Клас Manager, наследяващ виртуално от Employee
class Manager : virtual public Employee {
protected:
    int teamSize;

public:
    Manager(string n, int i, int size) : Employee(n, i), teamSize(size) {}

    void holdMeeting() {
        cout << name << " is holding a meeting with a team of " << teamSize << " members..." << endl;
    }
};

// Клас TechLead, наследяващ от Programmer и Manager
class TechLead : public Programmer, public Manager {
protected:
    string projectName;

public:
    TechLead(string n, int i, string lang, int size, string project)
        : Employee(n, i), Programmer(n, i, lang), Manager(n, i, size), projectName(project) {}

    void leadTeam() {
        cout << name << " is leading the project: " << projectName << "..." << endl;
    }
};

// Нов клас CTO, наследяващ от TechLead
class CTO : public TechLead {
protected:
    string visionStatement;

public:
    CTO(string n, int i, string lang, int size, string project, string vision)
        : Employee(n, i), TechLead(n, i, lang, size, project), visionStatement(vision) {}

    void defineStrategy() {
        cout << name << " is defining the company's technology strategy: " << visionStatement << "..." << endl;
    }

    void overseeProjects() {
        cout << name << " is overseeing all technology projects..." << endl;
    }
};

int main() {
    // Създаваме обект с помощта на указател директно към класа CTO
    CTO* cto = new CTO("Alice Smith", 1001, "C++", 10, "AI Development", "Innovate AI solutions for the future");

    cto->displayInfo();
    cto->writeCode();
    cto->holdMeeting();
    cto->leadTeam();
    cto->defineStrategy();
    cto->overseeProjects();

    // Освобождаваме паметта
    delete cto;

    return 0;
}
