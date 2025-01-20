#include <iostream>
using namespace std;

class Person {
public:
    string name;

    void changeName(string newName) {
        name = newName;
    }
};


// функция, която НЕ Е към класа Person, но има входен аргумент - указател към обект от класа Person
void updateName(Person* person, string newName) {
    person->changeName(newName);
}


int main() {
    Person p;
    p.name = "Ivan"; // Ръчно задаване на стойност; Вместо да се използва конструктор за задаване на началното име, то се задава директно след създаването на обекта.
    cout << "Before: " << p.name << endl;

    updateName(&p, "Georgi"); // Предаване на обект чрез указател
    cout << "After: " << p.name << endl;

    return 0;
}
