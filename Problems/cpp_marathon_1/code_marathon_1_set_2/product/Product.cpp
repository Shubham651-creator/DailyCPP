#include <iostream>
#include "Product.h"

Product::Product()
{
    productNumber = 1;
    productName = "Tshirt";
    productRate = 200;
    brandName = "Nick";
    productQuantityInStock = 200;
    productQuantityPurchased = 10;
    productCategory = " shirt";
    totalAmount = productRate * productQuantityPurchased;
}

Product::Product(int product_number, std::string product_name, int rate, std::string brand_name, int quantityInStock, int quantityPurchased, std::string product_category, int amount)
{
    productNumber = product_number;
    productName = product_name;
    productRate = rate;
    brandName = brand_name;
    productQuantityInStock = quantityInStock;
    productQuantityPurchased = quantityPurchased;
    productCategory = product_category;
    totalAmount = rate * quantityPurchased;
}

Product::~Product()
{
}

bool Product::validate()
{
    if (productQuantityPurchased > productQuantityInStock)
    {
        std::cout << "items are not avialable in stock. Reduce your quantity\n";
        return false;
    }
    return true;
}

void Product::accept()
{
    std::cout << "Enter product Number: ";
    std::cin >> productNumber;
    std::cout << "\nEnter product Name :";
    std::cin >> productName;
    std::cout << "\nEnter Rate : ";
    std::cin >> productRate;
    std::cout << "\nEnter brand Name :";
    std::cin >> brandName;
    std::cout << "\nEnter Quantity of product in stock:";
    std::cin >> productQuantityInStock;
    do
    {
        std::cout << "\nEnter Quantity of product purchased:";
        std::cin >> productQuantityPurchased;
    } while (!validate());

    std::cout << "Enter Category: ";
    std::cin >> productCategory;

    totalAmount = productRate* productQuantityPurchased;

    std::cout << "\n\n";
}

void Product::display()
{

    std::cout << productNumber <<"\t"<< productName<<"\t\t";

    std::cout <<  productQuantityPurchased<<"\t\t";

    std::cout << productRate<<"\t";

    std::cout << productCategory<<"\t\t";
    std::cout << totalAmount<<"\t";

    // std::cout << "\nbrand Name :" << brandName;

    // std::cout << "\nQuantity of product in stock:" << productQuantityInStock;

    std::cout << "\n\n";
}
