#include <iostream>
using namespace std;

class Base
{
public:
    virtual void mess1()
    { cout << "Base - message1 \n"; }

    virtual void mess2()
    { cout << "Base - message2 \n"; }

    void mess3()
    { cout << "Base - message3 \n"; }
};

class Derived : public Base
{
public:
    void mess1()
    { cout << "Derived - message1 \n"; }

    void mess2( int x)  // Не е виртуален
    {    cout << "Derived - message2 \n"; }

    void mess3()
    { cout << "Derived - message3 \n"; }
};
int main( )
{
    Derived x;
    Base y;
    Base *bp = &x; // bp е от тип Base, a сочи към обект от Derived
    bp -> mess1(); // Derived :: mess1()
    bp -> mess2(); // Base :: mess2()
    bp -> mess3(); // Base :: mess3() - не е виртуален
    bp = &y; // bp сочи към обект от клас Base
    bp -> mess1(); // Base :: mess1()

    return 0;
}