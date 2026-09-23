#include <iostream>
#include "library.h"
#include <vector>

// BOOK
Book::Book(int bookId, int bookCategory)
	: id(bookId), category(bookCategory), borrowed(false) {
};

int Book::getid() const {
	return id;
};

int Book::getbookcategory() const {
	return category;
};

bool Book::getborrowedstate() const {
	return borrowed;
};

void Book::setReturn() {
	borrowed = false;
}

void Book::setBorrow() {
	borrowed = true;
}


/*
int Library::countCategories() {
	std::vector<int> seenCategories;
	
	for (const Book& b : books)
	{
		int cat = b.getbookcategory();
		bool alreadySeen = false;

		for (int c : seenCategories)
		{
			if (c==cat)
			{
				alreadySeen = true;
				break;
			}
		}

		if (!alreadySeen)
		{
			seenCategories.push_back(cat);
		}

	}

	return seenCategories.size();
}
*/

std::vector<int> Library::countCategories() {
	std::vector<int> AllCategories;
	
	for (const Book& b : books)
	{
		AllCategories.push_back(b.getbookcategory());
	}

	return AllCategories;
}

void Library::addBook(int bookid, int category) {

	//ny bog laves
	Book newbook(bookid, category);
	books.push_back(newbook);

	std::vector<int> AllCategories = countCategories();
	int countOfCategory =0;
	int categories =1;

	//tæller den nyindsatte kategori
	for (int i =0; i<AllCategories.size(); i++){
		if (category == AllCategories[i])
		{
			++countOfCategory;
		}
	}

	//tæller mængden af kategorier
	for (int i =0; i<AllCategories.size(); i++){
		if (AllCategories[i] != category)
		{
			++categories;
		}
	}
	
	//finder gennemsnit blandt alle kategorier
	int avg = AllCategories.size() / categories;

	//hvis kategori indsat er mere end dobbelt så stor som gennemsnit, send besked.
	if (countOfCategory > avg*2)
	{
		std::cout<<"category " <<category<< " exceeds limit"<<std::endl;
	}
	
}

void Library::displayAllBooks() {
	for (const Book& b : books) {
		std::cout << "BookID: " << b.getid()
			<< " BookCategory: " << b.getbookcategory()
			<< " Borrowedstate: " << (b.getborrowedstate() ? "Borrowed" : "not borrowed") << std::endl;
	}
}

void Library::displayAvailableBooks() {
	for (const Book& b : books) {
		if (b.getborrowedstate() == false) {
			std::cout << "BookID: " << b.getid()
				<< " BookCategory: " << b.getbookcategory()
				<< " Borrowedstate: " << (b.getborrowedstate() ? "Borrowed" : "not borrowed") << std::endl;

		}
	}
}

bool Library::borrowBook(int a) {
	for (Book& b : books) {
		if (b.getid() == a) {
			if (b.getborrowedstate() == false) {
				b.setBorrow();
				return true;
			}
			else {
				return false;
			}
		}
		
	}
	return false;
}

void Library::displayBorrowedBooks() {
	for (const Book& b : books) {
		if (b.getborrowedstate()) {
			std::cout << "BookID: " << b.getid()
				<< " BookCategory: " << b.getbookcategory()
				<< " Borrowedstate: " << (b.getborrowedstate() ? "Borrowed" : "notborrowed") << std::endl;

		}
	}
}

bool Library::returnBook(int a) {
	for (Book& b : books) {
		if (b.getid() == a) {
			if (b.getborrowedstate() == true) {
				b.setReturn();
				return true;
			}
			else {
				return false;
			}
		}

	}
	return false;
}

int Library::countBooksInCategory(int a) {
	int countbooks = 0;
	for (const Book& b : books) {
		if (b.getbookcategory() == a) {
		 ++countbooks;
		}
	}
	return countbooks;
}





