#include <iostream>
using namespace std;

class Person {
private:
    string name;

public:
    void setName(string name) {
        this->name = name; // "this->name" се отнася до атрибута name, а не входния аргумент
    }

    void printName() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Person person;
    person.setName("John");
    person.printName(); // Извежда: Name: John
    return 0;
}
