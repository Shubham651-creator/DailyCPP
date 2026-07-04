#include <iostream>
#include "Book.h"
#include"Library.h"


Book::Book()
{
    bookNumber = 691;
    bookName = "Wings of fire";
    price = 120;
    autherName = "A.P.J. Kalam";
    numberOfCopiesInLibrary = 13;
    numberOfCopiesIssued = 5;
} 

void Book::accept()
{
    std::cout << "Input Book Number";
    std::cin >> bookNumber;
    std::cout << "\nInput Book Name = " ;
    std::cin >> bookName;
    std::cout << "\nInput book Price= ";
    std::cin>>price;
    std::cout << "\nInput author Name= ";
    std::cin>>autherName;
    std::cout <<"\nInput number of copies in library =  ";
    std::cin>>numberOfCopiesInLibrary;
    std::cout <<"\nInput number of copies in isssued := ";
    std::cin>>numberOfCopiesIssued;    
     std::cout <<std::endl<<std::endl;
}

void Book::display()
{
    std::cout << "Book Number = " << bookNumber;
    std::cout << "\nBook Name= " << bookName;
    std::cout << "\nbook Price= " << price;
    std::cout << "\nauthor Name= " << autherName;
    std::cout <<"\nNumber of copies in library =  "<<numberOfCopiesInLibrary;
    std::cout<<"\nNumber of copies Issued = "<<numberOfCopiesIssued<<"\n\n"; 
}

void operator<<(std::ostream &out, Book &book)
{
    out << "Book Number = " << book.bookNumber;
    out << "\nBook Name= " << book.bookName;
    out << "\nbook Price= " << book.price;
    out << "\nauthor Name= " << book.autherName;
    out <<"\nNumber of copies in library =  "<<book.numberOfCopiesInLibrary;
    out<<"\nNumber of copies Issued : "<<book.numberOfCopiesIssued;
    std::cout <<std::endl<<std::endl;
}

void operator>>(std::istream &in, Book &book)
{
    std::cout << "Book Numbe= ";
    in >> book.bookNumber;
    std::cout << "\nBook Name= " ;
    in >> book.bookName;
    std::cout << "\nbook Price= ";
    in>>book.price;
    std::cout << "\nauthor Name= ";
    in>>book.autherName;
    std::cout <<"\nNumber of copies in library =  ";
    in>>book.numberOfCopiesInLibrary;
    std::cout <<"\nNumber of copies in isssued =  ";
    in>>book.numberOfCopiesIssued;    

    std::cout << "\n\n";
}

// library class implementation
Library::Library()
{
    books = new Book;
}

Library::~Library()
{
    delete books;
}

Library::Library(Library &library)
{
    books = new Book;
    books = library.books;
}
 