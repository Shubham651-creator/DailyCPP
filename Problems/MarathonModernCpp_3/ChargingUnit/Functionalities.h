#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <variant>
#include <vector>
#include <array>
#include <memory>
#include <optional>
#include <algorithm>
#include <numeric>
#include "ChargingUnit.h"

using pointerOfcharging = std::shared_ptr<ChargingUnit>;

// container containes objects of ChargingUnit
using containerOfCharging = std::vector<pointerOfcharging>;

/*
    Create 5 objects of ChargingUnit
*/
void CreateObjects(containerOfCharging &chargingObject);

/*
    2. return GST float amount which has follow conditon
*/
float GSTAmountFunction(containerOfCharging &ChargingObject);

/*
    3. return container of 2 instance whose capacity value are
    hight and second highest.
*/
containerOfCharging HightAndSecondHighest(containerOfCharging &chargingObject);

/*
    4. return bool to indicate whether all instacne have value
    for ratingKw abovw 3
*/
bool RatingKWAbove3(containerOfCharging &chargingObject);

/*
    5. return container of instance whose id value passed
    as second arg
*/
std::optional<containerOfCharging> CheckId(containerOfCharging &chargingObject, std::string id);

/*
    6. return average of reting Kw whose calculate only
    costPerKw above 2.5
*/
float AverageOfCostPerKW(containerOfCharging &chargingObject);

#endif // FUNCTIONALITIES_H
