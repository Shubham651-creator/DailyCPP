#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarCategory.h"

class Car
{
private:
    int chassisNumber;
    std::string vehicalBrand;
    int vehiclePrice;
    int numberOfSeats;
    int vehicleTax;
    int insuranceAmount;
    enum CarCategory carCartegory;

public:
    Car();
    Car(int chassis, std::string brand, int price, int seats, int tax, int insurance, enum CarCategory carCategory);
    ~Car();

    void accept();
    void display();
    CarCategory inputEnum(int);
    std::string displayEnum();

    //extraction operator overloading <<
    friend void operator<<(std::ostream& out, Car& car);
};


#endif // CAR_H
