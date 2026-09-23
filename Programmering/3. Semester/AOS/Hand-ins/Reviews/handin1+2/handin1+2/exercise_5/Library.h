#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library
{
public:
    void addBook(int id, int category);
    bool borrowBook(int id);
    bool returnBook(int id);

    void displayAvailableBooks() const;
    void displayBorrowedBooks() const;

    int countBooksInCategory(int category) const;

private:
    std::vector<Book> books;

    void checkBalance();
};

#endif