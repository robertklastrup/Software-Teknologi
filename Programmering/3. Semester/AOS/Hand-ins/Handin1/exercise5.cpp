#include <iostream>
#include <vector>
#include <algorithm>

class Book{
    private:
        int id;
        int category; // 0-15
        bool borrowed;
    public:
        Book(int i, int c);
        int getCategory();
        int getId();
        bool isBorrowed();
        void setReturn();
        void setBorrowed();
        void print();
};

Book::Book(int i, int c){
    id = i;
    if (c < 0 || c > 15){
        std::cout << "Invalid input, try again" << std::endl;
        category = 0;
    }
    else{
        category = c;
    }
    borrowed = false;
}

int Book::getCategory(){
    return category;
}

int Book::getId(){
    return id;
}

bool Book::isBorrowed(){
    return borrowed;
}

void Book::setBorrowed(){
    borrowed = true;
}
        
void Book::setReturn(){
    borrowed = false;
}

void Book::print(){
    std::cout << "Book id: " << id << " Category: " << category << std::endl;
}


/*--------------------------------------------------------------------*/

class Library{
    private:
        std::vector<Book> books;
        std::vector<int> categoryCounts =std::vector<int>(16, 0);
        
        

    //Borrow, return, display avalible, display borrowed, addBook, Return number of books in category
    public:
        void addBook(int id, int c);
        bool borrowBook(int id);
        bool returnBook(int id);
        void displayAvailableBooks();
        void displayBorrowedBooks();
        int countBooksInCategory(int categoryToCheck);
        void displayAllBooks();
};

void Library::addBook(int id, int c){
    Book b (id, c);
    books.push_back(b);
    //Warning:
    double sum = 0;
    double validCategories = 0;
    for (int i = 0; i < categoryCounts.size(); i++){
        if(categoryCounts[i] > 0){
            sum = sum + categoryCounts[i];
            validCategories++;
        }
    }
    double average = sum / validCategories;
    categoryCounts[b.getCategory()]++;
    if(categoryCounts[b.getCategory()] > (average*2)){
        std::cout << "Warning: category" << b.getCategory() << " has significally more books than average"<< std::endl;
    }
    
}



bool Library::borrowBook(int id){
    for(int i = 0; i < books.size(); i++){
        if(books[i].getId() == id){
            if(books[i].isBorrowed() == false){
                books[i].setBorrowed();
                return true;
            }
            else{
                std::cout << "Book is already borrowed" << std::endl;
                return false;
            }
        }
    }
    return false;
}

bool Library::returnBook(int id){
    for(int i = 0; i < books.size(); i++){
        if(books[i].getId() == id){
            if(books[i].isBorrowed() == true){
                books[i].setReturn();
                return true;
            }
            else{
                std::cout << "Book is not borrowed and can therefore not be returned" << std::endl;
                return false;
            }
        }
    }
    return false;
}

void Library::displayAvailableBooks(){
    for (int i = 0; i < books.size(); i++){
        if (books[i].isBorrowed() == false){
            books[i].print();
        }
    }
}

void Library::displayBorrowedBooks(){
    for (int i = 0; i < books.size(); i++){
        if (books[i].isBorrowed() == true){
            books[i].print();
        }
    }
}

void Library::displayAllBooks(){
    std::cout << "All books in the library:" << std::endl;
    for (int i = 0; i < books.size(); i++){
        books[i].print();
    }
}

int Library::countBooksInCategory(int categoryToCheck){
    if(categoryToCheck < 0 || categoryToCheck > 15){
        return 0;
    }
    else{
        return categoryCounts[categoryToCheck];
    }
}




int main() {
    Library myLibrary;
    // Adding books to the library
    myLibrary.addBook(1, 3);   // Book ID: 1, Category: 3
    myLibrary.addBook(2, 7);   // Book ID: 2, Category: 7
    myLibrary.addBook(3, 3);   // Book ID: 3, Category: 3
    myLibrary.addBook(4, 15);  // Book ID: 4, Category: 15
    myLibrary.addBook(5, 3);   // Book ID: 5, Category: 3 (Warning should trigger here)
    myLibrary.addBook(6, 0);   // Book ID: 6, Category: 0
    // Display all books in the library
    std::cout << "\nAll books in the library:\n";
    myLibrary.displayAllBooks();
    // Display available books
    std::cout << "\nAvailable books in the library:\n";
    myLibrary.displayAvailableBooks();
    // Borrow a book by ID
    std::cout << "\nBorrowing Book_ID_2:\n";
    if (myLibrary.borrowBook(2)) {
        std::cout << "Book_ID_2_borrowed_successfully.\n";
    } else {
        std::cout << "Failed_to_borrow_Book_ID_2.\n";
    }
    // Attempt to borrow the same book again
    std::cout << "\nAttempting_to_borrow_Book_ID_2_again:\n";
    if (myLibrary.borrowBook(2)) {
        std::cout << "Book_ID_2_borrowed_successfully.\n";
    } else {
        std::cout << "Failed_to_borrow_Book_ID_2.\n";
    }
    // Display borrowed books
    std::cout << "\nBorrowed_books_in_the_library:\n";
    myLibrary.displayBorrowedBooks();
    // Return a borrowed book by ID
    std::cout << "\nReturning_Book_ID_2:\n";
    if (myLibrary.returnBook(2)) {
        std::cout << "Book_ID_2_returned_successfully.\n";
    } else {
        std::cout << "Failed_to_return_Book_ID_2.\n";
    }
    // Display available books after returning
    std::cout << "\nAvailable_books_in_the_library_after_returning_Book_ID_2:\n";
    myLibrary.displayAvailableBooks();
    // Display the number of books in a specific category
    int categoryToCheck = 3;
    std::cout << "\nNumber_of_books_in_category_" << categoryToCheck << ": "
               << myLibrary.countBooksInCategory(categoryToCheck) << std::endl;

    return 0;
}




/*
b)
1. std::vector<Book> books
The reason we chose to store the books in a vector is simply because, when using an array for example
you don't really know how many books will be stored, an a vector will expand to your needs using push_back,
where an array is more static, and you will have to do dynamic allocation manually, to expand the array so to say

2. std::vector<int> categoryCounts = std::vector<int>(16, 0)
If we didn't have categoryCounts, we would have to just use countBooksInCategory, which would have to
loop through the entire "books" vector and count matches every time its called. 
In terms of complexity, if we loop through books to find a number of books in a category each time, 
the big-o notation would be O(n), where when we have a vector where we keep cound we can just call
categoryCounts[x], which is just O(1)
On the other hand, there is extra steps in addBook, because we have to update both books and categoryCounts
when we add a book.

3. The dublication of categoryCounts and books
The reason we chose to have 2 vectors with similar data, was because we could use the two vectors
more independantly more efficient. Though they can get out of sync since they only follow each other
in addBook.

*/