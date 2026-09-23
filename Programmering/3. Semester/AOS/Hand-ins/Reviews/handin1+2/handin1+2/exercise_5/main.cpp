#include <iostream>
#include "Library.h"

int main()
{
    Library myLibrary;

    myLibrary.addBook(1, 3);
    myLibrary.addBook(2, 7);
    myLibrary.addBook(3, 3);
    myLibrary.addBook(4, 15);
    myLibrary.addBook(5, 3); 
    myLibrary.addBook(6, 0);

    std::cout << "\nAvailable books:\n";
    myLibrary.displayAvailableBooks();

    std::cout << "\nBorrowing Book ID 2:\n";
    std::cout << (myLibrary.borrowBook(2) ? "Success\n" : "Failed\n");

    std::cout << "\nBorrowing Book ID 2 again:\n";
    std::cout << (myLibrary.borrowBook(2) ? "Success\n" : "Failed\n");

    std::cout << "\nBorrowed books:\n";
    myLibrary.displayBorrowedBooks();

    std::cout << "\nReturning Book ID 2:\n";
    std::cout << (myLibrary.returnBook(2) ? "Success\n" : "Failed\n");

    std::cout << "\nAvailable books after return:\n";
    myLibrary.displayAvailableBooks();

    std::cout << "\nBooks in category 3: " << myLibrary.countBooksInCategory(3) << "\n";
        
    
    return 0;
}
