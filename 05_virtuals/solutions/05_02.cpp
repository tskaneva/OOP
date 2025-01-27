#include <iostream>
#include <string>
using namespace std;

// Базов клас Person
class Person {
protected:
    string name;
    int age;

public:
    // Конструктор
    Person(const string& personName, const int personAge)
        : name(personName), age(personAge) {}

    // Метод за показване на информация
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Базов клас Employee (виртуално наследяване)
class Employee : virtual public Person {
protected:
    string company;
    double salary;

public:
    // Конструктор
    Employee(const string& employeeCompany, const double employeeSalary, const string& personName, const int personAge)
        : Person(personName, personAge), company(employeeCompany), salary(employeeSalary) {}

    // Метод за показване на информация
    void displayInfo() const {
        cout << "Company: " << company << ", Salary: " << salary << endl;
    }

    // Метод за увеличение на заплатата
    void giveRaise(double percent) {
        salary += salary * percent / 100;
    }
};

// Производен клас Manager (виртуално наследяване)
class Manager : virtual public Employee {
private:
    int teamSize; // Размер на екипа

public:
    // Конструктор
    Manager(const string& managerName, const int managerAge, const string& managerCompany, const double managerSalary, const int initialTeamSize)
        : Person(managerName, managerAge), Employee(managerCompany, managerSalary, managerName, managerAge), teamSize(initialTeamSize) {}

    // Метод за увеличаване на размера на екипа
    void addToTeam(int newMembers) {
        teamSize += newMembers;
    }

    // Презаписване на displayInfo()
    void displayInfo() const {
        Person::displayInfo();  // Извиква displayInfo() от Person
        Employee::displayInfo(); // Извиква displayInfo() от Employee
        cout << "Team Size: " << teamSize << endl;
    }
};

// Клас Intern (Стажант), наследяващ Person
class Intern : public Person {
private:
    string university; // Университет на стажанта

public:
    // Конструктор
    Intern(const string& internName, const int internAge, const string& internUniversity)
        : Person(internName, internAge), university(internUniversity) {}

    // Презаписване на displayInfo()
    void displayInfo() const {
        Person::displayInfo();
        cout << "University: " << university << endl;
    }
};

// Клас TeamLead, наследяващ Manager
class TeamLead : public Manager {
private:
    string project; // Проект, който ръководи

public:
    // Конструктор
    TeamLead(const string& leadName, const int leadAge, const string& leadCompany, const double leadSalary, const int teamSize, const string& leadProject)
        : Manager(leadName, leadAge, leadCompany, leadSalary, teamSize), project(leadProject) {}

    // Презаписване на displayInfo()
    void displayInfo() const {
        Manager::displayInfo();
        cout << "Project: " << project << endl;
    }
};

// Клас Executive, наследяващ Manager и Employee
class Executive : public Manager {
private:
    double bonus; // Бонус на изпълнителния директор

public:
    // Конструктор
    Executive(const string& execName, const int execAge, const string& execCompany, const double execSalary, const int execTeamSize, const double execBonus)
        : Person(execName, execAge),
          Employee(execCompany, execSalary, execName, execAge),
          Manager(execName, execAge, execCompany, execSalary, execTeamSize),
          bonus(execBonus) {}

    // Метод за показване на информация
    void displayInfo() const {
        Manager::displayInfo(); // Извиква информацията от Manager
        cout << "Bonus: " << bonus << endl;
        cout << "Total Compensation: " << (salary + bonus) << endl; // salary вече е уникален
    }
};

int main() {
    // Създаване на обект от тип Manager
    Manager manager("Alice", 35, "TechCorp", 75000, 5);
    cout << "Manager Info:" << endl;
    manager.displayInfo();

    // Създаване на обект от тип Intern
    Intern intern("Bob", 21, "MIT");
    cout << "\nIntern Info:" << endl;
    intern.displayInfo();

    // Създаване на обект от тип TeamLead
    TeamLead teamLead("Charlie", 40, "TechCorp", 85000, 8, "AI Project");
    cout << "\nTeam Lead Info:" << endl;
    teamLead.displayInfo();

    // Създаване на обект от тип Executive
    Executive executive("Diana", 45, "TechCorp", 150000, 20, 50000);
    cout << "\nExecutive Info:" << endl;
    executive.displayInfo();

    return 0;
}
