#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Build your Author class here
class Author {
    public:
        string name;
        string nationality;
        Author() {}
    
    Author(string n, string na){
        name = n;
        nationality = na;
    }
    void describe(){
        cout << name << endl;
        cout << nationality << endl;
    }
};

// Build your Book class here
class Book {
    public:
        string title;
        Author author;
        int year;
        bool isAvailable;
    Book(string t, Author a, int y){
        title = t;
        author = a;
        year = y;
        isAvailable = true;
    }
    void describe(){
        if(isAvailable == true){
            cout << title << " (" << author.name << ") " << "- Available" << endl;
        }
        else{
            cout << title << " (" << author.name << ") " << "- Checked Out" << endl;
        }
    }
    void checkOut(){
        isAvailable = false;
    }
    void returnBook(){
        isAvailable = true;
    }
};

// Build your Member class here
class Member {
    public:
        string name;
        int memberID;
        vector <Book> borrowedBooks;
    Member(string n, int m){
        name = n;
        memberID = m;
    }
    void borrowBook(Book b){
        borrowedBooks.push_back(b);
        borrowedBooks[borrowedBooks.size() - 1].checkOut();
    }
    void returnBook(int m){
        borrowedBooks.erase(borrowedBooks.begin() + m);
    }
    void describe(){
        cout << name << " (ID: " << memberID << ")" << endl;
        if(borrowedBooks.size() == 0){
            cout << "  - (no books borrowed)" << endl;
        }
        for (int i = 0; i < borrowedBooks.size(); i++){
            cout << "  - " << borrowedBooks[i].title << endl;
        }
    }
};

// Build your Library class here
class Library{
    public:
        string libraryName;
        vector <Book> books;
        vector <Member> members;
    Library (string ln){
        libraryName = ln;
    }
    void addBook(Book b){
        books.push_back(b);
    }
    void addMember(Member m){
        members.push_back(m);
    }
    void borrowBook(int mi, int bi){
        members[mi].borrowBook(books[bi]);
        books[bi].checkOut();
    }
    int findBook(string t){
        for (int i = 0; i < books.size(); i++){
            if(t == books[i].title){
                return (i);
            }
        }
        return -1;
    }

    void describe(){
        cout << "Library: " << libraryName << endl;
        cout << "-----------------" << endl;
        for (int i = 0; i < books.size(); i++){
            books[i].describe();
        }
        cout << "-----------------" << endl;
        for (int i = 0; i < members.size(); i++){
            members[i].describe();
        }
    }
};

int main() {
    // Create a Library
    Library R ("Roberts Bibliotek");

    // Add at least 4 books with authors
    Author a1 ("Robert", "Denmark");
    Book b1("The Goat", a1, 2003);
    R.addBook(b1);

    Author a2 ("Malthe", "Denmark");
    Book b2("Tucan Club", a2, 2001);
    R.addBook(b2);

    Author a3 ("Kevin", "Denmark");
    Book b3("Durant", a3, 2002);
    R.addBook(b3);

    Author a4 ("Moein", "Afghanistan");
    Book b4("My Political Views", a4, 2004);
    R.addBook(b4);


    // Add at least 3 members
    Member m1 ("Frederik", 1);
    R.addMember(m1);

    Member m2 ("Hjalte", 2);
    R.addMember(m2);

    Member m3 ("Simon", 3);
    R.addMember(m3);

    // Borrow some books
    R.members[0].borrowBook(R.books[0]);
    R.members[0].borrowBook(R.books[2]);
    R.members[2].borrowBook(R.books[1]);
    R.members[1].borrowBook(R.books[3]);

    // Call describe()
    R.describe();
}

