#include "Car.h"

Car::Car(std::string id, std::string model, CarType type, float price, int fuelCap)
    : _id(id), _model(model), _type(type), _price(price), _fuelCapacity(fuelCap) {}

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_id: " << rhs._id
       << " _model: " << rhs._model
       << " _type: " << displayCarType(rhs._type)
       << " _price: " << rhs._price
       << " _fuelCapacity: " << rhs._fuelCapacity;
    return os;
}

std::string displayCarType(CarType type)
{
    if (type == CarType::HATCHBACK)
        return "HATCHBACK";
    if (type == CarType::SEDAN)
        return "SEDAN";
    else
        return "SUV";
}