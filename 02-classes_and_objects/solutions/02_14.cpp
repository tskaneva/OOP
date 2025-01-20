#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    string accountNumber = "BG000000000";
    double balance = 0;

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

    void getBalance() const{
      cout << accountNumber << ": " << balance << endl;
        // balance = balance + 25;  // не може да бъде изпълнено, защото методът е константен и не променя стойностите на атрибутите
    }

    void getAccountNumber() const {
      cout << accountNumber << endl;
    }
};

int main() {
    // константен обект
    const BankAccount account;
    account.getBalance();

    // динамично създаден константен обект
    const BankAccount *accountPtr = &account;
    accountPtr->getBalance();

    return 0;
}
