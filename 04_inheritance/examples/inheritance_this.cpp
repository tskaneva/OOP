#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class" << endl;
    }

    void display() {
        this->show(); // Извиква метода на текущия клас
        show();
    }
};

int main() {
    Derived obj;
    obj.display(); // Извежда: Derived class
    return 0;
}
