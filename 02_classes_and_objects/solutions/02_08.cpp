#include <iostream>
using namespace std;

class Point {
public:
    double x, y;

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Създаване на обект p от класа Point
    Point p;
    p.x = 3.5;
    p.y = -2.1;

    cout << "Object p:" << endl;
    p.print(); // Извежда: (3.5, -2.1)

    // Създаване на указател към обекта p
    Point* ptr = &p;

    cout << endl << "Pointer before modifications:" << endl;
    p.print(); // Извежда: (3.5, -2.1)

    ptr->x = 5.0; // Модифициране на координатите чрез указателя
    ptr->y = 4.0;

    cout << endl << "Pointer after modifications:" << endl;
    p.print(); // Извежда: (5.0, 4.0)

    return 0;
}