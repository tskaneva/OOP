#include <iostream>
using namespace std;

class Example {
private:
    int privateVar; // Достъпна само вътре в класа

protected:
    int protectedVar; // Достъпна в класа и неговите наследници

public:
    int publicVar; // Достъпна отвсякъде

    void setPrivateVar(int value) {
        privateVar = value;
    }

    int getPrivateVar() const {
        return privateVar;
    }
};

int main() {
    Example obj;
    obj.publicVar = 10; // Достъпно
    // obj.privateVar = 20; // Грешка: privateVar е private
    obj.setPrivateVar(20); // Достъп чрез метод

    cout << "Public variable: " << obj.publicVar << endl;
    cout << "Private variable (via getter): " << obj.getPrivateVar() << endl;

    return 0;
}