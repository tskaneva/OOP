#include <iostream>
using namespace std;

// Интерфейс
class IShape {
public:
    virtual void draw() const = 0;
    virtual ~IShape() {}
};

// Конкретни класове
class Circle : public IShape {
public:
    void draw() const override {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public IShape {
public:
    void draw() const override {
        cout << "Drawing a square" << endl;
    }
};

// Фабричен метод, който връща указател към обект от тип IShape.
IShape* createShape(const string& type) {
    if (type == "circle") return new Circle();
    if (type == "square") return new Square();
    return nullptr;
}

int main() {
    IShape* shape = createShape("circle");
    if (shape) {
        shape->draw();
        delete shape;
    }

    return 0;
}
