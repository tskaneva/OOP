#include <iostream>
#include <string>
using namespace std;

// Основен клас Animal
class Animal {
public:

    // метод за издаване на звук
    string speak() const {
        return "Some generic sound"; // Основен звук
    }
};

// Производен клас Dog
class Dog : public Animal {
public:
    // Презаписване на метода speak()
    string speak() const {
        return "Woof woof"; // Специфичен звук за куче
    }
};

int main() {
    // Създаване на обект от базовия клас
    Animal genericAnimal;
    cout << genericAnimal.speak() << endl; // Извикване на speak()

    // Създаване на обект от производния клас
    Dog dog;
    cout << dog.speak() << endl; // Извикване на speak()

    return 0;
}
