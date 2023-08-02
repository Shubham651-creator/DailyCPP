#include <iostream>
#include "CarNew.h"
#include "CarCategoryNew.h"

CarNew::CarNew()
{
}

CarNew::CarNew(std::string name, int count, enum CarCategoryNew carCategory, float price)
{
    carName = name;
    carSeatcount = count;
    this->carCategory = carCategory;
    carPrice = price;
}

CarNew::~CarNew()
{
    std::cout << "Car with name:"
              << this->carName
              << " is destroyed\n\n";
}

void CarNew::display()
{
     std::cout << carName<<"\n" << carSeatcount<<"\n"<< carPrice<<"\n" << carCategory<<"\n";
}
