#include <iostream>
#include "Product.h"

Product::Product()
{
    productId = 1;
    productName = "Cricket Kit";
    price = 2000;
}

Product ::Product(int productId,
                  std::string productName,
                  float price)
{
    this->productId = productId;
    this->productName = productName;
    this->price = price;
}

void Product::show()const
{

    std::cout << "The Product details are below:\n";

    std::cout << "\nProduct Id = " << productId << "\n"
              << "Product Name = " << productName << "\n"
              << "Product Price=" << price << "\n";
}