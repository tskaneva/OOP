#include <iostream>
using namespace std;

class Person {
public:
    string name;
    void printName(){
      cout << name << endl;
    }
};


int main() {
    Person people;
    Person *p = &people; // p е променлива от тип Person; p сочи към обекта people; на p се присвоява адреса на people;

    cout << p << endl; // ще изведе адреса в паметта, в който се съхранява обекта people;
    cout << p->name << endl; // в този "момент" няма да изведе нищо, защото атрибута name няма зададена стойност, няма и стойност по подразбиране
    p->name = "John"; // присвояваме стойността на атрибута name на обекта people
    p->printName(); // p извиква метода printName() на обекта people;
    people.printName(); // извикване на метода printName() на обекта people;

    (*p).printName(); // p извиква метода printName() на обекта people; Това е еквивалентно извикване на p->printName();, т.е. и двете са допустими
}