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
        cout << accountNumber << ": " << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.accountNumber = "BG123456789";
    account.balance = 500.0;
    account.deposit(200);
    account.withdraw(100);
    account.print(); // BG123456789: 600.0
    account.withdraw(700); // No money
    return 0;
}
