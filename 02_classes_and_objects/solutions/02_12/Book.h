#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    bool isAvailable;

public:
    void setDetails(string, string, int);
    void markAsBorrowed();
    void markAsReturned();
    void displayInfo();
    bool isOldEdition(int currentYear);
};

#endif //BOOK_H
