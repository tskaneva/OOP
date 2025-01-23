#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Базов клас Vehicle
class Vehicle {
protected:
    string brand; // Марка на превозното средство
    int year;          // Година на производство

public:
    // Конструктор
    Vehicle(const string& vehicleBrand, const int vehicleYear) : brand(vehicleBrand), year(vehicleYear) {}

    // Виртуален метод за показване на информация
    virtual void displayInfo() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }

    // Виртуален деструктор
    virtual ~Vehicle() {}
};

// Производен клас Car
class Car : public Vehicle {
private:
    int seats; // Брой седалки

public:
    // Конструктор, използващ базовия конструктор
    Car(const string& carBrand, const int carYear, const int carSeats): Vehicle(carBrand, carYear), seats(carSeats) {}

    // Презаписване на метода displayInfo()
    void displayInfo() const override {
        cout << "Brand: " << brand << ", Year: " << year << ", Seats: " << seats << endl;
    }
};

// Производен клас Bike
class Bike : public Vehicle {
private:
    string type; // Тип на велосипеда (напр. "Mountain")

public:
    // Конструктор, използващ базовия конструктор
    Bike(const string& bikeBrand, int bikeYear, const string& bikeType): Vehicle(bikeBrand, bikeYear), type(bikeType) {}

    // Презаписване на метода displayInfo()
    void displayInfo() const override {
        cout << "Brand: " << brand << ", Year: " << year << ", Type: " << type << endl;
    }
};

int main() {
    // Вариант 1 - статични обекти с масив от указатели
    // Създаване на обекти
    Car car1("Toyota", 2020, 5);
    Bike bike1("Giant", 2019, "Mountain");

    // Масив от указатели към базовия клас
    Vehicle* vehicles[2];
    vehicles[0] = &car1; // Първият елемент сочи към обект от тип Car
    vehicles[1] = &bike1; // Вторият елемент сочи към обект от тип Bike

    // Полиморфно извикване на displayInfo()
    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayInfo();
    }

    /*
    // Вариант 2 - използване на оператора new
    // Масив от указатели към базовия клас
    Vehicle* vehicles[2];
    vehicles[0] = new Car("Toyota", 2020, 5);  // създава обекта в динамичната памет и връща указател към него; не е необходима променлива за обекта
    vehicles[1] = new Bike("Giant", 2019, "Mountain");

    // Полиморфно извикване на displayInfo()
    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayInfo();
    }
    // Изчистване на динамичната памет
    for (int i = 0; i < 2; ++i) {
        delete vehicles[i];
    }
    */

    /*
    // Вариант 3 - използване на вектори
    // Създаване на обекти
    Car car1("Toyota", 2020, 5);
    Bike bike1("Giant", 2019, "Mountain");

    // Масив от указатели към базовия клас, използвайки Vector
    vector<Vehicle*> vehicles;
    vehicles.push_back(&car1);
    vehicles.push_back(&bike1);

    // Полиморфно извикване на displayInfo()
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
    }
    */

    return 0;
}
