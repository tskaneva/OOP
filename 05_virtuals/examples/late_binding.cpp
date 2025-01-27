#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {  // Виртуален метод
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override { // Преизползван виртуален метод
        cout << "Dog barks" << endl;
    }
};

int main() {
    // Animal* animal = new Dog(); // Указател към базовия клас
    Animal *animal;
    animal->sound();            // Dog barks (късно свързване)
    delete animal;
    return 0;
}
