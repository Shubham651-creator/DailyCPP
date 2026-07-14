#ifndef CARNEW_H
#define CARNEW_H

#include <iostream>
#include "CarCategoryNew.h"

class CarNew
{
private:
    std::string carName;
    int carSeatcount;
    enum CarCategoryNew carCategory;
    float carPrice;

public:
    CarNew();
    CarNew(const CarNew &);

    // explicit - There is keyword in modern cpp that block compiler 
    // using constructor for implicit type converstion.
    explicit CarNew(int count);
    CarNew(std::string name, int count, enum CarCategoryNew carCategory, float price);
    ~CarNew();
    void display();

    CarNew &operator=(const CarNew &);

    std::string getCarName() const { return carName; }
    void setCarName(const std::string &carName_) { carName = carName_; }

    int getCarSeatcount() const { return carSeatcount; }
    void setCarSeatcount(int carSeatcount_) { carSeatcount = carSeatcount_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    enum CarCategoryNew getCarCategory() const { return carCategory; }
    void setCarCategory(const enum CarCategoryNew &carCategory_) { carCategory = carCategory_; }
};

#endif // CARNEW_H
