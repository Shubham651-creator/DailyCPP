#include "Bike.h"

Bike::Bike(float price, std::string brand, VehicleType type, int seats)
    : BikePrice(price), BikeBrand(brand), BikeVehicleType(type), BikeSeatCount(seats)
{
    if (seats > 2 || seats < 0)
    {
        throw std::runtime_error(
            "Count of seat must be in 1 or 2.\n");
    }
}

std::ostream &operator<<(std::ostream &os, const Bike &rhs)
{
    os << "BikePrice: " << rhs.BikePrice
       << " BikeBrand: " << rhs.BikeBrand
       << " BikeVehicleType: " << DisplayVehicleType(rhs.BikeVehicleType)
       << " BikeSeatCount: " << rhs.BikeSeatCount;
    return os;
}
