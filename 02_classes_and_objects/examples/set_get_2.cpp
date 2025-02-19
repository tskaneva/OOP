#include <iostream>
using namespace std;

class Thermometer {
private:
    double temperature;

public:
    void setTemperature(double temp) {
        if (temp >= -273.15) { // Проверка за абсолютната нула
            temperature = temp;
        } else {
            cout << "Temperature cannot be below absolute zero!" << endl;
        }
    }

    double getTemperature() const {
        return temperature;
    }
};

int main() {
    Thermometer thermometer;
    thermometer.setTemperature(25.5);
    cout << "Current Temperature: " << thermometer.getTemperature() << " \u00B0C" << endl;

    thermometer.setTemperature(-300.0); // Невалидна стойност
    return 0;
}
