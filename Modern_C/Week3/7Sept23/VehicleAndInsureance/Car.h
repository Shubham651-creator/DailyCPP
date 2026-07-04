#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"
#include "Vehicle.h"

class Car : public Vehicle
{
private:
    CarType carType;
    float carPrice;
    std::string carColour;

public:
    Car() = delete;

    Car(const Car &) = delete;

    Car &operator=(const Car &) = delete;

    Car(Car &&) = delete;

    Car &operator=(Car &&) = delete;

    Car(std::variant<int, std::string> id, int registration, VehicleType type, refPointer plan,
        CarType, float, std::string);

    ~Car() = default;

    CarType getCarType() const { return carType; }

    float getCarPrice() const { return carPrice; }

    std::string getCarColour() const { return carColour; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

std::string DisplayCarType(CarType type);

#endif // CAR_H
