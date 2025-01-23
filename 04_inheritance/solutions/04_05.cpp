#include <iostream>
#include <string>
using namespace std;

// Базов клас Building
class Building {
private:
    string name; // Име на сградата
    int floors;  // Брой етажи

public:
    // Конструктор
    Building(const string& buildingName, int buildingFloors)
        : name(buildingName), floors(buildingFloors) {}

    // Метод за извеждане на информация
    void printInfo() const {
        cout << "Building: " << name << ", Floors: " << floors << endl;
    }
};

// Клас School, наследяващ Building
class School : public Building {
private:
    int students; // Брой ученици
    int teachers; // Брой учители

public:
    // Конструктор
    School(const string& schoolName, int schoolFloors, int numStudents, int numTeachers)
        : Building(schoolName, schoolFloors), students(numStudents), teachers(numTeachers) {}

    // Метод за извеждане на информация
    void printInfo() const {
        Building::printInfo();
        cout << "Students: " << students << ", Teachers: " << teachers << endl;
    }
};

// Клас Hospital, наследяващ Building
class Hospital : public Building {
private:
    int beds;    // Брой легла
    int doctors; // Брой лекари

public:
    // Конструктор
    Hospital(const string& hospitalName, int hospitalFloors, int numBeds, int numDoctors)
        : Building(hospitalName, hospitalFloors), beds(numBeds), doctors(numDoctors) {}

    // Метод за извеждане на информация
    void printInfo() const {
        Building::printInfo();
        cout << "Beds: " << beds << ", Doctors: " << doctors << endl;
    }
};

// Клас University, наследяващ School
class University : public School {
private:
    int faculties; // Брой факултети

public:
    // Конструктор
    University(const string& universityName, int universityFloors, int numStudents, int numTeachers, int numFaculties)
        : School(universityName, universityFloors, numStudents, numTeachers), faculties(numFaculties) {}

    // Метод за извеждане на информация
    void printInfo() const {
        School::printInfo();
        cout << "Faculties: " << faculties << endl;
    }
};

// Клас Clinic, наследяващ Hospital
class Clinic : public Hospital {
private:
    int specializations; // Брой специализации

public:
    // Конструктор
    Clinic(const string& clinicName, int clinicFloors, int numBeds, int numDoctors, int numSpecializations)
        : Hospital(clinicName, clinicFloors, numBeds, numDoctors), specializations(numSpecializations) {}

    // Метод за извеждане на информация
    void printInfo() const {
        Hospital::printInfo();
        cout << "Specializations: " << specializations << endl;
    }
};

int main() {
    // Създаване на обекти
    Building building("Generic Building", 3);
    School school("Green Valley School", 2, 500, 25);
    Hospital hospital("City Hospital", 5, 200, 50);
    University university("Tech University", 6, 3000, 200, 10);
    Clinic clinic("Sunrise Clinic", 2, 50, 10, 5);

    // Извеждане на информация
    cout << "Building Info:" << endl;
    building.printInfo();

    cout << "\nSchool Info:" << endl;
    school.printInfo();

    cout << "\nHospital Info:" << endl;
    hospital.printInfo();

    cout << "\nUniversity Info:" << endl;
    university.printInfo();

    cout << "\nClinic Info:" << endl;
    clinic.printInfo();

    return 0;
}
