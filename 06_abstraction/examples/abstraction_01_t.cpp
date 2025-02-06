#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0; // Чиста виртуална функция
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Bark! Bark!" << endl;
    }
};

class Cat : public Animal {
public:
    string someCatAttribute;
};

int main() {
    Animal* pet1 = new Dog();
    Animal* pet2 = new Cat();

    pet1->makeSound();
    pet2->makeSound();

    delete pet1;
    delete pet2;

    return 0;
}
