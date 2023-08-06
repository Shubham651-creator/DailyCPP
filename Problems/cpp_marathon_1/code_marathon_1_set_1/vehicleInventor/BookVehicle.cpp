#include <iostream>
#include "BookVehicle.h"

BookVehicle::BookVehicle()
{
    car = new Car;
}

BookVehicle::~BookVehicle()
{
    delete car;
}

Car* BookVehicle::operator->()
{
    return car;
}

Car BookVehicle::operator*()
{
    return *car;
}