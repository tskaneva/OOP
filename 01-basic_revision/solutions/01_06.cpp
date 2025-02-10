#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Въведете броя на елементите: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Въведете числата: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Сума: " << sum << endl;

    delete[] arr;
    return 0;
}
