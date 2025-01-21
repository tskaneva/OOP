#include <iostream>
using namespace std;

class Rectangle {
public:
    double width, height;

    Rectangle() {}
    Rectangle(double w, double h): width(w), height(h) {}
    Rectangle(Rectangle &obj) {
      width = obj.width;
      height = obj.height;
    }

    double area() {
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }

    void printInfo() const{
      cout << width << "; " << height << endl;
    }
};

int main() {
    Rectangle r;
    r.width = 4.0;
    r.height = 5.0;
    r.printInfo();

    Rectangle r2(5.0, 6);
    r2.printInfo();

    Rectangle r3(r2);
    r3.printInfo();
    return 0;
}
