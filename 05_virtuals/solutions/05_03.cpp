#include <iostream>
using namespace std;

class Device {
protected:
    string brand;
    string model;
    double softwareVersion;

public:
    Device(const string& deviceBrand, const string& deviceModel, double version)
        : brand(deviceBrand), model(deviceModel), softwareVersion(version) {
    }

    void displayInfo() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Software Version: " << softwareVersion << endl;
    }

    virtual void updateSoftware() {
        cout << "Updating..." << endl;
    };

    virtual ~Device() {}
};

class Phone : public Device {
private:
    string os;

public:
    Phone(const string& phoneBrand, const string& phoneModel, double version, const string& phoneOS)
        : Device(phoneBrand, phoneModel, version), os(phoneOS) {
    }

    void updateSoftware() override {
        softwareVersion += 1.0;
    }
};

class Laptop : public Device {
private:
    bool hasDedicatedGPU;

public:
    Laptop(const string& laptopBrand, const string& laptopModel, double version, bool dedicatedGPU)
        : Device(laptopBrand, laptopModel, version), hasDedicatedGPU(dedicatedGPU) {
    }

    void updateSoftware() override {
        softwareVersion += 0.5;
    }
};

class Tablet : public Device {
private:
    bool stylusSupport;

public:
    Tablet(const string& tabletBrand, const string& tabletModel, double version, bool supportsStylus)
        : Device(tabletBrand, tabletModel, version), stylusSupport(supportsStylus) {
    }

    void updateSoftware() override {
        softwareVersion += 0.2;
    }
};

int main() {
    Device* devices[3] = {
        new Phone("Apple", "iPhone 15", 17.0, "iOS"),
        new Laptop("Dell", "XPS 13", 10.5, true),
        new Tablet("Samsung", "Galaxy Tab S8", 5.1, true)
    };

    // Показване на информацията преди промяната на данните
    cout << "Before update:\n";
    for (int i = 0; i < 3; ++i) {
        devices[i]->displayInfo();
    }

    // Извикване на метода за промяна на данните
    for (int i = 0; i < 3; ++i) {
        devices[i]->updateSoftware();
    }

    // Показване на информацията след промяната
    cout << "\nAfter update:\n";
    for (int i = 0; i < 3; ++i) {
        devices[i]->displayInfo();
    }

    // Освобождаване на паметта
    for (int i = 0; i < 3; ++i) {
        delete devices[i];
    }

    return 0;
}
