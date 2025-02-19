#include <iostream>
using namespace std;

double average(int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum / size;
}

int main() {
    int n;
    cout << "Въведете броя на елементите: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Въведете числата: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Средна стойност: " << average(arr, n) << endl;

    delete[] arr;
    return 0;
}
