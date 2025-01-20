#include <iostream>
using namespace std;

class Car {
public:
    string model;

    void display() {
        cout << "Car model: " << model << endl;
    }
};

int main() {

    Car* car1 = new Car;  // Създаване на обект динамично с указател
    // ако операторът new не бъде изпълнен (напр. недостатъчно памет), то ще се върне стойност NULL
    car1->model = "Toyota"; // Ръчно задаване на стойност
    car1->display();

    delete car1;  // Освобождаване на динамично заделената памет

    return 0;
}
