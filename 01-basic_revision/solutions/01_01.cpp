#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Въведете броя на числата: ";
    cin >> n;

    int arr[n];
    cout << "Въведете числата: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    cout << "Минимум: " << min << endl;
    cout << "Максимум: " << max << endl;

    return 0;
}
