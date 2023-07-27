#include <iostream>
#include "CarCategory.h"

class Car
{
    int carNo;
    std::string vehicleBrand;
    double carPrice;
    int numberOfSeats;
    const float tax = 18.0f;
    double insuaranceAmount;
    enum carCategory cCategory;

    static int no;

public:
    Car();
    void accept();
    char display();

    // getter setter functions
    int getCarNo() const { return carNo; }
    void setCarNo(int carNo_) { carNo = carNo_; }

    std::string getVehicleBrand() const { return vehicleBrand; }
    void setVehicleBrand(const std::string &vehicleBrand_) { vehicleBrand = vehicleBrand_; }

    double getCarPrice() const { return carPrice; }
    void setCarPrice(double carPrice_) { carPrice = carPrice_; }

    int getNumberOfSeats() const { return numberOfSeats; }
    void setNumberOfSeats(int numberOfSeats_) { numberOfSeats = numberOfSeats_; }

    float getTax() const { return tax; }
    double getInsuaranceAmount() const { return insuaranceAmount; }

    void setInsuaranceAmount(double insuaranceAmount_) { insuaranceAmount = insuaranceAmount_; }
    enum carCategory getCCategory() const { return cCategory; }

    void setCCategory(const enum carCategory &cCategory_) { cCategory = cCategory_; }
    friend void operator<<(std::ostream &os, Car &c);
};

float calculateAvg(Car *, carCategory);

// wrapper class
class BookVehicle
{
    Car *cptr;

public:
    BookVehicle();
    ~BookVehicle();

    Car *operator->()
    {
        return cptr;
    }
    Car operator*()
    {
        return *cptr;
    }
};