#include <iostream>
#include <cmath>

using namespace std;

// Абстрактен клас
class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0; // Чиста виртуална функция
    virtual void display() const = 0; // Чиста виртуална функция
};

// Клас за правоъгълник
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void display() const override {
        cout << "Rectangle with area: " << area() << endl;
    }
};

// Клас за кръг
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle with area: " << area() << endl;
    }
};

int main() {
    Shape* shape1 = new Rectangle(5, 10);
    Shape* shape2 = new Circle(7);

    shape1->display();
    shape2->display();

    delete shape1;
    delete shape2;

    return 0;
}
