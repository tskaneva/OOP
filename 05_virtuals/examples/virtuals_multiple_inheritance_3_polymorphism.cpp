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
    // Създаваме масив от указатели към базовия клас
    Employee* employees[] = {
        new Programmer("Alice", 101, "C++"),
        new Manager("Bob", 102, 5),
        new TechLead("Charlie", 103, "Python", 7, "ML Project"),
        new CTO("Diana", 104, "Java", 10, "AI Platform", "Transform AI Industry")
    };

    // Използваме полиморфизъм за извикване на методи
    for (int i = 0; i < 4; i++) {
        employees[i]->displayInfo(); // извиква се подходящата версия на displayInfo()
    }

    // Освобождаваме паметта
    for (int i = 0; i < 4; i++) {
        delete employees[i];
    }

    return 0;
}

