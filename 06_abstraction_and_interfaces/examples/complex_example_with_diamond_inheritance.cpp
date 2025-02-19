#include <iostream>
#include <vector>
using namespace std;

// Абстрактен базов клас за всички компоненти
class LaptopComponent {
public:
    virtual void showDetails() const = 0; // Чиста виртуална функция
    virtual ~LaptopComponent() {}  // Виртуален деструктор
};

// Клас за процесора
class Processor : public LaptopComponent {
protected:
    string brand;
    int cores;
    double frequency;
public:
    Processor(string brand, int cores, double frequency)
        : brand(brand), cores(cores), frequency(frequency) {}

    virtual void boostClock() = 0; // Чиста виртуална функция

    void showDetails() const override {
        cout << "Processor: " << brand << " | " << cores << " cores | "
             << frequency << " GHz" << endl;
    }
};

// Интегрирано GPU (наследява Processor)
class IntegratedGPU : public Processor {
public:
    IntegratedGPU(string brand, int cores, double frequency)
        : Processor(brand, cores, frequency) {}

    void boostClock() override {
        cout << "Boosting integrated GPU frequency to " << (frequency * 1.1) << " GHz\n";
    }
};

// Дискретно GPU (наследява Processor)
class DedicatedGPU : public Processor {
private:
    int vram;
public:
    DedicatedGPU(string brand, int cores, double frequency, int vram)
        : Processor(brand, cores, frequency), vram(vram) {}

    void boostClock() override {
        cout << "Overclocking dedicated GPU to " << (frequency * 1.2) << " GHz\n";
    }

    void showDetails() const override {
        Processor::showDetails();
        cout << "VRAM: " << vram << " GB" << endl;
    }
};

// Абстрактен клас за памет (RAM и VRAM)
class Memory : public LaptopComponent {
protected:
    int capacity;
public:
    Memory(int capacity) : capacity(capacity) {}

    virtual void upgrade(int extraGB) = 0; // Чиста виртуална функция
};

// RAM клас
class RAM : public Memory {
public:
    RAM(int capacity) : Memory(capacity) {}

    void upgrade(int extraGB) override {
        capacity += extraGB;
        cout << "RAM upgraded to " << capacity << " GB\n";
    }

    void showDetails() const override {
        cout << "RAM: " << capacity << " GB" << endl;
    }
};

// VRAM клас
class VRAM : public Memory {
public:
    VRAM(int capacity) : Memory(capacity) {}

    void upgrade(int extraGB) override {
        cout << "VRAM cannot be upgraded!\n";
    }

    void showDetails() const override {
        cout << "VRAM: " << capacity << " GB (non-upgradable)" << endl;
    }
};

// Абстрактен клас за съхранение (HDD и SSD)
class Storage : public virtual LaptopComponent {
protected:
    int capacity;
public:
    Storage(int capacity) : capacity(capacity) {}

    virtual void format() = 0; // Чиста виртуална функция
};

// HDD клас
class HDD : public virtual Storage {
protected:
    int hddCapacity;
public:
    HDD(int capacity) : Storage(capacity), hddCapacity(capacity) {}

    void format() override {
        cout << "Formatting HDD...\n";
    }

    void showDetails() const override {
        cout << "HDD: " << capacity << " GB\n";
    }
};

// SSD клас
class SSD : public virtual Storage {
protected:
    int ssdCapacity;
public:
    SSD(int capacity) : Storage(capacity), ssdCapacity(capacity) {}

    void format() override {
        cout << "Formatting SSD...\n";
    }

    void showDetails() const override {
        cout << "SSD: " << capacity << " GB\n";
    }
};

// Хибридно устройство за съхранение (SSHD)
class HybridStorage : public HDD, public SSD {
public:
    HybridStorage(int hddCapacity, int ssdCapacity)
        : Storage(hddCapacity + ssdCapacity), HDD(hddCapacity), SSD(ssdCapacity) {}

    void format() override {
        cout << "Formatting Hybrid Storage (SSHD)...\n";
    }

    void showDetails() const override {
        cout << "Hybrid Storage (SSHD):\n";
        cout << " - HDD: " << HDD::hddCapacity << " GB\n";  // Взимаме правилно капацитета
        cout << " - SSD: " << SSD::ssdCapacity << " GB\n";  // Взимаме правилно капацитета
        cout << " - Total Capacity: " << Storage::capacity << " GB\n";
    }
};

// Абстрактен клас за дисплей (OLED и LCD)
class Display : public LaptopComponent {
protected:
    string resolution;
public:
    Display(string resolution) : resolution(resolution) {}

    virtual void adjustBrightness(int level) = 0; // Чиста виртуална функция
};

// OLED дисплей
class OLED : public Display {
public:
    OLED(string resolution) : Display(resolution) {}

    void adjustBrightness(int level) override {
        cout << "Adjusting OLED brightness to " << level << "%\n";
    }

    void showDetails() const override {
        cout << "Display: OLED, Resolution: " << resolution << endl;
    }
};

// LCD дисплей
class LCD : public Display {
public:
    LCD(string resolution) : Display(resolution) {}

    void adjustBrightness(int level) override {
        cout << "Adjusting LCD brightness to " << level << "%\n";
    }

    void showDetails() const override {
        cout << "Display: LCD, Resolution: " << resolution << endl;
    }
};

// Батерия
class Battery : public LaptopComponent {
private:
    int capacity;
public:
    Battery(int capacity) : capacity(capacity) {}

    void charge(int percent) {
        cout << "Charging battery by " << percent << "%\n";
    }

    void showDetails() const override {
        cout << "Battery: " << capacity << " mAh\n";
    }
};

// Лаптоп клас, който съдържа всички компоненти
class Laptop {
private:
    Processor* cpu;
    Memory* ram;
    Storage* storage;
    Display* display;
    Battery* battery;

public:
    Laptop(Processor* p, Memory* r, Storage* s, Display* d, Battery* b)
        : cpu(p), ram(r), storage(s), display(d), battery(b) {}

    void showLaptopDetails() {
        cout << "=== Laptop Configuration ===\n";
        cpu->showDetails();
        ram->showDetails();
        storage->showDetails();
        display->showDetails();
        battery->showDetails();
    }

    ~Laptop() {
        delete cpu;
        delete ram;
        delete storage;
        delete display;
        delete battery;
    }
};

// Главна функция за демонстрация
int main() {
    Laptop* myLaptop = new Laptop(
        new DedicatedGPU("NVIDIA RTX 3080", 10, 1.5, 16),
        new RAM(16),
        new HybridStorage(512, 256),
        new OLED("3840x2160"),
        new Battery(6000)
    );

    myLaptop->showLaptopDetails();

    delete myLaptop;
    return 0;
}
