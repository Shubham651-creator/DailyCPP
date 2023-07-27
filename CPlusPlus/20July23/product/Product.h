#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{

    int productId;
    std::string productName;
    float price;

public:
    Product();
    Product(int productId,
            std::string productName,
            float price);

    void show()const;

    int getProductId() const { return productId; }
    void setProductId(int productId_) { productId = productId_; }

    std::string getProductName() const { return productName; }
    void setProductName(const std::string &productName_) { productName = productName_; }

    float getPrice() const { return price; }
    void setPrice(float price_) { price = price_; }
};

#endif // PRODUCT_H
