#include <iostream>
using namespace std;

// Базов клас
class BaseClass {
private:
    int privateData; // Само класът BaseClass има достъп

protected:
    int protectedData; // Достъпен за BaseClass и производните класове

public:
    int publicData; // Достъпен за всички

    // Конструктор по подразбиране
    BaseClass() : privateData(0), protectedData(0), publicData(0) {
        cout << "BaseClass default constructor called.\n";
    }

    // Конструктор с един параметър
    BaseClass(int value) : privateData(value), protectedData(value), publicData(value) {
        cout << "BaseClass single-parameter constructor called.\n";
    }

    // Конструктор с три параметъра
    BaseClass(int privateValue, int protectedValue, int publicValue)
        : privateData(privateValue), protectedData(protectedValue), publicData(publicValue) {
        cout << "BaseClass parameterized constructor called.\n";
    }

    // Конструктор за копиране
    BaseClass(const BaseClass& other)
        : privateData(other.privateData), protectedData(other.protectedData), publicData(other.publicData) {
        cout << "BaseClass copy constructor called.\n";
    }

    // Метод за показване на данните
    void showData() const {
        cout << "BaseClass - Private Data: " << privateData
             << ", Protected Data: " << protectedData
             << ", Public Data: " << publicData << endl;
    }
};

// Производен клас
class DerivedClass : public BaseClass {
private:
    int derivedData; // Само класът DerivedClass има достъп

public:
    // Конструктор по подразбиране
    DerivedClass() : BaseClass(), derivedData(0) {
        cout << "DerivedClass default constructor called.\n";
    }

    // Конструктор с параметри
    DerivedClass(int privateValue, int protectedValue, int publicValue, int derivedValue)
        : BaseClass(privateValue, protectedValue, publicValue), derivedData(derivedValue) {
        cout << "DerivedClass parameterized constructor called.\n";
    }

    // Конструктор за копиране
    DerivedClass(const DerivedClass& other)
        : BaseClass(other), derivedData(other.derivedData) {
        cout << "DerivedClass copy constructor called.\n";
    }

    // Метод за показване на производните данни
    void showDerivedData() const {
        showData(); // Показва данните от базовия клас
        cout << "DerivedClass - Derived Data: " << derivedData << endl;
    }
};

int main() {
    // Създаване на обект с конструктора по подразбиране
    DerivedClass obj1;
    obj1.showDerivedData();

    // Създаване на обект с параметризиран конструктор
    DerivedClass obj2(10, 20, 30, 40);
    obj2.showDerivedData();

    // Създаване на обект чрез конструктора за копиране
    DerivedClass obj3(obj2);
    obj3.showDerivedData();

    // Създаване на обект с базовия конструктор с един параметър
    BaseClass baseObj(50);
    baseObj.showData();

    return 0;
}
