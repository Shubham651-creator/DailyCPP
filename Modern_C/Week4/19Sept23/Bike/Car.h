#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "VehicleType.h"

class Car
{
private:
    float carPrice;
    std::string carBrand;
    VehicleType carVehicleType;
    int carSeatCount;

public:
    Car() = delete;

    Car(const Car &) = delete;

    Car &operator=(Car &) = delete;

    Car(Car &&) = delete;

    Car &operator=(Car &&) = delete;

    Car(float price, std::string brand, VehicleType type, int seats);

    ~Car() = default;

    float Price() const { return carPrice; }

    std::string Brand() const { return carBrand; }

    VehicleType GetVehicleType() const { return carVehicleType; }

    int SeatCount() const { return carSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
