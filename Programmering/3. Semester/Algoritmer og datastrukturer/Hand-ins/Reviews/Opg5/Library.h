#pragma once
#include <vector>

class Book {
private:
	int id;
	int category;
	bool borrowed;

public:
	// Constructor
	Book(int bookId, int bookCategory);

	int getid() const;

	int getbookcategory() const;

	bool getborrowedstate() const;

	void setBorrow();
	
	void setReturn();

};

class Library {
	public:

	std::vector<int> countCategories();

	void addBook(int bookid, int category);

	void displayAllBooks();

	void displayAvailableBooks();

	bool borrowBook(int a);

	void displayBorrowedBooks();

	bool returnBook(int a);

	int countBooksInCategory(int a);

	private:
	std::vector<Book> books;

};

