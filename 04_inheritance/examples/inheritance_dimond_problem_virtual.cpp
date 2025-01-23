#include <iostream>
using namespace std;

class Base {
protected:
    int value;

public:
    Base(int val) : value(val) {}
    void printValue() const {
        cout << "Value: " << value << endl;
    }
};

class Derived1 : virtual public Base {
public:
    Derived1(int val) : Base(val) {}
};

class Derived2 : virtual public Base {
public:
    Derived2(int val) : Base(val) {}
};

class FinalDerived : public Derived1, public Derived2 {
public:
    FinalDerived(int val) : Base(val), Derived1(val), Derived2(val) {}
};

int main() {
    // Създаване на обект от FinalDerived
    FinalDerived obj(10);

    // Опит за извикване на printValue()
    obj.printValue(); // !!!

    // Решение: Ясно указване на кой Base да използваме
    obj.Derived1::printValue(); // Извиква printValue() от Derived1::Base
    obj.Derived2::printValue(); // Извиква printValue() от Derived2::Base

    return 0;
}