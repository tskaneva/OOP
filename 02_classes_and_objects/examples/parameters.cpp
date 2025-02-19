#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;

public:
    void setDimensions(int w, int h) { // w и h са формални параметри
        width = w;
        height = h;
    }

    int calculateArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(10, 20); // 10 и 20 са фактически параметри
    cout << "Area: " << rect.calculateArea() << endl;
    return 0;
}
