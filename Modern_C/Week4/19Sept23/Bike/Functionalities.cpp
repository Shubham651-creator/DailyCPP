#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <variant>
#include <list> // we don't want contigous memory
#include "Bike.h"
#include "Car.h"
#include "Functionalities.h"

using carPointer = std::shared_ptr<Car>;
using bikePointer = std::shared_ptr<Bike>;

using carContainer = std::list<carPointer>;
using bikeContainer = std::list<bikePointer>;

using variantPointer = std::variant<carPointer, bikePointer>;
using variantContainer = std::list<variantPointer>;

void CreateObjects(variantContainer &variantObjects)
{
    variantObjects.push_back(std::make_shared<Car>(
        1010.0f, "Ferrai", VehicleType::COMMUTE, 4));
    variantObjects.push_back(std::make_shared<Car>(
        100.0f, "Ford", VehicleType::SPORTS, 5));
    variantObjects.push_back(std::make_shared<Car>(
        264.0f, "BUS", VehicleType::PASSENGER, 6));

    variantObjects.push_back(std::make_shared<Bike>(
        111.0f, "Honda", VehicleType::SPORTS, 2));
    variantObjects.push_back(std::make_shared<Bike>(
        213.0f, "TVS", VehicleType::PASSENGER, 2));
    variantObjects.push_back(std::make_shared<Bike>(
        348.0f, "BMW", VehicleType::UTILITY, 2));
}

float AveragePriceOfInstances(variantContainer &variantObjects)
{
    // check container empty or not
    if (variantObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    float sum = std::accumulate(
        variantObjects.begin(),
        variantObjects.end(),
        0.0f,
        [](float ans, variantPointer object)
        {
            std::visit([&](auto &&obj)
                       { ans += obj->Price(); },
                       object);

            return ans;
        }

    );

    return sum / variantObjects.size();
}

std::string MaxPriceOfInstance(variantContainer &variantObjects)
{
    // check container empty or not
    if (variantObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto maxItr = std::max_element(
        variantObjects.begin(),
        variantObjects.end(),
        [](variantPointer &obj1, variantPointer &obj2)
        {
            float first = 0.0f, second = 0.0f;

            std::visit([&](auto &&val1, auto &&val2)
                       {
                    first = val1->Price();
                    second = val2->Price(); },
                       obj1, obj2);

            return first < second;
        });

    std::string store;
    std::visit([&](auto &&val)
               { store = val->Brand(); },
               *maxItr);

    return store;
}

std::optional<variantContainer> PriceBelowThreshold(variantContainer &variantObjects,
                                                    float thresholdPrice)
{
    // check container empty or not
    if (variantObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    variantContainer store;

    float objPrice;
    std::for_each(
        variantObjects.begin(),
        variantObjects.end(),
        [&](variantPointer &objects)
        {
            std::visit(
                [&](auto &&obj)
                {
                    objPrice = obj->Price();
                },
                objects);
            if (objPrice < thresholdPrice)
            {
                store.push_back(objects);
            }
        });

    // display variant objects
    for (auto &listOfObjects : store)
    {
        std::visit([](auto &&object)
                   { std::cout << *object << "\n\n"; },
                   listOfObjects);
    }

    return std::make_optional(store);
}

bool AllInstancesHasSameVehicle(variantContainer &variantObjects)
{
    // check container empty or not
    if (variantObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    std::string first, store;
    std::visit(
        [&](auto &&vtype)
        {
            store = DisplayVehicleType(vtype->GetVehicleType());
        },
        *variantObjects.begin());

    return std::all_of(
        variantObjects.begin(),
        variantObjects.end(),
        [&](variantPointer &obj1)
        {
            std::visit(
                [&](auto &&val1)
                {
                    first = DisplayVehicleType(val1->GetVehicleType());
                },
                obj1);

            return first == store;
        });
}
