#include <iostream>
#include "Inventory.h"

int Inventory::initProductCode = 101;

Inventory::Inventory()
{
    // Initial product stock size > 20
    description_of_product = "battery";
    balance_stock = 100;
    productcode = initProductCode;

    initProductCode++;
}

Inventory::Inventory(std::string dec, int bal_stock)
{
    description_of_product = dec;
    balance_stock = bal_stock;
    productcode = initProductCode;

    initProductCode++;
}

Inventory::~Inventory()
{
}

void Inventory::purchase()
{
    int items;
    std::cout << "Enter number of purchasing items for " << description_of_product << "\n";
    std::cin >> items;

    balance_stock += items;
}

void Inventory::sale()
{
    int items;
    std::cout << "Enter number of sales items for " << description_of_product << "\n";
    std::cin >> items;

    balance_stock -= items;
}

void operator<<(std::ostream &out, Inventory &stock)
{
    out << " description of product : " << stock.description_of_product << "\n";
    out << " product code : " << stock.productcode << "\n";
    out << " Balance stock : " << stock.balance_stock << "\n\n";
}

void operator>>(std::istream &in, Inventory &stock)
{
    std::cout << "Enter product name :";
    in >> stock.description_of_product;
    do
    {
        std::cout << "\nEnter initial product items in warehouse:";
        in >> stock.balance_stock;
    } while (stock.balance_stock < 20);
}
