#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    cout << "Въведете две числа: ";
    cin >> x >> y;

    cout << "Преди размяната: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "След размяната: x = " << x << ", y = " << y << endl;

    return 0;
}
