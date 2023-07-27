#include <iostream>
#include "Book.h"

void getData(Book book[], int n)
{
    int id;
    std::string bName;
    std::string author;
    float price;

    for(int i=0; i<n; i++){
        std::cin>>id>>bName>>author>>price;
        book[i].setBookId(id);
        book[i].setBookName(bName);
        book[i].setAuthor(author);
        book[i].setPrice(price);
    }
}

bool search(Book book[], int n)
{
    int id;
    std::cout << "Enter search book id: ";
    std::cin >> id;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (book[i].getBookId() == id)
        {
            std::cout << "Book is found\n";
            flag = true;
            break;
        }
    }
    if (!flag)
        std::cout << "Book is not found\n";
    return flag;
}

void modify(Book book[], int n)
{
    int choice;
    char ch;
    std::cout << "\nMENU\t1.Book Name\t2.Author\t3.price\n";
    std::cin >> choice;

    for (int i = 0; i < n; i++)
    {
        switch (choice)
        {
        case 1:
            if (search(book, n))
            {
                std::string bName;
                std::cin >> bName;
                book[i].setBookName(bName);
            }
            break;
        case 2:
            if (search(book, n))
            {
                std::string author;
                std::cin >> author;
                book[i].setAuthor(author);
            }
            break;

        case 3:
            if (search(book, n))
            {
                float price;
                std::cin >> price;
                book[i].setPrice(price);
            }
            break;

        default:
            break;
        }
    }
}

void putData(Book book[], int n)
{
    for (int i = 0; i < n; i++)
    {
        book[i].show();
    }
}

void showMenu(Book book[], int n)
{
    int choice;
    char ch;

    do
    {
        std::cout << "\nMENU\t1.Search\t2.Modify\t3.Display\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            search(book, n);
            break;
        case 2:
            modify(book, n);
            break;

        case 3:
            putData(book, n);
            break;

        default:
            break;
        }
        std::cout << "\nDo you want further operations(y/n)? ";
        std::cin >> ch;
    } while (ch == 'y');
}

int main()
{
    int n;
    std::cout << "Enter how much books you want: ";
    std::cin >> n;
    Book book[n];

    // take input
    getData(book, n);

    showMenu(book, n);

    // make a object using pointer
    std::cout << "Create object using pointer i.e assigned memory in heap\n";
    Book *b = new Book;
    b->show();
    std::cout << "release the heap memory using 'delete' keyword.\n";
    delete b;

    // create const object
    std::cout << "\nCreated the object using const keyword\n";
    const Book b1;
    b1.show();

    return 0;
}