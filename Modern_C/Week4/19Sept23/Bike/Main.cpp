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

int main()
{
    carPointer car1;
    bikePointer bike1;
    carContainer carObjects;
    bikeContainer bikeObjects;

    variantContainer variantObjects;

    try
    {

        CreateObjects(variantObjects);

        // display variant objects
        for (auto &listOfObjects : variantObjects)
        {
            std::visit([](auto &&object)
                       { std::cout << *object << "\n\n"; },
                       listOfObjects);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "1. The average price is "
                  << AveragePriceOfInstances(variantObjects)
                  << "\n\n";

        std::cout << "2. The maximum price of brand is "
                  << MaxPriceOfInstance(variantObjects)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "3. The container of instance whose below threshold:\n\n";
        // display variant objects
        if (PriceBelowThreshold(variantObjects, 500.0f).has_value())
        {
            // for (auto &listOfObjects : PriceBelowThreshold(variantObjects, 500.0f).value())
            // {
            //     std::cout << "shuam\n";
            //     std::visit([](auto &&object)
            //                { std::cout << "====================="
            //                            << "below thresholds : " << *object << "\n\n"; },
            //                listOfObjects);
            // }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "4. whether all instances has same vehicle type:\n"
                  << AllInstancesHasSameVehicle(variantObjects)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        carObjects.push_back(std::make_shared<Car>(
            1010.0f, "Ferrai", VehicleType::COMMUTE, 4));
        carObjects.push_back(std::make_shared<Car>(
            100.0f, "Ford", VehicleType::SPORTS, 5));
        carObjects.push_back(std::make_shared<Car>(
            264.0f, "Ford", VehicleType::PASSENGER, 6));

        std::cout << "5. A template function print instances:\n\n";

        BrandMatchesInstance<std::list<carPointer>>("Ford", std::ref(carObjects));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}