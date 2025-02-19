#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Въведете броя на елементите: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Въведете числата: ";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);  // Използване на указатели
    }

    cout << "Числата в обратен ред: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
