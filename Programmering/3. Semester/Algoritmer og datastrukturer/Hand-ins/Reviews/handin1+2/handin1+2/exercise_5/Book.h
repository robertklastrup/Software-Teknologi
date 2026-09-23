#ifndef BOOK_H
#define BOOK_H

class Book
{
public:
    Book(int id, int category);

    int id;
    int category;
    bool borrowed;
    
};

#endif
