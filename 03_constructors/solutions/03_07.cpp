#include <iostream>
using namespace std;

class Car {
  private:
    ....
  public:
  // Инициализиращ конструктор
  Car(const string& b, const string& m, int y, const char* plate) : brand(b), model(m), year(y) {
    licensePlate = new char[strlen(plate) + 1]; // Заделяне на динамична памет
    strcpy(licensePlate, plate);
    cout << "Created: " << brand << " " << model << " (" << year << ")\n";
  }
  // Деструктор
  ~Car() {
    std::cout << "Deleted: " << brand << " " << model << "\n";
    delete[] .......; // Освобождаване на паметта
  }
  ....
};