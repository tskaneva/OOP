#include <iostream>
using namespace std;

class Color {
private:
    int red, green, blue;

public:
    void setRed(int value) {
        if (value >= 0 && value <= 255) {
            red = value;
        } else {
            cout << "Invalid value for red!" << endl;
        }
    }

    int getRed() const {
        return red;
    }

    void setGreen(int value) {
        if (value >= 0 && value <= 255) {
            green = value;
        } else {
            cout << "Invalid value for green!" << endl;
        }
    }

    int getGreen() const {
        return green;
    }

    void setBlue(int value) {
        if (value >= 0 && value <= 255) {
            blue = value;
        } else {
            cout << "Invalid value for blue!" << endl;
        }
    }

    int getBlue() const {
        return blue;
    }
};

int main() {
    Color color;
    color.setRed(120);
    color.setGreen(200);
    color.setBlue(255);

    cout << "Color RGB: (" << color.getRed() << ", " << color.getGreen() << ", " << color.getBlue() << ")" << endl;
    return 0;
}
