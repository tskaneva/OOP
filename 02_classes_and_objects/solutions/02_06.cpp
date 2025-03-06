#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x, y, z;
public:
    void set(const double x, const double y, const double z) {
      this->x = x;
      this->y = y;
      this->z = z;
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    void scale(const double factor) {
        x *= factor;
        y *= factor;
        z *= factor;
    }

    void print() const {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }
};

int main() {
    Vector v;
    v.set(3, 4, 0);
    cout << "Length: " << v.length() << endl; // Length: 5
    v.scale(2);
    v.print(); // [6, 8, 0]
    return 0;
}
