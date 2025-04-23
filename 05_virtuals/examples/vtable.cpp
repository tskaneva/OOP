#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay(double amount) = 0;  // абстрактна функция
};

class CreditCard : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " with credit card.\n";
    }
};

class PayPal : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " via PayPal.\n";
    }
};
// Функция, която извършва плащането, без да се интересува от типа на обекта
void checkout(Payment* paymentMethod, double amount) {
    paymentMethod->pay(amount);
}

int main() {
    CreditCard card;
    PayPal paypal;

    checkout(&card, 50.0);   // Paid 50 with credit card.
    // Проверка на типа по време на изпълнение:
    checkout(&paypal, 75.5); // Paid 75.5 via PayPal.

    Payment* p = new CreditCard();
    p->pay(99.99);

    // Проверка на типа по време на изпълнение:
    cout << "Real type: " << typeid(*p).name() << endl;

    return 0;
}
