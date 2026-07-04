#include "Functionalites.h"
#include "Permit.h"

// reference wrapper around shared ptr of Permit class
using permitContainer = std::vector<std::shared_ptr<Permit>>;

// list container which stores tourist objects
using touristVehicleContainer = std::list<std::shared_ptr<TouristVehicle>>;

// function Pointer
using funPointer = std::function<touristVehicleContainer(touristVehicleContainer &, int)>;

touristVehicleContainer Operation(touristVehicleContainer &touristObject, funPointer &fn)
{
    return fn(touristObject, 4);
}

void CreateObjectsOfTourist(touristVehicleContainer &touristObject, permitContainer &permitObject) noexcept
{
    permitObject.push_back(std::make_shared<Permit>("Permit Serial 1", PermitType::LEASE, 200));

    permitObject.push_back(std::make_shared<Permit>("Permit Serial 2", PermitType::LEASE, 370));

    permitObject.push_back(std::make_shared<Permit>("Permit Serial 3", PermitType::OWNED, 9040));

    // store into the tourist vehicle objects
    touristObject.push_back(std::make_shared<TouristVehicle>(
        "tourist1",
        TouristVehicleType::BIKE,
        2,
        50,
        std::ref(permitObject[0])));

    touristObject.push_back(std::make_shared<TouristVehicle>(
        "tourist2",
        TouristVehicleType::BUS,
        31,
        702,
        std::ref(permitObject[1])));
    touristObject.push_back(std::make_shared<TouristVehicle>(
        "tourist3",
        TouristVehicleType::CAB,
        4,
        350,
        std::ref(permitObject[2])));
}

touristVehicleContainer ConditionSeatCountAndPermitType(touristVehicleContainer &touristObject, int seats)
{
    // check whether container empty or not
    if (touristObject.empty())
    {
        throw std::runtime_error("Toursit container is empty\n");
    }

    touristVehicleContainer store;

    for (std::shared_ptr<TouristVehicle> &object : touristObject)
    {
        if (object->seatCount() >= seats &&
            object.get()->permit().get()->permitType() == PermitType::LEASE)
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
            serialNumber = object.get()->permit().get()->serialNumber();
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
