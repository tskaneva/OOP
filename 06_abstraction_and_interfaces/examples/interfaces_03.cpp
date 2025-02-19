#include <iostream>
using namespace std;

// Интерфейс за устройства с USB
class IUSBDevice {
public:
    virtual void connect() const = 0;
    virtual void disconnect() const = 0;
    virtual ~IUSBDevice() {}
};

// Клас "Флашка", който имплементира интерфейса IUSBDevice
class FlashDrive : public IUSBDevice {
public:
    void connect() const override {
        cout << "Flash Drive connected!" << endl;
    }

    void disconnect() const override {
        cout << "Flash Drive disconnected!" << endl;
    }
};

// Клас "Принтер", който също имплементира интерфейса IUSBDevice
class Printer : public IUSBDevice {
public:
    void connect() const override {
        cout << "Printer connected!" << endl;
    }

    void disconnect() const override {
        cout << "Printer disconnected!" << endl;
    }
};

int main() {
    IUSBDevice* devices[] = { new FlashDrive(), new Printer() };

    for (IUSBDevice* device : devices) {
        device->connect();
        device->disconnect();
        delete device;
    }

    return 0;
}
