#include <iostream>
using namespace std;

class Person {
public:
    string name;
    void printName(){
      cout << "name:" << name << endl;
      cout << "age:" << age << endl;
      cout << "eye color:" << eyeColor << endl;
    }
private:
    int age = 18;
    string eyeColor = "black";
};


int main() {
    Person people;
    Person *p = &people; // p е променлива от тип Person; p сочи към обекта people; на p се присвоява адреса на people;

    p->name = "John"; // присвояваме стойността на атрибута name на обекта people
    p->printName(); // p извиква метода printName() на обекта people;
    people.printName(); // извикване на метода printName() на обекта people;
}