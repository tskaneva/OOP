// Класът Town описва град с различни характеристики и функционалности
#include <iostream>
#include <string>
using namespace std;

// Дефиниция на класа Town
class Town {
private:
    string name; // Име на града
    int population;   // Население
    double area;      // Площ на града в квадратни километри
    string mayor; // Име на кмета
    int schools;      // Брой училища
    int hospitals;    // Брой болници

public:
    // Конструктор по подразбиране
    Town() : name("Unknown"), population(0), area(0.0), mayor("Unknown"), schools(0), hospitals(0) {}

    // Конструктор с параметри
    /* Частта след : е инициализиращ списък (initializer list). Той директно присвоява стойности на атрибутите на класа
        Това означава, че:
        - name ще приеме стойността на townName,
        - population ще приеме стойността на townPopulation
        - т.н
        Тялото на конструктора ({}) е празно, защото всички атрибути вече са инициализирани в списъка за инициализация.
     */
    Town(string townName, int townPopulation, double townArea, string townMayor, int townSchools, int townHospitals)
        : name(townName), population(townPopulation), area(townArea), mayor(townMayor), schools(townSchools), hospitals(townHospitals) {}

    // Метод за задаване на име
    void setName(const string &townName) {
        name = townName;
    }

    // Метод за получаване на име
    string getName() const {
        return name;
    }

    // Метод за изчисляване на гъстотата на населението
    double calculatePopulationDensity() const {
        if (area == 0) {
            return 0.0; // Избягване на деление на нула
        }
        return population / area;
    }

    // Метод за добавяне на училище
    void addSchool() {
        schools++;
    }

    // Метод за отпечатване на информация за града
    void printInfo() const {
        cout << "Town: " << name << "\n";
        cout << "Population: " << population << "\n";
        cout << "Area: " << area << " sq.km\n";
        cout << "Mayor: " << mayor << "\n";
        cout << "Schools: " << schools << "\n";
        cout << "Hospitals: " << hospitals << "\n";
        cout << "Population Density: " << calculatePopulationDensity() << " people/sq.km\n";
    }
};

int main() {
    // Създаване на обекти на класа Town
    Town defaultTown; // Град с подразбиращи се стойности
    // Промяна на името на града
    defaultTown.setName("Roussee");

    // Добавяне на училище
    defaultTown.addSchool();

    Town myTown("Ruse", 30000, 150.5, "John Doe", 10, 5);

    // Отпечатване на информация
    cout << "Default Town Info:\n";
    defaultTown.printInfo();

    // Отпечатване на информация
    cout << "\nMy Town Info:\n";
    myTown.printInfo();

    return 0;
}
