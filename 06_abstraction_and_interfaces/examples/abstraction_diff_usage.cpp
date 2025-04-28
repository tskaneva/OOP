#include <iostream>
using namespace std;

// Абстрактен клас, обединяващ устройства с батерия
class BatteryPoweredDevice {
public:
    virtual void charge() = 0;
    virtual void use() = 0;

    virtual ~BatteryPoweredDevice() {}
};

// Различни на вид устройства, обединени чрез общите характеристики

class Laptop : public BatteryPoweredDevice {
public:
    void charge() override {
        cout << "Charging laptop..." << endl;
    }
    void use() override {
        cout << "Using laptop for programming." << endl;
    }
};

class Toothbrush : public BatteryPoweredDevice {
public:
    void charge() override {
        cout << "Charging electric toothbrush..." << endl;
    }
    void use() override {
        cout << "Brushing teeth..." << endl;
    }
};

class Drone : public BatteryPoweredDevice {
public:
    void charge() override {
        cout << "Charging drone..." << endl;
    }
    void use() override {
        cout << "Flying drone..." << endl;
    }
};

int main() {
    BatteryPoweredDevice* devices[] = {
        new Laptop(),
        new Toothbrush(),
        new Drone()
    };

    for (auto device : devices) {
        device->charge();
        device->use();
        cout << "-----" << endl;
    }

    for (auto device : devices) {
        delete device;
    }

    return 0;
}
