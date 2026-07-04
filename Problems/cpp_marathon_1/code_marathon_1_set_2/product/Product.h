#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{
private:
    int productNumber;
    std::string productName;
    int productRate;
    std::string brandName;
    int productQuantityInStock;
    int productQuantityPurchased;
    std::string productCategory;
    int totalAmount;

    std::string productCategoryArray[4] = {
        "SHIRT",
        "SWEATER",
        "COAT",
        "JEANS"};

public:
    Product();
    Product(int product_number, std::string product_name, int rate, std::string brand_name, int quantityInStock, int quantityPurchased, std::string product_category, int amount);
    ~Product();

    bool validate();
    void accept();
    void display();

    int getProductNumber() const { return productNumber; }
    void setProductNumber(int productNumber_) { productNumber = productNumber_; }

    std::string getProductName() const { return productName; }
    void setProductName(const std::string &productName_) { productName = productName_; }

    float getProductRate() const { return productRate; }
    void setProductRate(float productRate_) { productRate = productRate_; }

    std::string getBrandName() const { return brandName; }
    void setBrandName(const std::string &brandName_) { brandName = brandName_; }

    int getProductQuantityInStock() const { return productQuantityInStock; }
    void setProductQuantityInStock(int productQuantityInStock_) { productQuantityInStock = productQuantityInStock_; }

    int getProductQuantityPurchased() const { return productQuantityPurchased; }
    void setProductQuantityPurchased(int productQuantityPurchased_) { productQuantityPurchased = productQuantityPurchased_; }

    int getTotalAmount() const { return totalAmount; }
    void setTotalAmount(int totalAmount_) { totalAmount = totalAmount_; }
};

#endif // PRODUCT_H
