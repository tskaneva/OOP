#include <iostream>
using namespace std;

class Rectangle {
public:
    double width, height;

    double area() {
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle r;
    r.width = 4.0;
    r.height = 5.0;
    cout << "Area: " << r.area() << endl;       // Area: 20
    cout << "Perimeter: " << r.perimeter() << endl; // Perimeter: 18
    return 0;
}
