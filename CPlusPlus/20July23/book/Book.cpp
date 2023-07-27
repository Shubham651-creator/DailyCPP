k#include <iostream>
#include "Book.h"

Book::Book()
{
    bookId = 1;
    bookName = "Wings of fire";
    author = "APJ Kalam";
    price = 210;
}

Book::Book(int bookId, std::string bookName, std::string author, float price)
{
    this->bookId = bookId;
    this->bookName = bookName;
    this->author = author;
    this->price = price;
}

void Book::show() const
{
    std::cout << bookId << " " << bookName << " -" << author << " " << price << std::endl;
}

Book::~Book()
{
}