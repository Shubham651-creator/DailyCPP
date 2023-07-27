#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book
{
private:
    int bookId;
    std::string bookName;
    std::string author;
    float price;

public:
    Book();
    Book(int bookId, std::string bookName, std::string author, float price);
    void show()const;
    ~Book();

    int getBookId() const { return bookId; }
    void setBookId(int bookId_) { bookId = bookId_; }

    std::string getBookName() const { return bookName; }
    void setBookName(const std::string &bookName_) { bookName = bookName_; }

    std::string getAuthor() const { return author; }
    void setAuthor(const std::string &author_) { author = author_; }

    float getPrice() const { return price; }
    void setPrice(float price_) { price = price_; }
};

#endif // BOOK_H
