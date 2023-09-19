#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include "VehicleType.h"

class Bike
{
private:
    float BikePrice;
    std::string BikeBrand;
    VehicleType BikeVehicleType;
    int BikeSeatCount;

public:
    Bike() = delete;

    Bike(const Bike &) = delete;

    Bike &operator=(Bike &) = delete;

    Bike(Bike &&) = delete;

    Bike &operator=(Bike &&) = delete;

    Bike(float price, std::string brand, VehicleType type, int seats);

    ~Bike() = default;

    float Price() const { return BikePrice; }

    std::string Brand() const { return BikeBrand; }

    VehicleType GetVehicleType() const { return BikeVehicleType; }

    int SeatCount() const { return BikeSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H
