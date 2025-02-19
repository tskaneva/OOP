#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
    double x, y, z;

    double length() {
        return sqrt(x * x + y * y + z * z);
    }

    void scale(double factor) {
        x *= factor;
        y *= factor;
        z *= factor;
    }

    void print() {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }
};

int main() {
    Vector v;
    v.x = 3;
    v.y = 4;
    v.z = 0;
    cout << "Length: " << v.length() << endl; // Length: 5
    v.scale(2);
    v.print(); // [6, 8, 0]
    return 0;
}
