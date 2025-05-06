#include <iostream>
using namespace std;

// Интерфейс за рисуване
class IDrawable {
public:
    virtual void draw() const = 0;
    virtual ~IDrawable() = default;
};

// Интерфейс за движение
class IMovable {
public:
    virtual void move(double dx, double dy) = 0;
    virtual ~IMovable() = default;
};

// Клас, който имплементира и двата интерфейса
class Sprite : public IDrawable, public IMovable {
    double x, y;
public:
    Sprite(double startX, double startY) : x(startX), y(startY) {}

    void draw() const override {
        cout << "Drawing sprite at (" << x << ", " << y << ")" << endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        cout << "Moved sprite to (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Sprite s(10.0, 20.0);

    IDrawable* d = &s;
    IMovable* m = &s;

    d->draw();     // Викаме чрез IDrawable
    m->move(5, -3); // Викаме чрез IMovable
    d->draw();     // Виждаме новата позиция

    return 0;
}
