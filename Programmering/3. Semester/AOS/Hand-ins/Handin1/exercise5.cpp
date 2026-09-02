#include <iostream>
#include <vector>
#include <algorithm>

class Book{
    private:
        int id;
        int category; // 0-15
    public:
        Book(int i, int c);
        int getCategory();
};

Book::Book(int i, int c){
    id = i;
    if (c > 0 || c < 15){
        std::cout << "Invalid input, try again" << std::endl;
    }
    else{
        category = c;
    }
}
int Book::getCategory(){
    return category;
}


class Library{
    private:
        std::vector<Book> books;
        
        

    //Borrow, return, display avalible, display borrowed, addBook, Return number of books in category
    public:
        void addBook(Book());
        void borrowBook();
        void returnBook();
        void displayAvalible();
        void displayBorrowed();
        void displayBooksInCategory();
        
};

void Library::addBook(Book()){
    //Warning when books in category exceeds twice the number of books on average in other categories - a valid category is a category with more than one book
    
    int sum = 0;
    for (int i = 0; i < books.size();i++){
        books[i].getCategory();
        sum++;
    }
    double average = sum / books.size();
    for(int j = 0; j < books.size(); j++){
        if()
    }

}

//Jeg skal lave en funktion, som kigger på hvor mange bøger der er i hver kategori, lægger dem sammen, og dividerer med antallet af kategorier.

/*Først skal vi se hvor mange aktive kategorier der er
Vi kunne gøre noget i stil med at kigge på bøgerne i vores vector, sorterer vectoren, og skip hvis de er ens
Men vi bør måske lave en vector der hedder kategories
*/