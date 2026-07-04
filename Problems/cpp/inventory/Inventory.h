#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>

class Inventory
{
private:
    std::string description_of_product;
    int balance_stock;
    int productcode;

    static int initProductCode;

public:
    Inventory();
    Inventory(std::string dec, int bal_stock);
    ~Inventory();

    void purchase();
    void sale();

    friend void operator<<(std::ostream &out, Inventory &stock); // operator<<(cout, object)
    friend void operator>>(std::istream& in, Inventory& stock); //ooperator>>(cin, object)

    std::string descriptionOfProduct() const { return description_of_product; }
    void setDescriptionOfProduct(const std::string &descriptionOfProduct) { description_of_product = descriptionOfProduct; }

    int balanceStock() const { return balance_stock; }
    void setBalanceStock(int balanceStock) { balance_stock = balanceStock; }

    int getProductcode() const { return productcode; }
    void setProductcode(int productcode_) { productcode = productcode_; }
};

#endif // INVENTORY_H
