#include <iostream>
using namespace std;

// Интерфейс (чисто абстрактен клас)
class IAnimal {
public:
    virtual void makeSound() const = 0;  // Чисто виртуална функция
    virtual void move() const = 0;       // Чисто виртуална функция
    virtual ~IAnimal() {}                // Виртуален деструктор
};

// Клас "Куче", който имплементира интерфейса IAnimal
class Dog : public IAnimal {
public:
    void makeSound() const override {
        cout << "Dog: Woof! Woof!" << endl;
    }

    void move() const override {
        cout << "Dog is running!" << endl;
    }
};

// Клас "Котка", който имплементира интерфейса IAnimal
class Cat : public IAnimal {
public:
    void makeSound() const override {
        cout << "Cat: Meow! Meow!" << endl;
    }

    void move() const override {
        cout << "Cat is jumping!" << endl;
    }
};

int main() {
    IAnimal* animals[] = { new Dog(), new Cat() };

    for (IAnimal* animal : animals) {
        animal->makeSound();
        animal->move();
        delete animal;
    }

    return 0;
}
