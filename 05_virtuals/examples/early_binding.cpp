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
    Animal* animal1 = new Dog(); // Указател към базовия клас
    animal1->sound();            // Animal makes a sound (ранно свързване)
    delete animal1;

    Dog dog;
    dog.sound(); // Dog barks

    Animal animal2;
    animal2.sound();
    return 0;
}
