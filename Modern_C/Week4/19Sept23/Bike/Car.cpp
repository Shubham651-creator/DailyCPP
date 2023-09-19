#include "Car.h"
 

Car::Car(float price, std::string brand, VehicleType type, int seats)
    : carPrice(price), carBrand(brand), carVehicleType(type), carSeatCount(seats)
{
    if (seats < 2 || seats > 7)
    {
        throw std::runtime_error(
            "Count of seat must be in between 2 and 7.\n");
    }
}

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "carPrice: " << rhs.carPrice
       << " carBrand: " << rhs.carBrand
       << " carVehicleType: " << DisplayVehicleType(rhs.carVehicleType)
       << " carSeatCount: " << rhs.carSeatCount;
    return os;
}
