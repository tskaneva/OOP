#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author;
    double price;
public:
    void setTitle(string title){
        this->title = title;
    }
    void setAuthor(string author){
        this->author = author;
    }
    void setPrice(double price){
        this->price = price;
    }
    void print() {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price << endl;
    }
};

int main() {
    Book books[5];

    for (int i = 0; i < 5; i++) {
      books[i].setTitle("Title " + to_string(i + 1));
      books[i].setAuthor("Author " + to_string(i + 1));
      books[i].setPrice(i * 1.5);
    }

    for (int i = 0; i < 5; i++) {
        books[i].print();
    }

    return 0;
}
