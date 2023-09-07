#include <iostream>
#include <list>
#include <memory>
#include "TouristVehicleType.h"
#include "TouristVehicle.h"

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs)
{
    os << "_number: " << rhs._number
       << " \n_type: " << DisplayTouristVehicleType(rhs._type)
       << " \n_seat_count: " << rhs._seat_count
       << "\n _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << "\n _permit: " << *(rhs._permit.get());

    return os;
}

std::string DisplayTouristVehicleType(TouristVehicleType touristType)
{
    if (touristType == TouristVehicleType::BIKE)
        return "BIKE";
    if (touristType == TouristVehicleType::BUS)
        return "BUS";

    return "CAB";
}

TouristVehicle::TouristVehicle(std::string number, TouristVehicleType type, int seat, float charge, PermitPointer permit)
    : _number(number), _type(type), _seat_count(seat), _per_hour_booking_charge(charge), _permit(permit) {}
