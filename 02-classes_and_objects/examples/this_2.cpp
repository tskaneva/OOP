#include <iostream>
using namespace std;

class Car {
public:
    string model;

    void printModel(Car* car) {
        cout << "Car model: " << car->model << endl;
    }

    void display() {
        printModel(this); // Предаване на текущия обект
    }
};

int main() {
    Car car;
    car.model = "Tesla";
    car.display(); // Извежда: Car model: Toyota
    return 0;
}
