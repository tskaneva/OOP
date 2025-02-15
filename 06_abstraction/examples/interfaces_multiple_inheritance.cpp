#include <iostream>
using namespace std;

// Първи интерфейс
class IPrintable {
public:
    virtual void print() const = 0;
    virtual ~IPrintable() {}
};

// Втори интерфейс
class ISavable {
public:
    virtual void saveToFile(const string& filename) const = 0;
    virtual ~ISavable() {}
};

// Клас, който имплементира и двата интерфейса
class Report : public IPrintable, public ISavable {
public:
    void print() const override {
        cout << "Printing the report..." << endl;
    }

    void saveToFile(const string& filename) const override {
        cout << "Saving the report to " << filename << endl;
    }
};

int main() {
    Report report;
    report.print();
    report.saveToFile("report.txt");

    return 0;
}
