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
    Point p;
    p.x = 3.5;
    p.y = -2.1;
    p.print(); // Извежда: (3.5, -2.1)
    return 0;
}