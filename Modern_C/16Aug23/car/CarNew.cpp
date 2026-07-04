#include <iostream>
#include "CarNew.h"
#include "CarCategoryNew.h"

// default is side effect i.e any extra work
// side effect is bad habit
CarNew::CarNew() = default; // defaulted default value

// CarNew::CarNew() = delete; //diseable for all i.e you can't use this function

CarNew::CarNew(const CarNew &) = default; // defaulted copy constructor


CarNew::CarNew(std::string name, int count, enum CarCategoryNew carCategory, float price)
    : carName(name), carSeatcount(count), carCategory(carCategory), carPrice(price) {}

//parameterized construtor that takes one int
 CarNew::CarNew(int count): carSeatcount(count){}

CarNew::~CarNew()
{
    std::cout << "Car with name:"
              << this->carName
              << " is destroyed\n\n";
}

void CarNew::display()
{
    std::cout << carName << "\n"
              << carSeatcount << "\n"
              << carPrice << "\n"
              << carCategory << "\n";
}
