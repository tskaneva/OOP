#include <iostream>
using namespace std;

struct Student {
    char name[50];
    int facultyNumber;
    double grade;
};

int main() {
    int n;
    cout << "Въведете броя на студентите: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "Въведете име, факултетен номер и среден успех за студент " << i + 1 << ": ";
        cin >> students[i].name >> students[i].facultyNumber >> students[i].grade;
    }

    cout << "\nИнформация за студентите:\n";
    for (int i = 0; i < n; i++) {
        cout << "Име: " << students[i].name
             << ", Факултетен номер: " << students[i].facultyNumber
             << ", Среден успех: " << students[i].grade << endl;
    }

    return 0;
}
