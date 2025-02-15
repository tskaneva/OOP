// Пример за грешка -> един производен клас може да наследява само един абстрактен клас
#include <iostream>
using namespace std;

// Абстрактен клас Animal
class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0;
};

// Абстрактен клас за порода на куче
class Pomeran{
public:
    virtual ~Pomeran() = default;
    virtual void makeSound() const;
    virtual void furLength() const = 0;
};

// Опит за наследяване на два абстрактни класа => компилационна грешка
class Dog : public Animal, public Pomeran {
public:
    void makeSound() const override {
        cout << "Bark! Bark!" << endl;
    }
    void furLength() const override {
      cout << "Dog::furLength()" << endl;
    }
};

int main() {
    //Animal* pet1 = new Dog();
    Pomeran *pet1 = new Dog;

    pet1->makeSound();
    pet1->furLength();

    delete pet1;
    return 0;
}
