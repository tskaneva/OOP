#include <iostream>
using namespace std;

class Rectangle {
private:
    double width, height;
public:
    Rectangle() {
      width = 0;
      height = 0;
    }
    Rectangle(double w, double h): width(w), height(h) {}

    Rectangle(Rectangle &obj) {
      width = obj.width;
      height = obj.height;
    }

    double area() const{
        return width * height;
    }

    double perimeter() const{
        return 2 * (width + height);
    }

    void printInfo() const{
      cout << width << "; " << height << endl;
    }
};

int main() {
    Rectangle r;
    r.printInfo();

    Rectangle r2(5.0, 6);
    r2.printInfo();

    Rectangle r3(r2);
    r3.printInfo();

    return 0;
}
