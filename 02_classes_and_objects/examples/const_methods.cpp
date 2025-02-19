#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    string accountNumber;
    double balance;

    void print() {
        cout << accountNumber << ": " << balance << endl;
        balance = balance + 25;  // неправилна промяна на стойността на атрибута в метод за отпечатване на информация; Възможни са неочаквани и нежалани резултати при изпълнението на метода върху обектите на класа

    }

    void getBalance() const{
        cout << accountNumber << ": " << balance << endl;
        // balance = balance + 25;  // не може да бъде изпълнено, защото методът е константен и не променя стойностите на атрибутите
    }

};

int main() {
    BankAccount account;
    account.accountNumber = "BG123456789";
    account.balance = 500.0;
    account.getBalance();

    return 0;
}
