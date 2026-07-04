#include <iostream>
#include <variant>
#include <vector>
#include <array>
#include <memory>
#include <optional>
#include <algorithm>
#include <numeric>
#include "ChargingUnit.h"
#include "Functionalities.h"

using pointerOfcharging = std::shared_ptr<ChargingUnit>;

// container containes objects of ChargingUnit
using containerOfCharging = std::vector<pointerOfcharging>;

int main()
{
    containerOfCharging chargingObjects;

    try
    {
        CreateObjects(chargingObjects);

        for (pointerOfcharging &value : chargingObjects)
        {
            std::cout << *value << '\n';
        }

        std::cout << "GSTAmountFunction()" << '\n'
                  << GSTAmountFunction(chargingObjects) << '\n';

        std::cout << "HightAndSecondHighest()" << '\n';
        for (pointerOfcharging &value : HightAndSecondHighest(chargingObjects))
        {
            std::cout << *value << '\n';
        }

        std::cout << "RatingKWAbove3()\n"
                  << RatingKWAbove3(chargingObjects) << '\n';

        std::cout << "CheckId()\n";
        if (CheckId(chargingObjects, "unit101").has_value())
        {
            for (pointerOfcharging &value : chargingObjects)
            {
                std::cout << *value << '\n';
            }
        }

        std::cout << "AverageOfCostPerKW()\n"
                  << AverageOfCostPerKW(chargingObjects) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}