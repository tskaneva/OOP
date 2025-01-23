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
        cout << "Name: " << name << ", Age: " << age;
    }
};

// Базов клас Employee
class Employee {
protected:
    string company; // Компания
    double salary; // Заплата

public:
    // Конструктор
    Employee(const string& employeeCompany, const double employeeSalary)
        : company(employeeCompany), salary(employeeSalary) {}

    // Метод за показване на информация
    void displayInfo() const {
        cout << "Company: " << company << ", Salary: " << salary << endl;
    }
};

// Производен клас Manager
class Manager : public Person, public Employee {
public:
    // Конструктор, използващ конструкторите на базовите класове
    Manager(const string& managerName, int managerAge, const string& managerCompany, double managerSalary)
        : Person(managerName, managerAge), Employee(managerCompany, managerSalary) {}

    // Комбиниран метод за показване на информация
    void displayInfo() const {
        Person::displayInfo();  // Извиква displayInfo() от Person
        Employee::displayInfo(); // Извиква displayInfo() от Employee
    }
};

int main() {
    // Създаване на обект от тип Manager
    Manager manager("Alice", 35, "TechCorp", 75000);

    // Показване на информацията за мениджъра
    manager.displayInfo();

    return 0;
}
