#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {  // Не е виртуален метод
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* animal = new Dog(); // Указател към базовия клас
    animal->sound();            // Animal makes a sound (ранно свързване)
    delete animal;
    return 0;
}
