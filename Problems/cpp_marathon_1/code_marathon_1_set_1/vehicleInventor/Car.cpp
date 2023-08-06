#include <iostream>
#include "Car.h"

Car::Car()
{
}

Car::Car(int chassis, std::string brand, int price, int seats, int tax, int insurance, enum CarCategory carCategory)
    : chassisNumber(chassis), vehicalBrand(brand), vehiclePrice(price), numberOfSeats(seats), vehicleTax(tax), insuranceAmount(insurance), carCartegory(carCartegory)
{
}

Car::~Car()
{
}

void Car::accept()
{
    int chooseEnum;
    std::cin >> chassisNumber >> vehicalBrand >> vehiclePrice >> numberOfSeats >> vehicleTax >> insuranceAmount >> chooseEnum;
    carCartegory = inputEnum(chooseEnum);
}

void Car::display()
{
    std::cout << "chassis Number = " << chassisNumber
              << "\nbrand = " << vehicalBrand
              << "\nnumber of seats = " << numberOfSeats
              << "\nVehical Tax = " << vehicleTax
              << "\nInsureance amount = " << insuranceAmount;
    std::cout << "\ncar Category = " << displayEnum() << "\n\n";
}

CarCategory Car::inputEnum(int chooseEnum)
{
    if (chooseEnum == 0)
        return CarCategory::SUV;
    if (chooseEnum == 1)
        return CarCategory::HATCHBACK;
    else
        return CarCategory::SEDAN;
}

std::string Car::displayEnum()
{
    int check = (int)carCartegory;
    switch (check)
    {
    case 0:
        return "SUV";
    case 1:
        return "HATCHBACK";
    case 2:
        return "SEDAN";
    }

    return "nothing";
}

void operator<<(std::ostream &out, Car &car)
{
    out << "chassis Number = " << car.chassisNumber
              << "\nbrand = " << car.vehicalBrand
              << "\nnumber of seats = " << car.numberOfSeats
              << "\nVehical Tax = " << car.vehicleTax
              << "\nInsureance amount = " << car.insuranceAmount;
    out << "\ncar Category = " << car.displayEnum() << "\n\n";
}