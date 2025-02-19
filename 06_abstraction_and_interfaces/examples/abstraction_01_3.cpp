#include <iostream>

using namespace std;

class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0; // Чиста виртуална функция
    virtual void printInfo() const {
        cout << "Animal::printInfo()" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Bark! Bark!" << endl;
    }
    void printInfo() const override{
        cout << "Dog::printInfo()" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
};

int main() {
    Animal* pet1 = new Dog();
    Animal* pet2 = new Cat();
    Dog* pet3 = new Dog();

    pet1->makeSound();
    pet2->makeSound();
    pet3->makeSound();

    pet1->printInfo();  // ще извика Animal::printInfo()
    pet3->printInfo(); // ще извика Dog::printInfo()

    delete pet1;
    delete pet2;
    delete pet3;

    return 0;
}
