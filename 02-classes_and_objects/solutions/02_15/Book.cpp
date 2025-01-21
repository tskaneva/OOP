#include "Book.h"

void Book::setDetails(string t, string a, int y) {
    title = t;
    author = a;
    year = y;
    isAvailable = true;
}

void Book::markAsBorrowed() {
    if (isAvailable) {
        isAvailable = false;
        cout << "The book \"" << title << "\" is now borrowed.\n";
    } else {
        cout << "The book \"" << title << "\" is already borrowed.\n";
    }
}

void Book::markAsReturned() {
    if (!isAvailable) {
        isAvailable = true;
        cout << "The book \"" << title << "\" is now returned.\n";
    } else {
        cout << "The book \"" << title << "\" is already available.\n";
    }
}

void Book::displayInfo() {
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Year of publication: " << year << "\n";
    cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
}

bool Book::isOldEdition(int currentYear) {
    return year < currentYear - 20;
}