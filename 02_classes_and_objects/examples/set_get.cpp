#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void setName(const string& newName) {
        if (!newName.empty()) {
            name = newName;
        } else {
            cout << "Invalid name!" << endl;
        }
    }

    string getName() const {
        return name;
    }

    void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    int getAge() const {
        return age;
    }
};

int main() {
    Student student;
    student.setName("John Doe");
    student.setAge(20);

    cout << "Student Name: " << student.getName() << endl;
    cout << "Student Age: " << student.getAge() << endl;

    return 0;
}
