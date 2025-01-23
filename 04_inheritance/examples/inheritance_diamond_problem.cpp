#include <iostream>
using namespace std;

// Базов клас Base
class Base {
protected:
    int value; // Стойност

public:
    // Конструктор
    Base(int val) : value(val) {}

    // Метод за извеждане на стойността
    void printValue() const {
        cout << "Value: " << value << endl;
    }
};

// Производен клас Derived1, наследяващ Base
class Derived1 : public Base {
public:
    // Конструктор
    Derived1(int val) : Base(val) {}
};

// Производен клас Derived2, наследяващ Base
class Derived2 : public Base {
public:
    // Конструктор
    Derived2(int val) : Base(val) {}
};

// Клас FinalDerived, наследяващ едновременно от Derived1 и Derived2
class FinalDerived : public Derived1, public Derived2 {
public:
    // Конструктор
    FinalDerived(int val1, int val2)
        : Derived1(val1), Derived2(val2) {}
};

int main() {
    // Създаване на обект от FinalDerived
    FinalDerived obj(10, 20);

    // Опит за извикване на printValue()
    // obj.printValue(); // ГРЕШКА: Двусмисленост между Derived1::Base и Derived2::Base

    // Решение: Ясно указване на кой Base да използваме
    obj.Derived1::printValue(); // Извиква printValue() от Derived1::Base
    obj.Derived2::printValue(); // Извиква printValue() от Derived2::Base

    return 0;
}
