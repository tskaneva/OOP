#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    string accountNumber;
    double balance;

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "No money" << endl;
        } else {
            balance -= amount;
        }
    }

    void print() {
        cout << "Account: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Създаване на обект account
    BankAccount account;
    account.accountNumber = "BG123456789";
    account.balance = 500.0;

    // Създаване на указател към account
    BankAccount* ptr = &account;
    ptr->deposit(200); // Достъп до методите чрез указател
    ptr->withdraw(100); // Достъп до методите чрез указател
    cout << "Account: " << ptr->accountNumber << endl;
    cout << "Balance after: " << ptr->balance << endl;

    // Динамично създаване на обект
    BankAccount* dynamicAccount = new BankAccount;
    dynamicAccount->accountNumber = "BG987654321";
    dynamicAccount->balance = 1000.0;
    dynamicAccount->deposit(500); // Депозит чрез указател
    dynamicAccount->withdraw(300); // Теглене чрез указател
    cout << "\nDynamically created account: " << dynamicAccount->accountNumber << endl;
    cout << "Balance after operation: " << dynamicAccount->balance << endl;

    // Освобождаване на паметта
    delete dynamicAccount;

    return 0;
}
