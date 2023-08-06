#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "Book.h"


// library class is our wrapper class
class Library
{
private:
    Book *books;

public:
    // default constructor
    Library();
    // destructor
    ~Library();

    // deep copy constructor
    Library(Library &libraryBook);

    // overloading ->
    // it returns the address of book object
    Book *operator->()
    {
        return books;
    }
    // overloading *
    // it returns the book object directly
    Book operator*()
    {
        return *books;
    }
};

#endif // LIBRARY_H
