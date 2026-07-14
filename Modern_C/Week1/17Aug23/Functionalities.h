#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <list>
#include "Car.h"

// Container is list of car pointer
using Container = std::list<Car>;

/*
    createObject accepts on Container by lvalue reference
    and return void
*/
void CreateObjects(Container &data);

/*
    AveragePrice accepts on Container by lvalue reference
    and returns float
*/
float AveragePrice(Container &data);

/*
    function takes a container as input, finds all units with highest price
    and prints their _model string.
*/
void ModelNameHightestPrice(Container &data);

/*
    function to return a container by value of all units whose price is above a threshold.
*/
Container CarsAboveThreshold(Container &data, float threshold);

#endif // FUNCTIONALITIES_H
