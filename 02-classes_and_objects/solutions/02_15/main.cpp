#include "Book.h"

int main(){
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