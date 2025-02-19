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
    ptr->x = 5.0; // Модифициране на координатите чрез указателя
    ptr->y = 4.0;

    cout << "\nPointer:" << endl;
    p.print(); // Извежда: (5.0, 4.0)

    // Динамично създаване на обект от класа Point
    Point* dynamicPtr = new Point;
    dynamicPtr->x = -1.5; // Задаване на стойности чрез указателя
    dynamicPtr->y = 2.3;

    cout << "\nDynamically created object:" << endl;
    dynamicPtr->print(); // Извежда: (-1.5, 2.3)

    // Освобождаване на паметта
    delete dynamicPtr;

    return 0;
}