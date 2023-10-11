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

void HigherOrderFunction(Container &object, function_set_A &funcObject)
{
    funcObject(object);
}

void HigherOrderFunction(Container &object, function_set_B &funcObject, float threshold)
{
    funcObject(object, threshold);
}

void CreateObject(Container &object)
{
    object.push_back(std::make_shared<CabRide>(
        "101a",
        2500.0f,
        RidePaymentType::CARD,
        219.f,
        4,
        "Shubham",
        2.1f,
        210.0f));

    object.push_back(std::make_shared<CabRide>(
        "102a",
        3500.0f,
        RidePaymentType::CASH,
        376.0f,
        3,
        "Rasika",
        3.1f,
        310.0f));

    object.push_back(std::make_shared<CabRide>(
        "103a",
        4500.0f,
        RidePaymentType::CARD,
        87.4f,
        4,
        "Omkar",
        4.1f,
        410.0f));

    object.push_back(std::make_shared<CabRide>(
        "104a",
        5500.0f,
        RidePaymentType::UPI,
        46.3f,
        5,
        "shreya",
        2.3f,
        510.0f));
}

void CheckTypeCASH(Container &object)
{
    // check whether container empty
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto itr = std::find_if(
        object.begin(),
        object.end(),
        [](Pointer &obj)
        {
            return obj.get()->ridePaymentType() == RidePaymentType::CARD;
        });

    std::cout << "\n\nThe CASH instance is \n"
              << **itr << "\n\n";
}

void AvergeDistanceAboveThreshold(Container &object, float threshold)
{
    // check whether container empty
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = 0;
    float sum = std::accumulate(
        object.begin(),
        object.end(),
        0.0f,
        [&](float ans, Pointer &obj)
        {
            if (threshold > obj.get()->rideDriverRating())
            {
                count++;
                return ans + obj.get()->rideDistance();
            }

            return ans + 0.0f;
        });

    std::cout << "The average of ride distance whose above threshold is "
              << sum / (float)count << "\n\n";
}

void AvergeRatingAboveDistance(Container &object, float threshold)
{
    // check whether container empty
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count ;
    float sum = std::accumulate(
        object.begin(),
        object.end(),
        0.0f,
        [&](float ans, Pointer &obj)
        {
            if (threshold > obj.get()->rideDistance())
            {
                count++;
                return ans + obj.get()->rideDriverRating();
            }

            return ans + 0.0f;
        });

    std::cout << "The average of ride rating whose above threshold is "
              << sum / (float)count << "\n\n";
}

void CountInstanceAbove150Fare(Container &object)
{
    // check whether container empty
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int varCount = std::count_if(
        object.begin(),
        object.end(),
        [](Pointer &obj)
        {
            return obj.get()->rideFare() > 149;
        });

    std::cout << "The count of above 150 fare instance is "
              << varCount << "\n\n";
}

void CheckAllCountAbove4(Container &object)
{
    // check whether container empty
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    bool var = std::all_of(
        object.begin(),
        object.end(),
        [](Pointer &obj)
        {
            return obj.get()->ridePassengerCount() > 4;
        });

    std::cout << "Whether all instance is above 4 or not\t"
              << var << "\n\n";
}
