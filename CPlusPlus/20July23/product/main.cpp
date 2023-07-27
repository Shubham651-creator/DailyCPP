#include <iostream>
#include "Product.h"

void search(Product arr[], int n)
{
    int num;
    std::cout << "Enter Product number to search: ";
    std::cin >> num;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].getProductId() == num)
        {
            std::cout << "Product is found\n";
            flag = true;
            break;
        }
    }
    if (!flag)
        std::cout << "Product is NOT found\n";
}

void modify(Product arr[], int n)
{
    int num;
    std::cout << "Enter Product number to modify: ";
    std::cin >> num;

    std::cout << "Menu\t 1.Product name\t2.price\n";
    int choice;
    std::cin >> choice;

    for (int i = 0; i < n; i++)
    {
        switch (choice)
        {
        case 1:
            if (arr[i].getProductId() == num)
            {
                std::string name;
                std::cin >> name;
                arr[i].setProductName(name);
            }
            break;

        case 2:
            if (arr[i].getProductId() == num)
            {
                float bal;
                std::cin >> bal;
                arr[i].setPrice(bal);
            }
            break;

        default:
            break;
        }
    }
}

void putData(Product arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].show();
    }
}

void showMeun(Product arr[], int n)
{
    int choice;
    char ch;
    do
    {
        std::cout << "Application: 1.Search\t2.Modify\t3.Display \n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            search(arr, n);
            break;

        case 2:
            modify(arr, n);
            break;
        case 3:
            putData(arr, n);
            break;

        default:
            break;
        }
        std::cout << "\nDo you want further operations(y/n)? ";
        std::cin >> ch;

    } while (ch == 'y');
}

void getData(Product arr[], int n)
{
    int id;
    float bal;
    std::string name;
    for (int i = 0; i < n; i++)
    {
        std::cin >> id>>name >> bal;
        arr[i].setProductId(id);
        arr[i].setProductName(name);
        arr[i].setPrice(bal);
    }
}

int main()
{
    int n;
    std::cout << "Enter Number of Product: ";
    std::cin >> n;

    Product p[n];

    getData(p, n); // take a user input

    showMeun(p, n);

    // make object using pointer which assigned memory to heap
    std::cout << "Create object using pointer i.e assigned memory in heap\n";
    Product *a = new Product;
    a->show();
    std::cout << "release the heap memory using 'delete' keyword.\n";
    delete a;

    // create const object
    std::cout << "\nCreated the object using const keyword\n";
    const Product a1;
    a1.show();

    //a1.setPrice(200.00f);  //compiled time error

    return 0;
}