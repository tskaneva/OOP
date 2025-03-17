#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
public:
   // конструктор по подразбиране
    BankAccount(){
      accountNumber = "";
      balance = 0;
    }

    // инициализиращ конструктор
    BankAccount(string accountNumber, double balance): accountNumber(accountNumber), balance(balance){}

    void setAccountNumber(string accountNumber){
      this->accountNumber = accountNumber;
    }

    void setBalance(double balance){
      this->balance = balance;
    }

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

    void print() const{
        cout << accountNumber << ": " << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.setAccountNumber("BG123456789");
    account.setBalance(500);
    account.deposit(200);
    account.withdraw(100);
    account.print(); // BG123456789: 600.0
    account.withdraw(700); // No money
    return 0;
}
