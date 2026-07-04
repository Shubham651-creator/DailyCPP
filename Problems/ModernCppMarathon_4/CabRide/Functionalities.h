#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>
#include <optional>
#include "CabRide.h"

// pointer to cabRide
using Pointer = std::shared_ptr<CabRide>;

// list container of cabRide
using Container = std::list<Pointer>;

// function wrapper
using function_set_A = std::function<void(Container &)>;
using function_set_B = std::function<void(Container &, float)>;

// 1. higher order function
void HigherOrderFunction(Container &object, function_set_A &funcObject);

// 2. overloaded higher order function
void HigherOrderFunction(Container &object, function_set_B &funcObject, float threshold);

// 3. create objects
void CreateObject(Container &object);

// 4. print instances whose type is CASH
void CheckTypeCASH(Container &object);

// 5. print averge of distance of all instance whose rating is above threshold.
void AvergeDistanceAboveThreshold(Container &object, float threshold);

// 6. print averger of rating whose distance is above threshold.
void AvergeRatingAboveDistance(Container &object, float threshold);

// 7. print count of instance whose fare is above 150.
void CountInstanceAbove150Fare(Container &object);

// 8. print bool, whether all instance above 4 count
void CheckAllCountAbove4(Container &object);

#endif // FUNCTIONALITIES_H
