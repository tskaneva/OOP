#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {  // Виртуален метод
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {  // Предефиниране на метода
        cout << "Derived class display" << endl;
    }
};

int main() {
    Base* basePtr;           // Указател към базовия клас
    Derived derivedObj;      // Обект от производния клас

    basePtr = &derivedObj;   // Указателят сочи към производния обект
    basePtr->display();      // Извиква се предефинираният метод

    return 0;
}
