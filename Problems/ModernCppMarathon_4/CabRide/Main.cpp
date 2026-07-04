#include "Functionalities.h"
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

int main()
{

    Container object;
    try
    {
        CreateObject(object);

        for (auto &value : object)
        {
            std::cout << *value << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        function_set_A func4 = CheckTypeCASH;
        HigherOrderFunction(object, func4);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        function_set_A func7 = CountInstanceAbove150Fare;
        HigherOrderFunction(object, func7);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        function_set_A func8 = CheckAllCountAbove4;
        HigherOrderFunction(object, func8);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        auto funcbind5 = std::bind(&AvergeDistanceAboveThreshold, object, 4.5f);
        funcbind5(object, 4.5f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        auto funcBind6 = std::bind(&AvergeRatingAboveDistance, object, 6.1f);
        funcBind6(object, 6.1f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}