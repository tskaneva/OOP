// class diagram - 06_abstraction_and_interfaces/images/draw_abstract.png
#include <iostream>
using namespace std;

class GUIElement {
public:
    virtual void draw() = 0;
    virtual void click() = 0;
    virtual ~GUIElement() {}
};


class Button : public GUIElement {
public:
    void draw() override {
        cout << "Drawing a button." << endl;
    }
    void click() override {
        cout << "Button clicked!" << endl;
    }
};

class TextBox : public GUIElement {
public:
    void draw() override {
        cout << "Drawing a text box." << endl;
    }
    void click() override {
        cout << "TextBox focused for typing." << endl;
    }
};

class CheckBox : public GUIElement {
public:
    void draw() override {
        cout << "Drawing a checkbox." << endl;
    }
    void click() override {
        cout << "Checkbox toggled." << endl;
    }
};

