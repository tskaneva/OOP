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

    // Конструктор
    BaseClass(int privateValue, int protectedValue, int publicValue)
        : privateData(privateValue), protectedData(protectedValue), publicData(publicValue) {}

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
    // Конструктор, който използва базовия конструктор
    DerivedClass(int privateValue, int protectedValue, int publicValue, int derivedValue)
        : BaseClass(privateValue, protectedValue, publicValue), derivedData(derivedValue) {}

    // Метод за модифициране на данните
    void modifyData(int baseValue, int protectedValue, int derivedValue) {
        // privateData = baseValue; // ГРЕШКА: privateData не е достъпна в производния клас
        protectedData = protectedValue; // Може да се достъпи, защото е protected
        derivedData = derivedValue;     // Може да се достъпи, защото е private за DerivedClass
        publicData = baseValue;         // Може да се достъпи, защото е public
    }

    // Метод за показване на производните данни
    void showDerivedData() const {
        cout << "DerivedClass - Protected Data: " << protectedData
             << ", Public Data: " << publicData
             << ", Derived Data: " << derivedData << endl;
    }
};

int main() {
    // Създаване на обект от базовия клас
    BaseClass baseObj(10, 20, 30);
    baseObj.showData();

    // Създаване на обект от производния клас
    DerivedClass derivedObj(10, 20, 30, 40);
    derivedObj.showData();
    derivedObj.showDerivedData();

    // Промяна на данните чрез производния клас
    derivedObj.modifyData(50, 60, 70);
    derivedObj.showDerivedData();

    return 0;
}
