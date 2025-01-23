#include <iostream>
#include <string>
using namespace std;

// Базов клас Building
class Building {
private:
    string name;             // Име на сградата
    int floors;              // Брой етажи
    string address;          // Адрес
    int constructionYear;    // Година на построяване

public:
    // Конструктор
    Building(const string& buildingName, int buildingFloors, const string& buildingAddress, int year)
        : name(buildingName), floors(buildingFloors), address(buildingAddress), constructionYear(year) {}

    // Метод за извеждане на информация
    void printInfo() const {
        cout << "Building: " << name << ", Floors: " << floors
             << ", Address: " << address << ", Construction Year: " << constructionYear << endl;
    }
};

// Клас School, наследяващ Building като private
class School : private Building {
private:
    int students;   // Брой ученици
    int teachers;   // Брой учители
    int classrooms; // Брой класни стаи

public:
    // Конструктор
    School(const string& schoolName, int schoolFloors, const string& schoolAddress, int year,
           int numStudents, int numTeachers, int numClassrooms)
        : Building(schoolName, schoolFloors, schoolAddress, year),
          students(numStudents), teachers(numTeachers), classrooms(numClassrooms) {}

    // Метод за извеждане на информация
    void printInfo() const {
        Building::printInfo(); // Извежда информация за сградата
        cout << "Students: " << students << ", Teachers: " << teachers
             << ", Classrooms: " << classrooms << endl;
    }
};

// Клас Hospital, наследяващ Building като private
class Hospital : private Building {
private:
    int beds;       // Брой легла
    int doctors;    // Брой лекари
    int ambulances; // Брой линейки

public:
    // Конструктор
    Hospital(const string& hospitalName, int hospitalFloors, const string& hospitalAddress, int year,
             int numBeds, int numDoctors, int numAmbulances)
        : Building(hospitalName, hospitalFloors, hospitalAddress, year),
          beds(numBeds), doctors(numDoctors), ambulances(numAmbulances) {}

    // Метод за извеждане на информация
    void printInfo() const {
        Building::printInfo(); // Извежда информация за сградата
        cout << "Beds: " << beds << ", Doctors: " << doctors
             << ", Ambulances: " << ambulances << endl;
    }
};

// Клас University, наследяващ School като protected
class University : protected School {
private:
    int faculties;        // Брой факултети
    int researchProjects; // Брой изследователски проекти

public:
    // Конструктор
    University(const string& universityName, int universityFloors, const string& universityAddress, int year,
               int numStudents, int numTeachers, int numClassrooms, int numFaculties, int numProjects)
        : School(universityName, universityFloors, universityAddress, year,
                 numStudents, numTeachers, numClassrooms),
          faculties(numFaculties), researchProjects(numProjects) {}

    // Метод за извеждане на информация
    void printInfo() const {
        School::printInfo(); // Извежда информация за училището
        cout << "Faculties: " << faculties << ", Research Projects: " << researchProjects << endl;
    }
};

// Клас Clinic, наследяващ Hospital като public
class Clinic : public Hospital {
private:
    int specializations;  // Брой специализации
    int equipmentTypes;   // Брой видове оборудване

public:
    // Конструктор
    Clinic(const string& clinicName, int clinicFloors, const string& clinicAddress, int year,
           int numBeds, int numDoctors, int numAmbulances, int numSpecializations, int numEquipmentTypes)
        : Hospital(clinicName, clinicFloors, clinicAddress, year, numBeds, numDoctors, numAmbulances),
          specializations(numSpecializations), equipmentTypes(numEquipmentTypes) {}

    // Метод за извеждане на информация
    void printInfo() const {
        Hospital::printInfo(); // Извежда информация за болницата
        cout << "Specializations: " << specializations
             << ", Equipment Types: " << equipmentTypes << endl;
    }
};

int main() {
    // Създаване на обекти
    School school("Green Valley School", 2, "123 School St", 1985, 500, 25, 20);
    Hospital hospital("City Hospital", 5, "456 Hospital Blvd", 1990, 200, 50, 10);
    University university("Tech University", 6, "789 University Ave", 1965, 3000, 200, 50, 10, 25);
    Clinic clinic("Sunrise Clinic", 2, "101 Clinic Dr", 2005, 50, 10, 2, 5, 10);

    // Извеждане на информация
    cout << "School Info:" << endl;
    school.printInfo();

    cout << "\nHospital Info:" << endl;
    hospital.printInfo();

    cout << "\nUniversity Info:" << endl;
    university.printInfo();

    cout << "\nClinic Info:" << endl;
    clinic.printInfo();

    return 0;
}
