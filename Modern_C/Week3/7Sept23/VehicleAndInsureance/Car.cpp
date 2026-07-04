#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << static_cast<const Vehicle &>(rhs)
       << " carType: " << DisplayCarType(rhs.carType)
       << " carPrice: " << rhs.carPrice
       << " carColour: " << rhs.carColour;
    return os;
}
Car::Car(std::variant<int, std::string> id, int registration, VehicleType instype, refPointer plan,
         CarType ctype, float price, std::string colour)
    : Vehicle(id,registration, instype, plan), carType(ctype), carPrice(price) , carColour(colour) {}

std::string DisplayCarType(CarType type)
{
    if (type == CarType::HATCHBACK)
        return "HATCHBACK";
    if (type == CarType::SEDAN)
        return "SEDAN";

    return "SUV";
}