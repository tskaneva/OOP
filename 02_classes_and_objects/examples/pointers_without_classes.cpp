#include <iostream>
using namespace std;

int main() {
  // ПРИМЕР 1
  cout << "EX 1:" << endl;
  int a = 10;
  int* ptr = &a; // ptr е указател към a и съхранява адреса на a

  cout << *ptr << endl; // извежда стойността на a (10)
  cout << ptr << endl;  // извежда адреса на a

  *ptr = 100; // Промяна на стойността на a чрез указателя
  cout << *ptr << endl; // 100
  cout << a << endl; // 100

  // ПРИМЕР 2
  cout << endl << "EX 2:" << endl;
  int b = 10;
  int& ref = b; // ref е референция към b
  ref = 20;     // Променя стойността на b на 20

  cout << ref << endl; // 20
  cout << b << endl;  // 20

}