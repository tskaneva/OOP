#include <iostream>
using namespace std;

class Person {
public:
    Person() {}  // (1) конструктор по подразбиране
    Person(string name) : name(name) {}  // (2) Конструктор с 1 параметър
    Person(string name, int age) : name(name), age(age) {}  // Конструктор с 2 параметъра
    Person(Person& obj) : name(obj.name), age(obj.age) {}  // Копиращ конструктор
    ~Person() {}  // деструктор
private:
    string name;
    int age;
};