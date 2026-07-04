#ifndef FUNCTIONALITIES2_H
#define FUNCTIONALITIES2_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <optional>
#include <variant>
#include "Automobile.h"
#include "Engine.h"

using pointerOfEngine = std::shared_ptr<Engine>;
using pointerOfAutomobile = std::shared_ptr<Automobile>;

using EngineContainer = std::vector<pointerOfEngine>;
using AutomobileContainer = std::vector<pointerOfAutomobile>;

/*
    Create 5 objects using threads
*/
void CreateObjectEngine(EngineContainer &engineObjects,
                        float size, int hPower, EngineType etype);

void CreateObjectsAutomobile(AutomobileContainer &automobileObjects, EngineContainer &engineObjects,
                             std::variant<int, std::string> id, AutomobileType autoType, std::string brand,
                             pointerOfEngine engine, float price, std::array<int, 4> pressure);

/*
    2. return container of Automonile whose horsepower
    is abobe threshold
*/
std::optional<AutomobileContainer> HorsePowerAboveThreshold(
    AutomobileContainer &automobileObjects, int threshold);

/*
    3. return container of flaot of tax
*/
std::vector<float> CalculateTax(AutomobileContainer &automobileObjects);

/*
    4. return count whose horspowe and price above threshold
*/
int HorspowerPriceAboveThreshold(AutomobileContainer &automobileObjects,
                                 int thresholdHorse, float threholdPrice);

/*
    6.print detail engine of automobile whose price is min
*/
void MinimumPrice(AutomobileContainer &automobileObjects);

#endif // FUNCTIONALITIES2_H
