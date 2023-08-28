#include "Functionalites.h"
#include "Permit.h"

// list container which stores tourist objects
using touristVehicleContainer = std::list<std::shared_ptr<TouristVehicle>>;

void CreateObjectsOfTourist(touristVehicleContainer &touristObject) noexcept
{
    std::shared_ptr<TouristVehicle> t1 = std::make_shared<TouristVehicle>(
        "tourist1",
        TouristVehicleType::BIKE,
        2,
        50,
        std::make_shared<Permit>("Permit Serial 1", PermitType::LEASE, 200));

    std::shared_ptr<TouristVehicle> t2 = std::make_shared<TouristVehicle>(
        "tourist2",
        TouristVehicleType::BUS,
        31,
        702,
        std::make_shared<Permit>("Permit Serial 2", PermitType::LEASE, 370));

    std::shared_ptr<TouristVehicle> t3 = std::make_shared<TouristVehicle>(
        "tourist3",
        TouristVehicleType::CAB,
        4,
        350,
        std::make_shared<Permit>("Permit Serial 3", PermitType::OWNED, 9040));

    // store into the tousit vehicle objects
    touristObject.push_back(t1);
    touristObject.push_back(t2);
    touristObject.push_back(t3);
}

touristVehicleContainer ConditionSeatCountAndPermitType(touristVehicleContainer &touristObject)
{
    // check whether container empty or not
    if (touristObject.empty())
    {
        throw std::runtime_error("Toursit container is empty\n");
    }

    touristVehicleContainer store;

    for (std::shared_ptr<TouristVehicle> &object : touristObject)
    {
        if (object->seatCount() >= 4 &&
            object->permit()->permitType() == PermitType::LEASE)
        {
            store.push_back(object);
        }
    }

    return store;
}

float AvergeOfTypeCAB(touristVehicleContainer &touristObject)
{
    // check whether container empty or not
    if (touristObject.empty())
    {
        throw std::runtime_error("Toursit container is empty\n");
    }

    float sum = 0;
    float typeCount = 0;

    for (std::shared_ptr<TouristVehicle> &object : touristObject)
    {
        if (object->type() == TouristVehicleType::CAB)
        {
            sum += object->perHourBookingCharge();
            typeCount++; // count vehicle type CAB instances
        }
    }

    return sum / typeCount;
}

std::string BookingChargeIsMaximum(touristVehicleContainer &touristObject)
{
    // check whether container empty or not
    if (touristObject.empty())
    {
        throw std::runtime_error("Toursit container is empty\n");
    }

    float max = 0;
    std::string serialNumber = " ";

    for (std::shared_ptr<TouristVehicle> &object : touristObject)
    {
        if (object->perHourBookingCharge() > max)
        {
            max = object->perHourBookingCharge();
            serialNumber = object->permit()->serialNumber();
        }
    }

    return serialNumber;
}

touristVehicleContainer FirstNInstance(touristVehicleContainer &touristObject, int N)
{
    // check whether container empty or not
    if (touristObject.empty())
    {
        throw std::runtime_error("Toursit container is empty\n");
    }

    touristVehicleContainer store;
    int count = 0;

    for (std::shared_ptr<TouristVehicle> &object : touristObject)
    {
        if (count < N)
        {
            store.push_back(object);
            count++;
        }
        else
        {
            break;
        }
    }

    return store;
}
