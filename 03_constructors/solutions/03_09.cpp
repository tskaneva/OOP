#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool isBorrowed;

public:
    // Конструктор
    Book(const string& title, const string& author)
        : title(title), author(author), isBorrowed(false) {}

    // Метод за извеждане на информация за книгата
    void printInfo() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    // Приятелска декларация за класа Reader
    friend class Reader;
};

class Reader {
private:
    string name;
    Book* borrowedBook;

public:
    // Конструктор
    Reader(const string& name) : name(name), borrowedBook(nullptr) {}

    // Метод за взимане на книга
    void borrow(Book& book) {
        if (book.isBorrowed) {
            cout << "The book '" << book.title << "' is already borrowed." << endl;
        } else {
            borrowedBook = &book;
            book.isBorrowed = true;
            cout << name << " borrowed the book '" << book.title << "'." << endl;
        }
    }

    // Метод за връщане на книга
    void returnBook() {
        if (borrowedBook) {
            cout << name << " returned the book '" << borrowedBook->title << "'." << endl;
            borrowedBook->isBorrowed = false;
            borrowedBook = nullptr;
        } else {
            cout << name << " has no book to return." << endl;
        }
    }

    // Метод за извеждане на информация за читателя
    void printInfo() const {
        cout << "Reader: " << name << ", Book: ";
        if (borrowedBook) {
            cout << borrowedBook->title << endl;
        } else {
            cout << "None" << endl;
        }
    }
};

int main() {
    // Създаваме обекти от класовете
    Book book1("C++ Programming", "John Doe");
    Reader reader1("Ivan Ivanov");

    // Информация за книгата и читателя
    book1.printInfo();
    reader1.printInfo();

    // Читателят взима книгата
    reader1.borrow(book1);

    // Отново извеждаме информация
    book1.printInfo();
    reader1.printInfo();

    // Опит за взимане на вече заета книга
    Reader reader2("Maria Petrova");
    reader2.borrow(book1);

    // Читателят връща книгата
    reader1.returnBook();

    // Състояние след връщане
    book1.printInfo();
    reader1.printInfo();

    // Друг читател взима книгата
    reader2.borrow(book1);

    // Финално състояние
    book1.printInfo();
    reader2.printInfo();

    return 0;
}
