#include <iostream>
#include <string>
using namespace std;

// Клас Student
class Student {
private:
    string name;           // Име на студента
    string facultyNumber;  // Факултетен номер
    double averageGrade;   // Среден успех
    int year;              // Година на обучение

public:
    // Конструктор по подразбиране
    Student() {
        name = "Unknown";
        facultyNumber = "000000";
        averageGrade = 0.0;
        year = 1;
    }

    // Конструктор с параметри
    Student(string n, string fn, double grade, int yr) {
        name = n;
        facultyNumber = fn;
        averageGrade = grade;
        year = yr;
    }

    // Метод за отпечатване на информация
    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Faculty Number: " << facultyNumber << endl;
        cout << "Average Grade: " << averageGrade << endl;
        cout << "Year: " << year << endl;
    }
};

// Главна функция
int main() {
    // Създаване на студент чрез конструктора по подразбиране
    Student defaultStudent;
    cout << "Default student:" << endl;
    defaultStudent.printInfo();
    cout << endl;

    // Създаване на студент чрез конструктора с параметри
    Student paramStudent("Maria Ivanova", "123456", 5.75, 3);
    cout << "Student with parameters:" << endl;
    paramStudent.printInfo();

    return 0;
}
