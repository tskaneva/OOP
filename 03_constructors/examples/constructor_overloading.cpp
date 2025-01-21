#include <iostream>
using namespace std;

class Person {
public:
    Person() {}  // конструктор по подразбиране
    Person(string name) : name(name) {}  // Конструктор с 1 параметър
    Person(string name, int age) : name(name), age(age) {}  // Предефиниране на инициализиращия конструктор

    void print() const {
      cout << "Name: " << name << endl;
      cout << "Age: " << age << endl;
    }
private:
    string name;
    int age;
};

int main() {
    Person p;
    Person p2("Ivan");
    Person p3("Georgi", 25);

    p.print();
    p2.print();
    p3.print();
}