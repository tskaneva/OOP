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

// Базов клас Employee
class Employee {
protected:
    string company;
    double salary;

public:
    // Конструктор
    Employee(const string& employeeCompany, const double employeeSalary)
        : company(employeeCompany), salary(employeeSalary) {}

    // Метод за показване на информация
    void displayInfo() const {
        cout << "Company: " << company << ", Salary: " << salary << endl;
    }

    // Метод за увеличение на заплатата
    void giveRaise(double percent) {
        salary += salary * percent / 100;
    }
};

// Производен клас Manager
class Manager : public Person, public Employee {
private:
    int teamSize; // Размер на екипа

public:
    // Конструктор
    Manager(const string& managerName, const int managerAge, const string& managerCompany, const double managerSalary, const int initialTeamSize)
        : Person(managerName, managerAge), Employee(managerCompany, managerSalary), teamSize(initialTeamSize) {}

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

int main() {
    // Създаване на обект от тип Manager
    Manager manager("Alice", 35, "TechCorp", 75000, 5);

    // Показване на първоначалната информация
    cout << "Initial Info:" << endl;
    manager.displayInfo();

    // Увеличаване на заплатата с 10%
    manager.giveRaise(10);

    // Добавяне на 3 нови члена към екипа
    manager.addToTeam(3);

    // Показване на актуализираната информация
    cout << "\nUpdated Info:" << endl;
    manager.displayInfo();

    return 0;
}
