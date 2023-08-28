#include "CabBooking.h"

std::ostream &operator<<(std::ostream &os, const CabBooking &rhs)
{
    os << "_booking_id: " << rhs._booking_id
       << "\n _pickup_location: " << rhs._pickup_location
       << "\n _drop_location: " << rhs._drop_location
       << "\n _base_fare: " << rhs._base_fare;
    return os;
}

CabBooking::CabBooking(std::string id, std::string pickup, std::string drop, float fare)
    : _booking_id(id), _pickup_location(pickup), _drop_location(drop), _base_fare(fare) {}
