#ifndef BOOKVEHICLE_H
#define BOOKVEHICLE_H

#include <iostream>
#include "Car.h"

// BookVehicle is wrraper class of Car
class BookVehicle
{
private:
    Car *car;

public:
    BookVehicle();
    ~BookVehicle();
    Car* operator->();
    Car operator*();
};

#endif // BOOKVEHICLE_H
