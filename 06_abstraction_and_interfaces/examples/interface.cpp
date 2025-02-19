#include <iostream>
using namespace std;

// Интерфейс (чисто абстрактен клас)
class IShape {
public:
    virtual double area() const = 0;  // Чисто виртуална функция
    virtual void display() const = 0; // Чисто виртуална функция
    virtual ~IShape() {} // Виртуален деструктор
};

// Клас за кръг, който имплементира Shape
class Circle : public IShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        cout << "Circle with radius " << radius << " has area: " << area() << endl;
    }
};

// Клас за правоъгълник, който имплементира Shape
class Rectangle : public IShape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void display() const override {
        cout << "Rectangle with width " << width << " and height " << height << " has area: " << area() << endl;
    }
};

int main() {
    // Полиморфно използване на интерфейса
    IShape* shapes[] = { new Circle(5), new Rectangle(4, 6) };

    for (IShape* shape : shapes) {
        shape->display();
        delete shape; // Освобождаване на паметта
    }

    return 0;
}
