#ifndef BOOK_H
#define BOOK_H

#include <iostream>



class Book
{
private:
    int bookNumber;
    std::string bookName;
    float price;
    std::string autherName;
    int numberOfCopiesInLibrary;
    int numberOfCopiesIssued;

    // Book category
    const std::string category[4] = {"FICTION", "BIOGRAPHY", "HISTORICAL", "ADVENTURE"};

public:
    // default constructor
    Book();
    // parameterized construtor
    Book(int book_name);

    void accept();
    void display();

    int getBookNumber() const { return bookNumber; }
    void setBookNumber(int bookNumber_) { bookNumber = bookNumber_; }

    std::string getBookName() const { return bookName; }
    void setBookName(const std::string &bookName_) { bookName = bookName_; }

    float getPrice() const { return price; }
    void setPrice(float price_) { price = price_; }

    std::string getAutherName() const { return autherName; }
    void setAutherName(const std::string &autherName_) { autherName = autherName_; }

    int getNumberOfCopiesInLibrary() const { return numberOfCopiesInLibrary; }
    void setNumberOfCopiesInLibrary(int numberOfCopiesInLibrary_) { numberOfCopiesInLibrary = numberOfCopiesInLibrary_; }

    int getNumberOfCopiesIssued() const { return numberOfCopiesIssued; }
    void setNumberOfCopiesIssued(int numberOfCopiesIssued_) { numberOfCopiesIssued = numberOfCopiesIssued_; }

    // extraction operator overloading
    friend void operator<<(std::ostream &out, Book &book);
    friend void operator>>(std::istream &in, Book &book);
};

#endif // BOOK_H
