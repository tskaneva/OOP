#include <iostream>
#include <string>
using namespace std;

// Основен клас Animal
class Animal {
protected:
    string name; // Име на животното
public:
    // Конструктор
    Animal(string animalName) : name(animalName) {}

    // метод за издаване на звук
    string speak() const {
        return name + ": Some generic sound"; // Основен звук
    }
};

// Производен клас Dog
class Dog : public Animal {
public:
    // Конструктор, използващ базовия конструктор
    Dog(string dogName) : Animal(dogName) {}

    // Презаписване на метода speak()
    string speak() {
        return name + ": Woof woof"; // Специфичен звук за куче
    }
};

int main() {
    // Създаване на обект от базовия клас
    Animal genericAnimal("some animal");
    cout << genericAnimal.speak() << endl; // Извикване на speak()

    // Създаване на обект от производния клас
    Dog dog("Buddy");
    cout << dog.speak() << endl; // Извикване на speak()

    return 0;
}
