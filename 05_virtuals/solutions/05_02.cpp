#include <iostream>
using namespace std;

// Базов клас Vehicle
class Vehicle {
protected:
    string brand;
    int year;

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
    Car(const string& carBrand, const int carYear, const int carSeats) : Vehicle(carBrand, carYear), seats(carSeats) {}

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
    Bike(const string& bikeBrand, int bikeYear, const string& bikeType) : Vehicle(bikeBrand, bikeYear), type(bikeType) {}

    // Презаписване на метода displayInfo()
    void displayInfo() const override {
        cout << "Brand: " << brand << ", Year: " << year << ", Type: " << type << endl;
    }
};

int main() {
    // Създаване на масив от указатели към обекти от йерархията
    Vehicle* vehicles[] = {
            new Car("Toyota", 2020, 5),
            new Bike("Giant", 2019, "Mountain")
    };

    // Полиморфно извикване на displayInfo()
    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayInfo();
    }

    // Изтриване на динамично заделената памет
    for (int i = 0; i < 2; ++i) {
        delete vehicles[i];
    }

    return 0;
}