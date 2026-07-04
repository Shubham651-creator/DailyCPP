#include <iostream>
#include <memory>
#include <algorithm>
#include <optional>
#include <numeric>
#include <variant>
#include <list> // we don't want contigous memory
#include "Bike.h"
#include "Car.h"

using carPointer = std::shared_ptr<Car>;
using bikePointer = std::shared_ptr<Bike>;

using carContainer = std::list<carPointer>;
using bikeContainer = std::list<bikePointer>;

using variantPointer = std::variant<carPointer, bikePointer>;
using variantContainer = std::list<variantPointer>;

// create objects using list container as params
void CreateObjects(variantContainer &variantObjects);

/*
    1. take container as param and calculate averge price
    all instances
*/
float AveragePriceOfInstances(variantContainer &variantObjects);

// 2. a function to return brand of variant whose price is max
std::string MaxPriceOfInstance(variantContainer &variantObjects);

/*
    3. return container of vehicleType instance whose
    price is below threshold.
*/
std::optional<variantContainer> PriceBelowThreshold(
    variantContainer &variantObjects,
    float thresholdPrice);

/*
    4. check whether all instance passed who has
    same vehicletype and return bool
*/
bool AllInstancesHasSameVehicle(variantContainer &variantObjects);

/*
    5. A template function accpet container and print
    all instance whose brand matches second params.
*/
template <typename T>
void BrandMatchesInstance(
    std::string ownBrand, T listOfObjects)
{
    for(auto& objects : listOfObjects){
        if(ownBrand == objects->Brand()){
            std::cout<< *objects <<"\n\n";
        }
    }
}