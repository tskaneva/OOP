#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    bool isAvailable;

public:
    // Метод за задаване на информация за книгата
    void setDetails(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
        isAvailable = true; // При създаване книгата е налична
    }

    // Метод за маркиране на книгата като заета
    void markAsBorrowed() {
        if (isAvailable) {
            isAvailable = false;
            cout << "The book \"" << title << "\" is now borrowed.\n";
        } else {
            cout << "The book \"" << title << "\" is already borrowed.\n";
        }
    }

    // Метод за маркиране на книгата като върната
    void markAsReturned() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "The book \"" << title << "\" is now returned.\n";
        } else {
            cout << "The book \"" << title << "\" is already available.\n";
        }
    }

    // Метод за отпечатване на информация за книгата
    void displayInfo() {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Year of publication: " << year << "\n";
        cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
    }

    // Метод за проверка дали книгата е стара издание
    bool isOldEdition(int currentYear) {
        return year < currentYear - 20;
    }
};

int main() {
    // Създаване на обект от клас Book
    Book book1;

    // Задаване на информация за книгата
    book1.setDetails("1984", "George Orwell", 1949);

    // Отпечатване на информация за книгата
    book1.displayInfo();

    // Проверка дали книгата е старо издание
    if (book1.isOldEdition(2025)) {
        cout << "The book is an old edition.\n";
    } else {
        cout << "The book is not an old edition.\n";
    }

    // Маркиране на книгата като заета
    book1.markAsBorrowed();

    // Опит за повторно заемане
    book1.markAsBorrowed();

    // Маркиране на книгата като върната
    book1.markAsReturned();

    return 0;
}
