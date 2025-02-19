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

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Въведете име, факултетен номер и среден успех за студент " << i + 1 << ": ";
        cin >> students[i].name >> students[i].facultyNumber >> students[i].grade;
    }

    int bestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].grade > students[bestIndex].grade) {
            bestIndex = i;
        }
    }

    cout << "Най-добрият студент: " << students[bestIndex].name
         << " със среден успех " << students[bestIndex].grade << endl;

    delete[] students;
    return 0;
}
