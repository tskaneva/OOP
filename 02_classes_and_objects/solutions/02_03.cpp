#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int grade;

    bool isPassing() {
        return grade >= 3;
    }

    void print() {
        cout << name << ": " << grade << endl;
    }
};

int main() {
    Student s;
    s.name = "Ivan Ivanov";
    s.grade = 4;
    cout << "Is passing: " << s.isPassing() << endl; // Is passing: 1
    s.print(); // Ivan Ivanov: 4
    return 0;
}
