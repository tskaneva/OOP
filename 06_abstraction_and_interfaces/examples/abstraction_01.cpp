#include <iostream>

using namespace std;

// Абстрактен клас Animal
class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0; // Чиста виртуална функция
};

// Клас Dog (Куче), наследник на Animal
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Bark! Bark!" << endl;
    }
};

// Клас Cat (Котка), наследник на Animal
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
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
