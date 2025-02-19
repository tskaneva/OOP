#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title, author;
    double price;

    void print() {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price << endl;
    }
};

int main() {
    Book books[5] = {
        {"Book 1", "Author 1", 10.5},
        {"Book 2", "Author 2", 15.0},
        {"Book 3", "Author 3", 20.0},
        {"Book 4", "Author 4", 25.5},
        {"Book 5", "Author 5", 30.0}
    };

    for (int i = 0; i < 5; i++) {
        books[i].print();
    }

    return 0;
}
